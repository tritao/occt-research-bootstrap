# #22950 — PartDesign: hole tool fails to create hole on seam of sloped face

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22950`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22950
- State: `open`
- Created: `2025-08-06T17:30:23Z`
- Updated: `2025-10-25T12:55:29Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Type: Known issue`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

found an issue where you have a sketch with multiple holes and you use the hole tool.
if the holes go into a steep slope created from in this case a subtractive revolve one of the holes fails

<img width="669" height="514" alt="Image" src="https://github.com/user-attachments/assets/b729e4ce-311c-4163-b72e-596854aa6e20" />

if you reduce the slope it will work.
in another model it was extruding the hole options also aside from just not cutting it
I haven't figured out what caused that variant of the issue

example model: [hole-bug.FCStd.zip](https://github.com/user-attachments/files/21626661/hole-bug.FCStd.zip)

### Full version info

```shell
OS: Arch Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0dev.42837 (Git) AppImage
Build date: 2025/08/04 17:39:07
Build type: Release
Branch: main
Hash: 7d6c9c0ee601eb62717271f7cca9e6c1b34432a1
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.2.5, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: C/Default (C)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Turntable/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.8077/1
Installed mods: 
  * ThreadProfile 1.96.0
  * lattice2 1.0.0
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
