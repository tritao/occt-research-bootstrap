# #25158 — OCC: distToShape returns positive value for intersecting parts

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25158`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25158
- State: `open`
- Created: `2025-11-08T09:48:00Z`
- Updated: `2026-01-06T07:41:33Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I'm working on some CAM stuff and using `distToShape` to iteratively move an endmill until it just touches the part. (This is not a CAM problem though, it's an OpenCascade problem most likely)

`distToShape` mostly helps with this, but occasionally returns a relatively large `distToShape` even though it's still very much intersecting the part.

For instance, here you can clearly see the endmill is intersecting the part, but it reports that `distToShape` is `0.083mm`. Not much, but well beyond reasonable tolerances imho, and it breaks my ability to use `distToShape` in CAM work, and it happens quite frequently when simulating the tool bit at hundreds of locations:

<img width="1112" height="664" alt="Image" src="https://github.com/user-attachments/assets/8fb918ca-0e55-4e3b-be90-2658f92e4a3b" />

The attached `.FCStd` has this endmill copied at several different Z positions, progressively backing out by 0.1mm increments, and most increments (which all still intersect the part) report `~0`, but at +0.1mm (still colliding), we get the high `distToShape`. 

You can run this in the console to see the distances:

```python
faces = Part.Compound([App.ActiveDocument.Body.Shape.getElement('Face1')])
labels = ['Broken', 'Broken001', 'Broken002', 'Broken003']
for label in labels:
    tool = App.ActiveDocument.getObjectsByLabel(label)[0].Shape
    dist = faces.distToShape(tool)
    print(f'{label}: {dist[0]:>.5f}, {dist}')
```

And the distances reported:

```
Broken: 0.00006   # my "collision" alg backs the endmill out until the dist changes, and returns this as the closest approach before dist goes >>0.  It represents the Z height we should place the endmill at
Broken001: 0.08305   # if I show this bit backed out Z+0.1mm, we can see that indeed, we're getting high distToShape, but it's still actually colliding
Broken002: 0.00000   # Z+0.2mm still collides, and correctly reports 0
Broken003: 0.00000   # Z+0.3mm still collides, and correctly reports 0
```

Here's the `FCStd` (with appended `.txt` to appease github)

[t31_zface_roundnose_distToShape_problem.FCStd.txt](https://github.com/user-attachments/files/23430973/t31_zface_roundnose_distToShape_problem.FCStd.txt)

### Full version info

```shell
OS: Debian GNU/Linux 12 (bookworm) (GNOME/gnome/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow) AppImage
Build date: 2025/10/21 12:07:13
Build type: Release
Branch: main
Hash: 2096d0bd8603b429fdc0c746c34b3d73c3289fe1
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: TinkerCAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/127.628/1
Installed mods: 
  * ZFace
  * CurvedShapes 1.0.13
  * ProjectedFaces
  * FusedFilamentDesign 0.25.380
  * Curves-backup-before-zip-migration 0.6.68 (Disabled)
  * Curves 0.6.70
```

### Subproject(s) affected?

Core

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
