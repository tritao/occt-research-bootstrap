# #22349 — Assembly: Export of glTF and other OCAF2 formats with OCCT 7.9.0 omits parts.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22349`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22349
- State: `open`
- Created: `2025-07-05T14:46:55Z`
- Updated: `2025-10-16T04:25:26Z`
- Comments: `2`
- Labels: `Status: Needs confirmation`, `3rd party: OCC`, `File format: glTF`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Some parts in an assembly are not exported when FreeCAD is built against OCCT 7.9.0.  The problem is not present in OCCT 7.8.1.

### Full version info

```shell
OS: macOS 15.5
Architecture: arm64
Version: 1.1.0dev.42464 +2 (Git)
Build date: 2025/07/01 06:03:34
Build type: Unknown
Branch: assembly-mujoco-solver
Hash: 4361c77ba14b9c9c676ea35f821a4afb004bf2ca
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, OCC 7.9.0
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Blender/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: OpenLight.qss/OpenLight/
Logical DPI/Physical DPI/Pixel Ratio: 72/151.5/2
Installed mods: 
  * OpticsWorkbench 1.2.2
  * addFC 1.6.2
  * freecad.gears 1.3.0
  * parts_library
  * OpenTheme 2025.5.20
  * CfdOF 1.31.1
  * Silk 0.1.9
  * ReloadWB 0.2.0
  * AddonManager 2025.6.1
  * Assembly2MuJoCo 0.2.0
  * kicadStepUpMod 11.7.1
  * fasteners 0.5.38
  * AirPlaneDesign 0.4.1
  * CurvedShapes 1.0.13
  * sheetmetal 0.7.23
  * Curves 0.6.63
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
