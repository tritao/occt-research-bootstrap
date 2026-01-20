# #10760 — [Problem] Crash when adding PartDesign fillet

- Repo: `FreeCAD/FreeCAD`
- Issue: `#10760`
- URL: https://github.com/FreeCAD/FreeCAD/issues/10760
- State: `open`
- Created: `2023-09-20T09:35:17Z`
- Updated: `2025-05-17T08:17:49Z`
- Comments: `12`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

When trying to add a fillet to an edge FreeCAD crashes.

Steps to reproduce:

1. Click on edge as shown in image (green edge):
<img width="215" alt="Screenshot 2023-09-20 at 10 30 47" src="https://github.com/FreeCAD/FreeCAD/assets/2439728/7294faf0-49bc-4a91-b82a-e29af4820304">

2. Click on add fillet button
3. FreeCAD crashes

Minimal file: [crash.zip](https://github.com/FreeCAD/FreeCAD/files/12671484/crash.zip)

### Full version info

```shell
OS: macOS 14.5
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.38079 (Git)
Build type: Release
Branch: main
Hash: de508e437d13e7eb35baffceea496fb9107888cb
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: C/Default (C)
Installed mods: 
  * Launcher
  * Nodes 0.1.36
  * InventorLoader 1.4.0
  * Assembly4.backup1719958896.85335 0.50.12 (Disabled)
  * Render.backup1719959316.120863 2024.6.5 (Disabled)
  * woodworking 0.21.2.33771
  * ThreadProfile.backup1719959316.6397839 1.90.0 (Disabled)
  * MeshRemodel.backup1719959315.871541 1.9.23 (Disabled)
  * Silk 0.1.5
  * Defeaturing 1.2.2
  * Pyramids-and-Polyhedrons
  * Curves.backup1719958901.528519 0.6.36 (Disabled)
  * fasteners.backup1719958901.808955 0.5.20 (Disabled)
  * nurbs
  * sheetmetal.backup1719959316.3711638 0.4.21 (Disabled)
  * A2plus.backup1719958896.309429 0.4.64a (Disabled)
  * Manipulator 1.5.7
  * lattice2 1.0.0
  * CurvedShapes 1.0.9
  * toSketch 1.0.1
  * Curves 0.6.40
  * Assembly4 0.50.15
  * Assembly3 0.12.2
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
