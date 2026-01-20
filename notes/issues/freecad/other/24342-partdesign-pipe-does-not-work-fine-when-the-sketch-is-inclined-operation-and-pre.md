# #24342 — PartDesign: Pipe does not work fine when the Sketch is inclined - Operation and Preview are also not getting the same conclusion.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24342`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24342
- State: `open`
- Created: `2025-09-30T16:35:08Z`
- Updated: `2025-12-03T10:56:48Z`
- Comments: `13`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I have these 2 sketches; the path is not horizontal, it is inclined 0.5 degrees.

<img height="154" alt="Image" src="https://github.com/user-attachments/assets/12a60408-e84b-4e69-bf53-c66d834a51b5" />

<img height="154" alt="Image" src="https://github.com/user-attachments/assets/0464eb85-af2b-4fde-b76c-c6b449db0f62" />

When doing the PD:Pipe the preview works with the Standard, Fixed, and Frenet modes.
But when committing the feature, Fixed does not work.

<img height="562" alt="Image" src="https://github.com/user-attachments/assets/0d5bdfc0-aa22-4ce8-a529-87813a789542" />

Produced features are not what the preview showed.

<img height="562" alt="Image" src="https://github.com/user-attachments/assets/4f82f9d6-615c-4a7e-8393-d17c1a651287" />

This is what it should look like (here using Frenet). Standard looks the same here. Are they the same thing?

<img height="562" alt="Image" src="https://github.com/user-attachments/assets/815a0e39-a043-4f2a-b5e1-6b5cc9571368" />

The feature should move on an inclined Sketch. 
Everytime I use sketch with an angle (on x axis) features missbehave.

<hr/>

Now, sometimes we have a preview that fails, but the operation succeeds. 

<img height="254" alt="Image" src="https://github.com/user-attachments/assets/331d46cb-9d47-4562-b3c8-cf133de832cb" />

<img height="254" alt="Image" src="https://github.com/user-attachments/assets/33f83da4-fbf2-4aef-b6bf-c8f3732cce63" />

<img height="189" alt="Image" src="https://github.com/user-attachments/assets/74ce8ee4-0eb9-4f4b-82c4-c15308773cc9" />

### Full version info

```shell
OS: Ubuntu 25.04 (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow)
Build date: 2025/09/23 18:47:15
Build type: Release
Branch: main
Hash: e9ce06155d8d47aad7d6c079bfa8ba54df2b6081
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Touchpad/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.0767/1
Installed mods: 
  * Assembly4.1 0.60.2-0.1
  * Cables 0.2.1
  * CurvesWB 0.6.64
  * FreeCAD-render 2024.12.15
  * Assembly4 0.60.2
  * sheetmetal 0.7.55
  * DynamicData 2.75.0
  * Curves 0.6.70
  * InventorLoader 1.5.1
  * diff-tools 0.1.0
  * ose-piping
  * Assembly4.1_mod 0.60.2-0.1
  * OpenTheme 2025.5.20
  * fasteners 0.5.42
  * Silk 0.2.0
  * osh-autodoc-workbench 0.2.3
  * CurvedShapes 1.0.13
  * freecad-povray-render
  * OpticsWorkbench 1.2.2
  * lattice2 1.0.0
  * kicadStepUpMod 11.7.6
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
