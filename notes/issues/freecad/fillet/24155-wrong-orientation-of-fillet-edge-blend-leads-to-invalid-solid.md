# #24155 — Wrong orientation of fillet edge blend leads to invalid solid

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24155`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24155
- State: `open`
- Created: `2025-09-23T08:58:21Z`
- Updated: `2025-09-26T10:02:36Z`
- Comments: `8`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

When adding a fillet to the inner edge of the body, the fillet blends upwards on one edge, while the other edge blends downward as expected. The upward oriented edge is wrong and leads to an invalid solid.

<img width="1165" height="751" alt="Image" src="https://github.com/user-attachments/assets/0ae1e865-4c0f-49b3-b500-6c3bc3fc6c66" />

Above example:

[fillet_edge_blend_orientation.zip](https://github.com/user-attachments/files/22490095/fillet_edge_blend_orientation.zip)

### Full version info

```shell
OS: Ubuntu Core 22 (GNOME/gnome/wayland)
Architecture: x86_64
Version: 1.1.0dev.43555 (Git) Snap 1735
Build date: 2025/09/20 19:17:29
Build type: Release
Branch: main
Hash: f51893fbc698f04bb778e52658eb1319c6164216
Python 3.10.12, Qt 5.15.15, Coin 4.0.0, Vtk 9.1.0, boost 1_74, Eigen3 3.4.0, PySide 5.15.11
shiboken 5.15.11, SMESH 7.7.1.0, xerces-c 3.2.3, IfcOpenShell 0.8.2, OCC 7.7.1
Locale: C/Default (C)
Navigation Style/Orbit Style/Rotation Mode: CAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/159.34/1
Installed mods: 
  * FusedFilamentDesign 0.25.250
  * fasteners 0.5.39
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
