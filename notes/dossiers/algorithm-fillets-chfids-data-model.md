# Dossier: ChFiDS Data Model (Spine / Stripe / SurfData)

Status: draft

## Purpose

Explain the **internal data structures** OCCT uses while building 3D fillets/chamfers:
`ChFiDS_Spine`, `ChFiDS_Stripe`, and `ChFiDS_SurfData` (plus the smaller supporting types).

This is not a “how to use the API” page. It is a “how to read the kernel” page:
how to interpret the object graph, what each field *means*, and how it maps back to:

- the public contour indices (`IC`) you see in `BRepFilletAPI_MakeFillet`, and
- the observable signals we log in the fillets repro oracle.

## Where `ChFiDS` sits in the fillet pipeline

At a high level:

- `BRepFilletAPI_MakeFillet` (API) owns a `ChFi3d_FilBuilder` (internal builder).
- The builder groups selected edges into **contours** (tangent chains).
- Each contour corresponds to a `ChFiDS_Stripe` (a “band” of fillet).
- Each stripe references a `ChFiDS_Spine` (the guideline / parameterization along the contour).
- As the algorithm progresses along the spine, it emits one or more `ChFiDS_SurfData` patches
  (each patch describes a piece of blend surface + how it trims against the two supporting faces).

The important shift: **`ChFiDS_*` is the builder’s working model**. The final B-Rep you get from
`Shape()` is built later from these structures and a global DS (indices into surfaces/curves).

## Glossary (terms you see in code)

- **Contour**: one tangent-connected chain treated as one unit of construction and reporting.
  The API reports “per contour” status and counts via the contour index `IC`.
- **Spine**: the “follow path” abstraction for a contour (not a single smooth curve in practice).
- **Elementary spine**: a sub-arc of the spine used to pretend the path is smoothly evaluable.
- **Stripe**: the fillet band for one contour (spine + all generated patches/interferences).
- **Patch**: one segment of blend surface along the stripe (one `ChFiDS_SurfData`).
- **Interference**: the trimming relationship between a patch and one supporting face
  (stored as 2D curves / pcurves with parameter ranges and orientation).

## The object graph (what owns what)

For one contour/stripe (simplified):

- `ChFiDS_Stripe`
  - `mySpine: Handle(ChFiDS_Spine)`
  - `myHdata: Handle(ChFiDS_HData)` (sequence of `ChFiDS_SurfData`)
  - end bookkeeping: first/last parameters, first/last pcurves, orientations
- `ChFiDS_SurfData` (per patch)
  - `intf1/intf2: ChFiDS_FaceInterference` (trim against face 1 and face 2)
  - `pfirst/plast on S1/S2: ChFiDS_CommonPoint` (four endpoints)
  - `ufspine/ulspine`: the spine parameter range covered by this patch
  - `twistons1/twistons2`: self-intersection / inversion flags detected during building
- `ChFiDS_Spine` (per contour)
  - `spine: TopTools_SequenceOfShape` (ordered `TopoDS_Edge`s)
  - `abscissa[]`: cumulative-length table for “spine parameter” mapping
  - endpoint state + error classification

## `ChFiDS_Spine`: what it represents and why it matters

Source: `occt/src/ChFiDS/ChFiDS_Spine.hxx`

### Meaning

`ChFiDS_Spine` is the contour’s **guideline**: it stores the ordered edge chain and provides a
curve-like API (`Value/D0/D1/D2`) over the whole chain by reparameterizing via cumulative length.

That lets later stages “walk along the contour” as if it were a single parameterized curve:
given a spine parameter, get a point/tangent/curvature, step forward, repeat.

### Key fields (how to read them)

- `spine` / `offsetspine`: the actual ordered `TopoDS_Edge` chain (and an offset version when used).
- `abscissa` / `offset_abscissa`: a table mapping “spine parameter” (length-like abscissa) to
  per-edge local parameters.
- `myCurve` / `myOffsetCurve`: `BRepAdaptor_Curve` used as the “current elementary” segment.
- `firstState/lastState`: how the contour terminates (`Free`, `Closed`, `BreakPoint`, etc.).
- `errorstate`: the contour-level status surfaced by the API.

### The most important warning in this whole lane

The header explicitly states the spine “is not C2” even though the algorithm behaves as if it is.

What that means in practice:

- The “spine” is usually a concatenation of edges; at edge joints you often only have G1/C1,
  and sometimes less (degeneracy, tolerance artifacts).
- Any walking/stepping method that assumes stable curvature and second derivatives will have
  predictable failure zones at joints and near singularities.

If you’re debugging `ChFiDS_WalkingFailure`, this is usually the first mental model to keep.

### How it maps to what you can see externally

