# #18723 — Exception in Geometry.cpp when moving cursor around in Sketcher (Works in OCCT v8.7.1 but not in v8.6.3 or v8.7.2dev)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18723`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18723
- State: `open`
- Created: `2024-12-25T19:15:09Z`
- Updated: `2025-10-31T00:28:14Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Moving the cursor around while drawing something in Sketcher on a face frequently results in:

```
10:56:44  <Exception> Geometry.cpp(993): bool Part::GeomCurve::closestParameter(const Base::Vector3d&, double&) const -- N4Base14CADKernelErrorE
```

I've reduced the problem to a simple project file.  To trigger the bug, go into Sketcher and select the "Constrain horizontal/vertical" tool.  Then wave the cursor around the sketch, in particular around the horizontal line to the left of the semicircle.

[sketcher-param-bug.FCStd.gz](https://github.com/user-attachments/files/18246969/sketcher-param-bug.FCStd.gz)


### Full version info

```shell
OS: Devuan GNU/Linux 5 (daedalus) (MATE/lightdm-xsession/xcb)
Architecture: x86_64
Version: 1.0.0.39150 (Git)
Build type: Debug
Branch: releases/FreeCAD-1-0
Hash: d9e8fe0d7d99fd48fdeb5a0f6da5790ae3f54b69
Python 3.11.2, Qt 5.15.8, Coin 4.0.0, Vtk 9.1.0, OCC 7.8.2.dev
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * Assembly3 0.12.2
  * sheetmetal 0.6.11
  * freecad.gears 1.3.0
  * Assembly4 0.50.15
  * A2plus 0.4.68
  * InventorLoader 1.5.1
  * fasteners 0.5.33
  * Manipulator 1.5.7
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
