# #18078 — STEP: Export to inch is creating a model in mm

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18078`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18078
- State: `open`
- Created: `2024-11-22T17:48:48Z`
- Updated: `2026-01-01T15:54:37Z`
- Comments: `28`
- Labels: `Type: Bug`, `Mod: Core`, `File format: STEP`, `Topic: Units`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I have Step file export unit set to inches. With newest nightly build it exports the geometry data (the actual numerical information) as millimeters, but still tags the file as inch, meaning the model scales up in size. Previous nightly build I was using was 38684.

I do see there was an update from Open CASCADE 7.7.2 to 7.8.1. I did take a look at their tracker as well, but don't see any mention of an issue like this.

***Edit: I tracked the issue down to a known bug in OCCT 7.8.1 [OCCT Issue 354](https://github.com/Open-Cascade-SAS/OCCT/issues/354) that they fixed with 7.9.***

### Full version info

```shell
OS: Windows 11 build 22631
Architecture: x86_64
Version: 1.1.0dev.39240 (Git) Conda
Build type: Release
Branch: main
Hash: f9ba94c70b139ece6ba5ffba47632d91b5c9c645
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Qt default
Installed mods: 
  * Behave-Dark-Colors 0.1.1
  * ProDarkThemePreferencePack 1.0.0
  * ThreadProfile 1.92.0
```


### Subproject(s) affected?

Core

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
