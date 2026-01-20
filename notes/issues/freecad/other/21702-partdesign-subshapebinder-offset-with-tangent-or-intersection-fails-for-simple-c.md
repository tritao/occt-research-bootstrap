# #21702 — PartDesign: SubShapeBinder offset with Tangent or Intersection fails for simple cases

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21702`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21702
- State: `open`
- Created: `2025-06-01T23:03:04Z`
- Updated: `2025-08-16T00:13:22Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Shapebinder`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

SubShapeBinder with an offset that uses Tangent or Intersection join type fails when the sketch contains multiple areas, e.g. two simple squares. The offset works when deleting one of the squares or choosing Arc as join type.

[subshapebinder_offset_issue.zip](https://github.com/user-attachments/files/20542945/subshapebinder_offset_issue.zip)

### Full version info

```shell
OS: Arch Linux (KDE/plasma/wayland)
Architecture: x86_64
Version: 1.1.0dev.41913 (Git)
Build date: 2025/06/01 19:38:32
Build type: Release
Branch: main
Hash: 09fbb6162bfa3b3c3f97cdc0b690fd6ed386bcdd
Python 3.13.3, Qt 6.9.0, Coin 4.0.3, Vtk 9.4.2, boost 1_88, Eigen3 3.4.0, PySide 6.9.0
shiboken 6.9.0, SMESH 7.7.1.0, xerces-c 3.3.0, OCC 8.0.0.rc1-2398b87d36
Locale: English/United States (en_US) [ OS: German/Germany (de_DE) ]
Navigation Style/Orbit Style/Rotation Mode: Blender/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/breeze
Logical DPI/Physical DPI/Pixel Ratio: 96/93.1131/2
Installed mods: 
  * kicadStepUpMod 11.7.1
  * Gridfinity 0.11.9
  * sheetmetal 0.7.22
  * fcgear 1.0.0
  * fasteners 0.5.38
  * Assembly4 0.50.18
  * Curves 0.6.62
  * lattice2 1.0.0
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
