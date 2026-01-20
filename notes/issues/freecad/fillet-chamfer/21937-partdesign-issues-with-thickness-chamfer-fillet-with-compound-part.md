# #21937 — PartDesign: issues with thickness/chamfer/fillet with compound part

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21937`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21937
- State: `open`
- Created: `2025-06-11T17:06:56Z`
- Updated: `2025-10-15T00:27:00Z`
- Comments: `5`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Status: Needs feedback`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I stumbled across a bug while trying to create an example for someone
if you create 2 sketches, both touching 0,0

![Image](https://github.com/user-attachments/assets/974d537d-55df-4550-8a60-fa1d9846d282)
blue highlight is the other sketch

pad 1 normal and in reverse on the other:

![Image](https://github.com/user-attachments/assets/904d8d64-4dd8-4117-9b56-2135309b1cea)
chamfer and fillet won't work on the bottom face of the upper or the top of the lower face
thickness doesn't work on any face

in report view for both of those you'll see "<Exception> TopoShapeExpansion.cpp(3012): Null input shape"

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.1.0dev.42006 (Git)
Build date: 2025/06/02 16:32:08
Build type: Release
Branch: main
Hash: db1b5a877314f8d21514680421649fd9dc65acde
Python 3.11.12, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.2.5, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Turntable/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/80.9812/1
```

### Subproject(s) affected?

None

### Anything else?

example file
[thickness-compound-bug.zip](https://github.com/user-attachments/files/20694965/thickness-compound-bug.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
