# Dossier: Offsets (BRepOffsetAPI / BRepOffset / BRepFill)

Status: draft

## Purpose

Capture how OCCT builds **offset shapes** (3D offsets and thick solids) in a debuggable way:

- how “offset” is represented (parallel faces + joins between them)
- how join strategy (`GeomAbs_JoinType`) changes the pipeline
- where robustness constraints come from (C1 continuity, surface/surface intersections, topology junction degree)
- what signals exist for triage (`IsDone`, `Error`, `GetBadShape`, history maps)

This dossier focuses on 3D offsetting of faces/shells/solids via `BRepOffsetAPI_MakeOffsetShape` and `BRepOffset_MakeOffset`, with a short note on 2D wire offsetting (`BRepOffsetAPI_MakeOffset` / `BRepFill_OffsetWire`).

## Mental model (human-first)

An offset is a **local remodeling** operation that replaces each support face with a parallel face at distance *d*, then resolves the gaps between adjacent faces.

Two important degrees of freedom:

- **Join strategy** (`GeomAbs_JoinType`):
  - `GeomAbs_Arc`: fills gaps with rolling “pipes” along edges and “spheres” at vertices (good intuition, but introduces extra faces).
  - `GeomAbs_Intersection`: extends offset faces and intersects them so there are no free edges (more “trim by intersection” flavor).
- **Topology regime** (`BRepOffset_Mode`):
  - `BRepOffset_Skin`: offset a face/shell/solid “as a skin” (typical modeling offset).
  - others exist but the default API path is oriented around `Skin`.

The debugging shift: offsetting is not “make a parallel copy”. It is a pipeline of:
1) create offset faces,
2) intersect/trim,
3) rebuild loops/faces/shells,
4) optionally thicken into a solid,
5) optionally post-process (remove internal edges).

## Provenance (required)

- OCCT version + build config: `notes/maps/provenance.md`

## Scenario + observable outputs (required)

- Scenario: offset a simple solid (box) by a small value (expected success), then try a too-large offset or a shape with “difficult” junctions (expected failure or invalid result).
- Observable outputs:
  - API “done”: `BRepBuilderAPI_MakeShape::IsDone()` (via `BRepOffsetAPI_MakeOffsetShape`)
  - algorithm “done”: `BRepOffset_MakeOffset::IsDone()`
  - error classification: `BRepOffset_MakeOffset::Error()` (`BRepOffset_Error`)
  - precheck + bad input: `BRepOffset_MakeOffset::CheckInputData()` + `GetBadShape()`
  - join choice: `BRepOffsetAPI_MakeOffsetShape::GetJoinType()` / `BRepOffset_MakeOffset::GetJoinType()`
  - history: `Generated` / `Modified` / `IsDeleted` (both API and underlying algorithm expose these)
- Success criteria:
  - small offsets: `is_done=true` and resulting shape is B-Rep valid (e.g. `BRepCheck_Analyzer::IsValid()`)
  - “expected fail” cases: `is_done=false` with a meaningful `Error()` (or a non-empty `GetBadShape()` when failing input checks)

## Spine (call chain) (required)

1) `occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeOffsetShape.hxx` — `BRepOffsetAPI_MakeOffsetShape::PerformByJoin` (public 3D offset entry)
2) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BRepOffset_MakeOffset::Initialize` / `MakeOffsetShape` (core 3D algorithm driver)
3) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BRepOffset_MakeOffset::CheckInputData` / `Error` / `GetBadShape` (prechecks + triage)
4) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BuildOffsetByArc` / `BuildOffsetByInter` (join-dependent pipeline split)
5) `occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeThickSolid.hxx` — `BRepOffsetAPI_MakeThickSolid::MakeThickSolidByJoin` (thick solid: adds closing faces + calls `MakeThickSolid`)
6) `occt/src/BRepOffset/BRepOffset_Error.hxx` — `BRepOffset_Error` (failure categories)

## High-level pipeline

For `BRepOffsetAPI_MakeOffsetShape::PerformByJoin`:

- Configure: `BRepOffset_MakeOffset::Initialize(...)` with offset value, tolerance, mode, `Intersection` / `SelfInter`, join type, and optional “remove internal edges” flag.
- Compute: `BRepOffset_MakeOffset::MakeOffsetShape(...)`.
  - Internally, the algorithm chooses a join path: `BuildOffsetByArc` vs `BuildOffsetByInter`.
  - It builds offset faces, computes intersections (3D and 2D), rebuilds loops/faces, then shells/solids as needed.
- Publish: if `myOffsetShape.IsDone()`, the API stores `myShape = myOffsetShape.Shape()` and exposes history via `Generated/Modified/IsDeleted`.

For thick solids (`BRepOffsetAPI_MakeThickSolid`):

- Same offset pipeline, but closing faces are provided (`AddFace` on the underlying algorithm) and the entry calls `BRepOffset_MakeOffset::MakeThickSolid(...)`.

## Key classes/files

3D offsets:
- `occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeOffsetShape.hxx` — high-level 3D offset API (`PerformByJoin`, `PerformBySimple`)
- `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — main 3D offset engine (initialization, precheck, build, history)
- `occt/src/BRepOffset/BRepOffset_Mode.hxx` — mode selection (`BRepOffset_Skin`, ...)
- `occt/src/GeomAbs/GeomAbs_JoinType.hxx` — join strategy (`Arc`, `Tangent`, `Intersection`)
- `occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeThickSolid.hxx` — hollow/thick solid façade over `MakeOffsetShape`
- `occt/src/BRepOffset/BRepOffset_Error.hxx` — error categories used by `BRepOffset_MakeOffset::Error()`
- Data model deep-dive: [Dossier: BRepOffset Data Model](algorithm-offsets-brepoffset-data-model.md)

