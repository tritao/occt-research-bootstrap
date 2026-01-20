# #18879 — PartDesign: Additive Pipe does not correctly handle self-intersection (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18879`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18879
- State: `open`
- Created: `2025-01-05T15:41:50Z`
- Updated: `2025-11-01T00:30:36Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

When the result of a sweep is self-intersecting, the PartDesign AdditivePipe operation does not detect this and creates an invalid solid, i.e. edges are not created at places where parts of the sweep overlap, or removed at places within overlaps. See screenshot for an example of sweeping a profile along an intersecting path.

![AdditivePipe-SelfIntersect](https://github.com/user-attachments/assets/4581ced6-dedf-45aa-a3c9-00420ed367a8)

The resulting sweep can be manually checked for validity by running Check Geometry with the 'Run Boolean operation check' flag set so a quick and dirty half-fix would be to add this check after the sweep; if the result contains self-intersections, produce an explanatory warning message to the user.

However, Additive Pipe should generate the correct topology in the first place.

### Full version info

```shell
OS: Ubuntu 22.04.5 LTS (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * fasteners 0.5.34
  * OpenTheme 2024.9.1
  * sheetmetal 0.6.13
  * Assembly4 0.50.15
  * Render 2024.12.15
  * Help 1.0.3
  * freecad.gears 1.3.0
  * Curves 0.6.53
```


### Subproject(s) affected?

PartDesign

### Anything else?

See https://forum.freecad.org/viewtopic.php?p=801693#p801693 for some discussion.

Possibly related issues:
https://github.com/FreeCAD/FreeCAD/issues/18658 
https://forum.freecad.org/viewtopic.php?t=58298


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
