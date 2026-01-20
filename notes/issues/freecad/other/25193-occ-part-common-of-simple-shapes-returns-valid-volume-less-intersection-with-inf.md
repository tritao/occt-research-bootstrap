# #25193 — OCC: Part.common of simple shapes returns "valid" volume-less intersection with infinite bounds

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25193`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25193
- State: `open`
- Created: `2025-11-09T19:36:08Z`
- Updated: `2025-11-18T00:38:59Z`
- Comments: `10`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Has workaround`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Here's the repro (remove `.txt`, needed for github upload): [t33_part_common_broken.FCStd.txt](https://github.com/user-attachments/files/23441845/t33_part_common_broken.FCStd.txt)

The intersection of these 2 simple parts gives an empty shape that has 0.0 volume, and infinite bounding box.

Simply highlight both shapes, use the `Part WB` common/intersection tool, and it breaks without warning/error.

<img width="662" height="382" alt="Image" src="https://github.com/user-attachments/assets/502cc1c5-8ed4-40be-8d25-28dd500967be" />


<img width="767" height="144" alt="Image" src="https://github.com/user-attachments/assets/97164433-e7ca-4b2f-b558-99696fab52c2" />


----------------

At a high level, I believe several **core components** of OCC are at fault, but the good news is, these are likely the source of many other FreeCAD/OCC woes, and if we fix them, all of FreeCAD/OCC will dramatically benefit, and I have very thorough well documented reproductions now for 3 core issues:

* `common`, documented in this issue
* `section`, documented [here](https://github.com/FreeCAD/FreeCAD/issues/24115)
* `distToShape`, documented [here](https://github.com/FreeCAD/FreeCAD/issues/25158)

I found all of these issues while trying to write some CAM code which iterates these 3 different functions across a part using simulated endmill geometry.

I would propose that OCC robustness could be improved if something similar was done in tests, namely:

1. take known geometry for 2 parts, randomly place the parts at locations you know will give valid results for `common`/`section`/`distToShape`, and assert that the results *are* valid. If they fail, take the failing arrangement and keep it as a test case to track regressions.

2. Another automated test would be, take a shape with rotational symmetry (cylinder endmill, cylinder+hemisphere ballend, etc), and test these functions with the symmetrical part rotated. It should always give the same result, but I find that frequently, when I rotate a part, I get different results (often resolving the failures).

3. Functions fail more frequently when 2 parts have vertices/edges near each other, so in the random testing, attention should be paid to aligning vertices/edges in valid but likely-to-fail ways.

The impact of this would be, not to overstate it, tremendous. I believe many of our frustrations with FC come down to flakiness in these core functions. Please let me know if there's a way I can help.

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

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
