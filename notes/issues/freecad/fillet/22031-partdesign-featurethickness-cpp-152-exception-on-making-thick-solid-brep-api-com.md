# #22031 — PartDesign: `FeatureThickness.cpp(152): Exception on making thick solid: BRep_API: command not done Thickness: Failed to make thick solid`

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22031`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22031
- State: `open`
- Created: `2025-06-17T05:28:15Z`
- Updated: `2025-12-08T16:41:32Z`
- Comments: `6`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Type: Regression`, `Status: Confirmed`
- Assignees: `pieterhijma`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

There are couple of other issues that seem similar, but its not clear if this is the same issue or not. eg. #19184

### Problem description

I cannot apply thickness to my part. It's relatively simple geometry, but defined by compound curves:

![Image](https://github.com/user-attachments/assets/c27e1d63-886a-457b-8c0c-cd3135c272f6)

Gives me
```
<PartDesign> FeatureThickness.cpp(152): Exception on making thick solid: BRep_API: command not done Thickness: Failed to make thick solid
```

I am trying to apply thickness on bottom face of Body001 - Fillet: [octavia3-dash-plate.FCStd.zip](https://github.com/user-attachments/files/20768626/octavia3-dash-plate.FCStd.zip)


### Full version info

```shell
OS: Arch Linux (XFCE/Xfce Session/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow) AppImage
Build date: 2025/06/16 16:25:59
Build type: Release
Branch: main
Hash: fca41e4003f1680cf604b593a046ac2b1db6ba8a
Python 3.11.13, Qt 6.7.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.7.3
shiboken 6.7.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
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

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
