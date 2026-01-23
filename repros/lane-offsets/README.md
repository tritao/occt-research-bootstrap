# Repro: lane-offsets

## Goal

Exercise OCCT offset / thickening code deterministically and record stable, machine-checkable outputs:

- `BRepOffset_MakeOffset` precheck + build outcome (`IsDone`, `Error`, `GetBadShape`)
- join strategy differences (`GeomAbs_Arc` vs `GeomAbs_Intersection`)
- history/mapping signals (`OffsetFacesFromShapes`, `OffsetEdgesFromShapes`)
- resulting shape stats (topology counts + bounding box)

## Preconditions

- OCCT build exists and includes offset libs (`TKOffset`) (run `just occt-build` if needed).

## How to run (OCCT oracle)

From repo root:

- `just occt-build`
- `bash repros/lane-offsets/run.sh`

## Outputs

- Summary file:
  - `repros/lane-offsets/golden/offsets.json`
- Per-case model export:
  - `repros/lane-offsets/golden/artifacts/<case>/model.json`
- Validation:
  - `./tools/py.sh ./tools/validate_offsets_artifacts.py`

