# #25916 — Fillet malformed after applying.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25916`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25916
- State: `open`
- Created: `2025-12-03T10:58:00Z`
- Updated: `2025-12-06T11:41:16Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

When I'm applying a fillet to an edge resulting from an intersection of operations, the resulting fillet extends and goes all over the place. 

<img width="1140" height="924" alt="Image" src="https://github.com/user-attachments/assets/fb9c54ca-aca6-47e3-8708-b803413dc763" />

### Steps to reproduce

Based on the example made by Studycadcam #52 of the 3D exercises. 
https://blog.naver.com/studycadcam/220674492793

When I apply the fillet to create the inner edges with radius 1.0, the fillet goes wrong. 

The FreeCAD file I end up with. 
[Study_CADCAM_3D_053.zip](https://github.com/user-attachments/files/23904203/Study_CADCAM_3D_053.zip)



### Expected behavior

A clean fillet along the inner edge. 

### Actual behavior

The fillet shows extra surfaces and goes beyond the edge where it would stop. 

### Development version About Info (in Safe Mode)

```shell
OS: Debian GNU/Linux 13 (trixie) (KDE/plasma/wayland)
Architecture: x86_64
Version: 1.1.0rc1.20251125 (Git shallow) AppImage
Build date: 2025/11/25 17:53:08
Build type: Release
Branch: (HEAD detached at 5376760)
Hash: 53767601ea65de7cd9f6590e7d5856afc0841635
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.1104/1
```

### Last known good version (optional)

```shell

```
