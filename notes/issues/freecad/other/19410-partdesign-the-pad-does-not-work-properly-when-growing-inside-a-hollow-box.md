# #19410 — PartDesign: The Pad does not work properly when growing inside a hollow box.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19410`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19410
- State: `open`
- Created: `2025-02-04T18:57:20Z`
- Updated: `2025-11-04T00:34:13Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Has workaround`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

The Pad does not work properly when growing on a hollow but closed box.

[Pad_Issues.FCStd.zip](https://github.com/user-attachments/files/18661865/Pad_Issues.FCStd.zip)

See the last feature `Pad005` turns the hollow compartment filled.

The file is currently this way and filled... 
![Image](https://github.com/user-attachments/assets/801c406e-a181-4ab3-8e9e-672fd85bc3dd)

When inverting `Pad005` direction (as intended by the user) it becomes this (still filled)
![Image](https://github.com/user-attachments/assets/141c50a0-3ba2-4fb1-a187-fbd5b76de7d5)

### Full version info

```shell
OS: Ubuntu 24.04.1 LTS (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.40077 (Git) Conda AppImage
Build type: Release
Branch: main
Hash: a85756b1c94c30252f99c7bc497beed5c8dcbf25
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/Fusion
Logical/physical DPI: 96/145.143
Installed mods: 
  * Assembly4 0.50.16-dev
  * sheetmetal 0.7.5
  * Curves 0.6.54
  * InventorLoader 1.5.1
  * diff-tools 0.1.0
  * ose-piping
  * OpenTheme 2024.9.1
  * fasteners 0.5.37
  * GDT
  * osh-autodoc-workbench 0.2.3
  * OpticsWorkbench 1.0.26
  * lattice2 1.0.0
  * kicadStepUpMod 11.5.2
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