2D offsets (planar wire):
- `occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeOffset.hxx` — planar wire/face offset API (can “approximate” input contours)
- `occt/src/BRepFill/BRepFill_OffsetWire.hxx` — 2D offset implementation helpers (spine preparation, trimming, wire construction)

## Core data structures + invariants

- **Invariant**: 3D offsets assume input faces are at least **C1**; C0 Bspline geometry is explicitly called out as unsupported in the public API docs. (`BRepOffsetAPI_MakeOffsetShape.hxx`)
- **Invariant**: topology junction degree matters; vertices where **> 3 edges converge** are documented as a common failure point. (`BRepOffsetAPI_MakeOffsetShape.hxx`)
- **Invariant**: join choice changes geometry kind:
  - `GeomAbs_Arc` produces additional “join” faces (pipes/spheres).
  - `GeomAbs_Intersection` relies on extending and intersecting offset faces (no free edges expected on those parallels).

## Tolerance / robustness behaviors (observed)

- `Tol` in `PerformByJoin` is the coincidence tolerance for generated shapes; this is a key knob for intersection/merging stability. (`BRepOffsetAPI_MakeOffsetShape.hxx`)
- The algorithm is bounded by surface intersection robustness (“under limitations of surface intersection algorithm”). (`BRepOffsetAPI_MakeOffsetShape.hxx`)
- Flags `Intersection` and `SelfInter` exist, but are documented as not fully implemented / not recommended in the general case. (`BRepOffsetAPI_MakeOffsetShape.hxx`)

## Failure modes + diagnostics (recommended)

- `is_done=false`:
  - inspect `BRepOffset_MakeOffset::Error()` for a coarse category (`BRepOffset_C0Geometry`, `BRepOffset_NotConnectedShell`, `BRepOffset_BadNormalsOnGeometry`, …).
  - consider calling `CheckInputData()` first and looking at `GetBadShape()` to localize the problematic region.
- `is_done=true` but invalid result:
  - suspect self-intersections (“turn inside out”), tiny features relative to offset magnitude, or unstable trimming due to tolerances.
  - compare join types: `GeomAbs_Arc` vs `GeomAbs_Intersection`.

## Runnable repro + oracle outputs (optional, recommended)

Path: `repros/lane-offsets/README.md`

How to run:
- `just occt-build`
- `bash repros/lane-offsets/run.sh`

Oracle outputs:
- `repros/lane-offsets/golden/offsets.json`
- `repros/lane-offsets/golden/artifacts/*/model.json` (validated by `tools/validate_offsets_artifacts.py`)

## Compare to papers / alternatives

- Pure surface offsetting (e.g. “offset each face, intersect, trim”) is conceptually simple but relies heavily on robust surface/surface intersections and trimming; OCCT’s `GeomAbs_Intersection` join path is closest to this intuition.
- Join-by-blending (arc/rolling style) introduces dedicated join surfaces (pipes/spheres) that can be more stable in some configurations but increases topological/geom complexity; OCCT’s `GeomAbs_Arc` join path reflects this tradeoff.
- Mesh-based offsets (inflate/deflate triangle meshes) are often more robust for visualization, but lose exact analytic/spline surfaces and CAD continuity constraints; OCCT targets B-Rep + parametric geometry.
