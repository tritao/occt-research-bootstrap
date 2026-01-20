# #26161 — PartDesign: subtractive pipe has solid sphere in right angle joints when exporting to step or stl

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26161`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26161
- State: `open`
- Created: `2025-12-14T18:22:41Z`
- Updated: `2026-01-05T12:59:52Z`
- Comments: `12`
- Labels: `Type: Bug`, `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`, `Topic: Helix`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

subtractivepipe joints gets a solid ball in joints that are 90 degrees or more with round corner transition when they are exported to step or stl, the solid balls do not show up in freecad. Only after reimporting the file back to freecad or a slicer the problem is there

<img width="2560" height="1440" alt="Image" src="https://github.com/user-attachments/assets/89b03963-1436-48ed-9e71-195f8db2c6ef" />

### Steps to reproduce

[subpipe_bug.tar.gz](https://github.com/user-attachments/files/24152314/subpipe_bug.tar.gz)


Create a pipe in a box using a circular profile along a skeleton sketch with a 90* turn.

### Expected behavior

There should not be a solid ball in the joint

### Actual behavior

A soild sphere forms in the 90* bend effectivly blocking the pipe.

### Development version About Info (in Safe Mode)

```shell
OS: Manjaro Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0rc1.20251125 (Git shallow) AppImage
Build date: 2025/11/25 17:53:08
Build type: Release
Branch: (HEAD detached at 5376760)
Hash: 53767601ea65de7cd9f6590e7d5856afc0841635
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Turntable/Object center
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/123.476/1

```

### Last known good version (optional)

```shell
This is in freecad 1.1 RC1 but I know the problem has happened to me in freecad 1 stable too..
```
