# #21119 — Right corner pipe/sweep errors out with vast majority of spines featuring arcs

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21119`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21119
- State: `open`
- Created: `2025-05-03T22:39:00Z`
- Updated: `2025-10-10T00:26:17Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Part Design`, `Mod: Part`, `Status: Needs confirmation`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

This is a https://github.com/FreeCAD/FreeCAD/labels/3rd%20party%3A%20OCC https://github.com/FreeCAD/FreeCAD/labels/Type%3A%20Bug.

Any `Transition = Right corner` pipe (additive/subtractive) or sweep along a spine featuring arcs (of circle, maybe others too) with non-tangent endpoints can fail with a very obscure `TopoDS::Shell` message/status [1], when it shouldn't as the sweep is otherwise mathematically possible, especially since `Transition = Round corner` works for those same inputs.

On top of this, this failure causes a 20+ second hang of the entirety of FreeCAD.

There seems to be some amount of leeway in the allowable angle at the arcs' endpoints, depending on the profile being sweeped, but I've found circles to require exact tangency (0° margin).

Using an almost equivalent B-spline (it's possible to get an exact one, [OCC even has a function for that](https://dev.opencascade.org/doc/refman/html/class_convert___circle_to_b_spline_curve.html#afcee140510861478096f597d93cea99a)) does not seem to trigger the bug.

[topodsshell.FCStd.zip](https://github.com/user-attachments/files/20025231/topodsshell.FCStd.zip) contains multiple samples triggering this. Some of the sketches contain alternative geometry you can switch back from being construction if you want to try. 

[1]: Such a thing isn't good UX, see #19255.

### Full version info

```shell
OS: Void Linux (KDE/wayland)
Architecture: x86_64
Version: 1.1.0dev.41464 (Git) AppImage
Build date: 2025/04/28 16:20:16
Build type: Release
Branch: main
Hash: 8d6547d519ffb331cfba054b4db2750b3e71339b
Python 3.11.12, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 
shiboken , xerces-c 3.3.0, IfcOpenShell 0.8.0, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/92.6073/1
Installed mods: 
  * fasteners 0.5.31
  * OpenTheme 2024.9.1
  * FreeCAD-Ribbon 1.8.1.2
  * SearchBar 1.0.2
```

### Subproject(s) affected?

Part & Part Design (and probably more)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
