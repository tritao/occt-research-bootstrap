# #20546 — STEP: Export Does Not Convert Dimensions

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20546`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20546
- State: `open`
- Created: `2025-03-31T17:35:37Z`
- Updated: `2025-12-31T21:04:37Z`
- Comments: `8`
- Labels: `Type: Bug`, `Mod: Core`, `File format: STEP`, `Topic: Units`, `Status: Confirmed`, `Priority: High`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

It is often useful to send files using the native units for the design. 

When exporting STEP/STP files, there is an option to select "Units for export of STEP". The file gets flagged with the correct units, but the values are unchanged. 

For example, I have created a cube measuring 10mm x 10mm x 10mm. I have exported this into three different files: 

1. Units mm, Scheme AP214
2. Units m, Scheme AP214
3. Units in, Scheme AP214

When opening these files, the cube should still be 10mm on each edge. Importing Example 1 does result in a 10mm cube. However, importing Example 2 results in a 10m cube, and importing Example 3 results in a 10in cube.

[Cube 10x10x10mm.zip](https://github.com/user-attachments/files/19539123/Cube.10x10x10mm.zip)

I have not done comprehensive testing. I found this error by sending a STEP file for a manufacturing quote and their import showed a 50.8" dimension instead of a 2" dimension. 

Thank you, Chris

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/Fusion
Installed mods: 
  * Curves 0.6.54
  * fasteners 0.5.37
  * Ship 2024.11.26
```

### Subproject(s) affected?

None

### Anything else?

So far, this is the only reference of this sort of a problem that I have found: 
https://forum.freecad.org/viewtopic.php?p=340919

This may be related to other issues, I have searched but am not adept at doing so in this platform yet. 

Thank you, Chris

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
