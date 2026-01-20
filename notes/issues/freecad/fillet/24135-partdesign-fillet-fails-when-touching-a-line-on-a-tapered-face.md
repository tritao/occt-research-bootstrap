# #24135 — PartDesign: Fillet fails when touching a line on a tapered face

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24135`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24135
- State: `open`
- Created: `2025-09-22T15:24:37Z`
- Updated: `2025-10-30T04:13:50Z`
- Comments: `9`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`, `Status: Needs example file`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

When filleting a corner (tapered one), if the fillet touches some existing lines in the geometry, it fails. 
Can an option like "self intersect", as it is available on PD Thickness, be used here to avoid this kind of problem?

https://github.com/user-attachments/assets/a99715f9-ed00-4f8a-9eab-bef5625069f7

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
