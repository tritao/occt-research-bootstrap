# Walkthrough: Fillets repro casebook

This is the “cases and evidence” companion to:
- Algorithm dossier: `notes/dossiers/algorithm-fillets-chfi3d.md`
- Lane walkthrough: `notes/walkthroughs/fillets.md`

It’s intentionally concrete: for each case in the oracle JSON, it states what to expect and how to interpret the diagnostic fields.

## Run

From repo root:

- `just occt-build`
- `bash repros/lane-fillets/run.sh`

Oracle:
- `repros/lane-fillets/golden/fillets.json`

## How to read the JSON

- Each case lives under `cases.<case_name>`.
- `kind` distinguishes `fillet` vs `chamfer`:
  - fillets expose `stripe_status_name`, faulty contour/vertex lists, and computed surfaces
  - chamfers do not expose per-contour `ChFiDS_ErrorStatus` through `BRepFilletAPI_MakeChamfer`, so you mostly rely on `is_done`, `result.is_valid`, counts, and surface histograms

Fast triage order:
1) `build.did_throw` / `build.exception`
2) `build.is_done`
3) per-contour status (`build.contours[*].stripe_status_name`) when available
4) `result.is_valid` and topology deltas (counts/histogram/bbox)

## Fillet cases

### `single_edge_radius_1`

Intent: “hello world” constant-radius fillet on a single box edge.

Expected signals:
- `build.is_done=true`
- `build.nb_contours=1`, `build.contours[0].nb_edges=1`
- `build.contours[0].stripe_status_name=ChFiDS_Ok`
- `build.contours[0].computed_surface_types` contains a single analytic blend surface (usually `Geom_CylindricalSurface` on a box)
- `result.is_valid=true`
- `result.surface_types` adds one blend face (typically one cylinder face)

Interpretation:
- This case tells you whether the pipeline is working end-to-end (contour → stripe → topology rebuild).

### `corner_3_edges_radius_1`

Intent: exercise corner handling where three fillet stripes meet at one vertex.

Expected signals:
- `build.is_done=true`
- `build.nb_contours=3` (on a box, edges are not tangent-chained, so each selected edge becomes its own contour)
- all contours `ChFiDS_Ok`
- `result.surface_types` should include:
  - three cylindrical fillet faces (one per edge)
  - one corner patch (often `Geom_SphericalSurface` on a box corner)

Interpretation:
- This case validates the “fill corner” phase and the topological stitching of multiple stripes meeting at one vertex.
- If corner filling fails on harder shapes, fillets can still return `HasResult()==true` with a “holey” `BadShape()`.

### `single_edge_var_radius_0_5_to_2`

Intent: a variable-radius fillet using the linear `R1 → R2` API.

Expected signals:
- `build.is_done=true`
- `build.nb_contours=1`, contour `ChFiDS_Ok`
- `build.contours[0].computed_surface_types` may remain analytic on a box, but the result is still useful even if it switches to a spline surface on other shapes.

Interpretation:
- This case is a “bridge” to more complex laws (`Law_Function`, `UandR`) without changing the repro shape.

### `single_edge_radius_100`

Intent: a failure case that should not crash; demonstrates “cannot start”.

Expected signals:
- `build.is_done=false`
- `build.contours[0].stripe_status_name=ChFiDS_StartsolFailure`
- `result.*` is effectively empty/void (no final shape)

Interpretation:
- “Startsol” failures are the cleanest to debug: either the radius is geometrically infeasible or the seed solver can’t find a configuration.
- This is the canonical example of “status lives at the contour/stripe level, not the whole build”.

## Chamfer cases

### `single_edge_chamfer_dist_1`

Intent: symmetric chamfer on one box edge.

Expected signals:
- `build.is_done=true`
- `result.is_valid=true`
- `result.surface_types` includes one planar chamfer face (a new `Geom_Plane`), and the topology counts change similarly to the fillet single-edge case.

Interpretation:
- Chamfers share a lot of the contour-building and rebuilding machinery with fillets, but the public API exposes fewer “why did it fail?” per-contour diagnostics.

### `corner_3_edges_chamfer_dist_1`

Intent: chamfer meeting at a 3-edge box corner.

Expected signals:
- `build.is_done=true`
- `result.is_valid=true`
- `build.nb_contours` tends to be 3 on a box (same “no tangent propagation” reason as fillets)

Interpretation:
- This is a chamfer analogue to the fillet corner case; it’s a useful canary for “corner stitching” behaviors on your OCCT build/config.
