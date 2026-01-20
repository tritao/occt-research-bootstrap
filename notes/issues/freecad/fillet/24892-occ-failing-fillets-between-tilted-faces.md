# #24892 — OCC: Failing fillets between tilted faces

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24892`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24892
- State: `open`
- Created: `2025-10-28T04:54:53Z`
- Updated: `2025-11-19T22:23:10Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Fillet failing in relatively simple case of faces normal to each other, but one under a slight obtuse roll angle - refer to pictures / sample file

![Image](https://github.com/user-attachments/assets/56190ed6-8d2f-4b9a-8bae-9e30c5472dd3)

B (red) is the failing geometry, A and C works fine

![Image](https://github.com/user-attachments/assets/5162fe56-c8b6-463a-baad-6e75e81d0632)

Behavior is the same for all tested FreeCAD versions (`1.1.0dev.43944`, `1.1.0dev.39673`, `1.0.2.38641`) in both Part and PartDesign WB

Might be related to [#24135](https://github.com/FreeCAD/FreeCAD/issues/24135)

### Full version info

```shell
Affected versions:

OS: Windows 11 build 26220
Architecture: x86_64
Version: 1.1.0dev.43944 (Git)
Build date: 2025/10/14 15:14:51
Build type: Release
Branch: (HEAD detached at weekly-2025.10.15)
Hash: 41ce37233d64c81c2f105de085635d4dcd669943
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.0, boost 1_84, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Trackball/Object center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/72.7954/1.5
Installed mods: 
  * 3D_Printing_Tools
  * A2plus 0.4.68
  * Assembly3 0.12.2
  * Assembly4 0.60.2
  * Behave-Dark-Colors 0.1.1
  * CfdOF 1.32.3
  * CurvedShapes 1.0.13
  * Curves 0.6.70
  * Dracula 0.0.9
  * DynamicData 2.75.0
  * ExplodedAssembly
  * ExtremeProDark 2.8.1
  * fasteners 0.5.43
  * lattice2 1.0.0
  * Lithophane
  * Manipulator 1.6.3
  * OpenTheme 2025.5.20
  * sheetmetal 0.7.58
  * Silk 0.2.0

OS: Windows 11 build 26220
Architecture: x86_64
Version: 1.1.0dev.39673 (Git) Conda
Build type: Release
Branch: main
Hash: 1289997dfd604cb24f060f905f04ec3728d964e4
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: Darker-blue-INFI.qss/FreeCAD Dark/Fusion
Installed mods: 
  * 3D_Printing_Tools
  * A2plus 0.4.68
  * Assembly3 0.12.2
  * Assembly4 0.60.2
  * Behave-Dark-Colors 0.1.1
  * CfdOF 1.32.3
  * CurvedShapes 1.0.13
  * Curves 0.6.70
  * Dracula 0.0.9
  * DynamicData 2.75.0
  * ExplodedAssembly
  * ExtremeProDark 2.8.1
  * fasteners 0.5.43
  * Glass
  * lattice2 1.0.0
  * Lithophane
  * Manipulator 1.6.3
  * sheetmetal 0.7.55
  * Silk 0.2.0

OS: Windows 11 build 26220
Architecture: x86_64
Version: 1.0.2.38641 +678 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.13.0, Qt 6.7.3, Coin 4.0.3, Vtk 9.3.1, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/fusion
Installed mods: 
  * 3D_Printing_Tools
  * A2plus 0.4.68
  * Assembly3 0.12.2
  * Assembly4 0.60.2
  * Behave-Dark-Colors 0.1.1
  * CfdOF 1.32.3
  * CurvedShapes 1.0.13
  * Curves 0.6.70
  * Dracula 0.0.9
  * DynamicData 2.75.0
  * ExplodedAssembly
  * ExtremeProDark 2.8.1
  * fasteners 0.5.43
  * Glass
  * lattice2 1.0.0
  * Lithophane
  * Manipulator 1.6.3
  * sheetmetal 0.7.55
  * Silk 0.2.0
```

### Subproject(s) affected?

PartDesign

### Anything else?

[sample.zip](https://github.com/user-attachments/files/23179179/sample.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
