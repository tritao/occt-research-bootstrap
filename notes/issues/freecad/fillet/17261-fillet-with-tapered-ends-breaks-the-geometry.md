# #17261 — Fillet with tapered ends  breaks the geometry

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17261`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17261
- State: `open`
- Created: `2024-10-15T06:58:00Z`
- Updated: `2025-02-22T16:26:25Z`
- Comments: `3`
- Labels: `Status: Duplicate`, `Mod: Part`, `3rd party: OCC`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

If a fillet follows a contour where the isn't space for the entire fillet at the ends it breaks the geometry
<img width="572" alt="Skærmbillede 2024-10-15 085215" src="https://github.com/user-attachments/assets/7a7acceb-34a6-4366-a1af-fc1dc15c6285">


### Full version info

```shell
OS: Windows 11 build 22631
Word size of FreeCAD: 64-bit
Version: 1.0.0RC2.38806 (Git)
Build type: Release
Branch: (HEAD detached at 1.0rc2)
Hash: 3d63fc6c2f665a8d5e6468845a419bcac80756c7
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: Danish/Denmark (da_DK)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * Assembly4 0.50.2
  * CfdOF 1.27.10
  * Help 1.0.3
```


### Subproject(s) affected?

None

### Anything else?

[Ny ZIP-komprimeret mappe (2).zip](https://github.com/user-attachments/files/17373945/Ny.ZIP-komprimeret.mappe.2.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
