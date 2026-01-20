# #10435 — [Problem] Draft: Draft_Offset has multiple issues

- Repo: `FreeCAD/FreeCAD`
- Issue: `#10435`
- URL: https://github.com/FreeCAD/FreeCAD/issues/10435
- State: `open`
- Created: `2023-08-30T08:51:35Z`
- Updated: `2025-09-13T08:26:50Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Draft`, `3rd party: OCC`, `Status: Confirmed`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Draft_Offset has multiple issues:

1. User has to move the cursor to the correct side of the object in the 3D view before entering an offset value in the task panel.
2. When entering that value the mouse may accidentally move resulting in a new offset value.
3. OCC style offset fails for single lines. Cause: lines do not define a plane. There is a confusing error message. This should be prevented. Forum topic: https://forum.freecad.org/viewtopic.php?t=80775.
4. OCC style offset fails for arcs. Cause: `offsets.offsetWire` receives wrong argument type (float instead of vector). There is a confusing error message.
5. The OCC style offset checkbox is ignored for B-splines if a point is clicked in the 3D view.
6. If a distance is specified in the task panel, OCC style offset fails for B-splines. Cause: `offsets.offsetWire` receives wrong argument type (list of vectors instead of vector). There is a confusing error message.
7. Offsetting B-splines does not result in a 'true' offset. Their points are offset, and a new spline is constructed based on them.
8. The point indicated in the 3D view is not projected on the offset plane.

Using the `makeOffset2D` method inside `offsets.offsetWire` may be the way to go. The method can create an OCC style offset but also a single offset. The shape produced by `makeOffset2D` would then have to be 'Draftified'. OCC style offsets for single lines would require dedicated code (using the Draft WorkingPlane as a reference for the offset plane).

Version info:
```
OS: Windows 8 build 9600
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.33981 (Git)
Build type: Release
Branch: master
Hash: 5a153e50ffb6046b6cc4dba498344032f6edb952
Python 3.10.12, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.5, OCC 7.6.3
Locale: Dutch/Netherlands (nl_NL)
Installed mods:
```
