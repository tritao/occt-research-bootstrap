# #11082 — [Problem] Broken PartDesign fillet

- Repo: `FreeCAD/FreeCAD`
- Issue: `#11082`
- URL: https://github.com/FreeCAD/FreeCAD/issues/11082
- State: `open`
- Created: `2023-10-17T20:06:56Z`
- Updated: `2025-02-22T07:21:50Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Trying to fillet this edge to 1/64" breaks the part:
<img width="272" alt="Screenshot 2023-10-17 at 21 00 37" src="https://github.com/FreeCAD/FreeCAD/assets/2439728/3cfb666c-2795-4a44-8be7-d35a35b13551">
<img width="269" alt="Screenshot 2023-10-17 at 21 00 09" src="https://github.com/FreeCAD/FreeCAD/assets/2439728/cfc70050-0a31-48ae-856e-beb6fd2e5c19">

For some reason, trying the same edge on the other side works.
Part: [broken_fillet.FCStd.zip](https://github.com/FreeCAD/FreeCAD/files/12950237/broken_fillet.FCStd.zip)



### Full version info

```shell
OS: macOS 13.5.2
Word size of FreeCAD: 64-bit
Version: 0.21.1.33694 (Git)
Build type: Release
Branch: (HEAD detached at 0.21.1)
Hash: f6708547a9bb3f71a4aaade12109f511a72c207c
Python 3.10.12, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.5, OCC 7.6.3
Locale: C/Default (C)
Installed mods: 
  * MeshRemodel 1.8919.0
  * Launcher
  * InventorLoader 1.4.0
  * Render 2023.8.18
  * Silk 0.1.5
  * Defeaturing 1.2.1
  * A2plus 0.4.60n
  * Manipulator 1.5.0
  * fasteners 0.4.66
  * lattice2 1.0.0
  * sheetmetal 0.3.1
  * toSketch 1.0.1
  * Curves 0.6.13
  * Assembly4 0.50.4
  * Assembly3 0.12.0
```

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
