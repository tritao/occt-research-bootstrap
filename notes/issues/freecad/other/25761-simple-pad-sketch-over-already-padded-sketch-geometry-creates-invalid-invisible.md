# #25761 — Simple Pad->Sketch over already padded sketch geometry creates invalid/invisible result

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25761`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25761
- State: `closed`
- Created: `2025-11-28T10:43:32Z`
- Updated: `2025-11-29T07:29:06Z`
- Closed: `2025-11-29T07:18:59Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Priority: High`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

PartDesign

### Problem description

**Scenario:** A circle sketch, padded in both directions, another larger circle sketch to create a thicker section in the middle.
The first padded sketch (Sketch_1) creates valid geometry:

<img width="1228" height="422" alt="Image" src="https://github.com/user-attachments/assets/be06e4fc-16e4-4b7b-9d56-1e7bdfa3d524" />

**Problem:**
Padding the second sketch (Sketch_2) creates unexpected geometry, only a small circle, removing the previous pad and not adding the current one:

<img width="1444" height="496" alt="Image" src="https://github.com/user-attachments/assets/6a2d6874-302d-4d1b-81eb-9c378919d9f7" />

[pad_bug.FCStd.zip](https://github.com/user-attachments/files/23821430/pad_bug.FCStd.zip)

> OS: KDE Flatpak runtime (ubuntu:GNOME/ubuntu/xcb)
> Architecture: x86_64
> Version: 1.0.2.39319 (Git) Flatpak
> Build type: Release
> Branch: (HEAD detached at 256fc7e)
> Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
> Python 3.12.10, Qt 6.9.0, Coin 4.0.3, Vtk 9.3.1, OCC 7.8.1
> Locale: German/Germany (de_DE)
> Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
> Installed mods: 
>   * fasteners 0.5.43
>   * Curves 0.6.70
>   * Manipulator 1.6.3
>   * freecad.gears 1.3.0

In the latest development version, the pad operation produces a multiple solids warning, even though this shouldn't produce multiple solids in my understanding. Confirming the warning/error dialog produces a completely empty object then.

### Steps to reproduce

Open the attached file and use the Pad command on "Sketch_2".

### Expected behavior

The geometry of _Sketch_2_ should have been added to that of Sketch_1/Pad.

### Actual behavior

Invalid/unexpected/invisible geometry

### Development version About Info (in Safe Mode)

```shell
OS: Ubuntu 24.04.3 LTS (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.2.0dev.20251126 (Git shallow) AppImage
Build date: 2025/11/26 00:30:17
Build type: Release
Branch: (HEAD detached at de230cf)
Hash: de230cfaa75433441366ad09a4d5fda828e7bfdb
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: German/Germany (de_DE)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/109.57/1
```

### Last known good version (optional)

```shell

```
