# #21120 — OCC: Pipe/sweep on arc/spline section freezes FreeCAD forever

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21120`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21120
- State: `open`
- Created: `2025-05-03T23:27:10Z`
- Updated: `2025-11-27T00:29:11Z`
- Comments: `5`
- Labels: `Type: Bug`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Yet another https://github.com/FreeCAD/FreeCAD/labels/3rd%20party%3A%20OCC https://github.com/FreeCAD/FreeCAD/labels/Type%3A%20Bug.

Trying to apply a pipe/sweep on a Part Section'd spine containing an arc of ellipse just freezes FreeCAD if the mode is Standard or Frenet. Fixed is not affected.

[model.FCStd.zip](https://github.com/user-attachments/files/20025367/model.FCStd.zip). Just trigger a recompute (of the pipe).

### Full version info

```shell
OS: Void Linux (KDE/wayland)
Architecture: x86_64
Version: 1.1.0dev.41464 (Git) AppImage
Build date: 2025/04/28 16:20:16
Build type: Release
Branch: main
Hash: 8d6547d519ffb331cfba054b4db2750b3e71339b
Python 3.11.12, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 
shiboken , xerces-c 3.3.0, IfcOpenShell 0.8.0, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/92.6073/1
Installed mods: 
  * fasteners 0.5.31
  * OpenTheme 2024.9.1
  * FreeCAD-Ribbon 1.8.1.2
  * SearchBar 1.0.2
```

### Subproject(s) affected?

Part & Part design

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
