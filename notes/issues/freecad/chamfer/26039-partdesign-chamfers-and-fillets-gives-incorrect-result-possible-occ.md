# #26039 — PartDesign: Chamfers and Fillets Gives Incorrect Result (Possible OCC)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26039`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26039
- State: `open`
- Created: `2025-12-09T05:14:17Z`
- Updated: `2025-12-09T19:00:41Z`
- Comments: `7`
- Labels: `Type: Bug`, `Status: Duplicate`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

When chamfering a slot cut right against a wall, FreeCAD may generate an incorrect result on one or both sides.
This happens as far back as 0.21.2 and as recent as the lastest weekly.

<img width="1230" height="1093" alt="Image" src="https://github.com/user-attachments/assets/3dc1014c-fde1-41de-be8a-3bbd55f82840" />

### Steps to reproduce

[Slot Chamfer Bug 1.zip](https://github.com/user-attachments/files/24046468/Slot.Chamfer.Bug.1.zip)

View this example file for the setup for this chamfer bug.

### Expected behavior

The correct chamfer should look like this on both sides, since the model is symmetrical.

<img width="1006" height="851" alt="Image" src="https://github.com/user-attachments/assets/4fbb0e3b-cc84-444d-9059-f42196118497" />

### Actual behavior

On the other side, the chamfer looks like this regardless of chamfer values set:

<img width="1052" height="1049" alt="Image" src="https://github.com/user-attachments/assets/5f5e489b-3715-4db0-a844-f4b866c1238c" />

Also, trying to do both sides in the same chamfer operation yields a "BRep_API: command not done" Input error.

### Development version About Info (in Safe Mode)

```shell
OS: Windows 11 build 26200
Architecture: x86_64
Version: 1.1.0rc1.20251125 (Git shallow)
Build date: 2025/11/25 17:53:08
Build type: Release
Branch: (HEAD detached at 5376760)
Hash: 53767601ea65de7cd9f6590e7d5856afc0841635
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/Canada (en_CA)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.0767/1.25
```

### Last known good version (optional)

```shell
N/A:
Issue existed back in 0.21.2 and 1.0.
```
