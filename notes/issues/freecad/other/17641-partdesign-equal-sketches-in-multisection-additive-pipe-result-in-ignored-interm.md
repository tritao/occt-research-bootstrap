# #17641 — PartDesign: Equal sketches in multisection Additive Pipe result in ignored intermediate sections

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17641`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17641
- State: `open`
- Created: `2024-11-03T11:14:35Z`
- Updated: `2025-02-22T07:13:02Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

In Part Design, when performing a multisection Additive Pipe, if the start and end sections coincide (the former being the sweeped, and the latter being added amongst the multisection list), the resulting solid will ignore the added sections and effectively result in a constant pipe. 

In the attached file, try changing the vertical dimension of *end_section* from __4.2__ to __4.0__ to reproduce.
[additive_pipe_issue.zip](https://github.com/user-attachments/files/17610146/additive_pipe_issue.zip)

No errors are generated as result of this issue.

### Full version info

```shell
OS: Linux Mint 21.3 (X-Cinnamon/cinnamon/xcb)
Word size of FreeCAD: 64-bit
Version: 1.1.0dev.39092 (Git) AppImage
Build type: Release
Branch: main
Hash: a65d05c6e495038168eefcba6a1e43218fbb3a20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * Curves 0.6.51
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
