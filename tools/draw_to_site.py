#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
import time
from dataclasses import dataclass
from pathlib import Path


def _die(msg: str, code: int = 2) -> "None":
    print(msg, file=sys.stderr)
    raise SystemExit(code)


def _repo_root() -> Path:
    return Path(__file__).resolve().parent.parent


def _have_occt_env() -> bool:
    return bool(os.environ.get("CSF_OCCTIncludePath")) and bool(os.environ.get("CSF_OCCTLibPath"))


def _find_drawexe(root: Path) -> str | None:
    # Prefer PATH (after sourcing build-occt/env.sh).
    p = shutil.which("DRAWEXE")
    if p:
        return p

    # Fallback to default build location (if user didn't add it to PATH).
    guess = root / "build-occt" / "lin64" / "gcc" / "bini" / "DRAWEXE"
    if guess.exists():
        return str(guess)
    return None


def _ensure_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def _load_json(path: Path) -> dict:
    if not path.exists():
        return {}
    return json.loads(path.read_text(encoding="utf-8"))


def _write_json(path: Path, data: object) -> None:
    path.write_text(json.dumps(data, indent=2, sort_keys=False) + "\n", encoding="utf-8")


def _build_mesh_exporter(root: Path, bin_path: Path) -> None:
    if bin_path.exists():
        return

    if not _have_occt_env():
        _die(
            "OCCT env not set. Run:\n"
            "  source build-occt/env.sh i\n"
            "and re-run this command."
        )

    include = os.environ["CSF_OCCTIncludePath"]
    lib = os.environ["CSF_OCCTLibPath"]

    src = root / "tools" / "mesh_brep_to_json.cpp"
    if not src.exists():
        _die(f"missing source: {src}")

    _ensure_dir(bin_path.parent)

    cxx = os.environ.get("CXX", "g++")
    cmd = [
        cxx,
        "-std=c++17",
        "-O2",
        "-g",
        f"-I{include}",
        str(src),
        f"-L{lib}",
        "-lTKMesh",
        "-lTKTopAlgo",
        "-lTKBRep",
        "-lTKGeomBase",
        "-lTKG3d",
        "-lTKG2d",
        "-lTKMath",
        "-lTKernel",
        "-o",
        str(bin_path),
    ]
    subprocess.check_call(cmd)


@dataclass(frozen=True)
class Step:
    id: str
    brep: str
    mesh: str


def _collect_steps(out_dir: Path) -> list[Step]:
    steps: list[Step] = []
    for brep_path in sorted(out_dir.glob("*.brep")):
        step_id = brep_path.stem
        steps.append(
            Step(
                id=step_id,
                brep=brep_path.name,
                mesh=f"{step_id}.mesh.json",
            )
        )
    return steps


def main() -> int:
    ap = argparse.ArgumentParser(description="Run a DRAW .tcl script and publish captured BREP steps to the site as mesh.json.")
    ap.add_argument("--tcl", required=True, help="Path to DRAW .tcl script")
    ap.add_argument("--session", required=True, help="Session id (folder name under site/public/occt/draw/)")
    ap.add_argument("--deflection", type=float, default=0.05, help="Meshing deflection (default: 0.05)")
    ap.add_argument("--site-public", default="site/public", help="Site public dir (default: site/public)")
    ap.add_argument("--run", action="store_true", help="Actually run DRAWEXE (otherwise just convert existing BREP in out dir)")
    ap.add_argument("--out", default="", help="Override capture output dir (default: .cache/draw/<session>)")
    args = ap.parse_args()

    root = _repo_root()
    tcl_path = (Path(args.tcl).resolve())
    if not tcl_path.exists():
        _die(f"missing script: {tcl_path}")

    site_public = (root / args.site_public).resolve()
    if not site_public.exists():
        _die(f"missing site public dir: {site_public}")

    capture_dir = Path(args.out).resolve() if args.out else (root / ".cache" / "draw" / args.session).resolve()
    _ensure_dir(capture_dir)

    log_path = capture_dir / "draw.log.txt"

    if args.run:
        drawexe = _find_drawexe(root)
        if not drawexe:
            _die(
                "DRAWEXE not found.\n"
                "This repo's default OCCT build disables Draw.\n\n"
                "Build it once:\n"
                "  cmake -S occt -B build-occt -G Ninja -DBUILD_MODULE_Draw=ON\n"
                "  ninja -C build-occt DRAWEXE\n"
                "  source build-occt/env.sh i\n"
            )

        env = os.environ.copy()
        env["OCCT_RESEARCH_OUT"] = str(capture_dir)
        env["OCCT_RESEARCH_SESSION"] = str(args.session)

        # Note: DRAW uses Tcl; a failing command should exit non-zero in batch mode.
        cmd = [drawexe, "-b", "-f", str(tcl_path)]
        proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, env=env, text=True)
        log_path.write_text(proc.stdout, encoding="utf-8")
        if proc.returncode != 0:
            _die(f"DRAWEXE failed (exit={proc.returncode}). See: {log_path}", code=proc.returncode)

    steps = _collect_steps(capture_dir)
    if not steps:
        _die(
            f"No *.brep files found in capture dir: {capture_dir}\n"
            "In your .tcl script, write snapshots like:\n"
            "  set out $env(OCCT_RESEARCH_OUT)\n"
            "  writebrep myShape $out/010_after_step.brep\n"
        )

    # Publish into site/public so Astro can serve without sync/restart.
    draw_root = site_public / "occt" / "draw"
    session_dir = draw_root / args.session
    _ensure_dir(session_dir)

    # Copy raw captures (useful for download / re-meshing).
    for step in steps:
        shutil.copy2(capture_dir / step.brep, session_dir / step.brep)
    if log_path.exists():
        shutil.copy2(log_path, session_dir / "draw.log.txt")

    # Convert BREP → mesh.json
    mesh_bin = root / ".cache" / "bin" / "mesh_brep_to_json"
    _build_mesh_exporter(root, mesh_bin)

    for step in steps:
        in_brep = session_dir / step.brep
        out_mesh = session_dir / step.mesh
        subprocess.check_call([str(mesh_bin), str(in_brep), str(out_mesh), str(args.deflection)])

    session_index = {
        "session": args.session,
        "created_at": int(time.time()),
        "script": str(tcl_path),
        "deflection": args.deflection,
        "steps": [{"id": s.id, "brep": s.brep, "mesh": s.mesh} for s in steps],
        "log": "draw.log.txt" if (session_dir / "draw.log.txt").exists() else None,
    }
    _write_json(session_dir / "index.json", session_index)

    registry_path = draw_root / "index.json"
    registry = _load_json(registry_path) or {}
    sessions = registry.get("sessions")
    if not isinstance(sessions, list):
        sessions = []

    # Update / upsert entry
    now = int(time.time())
    sessions = [s for s in sessions if isinstance(s, dict) and s.get("session") != args.session]
    sessions.append({"session": args.session, "updated_at": now})
    sessions = sorted(sessions, key=lambda x: int(x.get("updated_at", 0)), reverse=True)
    registry["sessions"] = sessions
    _write_json(registry_path, registry)

    print(f"[ok] published session: {args.session}")
    print(f"     session index: {session_dir / 'index.json'}")
    print(f"     registry:      {registry_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

