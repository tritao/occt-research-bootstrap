# #25955 — Assembly: Failure to load existing file

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25955`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25955
- State: `open`
- Created: `2025-12-04T16:52:30Z`
- Updated: `2026-01-05T23:06:26Z`
- Comments: `13`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Core`, `Mod: Part`, `3rd party: OCC`, `Type: Regression`, `Status: Confirmed`, `Priority: High`, `Mod: Assembly`
- Assignees: `chennes`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Core (App, Gui,...)

### Problem description

Some assembly files posted on the forum open fine in v1.0.2, but in v1.1 there is an error message:
`Reading failed from embedded file: Boolean00#.Shape.brp`.

 Attached is a zip with 6 files.

The problem files are:
* Centre Block.FCStd
* Reuleaux 3.FCStd

The assembly is Carrier.FCStd.

[Assy_brp_failure.zip](https://github.com/user-attachments/files/23939416/Assy_brp_failure.zip)

Forum post:
https://forum.freecad.org/viewtopic.php?p=860502#p860502

### Steps to reproduce

1. Place the files from the zip in a single folder.
2. Start v1.1.
3. Open Carrier.FCStd.
4. For two referenced files the mentioned error is reported.
5. Probably as a result the assembly also fails.

### Expected behavior

In v1.0.2 the Carrier.FCStd file opens without errors, and, after activating the assembly, the green arm can be dragged around.

### Actual behavior

See above.

### Development version About Info (in Safe Mode)

```shell
OS: Ubuntu 22.04.5 LTS (ubuntu:GNOME/ubuntu/wayland)
Architecture: x86_64
Version: 1.1.0rc1.20251125 (Git shallow) AppImage
Build date: 2025/11/25 17:53:08
Build type: Release
Branch: (HEAD detached at 5376760)
Hash: 53767601ea65de7cd9f6590e7d5856afc0841635
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: Dutch/Netherlands (nl_NL)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/86.1283/1
```

### Last known good version (optional)

```shell
OS: Ubuntu 22.04.5 LTS (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: C/Default (C) [ OS: Dutch/Netherlands (nl_NL) ]
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Fusion
Installed mods:
```
