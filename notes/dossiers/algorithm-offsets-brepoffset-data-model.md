# Dossier: BRepOffset Data Model (MakeOffset / Analyse / History)

Status: draft

## Purpose

Explain the **internal working model** you can observe (and partially query) when building offsets in OCCT:

- the main driver object: `BRepOffset_MakeOffset`
- the analysis/precheck layer: `BRepOffset_Analyse`
- history/mapping structures: `BRepAlgo_Image` (input → generated/modified/deleted)
- error classification: `BRepOffset_Error`

This is a “how to read the kernel” page: what these objects represent, what invariants they imply, and which fields/APIs are useful for debugging offset failures.

## Provenance (required)

- OCCT version + build config: `notes/maps/provenance.md`

## Scenario + observable outputs (required)

- Scenario: offset a box face/shell/solid by a small value (should succeed), then try a larger offset or a shape with problematic continuity/junction degree (should fail or produce invalid topology).
- Observable outputs:
  - `BRepOffset_MakeOffset::IsDone()` (success gate)
  - `BRepOffset_MakeOffset::Error()` (`BRepOffset_Error`)
  - `BRepOffset_MakeOffset::CheckInputData()` + `GetBadShape()` (precheck localization)
  - `BRepOffset_MakeOffset::OffsetFacesFromShapes()` / `OffsetEdgesFromShapes()` (input→output mapping)
  - `BRepOffset_MakeOffset::Generated/Modified/IsDeleted` (history in terms of topology objects)
- Success criteria:
  - success case: `IsDone()==true`, `Error()==BRepOffset_NoError`, output is valid B-Rep
  - fail case: `IsDone()==false` with a meaningful `Error()` (and ideally a non-null `GetBadShape()` when failing prechecks)

## Spine (call chain)

1) `occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeOffsetShape.hxx` — `BRepOffsetAPI_MakeOffsetShape::PerformByJoin` (public entry)
2) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BRepOffset_MakeOffset::Initialize` (parameterization + flags)
3) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BRepOffset_MakeOffset::CheckInputData` (precheck + early failure)
4) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BRepOffset_MakeOffset::MakeOffsetShape` (main build)
5) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `BuildOffsetByArc` / `BuildOffsetByInter` (join-dependent branch)
6) `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — `OffsetFacesFromShapes` / `OffsetEdgesFromShapes` (history maps)

## High-level pipeline

From the perspective of the data model:

- **Initialization** seeds:
  - the input shape (`InitShape()`)
  - numeric knobs (offset value, tolerance)
  - mode/flags (`BRepOffset_Mode`, join type, intersection/self-intersection toggles)
  - optional closing faces (for thick solids)
- **Analysis/precheck** (`CheckInputData`) attempts to detect known-invalid conditions early and preserve a “bad” subshape for debugging (`GetBadShape`).
- **Construction** (`MakeOffsetShape` / `MakeThickSolid`) builds offset faces, resolves intersections/trimming, and rebuilds the resulting topology.
- **History/mapping** is accumulated as the algorithm constructs images of input subshapes (faces/edges), surfaced via:
  - `BRepAlgo_Image` maps returned by `OffsetFacesFromShapes()` / `OffsetEdgesFromShapes()`
  - per-shape queries (`Generated`, `Modified`, `IsDeleted`)

## Key classes/files

- `occt/src/BRepOffset/BRepOffset_MakeOffset.hxx` — main algorithm state (inputs, results, history, errors)
- `occt/src/BRepOffset/BRepOffset_Analyse.hxx` — analysis/auxiliary structure for tangency/ancestors/descendants, and for “tangent faces with different offsets” corner cases
- `occt/src/BRepAlgo/BRepAlgo_Image.hxx` — history map type used to relate input shapes to their images
- `occt/src/BRepOffset/BRepOffset_Error.hxx` — error categories returned by `BRepOffset_MakeOffset::Error()`
- `occt/src/GeomAbs/GeomAbs_JoinType.hxx` — join strategy that affects downstream topology (pipes/spheres vs intersections)

## Core data structures + invariants

### `BRepOffset_MakeOffset` (the driver object)

Think of `BRepOffset_MakeOffset` as “the entire offset build session”, holding:

- inputs: initial shape + configuration (offset, tolerance, join/mode flags)
- outputs: final shape + `IsDone` / error category
- history: mappings between initial subshapes and resulting subshapes

Invariants to rely on:

- If `IsDone()==false`, the shape returned by `Shape()` must not be assumed meaningful; prefer `Error()` and `GetBadShape()`.
- If `IsDone()==true`, the output still may be invalid; offsets are sensitive to self-intersections and trimming robustness.

### `BRepAlgo_Image` (history maps: input → images)

`BRepAlgo_Image` stores the relation “shape S produced image(s) NewS”.

Key behaviors:

- `HasImage(S)` answers whether S has any recorded images.
- `Image(S)` returns a list; if there is no image it returns a singleton list containing `S`.
- `LastImage(S, L)` recursively follows images-of-images to produce the final leaves (useful when there are multiple transformation stages).

This is the most practical “data model” handle for offset debugging, because it lets you answer:

- which input faces/edges contributed to which output faces/edges?
- are some inputs missing images entirely (unexpected deletions)?

### `BRepOffset_Analyse` (adjacency/tangency/descendants)

`BRepOffset_Analyse` is an auxiliary structure used in offseting to reason about:

- which faces are adjacent via which edges
- which edges/faces are tangent (angle criteria)
- ancestors/descendants relationships between shapes during transformations
- special “tangent faces with different offset values” cases (it can generate “new faces” to close gaps)

Invariants to keep in mind:

- “tangent connectivity” is not the same as topological connectivity; it is computed from geometry + an angle criterion.
- junction degree matters: documented offset limitations include vertices with more than 3 converging edges.

### `BRepOffset_Error` (coarse failure classification)

`BRepOffset_Error` provides coarse buckets like:

- `BRepOffset_C0Geometry` (continuity)
- `BRepOffset_BadNormalsOnGeometry` (normal evaluation failures)
- `BRepOffset_NotConnectedShell` (topological issues)
- plus several “cannot ...” categories indicating exceptions in trimming/extending/fusing.

Treat this as “where to start reading code”, not as a complete diagnosis.

## Tolerance / robustness behaviors (observed)

- Offsetting is bounded by robustness of surface/surface intersections and trimming; many failures are ultimately “intersection/trim did not produce consistent loops”.
- Join type is a major robustness knob:
  - `GeomAbs_Arc` tends to introduce dedicated join surfaces (pipes/spheres).
  - `GeomAbs_Intersection` relies on extending and intersecting offset faces.
- The public API warns about C1 continuity requirements and about offsets that are too large causing self-intersections or “turn inside out” behavior. (`occt/src/BRepOffsetAPI/BRepOffsetAPI_MakeOffsetShape.hxx`)

## Compare to papers / alternatives

- “Offset + intersect + trim” (classic surface-offset formulation) matches the intuition behind `GeomAbs_Intersection`, but depends heavily on robust intersection and loop building.
- Join-by-blending (`GeomAbs_Arc`) adds explicit join geometry (pipes/spheres) which can simplify some adjacency cases at the cost of extra faces and more complex topology.
- Mesh offsets (inflate/deflate triangulations) are often more robust for visualization workflows, but they do not preserve OCCT’s exact surface types/continuity guarantees.

