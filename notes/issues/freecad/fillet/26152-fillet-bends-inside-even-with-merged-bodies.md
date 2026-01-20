# #26152 — Fillet bends inside even with merged bodies.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26152`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26152
- State: `open`
- Created: `2025-12-14T13:08:33Z`
- Updated: `2025-12-23T14:42:29Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

```
OS: Windows 11 build 26200
Architecture: x86_64
Version: 1.1.0rc1.20251125 (Git shallow)
Build date: 2025/11/25 17:53:08
Build type: Release
Branch: (HEAD detached at 5376760)
Hash: 53767601ea65de7cd9f6590e7d5856afc0841635
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Blender/Turntable/Object center
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.3898/1.5
Installed mods: 
  * A2plus 0.4.68
  * ExplodedAssembly
  * fasteners 0.5.43
  * Freecad-Built-in-themes-beta 1.2.2
  * freecad.gears 1.3.0
  * OpenTheme 2025.5.20
  * Quetzal 1.6.8
  * QuickMeasure 2022.10.28
  * SaveAndRestore 0.2.1
  * sheetmetal 0.7.58
```
I am not sure if it is a bug or something, but the result of Radius seems weird with intersecting cylindrical surface body.

<img width="811" height="665" alt="Image" src="https://github.com/user-attachments/assets/71a24d8f-e8e5-45bc-8e64-a4825c157e23" />


### Steps to reproduce

[NRV Body.zip](https://github.com/user-attachments/files/24149921/NRV.Body.zip)
1. Unzip the file.
2. Open the file in any FreeCAD version newer than 1.0.0
3. In feature tree, look for 'Pad001' and  (OPTIONAL: toggle all the feature by hiding it below that)
4. Try fillet the edge greater than 1.00 mm (same as shown in image of this post)
5. See the result! 

### Expected behavior

Fillet should merge with the cylindrical face at quadrant point edge or follow the direction as per curve bends. (see the image for more clarity)

### Actual behavior

Instead of merge and follow direction of the cylinder edge, it bends inside like the 'pad' is not merged with the cylinder and fillet bend otherwise. 

### Development version About Info (in Safe Mode)

```shell
OS: Windows 11 build 26200
Architecture: x86_64
Version: 1.2.0dev.20251209 (Git shallow)
Build date: 2025/12/09 13:53:17
Build type: Release
Branch: grafted,grafted
Hash: 5ad6a1ba58c665c23f1d217c23e74379d8c1a5a4
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Blender/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.3898/1.5
```

### Last known good version (optional)

```shell

```
