# #24132 — PartDesign: Thickness fail when there are round corners.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24132`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24132
- State: `open`
- Created: `2025-09-22T15:06:52Z`
- Updated: `2025-09-23T23:58:22Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Topic: Thickness`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Thickness fails when there are round corners.

I have some quick tests here: [thickness.FCStd.zip](https://github.com/user-attachments/files/22470163/thickness.FCStd.zip)

<img width="705" height="471" alt="Image" src="https://github.com/user-attachments/assets/71acfeef-7b6b-4160-ac01-f7b605942f48" />

### Full version info

```shell
OS: Ubuntu 25.04 (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/09/16 20:38:23
Build type: Release
Branch: main
Hash: bac49e465908071e7400a547eb813bc5017ae7dc
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Touchpad/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.0767/1
Installed mods: 
  * Assembly4.1 0.60.2-0.1
  * Cables 0.2.1
  * CurvesWB 0.6.64
  * FreeCAD-render 2024.12.15
  * Assembly4 0.60.2
  * sheetmetal 0.7.55
  * DynamicData 2.75.0
  * Curves 0.6.70
  * InventorLoader 1.5.1
  * diff-tools 0.1.0
  * ose-piping
  * OpenTheme 2025.5.20
  * fasteners 0.5.42
  * Silk 0.2.0
  * osh-autodoc-workbench 0.2.3
  * CurvedShapes 1.0.13
  * freecad-povray-render
  * OpticsWorkbench 1.2.2
  * lattice2 1.0.0
  * kicadStepUpMod 11.7.6
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
