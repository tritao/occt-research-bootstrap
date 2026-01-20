# #24996 — PartDesign: AdditivePipe ignores islands in profile if path is closed

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24996`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24996
- State: `open`
- Created: `2025-11-02T12:48:10Z`
- Updated: `2025-11-02T13:27:35Z`
- Comments: `0`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Internal Faces`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

1. Open the attached file (remove the zip extension).
2. Notice that the profile sketch has an island and the swept shape is a pipe.
3. Change the Closed property of the Wire to true.
4. Result: the swept object is no longer a pipe. Using Part_CheckGeometry confirms there is only 1 shell.

[AdditivePipe_Closed_Path.FCStd.zip](https://github.com/user-attachments/files/23290335/AdditivePipe_Closed_Path.FCStd.zip)

### Full version info

```shell
OS: Ubuntu 22.04.5 LTS (ubuntu:GNOME/ubuntu/wayland)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/10/21 12:07:13
Build type: Release
Branch: main
Hash: 2096d0bd8603b429fdc0c746c34b3d73c3289fe1
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: Dutch/Netherlands (nl_NL)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/86.1283/1
Installed mods:
```

### Subproject(s) affected?

PartDesign

### Anything else?

May be related to #24994.

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
