# #12240 — [Problem] Chamfer001: Failed to create chamfer after modification

- Repo: `FreeCAD/FreeCAD`
- Issue: `#12240`
- URL: https://github.com/FreeCAD/FreeCAD/issues/12240
- State: `open`
- Created: `2024-02-02T20:30:44Z`
- Updated: `2025-02-22T07:20:59Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Attached is a File with two bodies.
The first body is correct.
The second got build the same way, but after a modification the chamfer is failing.
The error is shown: Chamfer001: Failed to create chamfer after modification

[Ptrichter3.zip](https://github.com/FreeCAD/FreeCAD/files/14145031/Ptrichter3.zip)

The same chamfer is working as shown in body1
!?!

That seems to be a bug.
I`m using the latest weekly build on windows.

### Full version info

```
OS: Windows 10 build 19045
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.35759 (Git)
Build type: Release
Branch: main
Hash: 90d36f60c30cb6549a7987fcd9d4769eab1c160c
Python 3.10.13, Qt 5.15.8, Coin 4.0.2, Vtk 9.2.6, OCC 7.6.3
Locale: German/Germany (de_DE)
Installed mods: 
  * Curves 0.6.23
  * Help 1.0.3
  * lattice2 1.0.0
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
