# #20194 — Measuring distance between circles centers make everything crash

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20194`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20194
- State: `closed`
- Created: `2025-03-14T13:22:48Z`
- Updated: `2025-06-23T15:44:53Z`
- Closed: `2025-06-23T15:44:53Z`
- Comments: `5`
- Labels: `Status: Needs confirmation`, `3rd party: OCC`, `Type: Crash`, `Mod: Measurement`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

When performing the meshurmant between the centers of two holes (via the selection of their relative perimeters) the program (FreeCAD 1.1.0dev) crashes.
 This behaviour is present also in the default configuration (Restart in Safe Mode). This behaviour is not present in the FreeCAD 1.0.0RC4 relase.

Example file: [BugN005.zip](https://github.com/user-attachments/files/19248001/BugN005.zip)

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.40504 (Git) Conda
Build type: Release
Branch: main
Hash: 855ad6c70904f911b2ce7114dd1a5bc24da98bd1
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Logical/physical DPI: 96/113.561
Installed mods: 
  * AirPlaneDesign 0.4.1
  * Beltrami 1.1.0
  * CfdOF 1.29.8
  * CurvedShapes 1.0.13
  * Curves 0.6.59
  * Defeaturing 1.2.3
  * EM 2.1.1
  * ExplodedAssembly
  * fasteners 0.5.37
  * FoamCut 0.1.6
  * freecad.gears 1.3.0
  * GDT
  * kicadStepUpMod 11.5.5
  * LCInterlocking
  * Lithophane
  * OpticsWorkbench 1.1.2
  * osh-autodoc-workbench 0.2.3
  * Reinforcement
  * Rocket 4.1.1
  * sheetmetal.backup1730147766.3034592 0.5.3 (Disabled)
  * Ship 2024.11.26
  * STEMFIE 0.3.1
```

### Subproject(s) affected?

Measurement

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
