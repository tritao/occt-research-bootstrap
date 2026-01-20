# #25146 — TechDraw: Missing edges/lines accompanied with OCC fuse warnings

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25146`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25146
- State: `open`
- Created: `2025-11-07T17:01:36Z`
- Updated: `2025-11-16T18:24:32Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: TechDraw`, `Mod: Part`, `3rd party: OCC`, `Status: Needs feedback`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Attached assembly file (via FreeCAD Step by Step book 1) has 3 views on a page in TechDraw. A number of edges aren't drawn from the "Left" and "Top" views. Warnings from console:

<img width="1656" height="1168" alt="Image" src="https://github.com/user-attachments/assets/0127bf8b-c2f3-43da-938a-02b50a714eec" />

```
10:57:17  DrawProjectSplit::scrubEdges - OCC fuse raised warning(s):
BOPAlgo_AlertSelfInterferingShape

10:57:18  DrawProjectSplit::scrubEdges - OCC fuse raised warning(s):
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertTooSmallEdge
BOPAlgo_AlertTooSmallEdge
BOPAlgo_AlertBadPositioning
BOPAlgo_AlertBadPositioning
BOPAlgo_AlertBadPositioning
BOPAlgo_AlertBadPositioning
BOPAlgo_AlertBadPositioning
BOPAlgo_AlertBadPositioning
BOPAlgo_AlertTooSmallEdge
BOPAlgo_AlertTooSmallEdge
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertSelfInterferingShape
BOPAlgo_AlertTooSmallEdge
BOPAlgo_AlertTooSmallEdge
BOPAlgo_AlertTooSmallEdge
```

[2assembly.zip](https://github.com/user-attachments/files/23422456/2assembly.zip)

### Full version info

```shell
Tried on 1.0.2 and most recent weekly. Version details:


OS: Windows 11 build 26200
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Light/Fusion
Installed mods: 
  * A2plus 0.4.68
  * ThreadProfile 1.97.0


and


OS: Windows 11 build 26200
Architecture: x86_64
Version: 1.1.0dev.20251104 (Git shallow)
Build date: 2025/11/04 19:07:44
Build type: Release
Branch: main
Hash: af014a1bb44264d749ba9522917f0d1ac76c4bbf
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: CAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Light/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/105.828/1.5
Installed mods: 
  * A2plus 0.4.68
  * ThreadProfile 1.97.0
```

### Subproject(s) affected?

None

### Anything else?

Thank you for all the work, FreeCAD is so rad!

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
