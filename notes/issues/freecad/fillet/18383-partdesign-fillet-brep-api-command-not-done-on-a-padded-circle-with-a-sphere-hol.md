# #18383 — PartDesign: Fillet: BRep_API: command not done - on a padded circle with a sphere hollow on its side

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18383`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18383
- State: `open`
- Created: `2024-12-09T11:10:27Z`
- Updated: `2025-10-29T01:10:44Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Type: Known issue`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

1. Sketch a circle on XY and pad it to make a cylinder
2. Sketch on XZ a half circle closed by a line (the arc should be inside the mass of cylinder, set its position at the side of cylinder and groove cut (select vertical line of arc as groove axis) to make a sphere hollow.
3. Then select the side of cylinder and try fillet.
The fillet fails with Fillet: BRep_API: command not done
![1](https://github.com/user-attachments/assets/47985956-f9d9-4126-a445-51fc6b02b92c)




If on step 2 the arc is sketched outside of cylinder mass, the step 3 makes the fillet successfully.
![2](https://github.com/user-attachments/assets/0e16ec36-720a-426a-8e73-9e373894d5eb)


### Full version info

```shell
OS: Arch Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0dev.39512 (Git)
Build type: Release
Branch: main
Hash: d37115c692e66d3c5aa821eaec57e7b3dd0f1cd4
Python 3.12.7, Qt 5.15.16, Coin 4.0.3, Vtk 9.3.1, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/Qt default
Installed mods: 
  * Curves 0.6.51
  * CurvedShapes 1.0.13
  * A2plus 0.4.68
  * freecad.gears 1.3.0
  * OpticsWorkbench 1.0.26
  * OpenTheme 2024.5.16
  * sheetmetal 0.6.1
  * fasteners 0.5.33
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
