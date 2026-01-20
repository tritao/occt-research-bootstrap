# #15700 — PartDesign: Pocket circle hole not done on revolution seam but appears on polar pattern

- Repo: `FreeCAD/FreeCAD`
- Issue: `#15700`
- URL: https://github.com/FreeCAD/FreeCAD/issues/15700
- State: `open`
- Created: `2024-07-30T22:28:32Z`
- Updated: `2025-08-31T10:31:52Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I'm trying to model a bicycle wheel, I made 2 **Pocket** holes to pattern them using a polar array, the problem is that the original instance of **the second Pocket hole does not modify the part**, instead of a hole there is interruption on the edge that form the face of the revoluted profile (see blue line on image).

**Edit:** The small holes are result from polar pattern of the original hole not properly done on geometry.

![image](https://github.com/user-attachments/assets/4454f98d-65ed-47ce-83c9-df65f73cbffa)


### Full version info

```shell
OS: Arch Linux (Hyprland/hyprland)
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.38334 (Git) AppImage
Build type: Release
Branch: main
Hash: 61c964caa9a7e5bbc7a8d5f7d8914505d365113e
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Installed mods: 
  * ThreadProfile 1.90.0
  * FreeCAD-Movie 2024.2.15
  * freecad.gears 1.2.0
  * PieMenu 1.7.3
  * freecad_metal_workbench 0.0.1
  * Ship 2022.4.11
  * OpenTheme 2024.7.3
  * FreeGrid 2.0.0
  * FreeCAD-Reinforcement
  * Defeaturing 1.2.2
  * FreeCAD_SheetMetal 0.4.16
  * FreeCAD-Pyramids-and-Polyhedrons
  * yaml-workspace 0.1.2
  * woodworking 0.21.2.33771
  * Assembly4 0.50.10
  * FastenersWB 0.5.24
  * lattice2 1.0.0
  * Rocket 3.3.0
  * dodo 1.0.1
  * DidYouKnowThat
  * FreeCAD-motion
  * cadquery_module
  * Profiles 0.0.1
  * Alternate_OpenSCAD 1.0.0
  * osh-autodoc-workbench 0.2.3
  * CfdOF 1.27.4
  * A2plus 0.4.64a
  * kicadStepUpMod 11.2.4
  * Nodes 0.1.36
  * Marz 0.1.5
  * frame 0.1.1
  * pcb 6.2023.1
  * FreeCAD_assembly3 0.12.2
  * Render 2024.7.4
```


### Subproject(s) affected?

PartDesign

### Anything else?

I replaced the circle sketch to a square, octagon, Bezier curve and the hole appeared, so it seems only a circle is causing troubles. Maybe an edge case?

Here is my file: [BicycleWheel.zip](https://github.com/user-attachments/files/16434025/BicycleWheel.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
