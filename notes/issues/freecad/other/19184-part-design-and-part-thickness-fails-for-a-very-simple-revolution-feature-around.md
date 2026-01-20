# #19184 — Part Design and Part Thickness fails for a very simple revolution feature around Z axis, but not for X or Y axes

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19184`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19184
- State: `open`
- Created: `2025-01-21T19:38:11Z`
- Updated: `2025-11-25T08:17:07Z`
- Comments: `9`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Topic: Thickness`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Part Design Thickness fails for a very simple shape, a hemisphere made by Revolution around Z axis. But not for the very similar ones created by revolution around Y or X.

To reproduce:
1. Download (change extension to FCstd):
[Hemisphere Z - error.zip](https://github.com/user-attachments/files/18495534/Hemisphere.Z.-.error.zip)
2. Select the flat face and apply Part Desgn Thickness.

It will fail with:
```20:22:18  <PartDesign> FeatureThickness.cpp(150): Exception on making thick solid: BRep_API: command not done```
```20:22:18  Thickness: Failed to make thick solid```

3. Change to Revolution base axis from Z to X.  Select the flat face. Apply thickness.
4. A Thickness feature will be successfully created.

Part thickness fails too.
But not if you create a copy:
1. Use Part-Create a copy-Create simple copy
2. Select the flat face on the copy
3. Apply the Part Thickness
4. A Thickness shape will be created without error.



### Full version info

```shell
OS: Fedora Linux 41 (KDE Plasma) (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: Polish/Poland (pl_PL)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * OpticsWorkbench 1.0.26
  * fasteners 0.5.35
  * sheetmetal 0.6.13
  * Curves 0.6.53
  * freecad.gears 1.3.0
  * freecad-xr-workbench 0.9.3
  * kicadStepUpMod 11.4.4
```

### Subproject(s) affected?

PartDesign, Part

### Anything else?

Initial discussion: https://forum.freecad.org/viewtopic.php?p=805383#p805383

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
