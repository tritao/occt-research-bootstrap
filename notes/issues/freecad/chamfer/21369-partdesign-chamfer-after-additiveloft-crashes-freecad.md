# #21369 — PartDesign: Chamfer after AdditiveLoft crashes freecad

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21369`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21369
- State: `open`
- Created: `2025-05-15T18:28:08Z`
- Updated: `2025-06-13T10:37:03Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

FC crashing still with chamfers.

Sample file is here: [chamfer_crash.FCStd.zip](https://github.com/user-attachments/files/20232779/chamfer_crash.FCStd.zip)

No matter the line I select on the highlighted edges of the chamfer, it crashes.

![Image](https://github.com/user-attachments/assets/934cf811-f245-4270-b3ae-920f57db2e22)

I feel the shape is not well formed since it has this odd vertical line.

![Image](https://github.com/user-attachments/assets/b628d1b6-2edd-4808-baf8-ff93f074e59d)

### Full version info

```shell
OS: Ubuntu 25.04 (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.41694 (Git)
Build date: 2025/05/13 12:46:54
Build type: Release
Branch: main
Hash: 5e624a4775c993a3d940f37876840c65ac0cc60c
Python 3.11.12, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.2.5, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/
Logical DPI/Physical DPI/Pixel Ratio: 96/145.143/1
Installed mods: 
  * Assembly4 0.50.19-dev
  * sheetmetal 0.7.22
  * DynamicData 2.74.0
  * Curves 0.6.61
  * InventorLoader 1.5.1
  * diff-tools 0.1.0
  * ose-piping
  * OpenTheme 2024.9.1
  * fasteners 0.5.38
  * osh-autodoc-workbench 0.2.3
  * OpticsWorkbench 1.2.0
  * lattice2 1.0.0
  * kicadStepUpMod 11.6.9
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
