# #22694 — PartDesign: Additive pipe does not preserve base geometry

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22694`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22694
- State: `open`
- Created: `2025-07-23T22:06:25Z`
- Updated: `2025-07-25T11:13:24Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I am doing additive pipe of sketch along my part edge like this:

<img width="1009" height="466" alt="Image" src="https://github.com/user-attachments/assets/f70bb68e-e97c-4573-9524-d005ec561b3d" />

But when i click OK, only the "addition" is left, instead of it being added to original part:

<img width="1032" height="385" alt="Image" src="https://github.com/user-attachments/assets/b40adc2c-660d-4bf4-a89c-50d1f284972f" />

### Full version info

```shell
This happens in FreeCAD 1.0.1, but also in latest weekly:

OS: Arch Linux (XFCE/Xfce Session/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow) AppImage
Build date: 2025/07/21 18:24:28
Build type: Release
Branch: main
Hash: 80935791fd91ef89bfd3789fe1d6b76fbe0e384a
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.0, OCC 7.8.1
Locale: Czech/Czechia (cs_CZ)
Navigation Style/Orbit Style/Rotation Mode: OpenSCAD/Turntable/Object center
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 90/172.811/1
Installed mods: 
  * sheetmetal 0.7.22
  * Curves 0.6.58
```

### Subproject(s) affected?

PartDesign

### Anything else?

Here is the file, in case it helps:

[octavia3-dash-plate5.FCStd.zip](https://github.com/user-attachments/files/21395921/octavia3-dash-plate5.FCStd.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
