# #25161 — Additive loft crashing when using "Loft parameters" "Closed"

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25161`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25161
- State: `open`
- Created: `2025-11-08T12:57:40Z`
- Updated: `2025-11-24T21:42:28Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Creating a additive loft using two sections crashes freecad when "Closed" option is selected.

To reproduce, open the attached project, click two times in AdditiveLoft and check loft parameters "Closed". Freecad crashes immediately.

Download this project to reproduce: [https://laced.com.br/Teste.FCStd](https://laced.com.br/Teste.FCStd)

### Full version info

```shell
OS: Ubuntu 24.04.3 LTS (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: Portuguese/Brazil (pt_BR)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * ExplodedAssembly
  * fasteners 0.5.41
  * kicadStepUpMod 11.7.3
  * AirPlaneDesign 0.4.1
  * 3D_Printing_Tools
  * ArchTextures
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
