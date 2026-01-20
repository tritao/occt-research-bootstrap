# #23975 — PartDesign: Crash whenever linear pattern iterations reaches 10

- Repo: `FreeCAD/FreeCAD`
- Issue: `#23975`
- URL: https://github.com/FreeCAD/FreeCAD/issues/23975
- State: `open`
- Created: `2025-09-16T15:01:38Z`
- Updated: `2026-01-05T23:12:34Z`
- Comments: `22`
- Milestone: `1.1`
- Labels: `Mod: Part Design`, `Type: Crash`, `Status: Confirmed`, `Topic: Toponaming`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

While trying to follow the MangoJelly tutorial (https://youtu.be/YWgCCgpxNCQ?si=QBPj4KjCn1Twhw3d), when I try to create a linear pattern of a subtractive hole, I can increase the occurrences up to 9, and it works correctly. Once I add one more, trying for 10, FreeCAD immediately crashes. I have repeated the issue multiple times with the exact same behavior. The same thing was happening with the weekly version from 2025.08.20.

### Full version info

```shell
OS: macOS 15.6.1
Architecture: arm64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/09/12 03:41:38
Build type: Release
Branch: main
Hash: 952bff5b63a62b55a7ea1623edfb39e90dee2d4c
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Trackball/Window center
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 72/151.5/2
Installed mods: 
  * Gridfinity 0.11.9
  * FusedFilamentDesign 0.25.250
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