- Public contour enumeration maps to spines:
  - `BRepFilletAPI_MakeFillet::NbContours()` returns the number of stripes/spines.
  - `BRepFilletAPI_MakeFillet::NbEdges(IC)` / `Edge(IC,J)` enumerate `Spine->Edges(J)`.
  - `StripeStatus(IC)` is effectively “what ended up in `Spine->ErrorStatus()`”.

Anchors:
- `occt/src/BRepFilletAPI/BRepFilletAPI_MakeFillet.cxx`
- `occt/src/ChFi3d/ChFi3d_Builder_1.cxx` (contour construction / spine propagation)

## `ChFiDS_Stripe`: the per-contour “bundle”

Source: `occt/src/ChFiDS/ChFiDS_Stripe.hxx`

### Meaning

A stripe is “everything the builder knows” about the fillet band for one contour:

- which spine it is following,
- the list of generated patches (`ChFiDS_SurfData`),
- orientations and end conditions needed to connect the band back into the surrounding faces.

In many parts of `ChFi3d`, the term “contour” and “stripe” are used almost interchangeably:
the stripe is the data container for one contour’s work.

### Key fields

- `mySpine`: which contour this stripe follows.
- `myHdata`: the generated patches (sequence of `ChFiDS_SurfData`).
- `pardeb*/parfin*`, `pcrv*`, and various index fields: stitching bookkeeping for
  “first” and “last” ends of the stripe (used heavily when corners are solved).

## `ChFiDS_SurfData`: one blend patch + its trimming

Source: `occt/src/ChFiDS/ChFiDS_SurfData.hxx`

### Meaning

`ChFiDS_SurfData` describes one piece of the blend surface and how it connects to the two
supporting faces:

- It does not directly store “TopoDS_Face result pieces”.
- It stores enough to build them: surface index, trimming curves, endpoint constraints, and
  the spine parameter range over which the patch is valid.

### Key fields

- `indexOfConge` (`Surf()`): an **index** of the computed blend surface in the builder’s global DS.
- `indexOfS1/indexOfS2`: indices of the two supporting faces in the same DS.
- `intf1/intf2`: `ChFiDS_FaceInterference` for S1 and S2.
  Think: “where does the patch cut the face (UV curve on face), and where on the patch (UV curve on patch)?”
- `pfirst*/plast*` (`ChFiDS_CommonPoint`): endpoint constraints for each side.
- `ufspine/ulspine`: which portion of the spine this patch covers.
- `twistons1/twistons2`: flags for detected inversions/twists (often non-recoverable without re-doing the walk).

## Supporting types (small but critical)

### `ChFiDS_FaceInterference`

Source: `occt/src/ChFiDS/ChFiDS_FaceInterference.hxx`

This is the “trim contract” between a patch and a supporting face:

- `pCurveOnFace`: a 2D curve in the face’s UV domain (where to trim the original face).
- `pCurveOnSurf`: a 2D curve in the fillet surface’s UV domain (boundary curve on the patch).
- `firstParam/lastParam`, `LineTransition`: parameter range + orientation/transition.

If you want to understand “why topology rebuild is hard”, follow how these interferences
turn into actual split faces/edges later in the builder.

### `ChFiDS_CommonPoint`

Source: `occt/src/ChFiDS/ChFiDS_CommonPoint.hxx`

Represents an endpoint constraint for a patch:

- either a `TopoDS_Vertex` (hard topological anchor), or
- a point “on an arc” (`TopoDS_Edge` + parameter + transition), or
- a raw 3D point (less common / fallback).

It also carries tolerance and an optional vector that the algorithm can use for directionality.

## Debugging recipe: reading a failure through `ChFiDS`

When a repro says contour `IC` failed with `ChFiDS_StartsolFailure` / `ChFiDS_WalkingFailure`:

1) Use the API-level mapping to list the edges in the spine:
   - `NbEdges(IC)` and `Edge(IC,J)` (this is literally `Spine->Edges(J)`).
2) Treat joints as first-class suspects:
   - the spine is not C2; failures often correlate with edge junctions or singular face zones.
3) Look at “how far it got”:
   - a stripe may have a non-empty `myHdata` (some patches), even when the final build fails.
4) Separate “geometry construction” from “topology rebuild”:
   - `StartsolFailure` is often “no feasible start configuration” (radius/geometry constraints).
   - `WalkingFailure` is often “numerical walk diverged” (curvature/joints/tolerances).
   - corner failures often mean constraints incompatible at multi-edge vertices.

## Links to the fillet algorithm dossier

- Fillets lane overview: [Dossier: Fillets](lane-fillets.md)
- Full fillet/chamfer algorithm deep dive: [Dossier: Fillet and Chamfer Algorithm (ChFi3d)](algorithm-fillets-chfi3d.md)
