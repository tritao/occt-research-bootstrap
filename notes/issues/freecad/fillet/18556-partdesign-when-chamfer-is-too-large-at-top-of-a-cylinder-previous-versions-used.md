# #18556 — PartDesign: When chamfer is too large at top of a cylinder, previous versions used to report an error but in 1.1-dev it computes an invalid body

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18556`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18556
- State: `open`
- Created: `2024-12-16T17:21:37Z`
- Updated: `2025-02-22T07:11:35Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

When chamfer is too large at top of a cylinder, old versions used to report an error, but in current version it compute an invalid body
![image](https://github.com/user-attachments/assets/bc2dc3f0-e95a-4ec4-810d-cf426cff056a)
Does the same with more complex shapes containing curved edges.

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.39646 (Git) Conda
Build type: Release
Branch: main
Hash: b25b83c1a58bf0ae95cbd502d0ccae27e8127cad
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: French/France (fr_FR)
Stylesheet/Theme/QtStyle: OpenDark.qss/FreeCAD Classic/Qt default
Installed mods: 
  * Assembly3 0.12.2
  * CurvesWB 0.6.12
  * Defeaturing 1.2.2
  * ExtremeProDark 2.6.4
  * OpenDark 2024.3.13
  * parts_library
  * parts_library.bak
  * workfeature
```


### Subproject(s) affected?

PartDesign

### Anything else?

[ChamferOnCylinder.zip](https://github.com/user-attachments/files/18154648/ChamferOnCylinder.zip)

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
