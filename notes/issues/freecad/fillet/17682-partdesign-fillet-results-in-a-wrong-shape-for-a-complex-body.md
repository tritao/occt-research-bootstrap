# #17682 — PartDesign: Fillet results in a wrong shape for a complex body

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17682`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17682
- State: `open`
- Created: `2024-11-05T09:10:08Z`
- Updated: `2025-10-26T00:29:34Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

The problem I'm experiencing is a wrong geometry produced by a Fillet operation for a body partly built using the Curves workbench. The front wall which should be flat starts to be three dimensional and has a hole.

[repro.tgz](https://github.com/user-attachments/files/17629845/repro.tgz)

![Screenshot From 2024-11-05 11-57-00](https://github.com/user-attachments/assets/729727c4-9db0-4dad-97bc-83892a8a1c72)


### Full version info

```shell
OS: Arch Linux (GNOME/gnome)
Word size of FreeCAD: 64-bit
Version: 1.0.0RC2.38806 (Git)
Build type: Release
Branch: makepkg
Hash: 3d63fc6c2f665a8d5e6468845a419bcac80756c7
Python 3.12.7, Qt 6.8.0, Coin 4.0.3, Vtk 9.3.1, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Installed mods: 
  * sheetmetal 0.3.12
  * A2plus 0.4.60n
  * Curves 0.6.48
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
