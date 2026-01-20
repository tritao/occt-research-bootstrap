#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

from jsonschema.validators import validator_for


def fail(msg: str) -> None:
    print(f"[FAIL] {msg}")


def ok(msg: str) -> None:
    print(f"[OK] {msg}")


def _is_finite_number(x: object) -> bool:
    if not isinstance(x, (int, float)):
        return False
    return math.isfinite(float(x))


def _validate_flat_vec(data: object, *, stride: int, allow_empty: bool, ctx: str) -> list[str]:
    errs: list[str] = []
    if not isinstance(data, list):
        return [f"{ctx}: expected list, got {type(data).__name__}"]
    if not data:
        if allow_empty:
            return []
        return [f"{ctx}: empty array"]
    if len(data) % stride != 0:
        errs.append(f"{ctx}: length {len(data)} not divisible by {stride}")
    if any(not _is_finite_number(x) for x in data):
        errs.append(f"{ctx}: contains non-finite entries")
    return errs


def validate_model_json(schema: dict, model_path: Path) -> list[str]:
    Validator = validator_for(schema)
    validator = Validator(schema)

    errs: list[str] = []
    try:
        data = json.loads(model_path.read_text(encoding="utf-8"))
    except Exception as e:  # noqa: BLE001
        return [f"{model_path}: failed to parse JSON: {e}"]

    try:
        validator.validate(data)
    except Exception as e:  # noqa: BLE001
        errs.append(f"{model_path}: schema validation failed: {e}")
        return errs

    # Extra invariants that JSON Schema doesn't express well (stride / finiteness).
    stripes = data.get("stripes")
    if not isinstance(stripes, list):
        return errs

    for si, stripe in enumerate(stripes):
        if not isinstance(stripe, dict):
            errs.append(f"{model_path}: stripes[{si}] is not an object")
            continue

        spine = stripe.get("spine")
        if isinstance(spine, dict):
            errs.extend(
                _validate_flat_vec(
                    spine.get("polyline_points"),
                    stride=3,
                    allow_empty=True,
                    ctx=f"{model_path}: stripes[{si}].spine.polyline_points",
                )
            )

        surf_data = stripe.get("surfData")
        if not isinstance(surf_data, list):
            continue

        for pi, patch in enumerate(surf_data):
            if not isinstance(patch, dict):
                errs.append(f"{model_path}: stripes[{si}].surfData[{pi}] is not an object")
                continue
            ints = patch.get("interferences")
            if not isinstance(ints, dict):
                continue
            for side in ("on_s1", "on_s2"):
                it = ints.get(side)
                if not isinstance(it, dict):
                    continue
                errs.extend(
                    _validate_flat_vec(
                        it.get("pcurve_on_face_uv"),
                        stride=2,
                        allow_empty=True,
                        ctx=f"{model_path}: stripes[{si}].surfData[{pi}].interferences.{side}.pcurve_on_face_uv",
                    )
                )
                errs.extend(
                    _validate_flat_vec(
                        it.get("pcurve_on_surf_uv"),
                        stride=2,
                        allow_empty=True,
                        ctx=f"{model_path}: stripes[{si}].surfData[{pi}].interferences.{side}.pcurve_on_surf_uv",
                    )
                )
                errs.extend(
                    _validate_flat_vec(
                        it.get("curve3d_on_face"),
                        stride=3,
                        allow_empty=True,
                        ctx=f"{model_path}: stripes[{si}].surfData[{pi}].interferences.{side}.curve3d_on_face",
                    )
                )
                errs.extend(
                    _validate_flat_vec(
                        it.get("curve3d_on_surf"),
                        stride=3,
                        allow_empty=True,
                        ctx=f"{model_path}: stripes[{si}].surfData[{pi}].interferences.{side}.curve3d_on_surf",
                    )
                )

    return errs


def validate_mesh_json(mesh_path: Path) -> list[str]:
    errs: list[str] = []
    try:
        data = json.loads(mesh_path.read_text(encoding="utf-8"))
    except Exception as e:  # noqa: BLE001
        return [f"{mesh_path}: failed to parse JSON: {e}"]

    pos = data.get("positions")
    ind = data.get("indices")
    if not isinstance(pos, list) or not isinstance(ind, list):
        return [f"{mesh_path}: expected 'positions' and 'indices' arrays"]

    if len(pos) < 9 or len(pos) % 3 != 0:
        errs.append(f"{mesh_path}: positions length {len(pos)} must be >= 9 and divisible by 3")
        return errs

    if len(ind) < 3 or len(ind) % 3 != 0:
        errs.append(f"{mesh_path}: indices length {len(ind)} must be >= 3 and divisible by 3")
        return errs

    if any(not _is_finite_number(x) for x in pos):
        errs.append(f"{mesh_path}: positions contain non-finite values")
        return errs

    indices_int: list[int] = []
    for x in ind:
        if isinstance(x, int):
            indices_int.append(x)
        elif isinstance(x, float) and x.is_integer():
            indices_int.append(int(x))
        else:
            errs.append(f"{mesh_path}: indices contain non-integer value {x!r}")
            return errs

    nverts = len(pos) // 3
    if nverts <= 0:
        errs.append(f"{mesh_path}: no vertices")
        return errs

    lo = min(indices_int)
    hi = max(indices_int)
    if lo < 0 or hi >= nverts:
        errs.append(f"{mesh_path}: index out of range (nverts={nverts}, min={lo}, max={hi})")
    return errs


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default=".", help="repo root (default: .)")
    ap.add_argument(
        "--schema",
        default="tools/schemas/fillets_chfids_model.schema.json",
        help="path to ChFiDS model schema (default: tools/schemas/fillets_chfids_model.schema.json)",
    )
    ap.add_argument(
        "--artifacts",
        default="repros/lane-fillets/golden/artifacts",
        help="path to fillets artifacts dir (default: repros/lane-fillets/golden/artifacts)",
    )
    args = ap.parse_args()

    root = Path(args.root).resolve()
    schema_path = (root / args.schema).resolve()
    artifacts_dir = (root / args.artifacts).resolve()

    if not schema_path.is_file():
        fail(f"missing schema: {schema_path}")
        return 1
    if not artifacts_dir.is_dir():
        fail(f"missing artifacts dir: {artifacts_dir}")
        return 1

    schema = json.loads(schema_path.read_text(encoding="utf-8"))
    Validator = validator_for(schema)
    Validator.check_schema(schema)
    ok(f"schema OK: {schema_path.relative_to(root)} ({Validator.__name__})")

    errors: list[str] = []

    model_paths = sorted(artifacts_dir.glob("*/model.json"))
    if not model_paths:
        fail(f"no model.json files under {artifacts_dir.relative_to(root)}")
        return 1

    for p in model_paths:
        errors.extend(validate_model_json(schema, p))
    if errors:
        for e in errors:
            fail(e)
        fail(f"{len(errors)} model.json issues found")
        return 1
    ok(f"{len(model_paths)} model.json files validated")

    mesh_paths = sorted(artifacts_dir.glob("*/*.mesh.json"))
    mesh_errors: list[str] = []
    for p in mesh_paths:
        mesh_errors.extend(validate_mesh_json(p))
    if mesh_errors:
        for e in mesh_errors:
            fail(e)
        fail(f"{len(mesh_errors)} mesh issues found")
        return 1
    ok(f"{len(mesh_paths)} mesh files passed basic checks")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

