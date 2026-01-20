# #23133 — Floating artifacts added after fillet is created

- Repo: `FreeCAD/FreeCAD`
- Issue: `#23133`
- URL: https://github.com/FreeCAD/FreeCAD/issues/23133
- State: `open`
- Created: `2025-08-15T19:27:33Z`
- Updated: `2025-09-24T03:04:26Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Object initially created using FreeCAD 1.02.  File was later edited using V 1.1.0 dev

A fillet was added to round edges of the large center hole.  3 floating polygons then appeared.  See image.

When exporting to .STEP file the artifact do not show when reloaded into FreeCAD.

Nice work on the fillet/chamfer preview!

<img width="511" height="617" alt="Image" src="https://github.com/user-attachments/assets/79b1b3ab-33cc-464d-9023-08d80f5d8799" />

Original FreeCAD attached.

[FixationMoustiquaireV3.zip](https://github.com/user-attachments/files/21801269/FixationMoustiquaireV3.zip)

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: French/Canada (fr_CA)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * Curves 0.6.62
  * Defeaturing 1.2.6
  * fasteners 0.5.41
  * fasteners.backup1748094423.5998592 0.5.38 (Disabled)
  * FreeCAD-themes 2025.6.4
  * FusedFilamentDesign 0.25.250
  * Gridfinity 0.11.9
  * OpenTheme 2025.5.20

OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/08/12 22:08:35
Build type: Release
Branch: main
Hash: 4195f7fee28e65b289b9390ff7a0deab49e81040
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.0, OCC 7.8.1
Locale: French/Canada (fr_CA)
Navigation Style/Orbit Style/Rotation Mode: TinkerCAD/Turntable/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.5973/1
Installed mods: 
  * Curves 0.6.62
  * Defeaturing 1.2.6
  * fasteners 0.5.41
  * fasteners.backup1748094423.5998592 0.5.38 (Disabled)
  * FreeCAD-themes 2025.6.4
  * FusedFilamentDesign 0.25.250
  * Gridfinity 0.11.9
  * OpenTheme 2025.5.20
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
