# #26517 — PartDesign: Hollow profile on Additive Pipe in closed path

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26517`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26517
- State: `closed`
- Created: `2025-12-29T14:52:58Z`
- Updated: `2026-01-09T10:47:32Z`
- Closed: `2025-12-29T19:56:54Z`
- Comments: `4`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Problem description

Hi All,
I found Part Design additive Pipe doesn't work as expected anymore.. I explain..
If I want to make a sweep additive hollow profile along a close path (sketch) the internal hollow is showed in the preview overlay but not in the final result .
This occurs since FreeCAD_weekly-2025.10.01-Linux-x86_64-py311.AppImage not into previoulsy

### Workbench affected?

Part Design

### Steps to reproduce

In Part Design
Create hollow profile
Create rectangular sketch
Map the profile sketch on path sketch
Create an additive pipe 

[hollow_section.zip](https://github.com/user-attachments/files/24369704/hollow_section.zip)

<img width="761" height="455" alt="Image" src="https://github.com/user-attachments/assets/2d6c0d49-6005-459d-8780-f56bca7df9cd" />

<img width="761" height="455" alt="Image" src="https://github.com/user-attachments/assets/ee384033-8fa6-40f0-ac0e-8401960c1bcc" />

but if the path is not closed all works as expected

<img width="761" height="455" alt="Image" src="https://github.com/user-attachments/assets/a8b47327-e171-4356-b453-304cf248fe9a" />

### Expected behavior

The hollow section inside could be created

### Actual behavior

The hollow section inside is not  created

### Development version About Info (in Safe Mode)

```shell
OS: Arch Linux (KDE/plasmax11/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow) AppImage
Build date: 2025/09/30 23:55:55
Build type: Release
Branch: main
Hash: b08a0f87d68dd38cfcf39046209a7075adf11576
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Blender/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.1104/1
```

### Last known good version (optional)

```shell

```
