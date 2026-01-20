# #20085 — Freeze on fillet creation

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20085`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20085
- State: `open`
- Created: `2025-03-09T14:25:04Z`
- Updated: `2025-08-29T18:31:18Z`
- Comments: `5`
- Labels: `Type: Bug`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I made a rounded cube, made a square hole on a face. Then when I try to create a fillet at the for hole edges Freecad freezes. 
The bug is present on V 1.0.0

Test file : 

[RoundedCude Filets freeze.zip](https://github.com/user-attachments/files/19150130/RoundedCude.Filets.freeze.zip)

![Image](https://github.com/user-attachments/assets/4b173549-3acc-4d5c-b1ac-53bf90cef979)

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.40504 (Git) Conda
Build type: Release
Branch: main
Hash: 855ad6c70904f911b2ce7114dd1a5bc24da98bd1
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Locale: French/France (fr_FR)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Logical/physical DPI: 96/79.7968
Installed mods: 
  * CurvesWB 0.6.12
  * Defeaturing 1.2.3
  * ExtremeProDark 2.6.4
  * fasteners 0.5.37
  * FreeCAD-Ribbon 1.7.3.10
  * FreeCAD-themes 2025.1.7
  * freecad-xr-workbench 0.9.4
  * freecad_streamdeck_addon 0.1.7 (Disabled)
  * OpenDark 2024.3.13
  * OpenTheme 2024.9.1
  * parts_library
  * parts_library.bak
  * ProDarkThemePreferencePack 1.0.0
  * SearchBar 1.4.1
  * workfeature
```

### Subproject(s) affected?

None

### Anything else?

If I select a two or tree edges, it won't crash, but I get buggy fillets. Note that trying to reproduce from start, I got different behaviors, but always wrong.

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
