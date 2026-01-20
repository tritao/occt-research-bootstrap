# #18656 — PartDesign: Groove not Performed Correctly on One Side of a Profile (Regression introduced between r38728 and r39109)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18656`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18656
- State: `open`
- Created: `2024-12-21T17:53:57Z`
- Updated: `2025-12-17T13:44:02Z`
- Comments: `12`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Regression`, `Status: Confirmed`, `Help wanted`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Please see the attached file. This was created in FC 0.21.1. Both grooves are as expected. Now open the file in FC1.0 release. The groove on the positive Y direction is not performed. This is not related to the recalculation from an older version of FC as the same issue occurs if the sketches are drawn from scratch in FC 1.0

[Grooves_0.21.zip](https://github.com/user-attachments/files/18219454/Grooves_0.21.zip)


### Full version info

```shell
OS: openSUSE Leap 15.5 (KDE//usr/share/xsessions/plasma5/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * CurvedShapes 1.0.13
  * Curves 0.6.52
  * freecad.gears 1.3.0
```


### Subproject(s) affected?

None

### Anything else?

A discussion about this can be found [here](https://forum.freecad.org/viewtopic.php?t=93052). The last post states that this problem was introduced between 38728 and 39109

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
