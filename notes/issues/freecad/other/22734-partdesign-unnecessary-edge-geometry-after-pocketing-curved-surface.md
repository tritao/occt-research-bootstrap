# #22734 — PartDesign: Unnecessary edge geometry after pocketing curved surface?

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22734`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22734
- State: `open`
- Created: `2025-07-25T11:41:13Z`
- Updated: `2025-10-18T00:25:03Z`
- Comments: `4`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Hello,
i have curved surface like this and i've made pocket sketch to make it round.

<img width="809" height="500" alt="Image" src="https://github.com/user-attachments/assets/0f3c0126-ccc0-4142-a676-c636cfe909d6" />

After cuting the pocket, it seems the edges are unnecessarily split into two pieces (one long and one short)

<img width="912" height="574" alt="Image" src="https://github.com/user-attachments/assets/8f7d8e23-b664-4ece-933f-eab800e8e9a0" />

Those seem to be tangent, so i think it should be single edge that goes all the way around the piece....

### Full version info

```shell
(tested in 1.0.1 release as well)

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

This seems to trigger more bugs, down the line, eg: #22694

Here is the file: 

[extra-geometry-bug.FCStd.zip](https://github.com/user-attachments/files/21430159/extra-geometry-bug.FCStd.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
