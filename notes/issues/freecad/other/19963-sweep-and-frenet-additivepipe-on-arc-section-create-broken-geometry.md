# #19963 — Sweep and Frenet AdditivePipe on arc Section create broken geometry

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19963`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19963
- State: `open`
- Created: `2025-03-03T11:25:46Z`
- Updated: `2025-10-01T12:05:02Z`
- Comments: `7`
- Labels: `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I used a <img src="https://raw.githubusercontent.com/FreeCAD/FreeCAD/6f44ab352279a020b12bb994e80ac6b93747571b/src/Mod/Part/Gui/Resources/icons/booleans/Part_Section.svg" height="24" align="top"> *Part Section* of two <img src="https://raw.githubusercontent.com/FreeCAD/FreeCAD/6f44ab352279a020b12bb994e80ac6b93747571b/src/Mod/Part/Gui/Resources/icons/tools/Part_Extrude.svg" height="24" align="top"> *Part Extrude*d sketches featuring arcs to create a 3D path to extrude a profile along.
Both <img src="https://raw.githubusercontent.com/FreeCAD/FreeCAD/6f44ab352279a020b12bb994e80ac6b93747571b/src/Mod/Part/Gui/Resources/icons/tools/Part_Sweep.svg" height="24" align="top"> *Part Sweep* and <img src="https://raw.githubusercontent.com/FreeCAD/FreeCAD/6f44ab352279a020b12bb994e80ac6b93747571b/src/Mod/PartDesign/Gui/Resources/icons/PartDesign_AdditivePipe.svg" height="24" align="top"> *PartDesign AdditivePipe* in Frenet mode (and some other modes too) create a completely broken extrusion along the path, with excessive degenerate geometry that bloats the FCStd file.

#17762 and #5651 could be related but they're about Bézier and B-splines respectively, not arcs, not sure how FC/OCCT handles those as primitives.

Left/orange is the sweep, right/green is the additive pipe.
In addition computing the geometry for both takes a long time, but the pipe is especially long for almost the same output geometry.

![Image](https://github.com/user-attachments/assets/f025cd8a-a529-4d1e-b7d8-47df6538d277)

[broken.FCStd.zip](https://github.com/user-attachments/files/19052373/broken.FCStd.zip)

### Full version info

```shell
OS: Void Linux (KDE/xcb)
Architecture: x86_64
Version: 1.1.0dev.40444 (Git) Conda AppImage
Build type: Release
Branch: main
Hash: 089605bb4db98668661bf56db3f5f5bb4f7f0d87
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, IfcOpenShell 0.7.0, OCC 7.7.2
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Logical/physical DPI: 96/92.6073
Installed mods: 
  * fasteners 0.5.31
  * OpenTheme 2024.9.1
  * FreeCAD-Ribbon 1.4.3 (Disabled)
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
