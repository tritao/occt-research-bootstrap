# #21372 — PartDesign: Pocket fails on solid which consists of a revolve, a groove and another pocket

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21372`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21372
- State: `open`
- Created: `2025-05-15T21:35:13Z`
- Updated: `2025-11-27T00:29:13Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Creating a Pocket from a Sketch containing a single circle fails on a solid which consists of a revolve, a groove and another pocket.

![Image](https://github.com/user-attachments/assets/6f01fa9d-fa18-4443-a766-3bde5ed01d4d)
![Image](https://github.com/user-attachments/assets/af1acc64-76ba-41a3-b4b5-e6d433ff9ad3)

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: German/Germany (de_DE)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * A2plus 0.4.68
  * ArchTextures
  * Assembly4 0.50.18
  * Curves 0.6.54
  * Defeaturing 1.2.6
  * ExplodedAssembly
  * fasteners 0.5.38
  * freecad.gears 1.3.0
  * Marz 0.1.15
  * QuickMeasure 2022.10.28
  * Render 2024.12.15
```

### Subproject(s) affected?

None

### Anything else?

The .zip containes the FCStd file. I named the sketch for the failing pocket "Pockt_fails" and the failing pocket "failing_pocket".

[Pocket_fails.zip](https://github.com/user-attachments/files/20234657/Pocket_fails.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
