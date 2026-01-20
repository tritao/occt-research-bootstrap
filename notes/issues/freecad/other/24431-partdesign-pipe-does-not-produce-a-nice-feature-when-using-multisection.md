# #24431 — PartDesign: Pipe does not produce a nice feature when using Multisection

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24431`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24431
- State: `open`
- Created: `2025-10-04T05:01:35Z`
- Updated: `2025-10-07T14:14:16Z`
- Comments: `13`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Part Design Pipe does not produce a nice feature.
I would like to see this as a bug that can be fixed. 

File: [internal_wall_issue3.FCStd.zip](https://github.com/user-attachments/files/22691830/internal_wall_issue3.FCStd.zip)

I would also like to add only 2 profiles to make this work. However, it also produces a not smooth transition. My goal is to make an inclined top face. 

Here, I tried to add a profile at each point of the given path. But I could not generate something gradual. 

<img width="761" height="189" alt="Image" src="https://github.com/user-attachments/assets/907a0a71-4464-4cfc-857b-0307669a7fe5" />

<img width="780" height="658" alt="Image" src="https://github.com/user-attachments/assets/7fe4a469-ce02-46ea-9056-b54d2ec76593" />

<img width="1069" height="242" alt="Image" src="https://github.com/user-attachments/assets/b4cbeabf-65dc-4c2b-96c8-27626ab977af" />

### Full version info

```shell
OS: Ubuntu 25.04 (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/09/30 23:55:55
Build type: Release
Branch: main
Hash: b08a0f87d68dd38cfcf39046209a7075adf11576
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
  * Assembly4.1_mod 0.60.2-0.1
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
