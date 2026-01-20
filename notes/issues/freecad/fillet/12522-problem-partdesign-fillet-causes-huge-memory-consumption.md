# #12522 — [Problem] PartDesign: fillet causes huge memory consumption

- Repo: `FreeCAD/FreeCAD`
- Issue: `#12522`
- URL: https://github.com/FreeCAD/FreeCAD/issues/12522
- State: `open`
- Created: `2024-02-20T16:47:57Z`
- Updated: `2025-02-22T07:20:28Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

There are several open fillet issues. But this one seems particularly severe as it causes a huge memory consumption that can render the computer unusable.

1. Remove the .zip extension from the file.
2. Open the file.
3. Change the fillet radius to 30mm.

Forum topic:
https://forum.freecad.org/viewtopic.php?t=85450

[Cocobo 3D print packaging 5 fillet-1mm.FCStd.zip](https://github.com/FreeCAD/FreeCAD/files/14348635/Cocobo.3D.print.packaging.5.fillet-1mm.FCStd.zip)





### Full version info

```shell
OS: Windows 8 build 9600
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.35994 (Git)
Build type: Release
Branch: main
Hash: 69097667df47b2cc86d8688d2dbb545319e33e68
Python 3.10.13, Qt 5.15.8, Coin 4.0.2, Vtk 9.2.6, OCC 7.6.3
Locale: Dutch/Netherlands (nl_NL)
Installed mods:
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
