#!/usr/bin/env python3
import argparse
import json
from pathlib import Path

def load_packages(packages_json: Path):
    data = json.loads(packages_json.read_text())
    return data["packages"].keys()

def load_edges(include_dot: Path):
    edges = []
    for line in include_dot.read_text().splitlines():
        line = line.strip()
        if not line.startswith('"'):
            continue
        # "A" -> "B" [label="123"];
        try:
            left, rest = line.split("->", 1)
            a = left.strip().strip('"')
            b = rest.split("[", 1)[0].strip().strip('"')
            label = rest.split('label="', 1)[1].split('"', 1)[0]
            edges.append((a, b, int(label)))
        except Exception:
            continue
    return edges

def write_include_graph(edges, out_dot: Path, out_md: Path):
    dot = ["digraph occt_includes {", "  rankdir=LR;"]
    for a, b, w in edges:
        dot.append(f'  "{a}" -> "{b}" [label="{w}"];')
    dot.append("}")
    out_dot.write_text("\n".join(dot) + "\n")

    heavy = sorted(edges, key=lambda e: e[2], reverse=True)[:120]
    lines = ["# Heaviest package -> package include edges", ""]
    for w in heavy:
        lines.append(f"- `{w[0]}` -> `{w[1]}`: **{w[2]}**")
    out_md.write_text("\n".join(lines) + "\n")

def write_packages_md(pkgs, out_md: Path, title: str):
    lines = [f"# {title}", ""]
    for pkg in sorted(pkgs):
        lines.append(f"- `{pkg}`")
    out_md.write_text("\n".join(lines) + "\n")

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--packages_json", required=True)
    ap.add_argument("--include_dot", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--mode", choices=["core", "exchange_vis"], required=True)
    args = ap.parse_args()

    packages = set(load_packages(Path(args.packages_json)))
    edges = load_edges(Path(args.include_dot))
    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)

    # Heuristic filters: grouped by common OCCT naming conventions.
    exchange_prefixes = [
        "Step", "RWStep", "IGES", "RWIGES", "IFSelect", "Interface", "Transfer",
        "Vrml", "XCAF", "DE", "RW", "XS", "TObj",
        "Xml", "XmlM", "XmlObj", "Bin", "BinM", "BinObj",
    ]
    vis_prefixes = [
        "AIS", "Prs3d", "Graphic3d", "OpenGl", "V3d", "MeshVS", "DsgPrs",
        "StdPrs", "Select3D", "Aspect", "Image", "Font", "Media",
    ]
    exchange_names = {
        "BRepToIGES",
        "BRepToIGESBRep",
        "IGESToBRep",
        "StepToGeom",
        "StepToTopoDS",
        "TopoDSToStep",
        "XSControl",
        "XSAlgo",
    }
    exchange_vis = set()
    for p in packages:
        if p in exchange_names or any(p.startswith(pref) for pref in exchange_prefixes + vis_prefixes):
            exchange_vis.add(p)

    if args.mode == "core":
        keep = packages - exchange_vis
        suffix = "core"
        title = "OCCT core packages (heuristic)"
    else:
        keep = exchange_vis
        suffix = "exchange_vis"
        title = "OCCT data exchange + visualization packages (heuristic)"

    filtered_edges = [(a, b, w) for (a, b, w) in edges if a in keep and b in keep]
    write_include_graph(
        filtered_edges,
        out_dir / f"include_graph.{suffix}.dot",
        out_dir / f"include_graph.{suffix}.md",
    )
    write_packages_md(keep, out_dir / f"packages.{suffix}.md", title)

if __name__ == "__main__":
    main()
