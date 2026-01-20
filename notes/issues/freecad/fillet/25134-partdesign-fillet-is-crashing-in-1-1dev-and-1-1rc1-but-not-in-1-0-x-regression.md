# #25134 — PartDesign: Fillet is crashing in 1.1dev and 1.1RC1 but not in 1.0.x (Regression)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25134`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25134
- State: `open`
- Created: `2025-11-06T22:58:33Z`
- Updated: `2025-12-27T14:40:26Z`
- Comments: `39`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Type: Regression`, `Status: Confirmed`
- Assignees: `kadet1090`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Hi :) 
I was testing latest bulit "FreeCAD_weekly-2025.11.05-Windows-x86_64-py311"
and radius is crashing Freecad. It's working (wrongly) but still working on FreeCAD_weekly-2025.09.03-Windows-x86_64-py311". Just open PartDesignSample and make radius more then 20mm -> 21mm.

FreeCAD_weekly-2025.11.05-Windows-x86_64-py311:

<img width="1602" height="960" alt="Image" src="https://github.com/user-attachments/assets/e8265f14-16ec-4308-ad42-aff1549a185d" />

<img width="1524" height="951" alt="Image" src="https://github.com/user-attachments/assets/b916304b-0a29-48ce-a578-d24d0c8066db" />

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.20251104 (Git shallow)
Build date: 2025/11/04 19:07:44
Build type: Release
Branch: main
Hash: af014a1bb44264d749ba9522917f0d1ac76c4bbf
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: Polish/Poland (pl_PL)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/91.7938/1
Installed mods: 
  * fasteners 0.5.43
  * FreeCAD-Ribbon 1.9.1.19
  * SaveAndRestore 0.2.1
  * SearchBar 1.8.0
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
