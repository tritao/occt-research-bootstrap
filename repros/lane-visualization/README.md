# Repro: lane-visualization

## Goal

Exercise OCCT visualization-side tessellation logic (no GUI) using `Prs3d_Drawer` + `StdPrs_ToolTriangulatedShape`:

- deflection settings (absolute vs relative)
- computed effective deflection for a shape
- resulting triangulation size proxies (nodes/triangles)

## Preconditions

- OCCT build exists and includes `TKV3d` and `TKMesh` (run `just occt-build` if needed).

## How to run (OCCT oracle)

From repo root:

- `just occt-build`
- `bash repros/lane-visualization/run.sh`

## Outputs

- Output files:
  - `repros/lane-visualization/golden/visualization.json`
- Match criteria:
  - exact: all strings, bools, integers (counts)
  - tolerant: floating-point fields (deflections), compare within `eps = 1e-9`

## Scenarios covered / not covered

- Covered:
  - `StdPrs_ToolTriangulatedShape::GetDeflection/IsTessellated/Tessellate` for box + cylinder under several drawer settings
- Not covered (next extension):
  - full `AIS_InteractiveContext` / `V3d_View` rendering pipeline and selection; OpenGL driver integration

