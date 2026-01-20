# #19587 — Sketcher: Offset geometry on a sketch with two squares hangs FreeCAD on macos (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19587`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19587
- State: `open`
- Created: `2025-02-14T04:18:22Z`
- Updated: `2025-07-21T19:51:45Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Sketcher`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Load the attached FreedCAD file, then:

1. Open the sketch of two adjacent squares.
2. Select all elements.
3. Choose Offset Geometry.
4. Change from "arc" to "intersection".
5. Select an offset amount inside the left square.

At this point FreeCAD on macos hangs and needs to be force-quit.

With the same file, but the squares unconstrained the same operation crashes FreeCAD.


### Full version info

```shell
OS: macOS 15.3
Architecture: arm64
Version: 1.1.0dev.40176 (Git) Conda
Build type: Release
Branch: main
Hash: 2745f436026b6f1fb84dbaaf89ea22b5fb4c2295
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Locale: C/Default (C)
Stylesheet/Theme/QtStyle: OpenLight.qss/OpenLight/Fusion
Logical/physical DPI: 72/108
Installed mods: 
  * woodworking 0.21.2.33771.0.23.1
  * OpenTheme 2024.9.1
  * IconThemes
  * Curves 0.6.55
```

### Subproject(s) affected?

Sketcher

### Anything else?

[test.FCStd.zip](https://github.com/user-attachments/files/18793366/test.FCStd.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
