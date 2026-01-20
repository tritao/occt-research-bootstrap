# #25067 — PartDesign: Fillet or chamfer on a loft breaks the model

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25067`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25067
- State: `open`
- Created: `2025-11-04T19:39:59Z`
- Updated: `2025-11-06T13:36:02Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Originally reported here: https://forum.freecad.org/viewtopic.php?t=100938

Try applying fillet or chamfer to this edge:

<img width="803" height="495" alt="Image" src="https://github.com/user-attachments/assets/6abdf7bd-8c03-4bff-bc67-1fc3bb8566de" />

[loft_fillet_error.FCStd.zip](https://github.com/user-attachments/files/23344299/loft_fillet_error.FCStd.zip)

### Full version info

```shell
OS: Windows 11 build 26200
Architecture: x86_64
Version: 1.1.0dev.20251031 (Git shallow)
Build date: 2025/10/31 03:23:50
Build type: Release
Branch: main
Hash: c270a8ac666dff22a92baf2a3a4f5200197bb678
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: Polish/Poland (pl_PL)
Navigation Style/Orbit Style/Rotation Mode: Blender/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.5973/1
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
