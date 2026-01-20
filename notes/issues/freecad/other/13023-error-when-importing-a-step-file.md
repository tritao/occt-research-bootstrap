# #13023 — Error when importing a step file

- Repo: `FreeCAD/FreeCAD`
- Issue: `#13023`
- URL: https://github.com/FreeCAD/FreeCAD/issues/13023
- State: `open`
- Created: `2024-03-17T23:04:07Z`
- Updated: `2025-02-22T07:20:03Z`
- Comments: `9`
- Labels: `Type: Bug`, `3rd party: OCC`, `File format: STEP`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Most of the step models from https://www.multiboard.io/parts-library/remixing show the same behavior
![screenshot](https://github.com/FreeCAD/FreeCAD/assets/62505756/45c7d342-ed90-426b-9862-317a9780be8a)

I wanted to import the files for remixing in a complete empty FCStd file.
gmsh.exe crashes when opening these files too. This may be a problem of my windows installation???

### Full version info

```shell
[code]
OS: Windows 11 build 22631
Word size of FreeCAD: 64-bit
Version: 0.21.2.33771 (Git)
Build type: Release
Branch: releases/FreeCAD-0-21
Hash: b9bfa5c5507506e4515816414cd27f4851d00489
Python 3.8.10, Qt 5.15.2, Coin 4.0.1, Vtk 8.2.0, OCC 7.6.3
Locale: English/Austria (en_AT)
[/code]
```


### Subproject(s) affected?

None

### Anything else?

I started a discussion in the forum: https://forum.freecad.org/viewtopic.php?p=747665#p747665

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
