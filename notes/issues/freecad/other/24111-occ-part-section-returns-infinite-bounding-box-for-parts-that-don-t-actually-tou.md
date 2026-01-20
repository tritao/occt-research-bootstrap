# #24111 — OCC: `part.section` returns infinite bounding box for parts that don't actually touch

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24111`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24111
- State: `open`
- Created: `2025-09-21T16:58:44Z`
- Updated: `2026-01-06T07:41:12Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

These parts don't touch:

<img width="334" height="313" alt="Image" src="https://github.com/user-attachments/assets/845df90e-edf4-4886-a9c2-dfd0a621a3b5" />

But their `section` has a weird BoundBox, `BoundBox (1.79769e+308, 1.79769e+308, 1.79769e+308, -1.79769e+308, -1.79769e+308, -1.79769e+308)`:

```python
# CODE

tube = FreeCAD.ActiveDocument.getObject('Tube').Shape
cyl = FreeCAD.ActiveDocument.getObject('Cylinder').Shape
section = tube.section(cyl)
# section.tessellate(0.01)
print(f'{section.isValid()=}')
print(f'{section.isNull()=}')
print(f'{section.Area=}')
print(f'{section.Edges=}')
print(f'{section.BoundBox=}')


# RESULTS

>>> tube = FreeCAD.ActiveDocument.getObject('Tube').Shape
>>> cyl = FreeCAD.ActiveDocument.getObject('Cylinder').Shape
>>> section = tube.section(cyl)
>>> section.tessellate(0.01)
([], [])
>>> print(f'{section.isValid()=}')
section.isValid()=True
>>> print(f'{section.isNull()=}')
section.isNull()=False
>>> print(f'{section.Area=}')
section.Area=0.0
>>> print(f'{section.Edges=}')
section.Edges=[]
>>> print(f'{section.BoundBox=}')
section.BoundBox=BoundBox (1.79769e+308, 1.79769e+308, 1.79769e+308, -1.79769e+308, -1.79769e+308, -1.79769e+308)
>>> 
```

A related issue is that after doing this, even if I don't `Part.show(section)`, the 3D view starts glitching out.

Here's the `.FCStd` file renamed to `.py` (so github accepts the upload)
[t24_infinite_intersection_bug.py](https://github.com/user-attachments/files/22453158/t24_infinite_intersection_bug.py)





### Full version info

```shell
OS: Debian GNU/Linux 12 (bookworm) (GNOME/gnome/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow) AppImage
Build date: 2025/09/02 21:58:19
Build type: Release
Branch: main
Hash: 04e085cba3b43d1e09aedd4445824a6eb46e45b6
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: TinkerCAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/127.628/1
Installed mods: 
  * ZFace
  * CurvedShapes 1.0.13
  * Curves 0.6.68
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
