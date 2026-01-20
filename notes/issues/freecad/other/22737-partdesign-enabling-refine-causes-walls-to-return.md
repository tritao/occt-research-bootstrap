# #22737 — PartDesign: enabling refine causes walls to return

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22737`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22737
- State: `open`
- Created: `2025-07-25T16:04:30Z`
- Updated: `2025-07-27T06:33:15Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

stumbled across this issue with refine while trying to figure out a design. the base part that has the reappearing walls starts as a revolution which includes a b-spline
without refine:

<img width="656" height="689" alt="Image" src="https://github.com/user-attachments/assets/a472372c-1815-4c81-915b-ea5bc5c8e958" />

enabling refine on last pocket operation:

<img width="547" height="625" alt="Image" src="https://github.com/user-attachments/assets/f887e936-9c8e-413b-9ed1-b4489d34f6a6" />

geometry check does show issues only when refine is enabled also:

<img width="361" height="122" alt="Image" src="https://github.com/user-attachments/assets/2ec1182d-6aea-45cf-b3b0-77b59973dde3" />

model:

[tini-holder.FCStd.zip](https://github.com/user-attachments/files/21434150/tini-holder.FCStd.zip)

### Full version info

```shell
OS: Arch Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0dev.42653 (Git) AppImage
Build date: 2025/07/21 16:35:39
Build type: Release
Branch: main
Hash: c99cd73cd60874f231bda6233477e9051afcea57
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.2.5, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: C/Default (C)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Turntable/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.8077/1
Installed mods: 
  * ThreadProfile 1.96.0
```

### Subproject(s) affected?

None

### Anything else?

i did experiment a bit trying to find a simpler example, but it seems the cut operation is helping create the issue 

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
