# Repro (DRAWEXE): #8549 — bumpy fillet on cylinder edge

Source issue: `notes/issues/freecad/fillet/08549-occt-fillet-is-bumpy-on-edge-of-cylinder.md`

Issue summary (per report): a simple cylinder (R=25, H=10) filleted with radius 1 shows visible “bumps” on the fillet; the bumps reportedly disappear around cylinder radius ~65 (with the same fillet radius).

This repro is meant to answer the first question: **is it fillet geometry, or triangulation/display?**

## Run in OCCT DRAWEXE

1) Start DRAWEXE (built with TKDraw + modeling toolkits).

2) Load the needed command sets:

- `pload MODELING` (for `pcylinder`, `explode`, `blend`, `mpincmesh`, etc)
- Optional (for viewer): `pload VISUALIZATION` or just `pload ALL`

3) Run the script:

- `source notes/issues/freecad/fillet/08549/bumpy-cylinder-fillet.tcl`

4) In DRAW, execute the suggested commands printed by the script.

## Headless / log-driven run (AI-friendly)

Use the fully automatic script:

- `notes/issues/freecad/fillet/08549/bumpy-cylinder-fillet-auto.tcl`

Example:

- `DRAWEXE -b -f notes/issues/freecad/fillet/08549/bumpy-cylinder-fillet-auto.tcl`

To capture logs:

- `tools/run_drawexe_capture.sh --drawexe /path/to/DRAWEXE --script notes/issues/freecad/fillet/08549/bumpy-cylinder-fillet-auto.tcl --out /tmp/draw-8549.log`

## What to look for

1) Compare `R=64` vs `R=65` with **the same** meshing settings.
2) Change only meshing deflection (e.g. `0.2 → 0.05 → 0.01`):
   - if bumps change/disappear, it’s very likely **triangulation** (not the underlying fillet surface).
   - if bumps persist even with very fine deflection, suspect **surface generation/approximation**.

## Notes

- The original report was on OCCT `7.6.3`. Your local OCCT version may behave differently.
- This repo’s fillet oracle lane is on OCCT `7.9.3` by default.
- If you previously did `pload ALL`, beware that DRAW’s `cylinder` command can refer to an analytic surface creator; these scripts prefer `pcylinder` (BRep primitive) when available.
- The auto script prefers circular rim edges (and skips the seam) using `getanacurve ... cir` when that command is available.
