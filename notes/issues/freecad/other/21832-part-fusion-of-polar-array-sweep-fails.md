# #21832 — Part: Fusion of Polar Array & Sweep Fails

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21832`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21832
- State: `open`
- Created: `2025-06-06T21:39:34Z`
- Updated: `2025-12-24T11:12:30Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I created an Archimedes blade using a helix and sketch, then offset the ruled surface by 2mm and made an array of 3 in draft. Made sure Fuse & Freenet were true. Then created a sketch for the circular shaft, then used sweep to follow the length of the ruled surface. Applying a fusion to the sweep and the array cause the object to disappear and cannot be refreshed. The report view shows the following msg:

21:55:26  <Exception> TopoShapeExpansion.cpp(2484): no image for shape
22:09:38  pyException: Traceback (most recent call last):
  File "<string>", line 2, in <module>
<class 'ValueError'>: Null shape
22:09:38  Cannot convert Array because Null shape.

This does not happen in 0.21.2!

### Full version info

```shell
OS: Ubuntu 22.04.5 LTS (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.0.1.39285 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.1)
Hash: 878f0b8c9c72c6f215833a99f2762bc3a3cf2abd
Python 3.11.12, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: unset/FreeCAD Light/Fusion
Installed mods: 
  * ThreadProfile 1.93.0
  * lattice2 1.0.0
  * Curves 0.6.61
  * CurvedShapes 1.0.13
  * Pyramids-and-Polyhedrons
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
