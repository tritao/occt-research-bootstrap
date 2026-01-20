# #14901 — PartDesign: Subtractive helix sometimes adds instead of subtracting

- Repo: `FreeCAD/FreeCAD`
- Issue: `#14901`
- URL: https://github.com/FreeCAD/FreeCAD/issues/14901
- State: `open`
- Created: `2024-06-23T23:01:26Z`
- Updated: `2025-02-22T07:18:43Z`
- Comments: `9`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Helix`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I have a part from which I'm trying to cut part of a helical thread, and sometimes the subtractive helix adds instead of subtracting.

I set the Boolean to tip and show the sketch:

![image](https://github.com/FreeCAD/FreeCAD/assets/79751/852ca4b9-eff8-4df2-b61f-f9987be6a8b8)

Then set the SubtractiveHelix to tip — and it's adding instead:

![image](https://github.com/FreeCAD/FreeCAD/assets/79751/280763a3-325f-4aee-b878-1d5f1fecf457)

Sometimes editing the helix and changing it to reversed, then back, fixes it. Sometimes it doesn't. Sometimes it causes the entire part to disappear.

The sketch passes all of "Validate Sketch" so it shouldn't be problems with a wire not being closed.

[DremelNut.zip](https://github.com/user-attachments/files/15946657/DremelNut.zip)


### Full version info

```shell
OS: Debian GNU/Linux 12 (bookworm) (GNOME/gnome)
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.37859 (Git)
Build type: Unknown
Branch: main
Hash: 6fd73487c7ea2c66e42395355de916f718320c9a
Python 3.11.2, Qt 5.15.8, Coin 4.0.0, Vtk 9.1.0, OCC 7.6.3
Locale: English/United States (en_US)
Installed mods: 
  * Assembly4 0.50.4
  * Curves 0.6.13
  * sheetmetal 0.3.0
  * ExplodedAssembly
  * fasteners 0.4.66
  * MeshRemodel 1.8919.0
  * freecad.gears 1.0.0
  * Pyramids-and-Polyhedrons
  * dxf_library
  * lattice2 1.0.0
  * boltsfc 2022.11.5
  * in3dca-freegrid 2.0.0
  * parts_library
  * Defeaturing 1.2.0
  * A2plus 0.4.60n
  * CurvedShapes 1.0.4
  * Manipulator 1.5.0
  * Pyramids-and-Polyhedrons.backup1696298372.5270553 (Disabled)
  * Assembly3 0.12.2
  * DynamicData 2.62.0
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
