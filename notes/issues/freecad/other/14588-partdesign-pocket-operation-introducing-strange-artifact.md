# #14588 — PartDesign: Pocket operation introducing strange artifact

- Repo: `FreeCAD/FreeCAD`
- Issue: `#14588`
- URL: https://github.com/FreeCAD/FreeCAD/issues/14588
- State: `open`
- Created: `2024-06-10T13:30:10Z`
- Updated: `2025-07-07T13:55:45Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

The included file introduces a strange artifact when performing a pocket operation (the last operation in the file). I have a shape that I then want to pocket. Apply a sketch of a circle going through all and a strange artifact appears.
![artifact1](https://github.com/FreeCAD/FreeCAD/assets/38090157/01a4bdc3-6a74-4c14-b21e-34828e6f6cf4)
![artifact2](https://github.com/FreeCAD/FreeCAD/assets/38090157/5d60c2af-e4de-4680-8b49-8bd124604fbc)

This is not an issue with the drawing. Exporting as a .3mf (or any other format) shows the artifact is part of the object.
![artifact3](https://github.com/FreeCAD/FreeCAD/assets/38090157/86f19631-cf1d-48ab-8e16-b3c5369c0a65)

[SVG Error.FCStd.zip](https://github.com/user-attachments/files/15771914/SVG.Error.FCStd.zip)


### Full version info

```shell
Latest Dev version built from source:

OS: Windows 11 build 22631
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.37670 (Git)
Build type: Release
Branch: main
Hash: ba0ff0db5e78973cb994b82f27bdd228c7ad41bd
Python 3.8.10, Qt 5.15.2, Coin 4.0.1, Vtk 8.2.0, OCC 7.6.3
Locale: English/United States (en_US)
Installed mods: 
  * ArchTextures
  * CfdOF 1.25.11
  * fasteners 0.5.17
  * fcgear 1.0.0
  * FeedsAndSpeeds 0.5.0
  * GDML.backup1701064072.5104816 2.0.0 (Disabled)
  * kicadStepUpMod 11.1.2
  * LCInterlocking
  * MaterialTest
  * OpenTheme 2024.5.3
  * render 2023.8.18
  * Rocket 4.0.0
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
