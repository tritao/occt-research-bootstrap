# #16206 — OCC: Thickness shelling failed

- Repo: `FreeCAD/FreeCAD`
- Issue: `#16206`
- URL: https://github.com/FreeCAD/FreeCAD/issues/16206
- State: `open`
- Created: `2024-09-02T02:46:47Z`
- Updated: `2025-11-29T12:35:16Z`
- Comments: `13`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Has workaround`, `Topic: Thickness`, `Status: Confirmed`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

When designing the attached model with FreeCAD, shelling fails. There are too few shelling parameters. Arc-type shelling is not desired and is not supported by FreeCAD.
![3D01_04](https://github.com/user-attachments/assets/dfd7c838-bda3-4b91-b57d-dc314ae7e17e)


### Full version info

```shell
OS: Windows 10 build 19045
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.38467 (Git)
Build type: Release
Branch: main
Hash: 87e73967da5734e100d5ac4b2fd5af1648a02572
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: Chinese/China (zh_CN)
Installed mods:

3D_Printing_Tools
A2plus 0.4.62
AirPlaneDesign 0.4.0
Assembly4 0.50.6
BIM021 2021.12.0
CurvedShapes 1.0.5
Curves 0.6.22
Defeaturing 1.2.2
ExplodedAssembly
fasteners 0.5.0
fcgear 1.0.0
freecad.gears 1.0.0
Glass (Disabled)
kicadStepUpMod 10.22.9
LCInterlocking
sheetmetal 0.4.0
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
