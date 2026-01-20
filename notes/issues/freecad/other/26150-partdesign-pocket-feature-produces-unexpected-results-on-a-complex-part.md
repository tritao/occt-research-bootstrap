# #26150 — PartDesign: Pocket feature produces unexpected results on a complex part

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26150`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26150
- State: `open`
- Created: `2025-12-14T12:54:41Z`
- Updated: `2025-12-31T00:16:11Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

Creating a hole results in unexpected geometry
<img width="275" height="230" alt="Image" src="https://github.com/user-attachments/assets/d3cdf04e-d195-4d87-b709-78b3fadb98a3" />

Both 1.0.2 and latest dev builds are affected. Observing on both macos and linux.
Unable to reproduce on simpler parts

### Steps to reproduce

Open the sample file. Observe invalid geometry as in screenshot above

[axle.FCStd.zip](https://github.com/user-attachments/files/24150067/axle.FCStd.zip)

### Expected behavior

Hole appears corresponding to sketch circle

### Actual behavior

Adding a circle in the lower left quadrant on Sketch12 results in unexpected cut profile. Only certain positions produce the behavior in the screen shot, some positions are fine, some result in no hole at all, some result in whole part being cut leaving only a few slivers.

<img width="807" height="541" alt="Image" src="https://github.com/user-attachments/assets/63b7db8f-a8ac-49c8-ac4c-e6cde5c723e0" />

### Development version About Info (in Safe Mode)

```shell
OS: macOS 15.6.1
Architecture: x86_64
Version: 1.2.0dev.20251209 (Git shallow)
Build date: 2025/12/09 13:53:17
Build type: Release
Branch: grafted,grafted
Hash: 5ad6a1ba58c665c23f1d217c23e74379d8c1a5a4
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 72/127.75/2
```

### Last known good version (optional)

```shell

```
