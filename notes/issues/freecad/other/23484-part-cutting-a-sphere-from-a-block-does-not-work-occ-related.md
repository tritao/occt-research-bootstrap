# #23484 — Part: Cutting a sphere from a block does not work (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#23484`
- URL: https://github.com/FreeCAD/FreeCAD/issues/23484
- State: `open`
- Created: `2025-08-30T17:48:22Z`
- Updated: `2025-09-11T14:47:15Z`
- Comments: `13`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Cutting a sphere from a block with a hole does not work in the attached example. 
Both workbenches "Part" and "Part Design" show the same behaviour.
AFAIKT no coplanar faces or other strange geometry is involved.

The image show the block with the red sphere but the block shows no cutout.

Note that even moving the sides of the block inwards a little bit "fix" the problem -- even when no obvious borders are crossed.

Found in Version: `1.0.2.39319 (Git) Flatpak` but also tested it in `1.1.0dev.14555`.

![Image](https://github.com/user-attachments/assets/de37a55c-f1b3-4515-a783-8bb62c753ebf)


### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/08/26 20:37:46
Build type: Release
Branch: main
Hash: a5b3a2caac8feb34070415b637b5fbc2a3043a48
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: German/Germany (de_DE)
Navigation Style/Orbit Style/Rotation Mode: TinkerCAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/91.7938/1
```

### Subproject(s) affected?

None

### Anything else?

[Bug-CutSphere.zip](https://github.com/user-attachments/files/22059647/Bug-CutSphere.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
