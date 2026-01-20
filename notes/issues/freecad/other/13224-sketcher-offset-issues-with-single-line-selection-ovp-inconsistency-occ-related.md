# #13224 — Sketcher: Offset issues with single line selection + OVP inconsistency (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#13224`
- URL: https://github.com/FreeCAD/FreeCAD/issues/13224
- State: `open`
- Created: `2024-03-29T19:14:13Z`
- Updated: `2025-07-21T17:13:47Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Sketcher`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

1. Create a sketch with a single fully constrained horizontal line.
2. Select it.
3. Call Sketcher_Offset.
4. Check the "Add offset constraint" option.
5. Pick a point to define the distance,
6. Result: the sketch is over-constrained.
7. Delete the proposed constraint.
8. Result: under-constrained: 4 DoFs.

The offset shape has 4 lines (why?) and if you skip step 4 the resulting shape is not stable.

The "Add offset constraint" checkbox is inconsistent if you compare how other OVP tools work. IMO it should be removed. If the user enters a value a constraint should be added automatically.

### Full version info

```shell
OS: Windows 8 build 9600
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.36596 (Git)
Build type: Release
Branch: main
Hash: 380d452adb5da85f47543a316b6b533f84e829c7
Python 3.11.8, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: Dutch/Netherlands (nl_NL)
Installed mods:
```


### Subproject(s) affected?

Sketcher

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
