# #20588 — STEP Export does not contain all the geometry

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20588`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20588
- State: `open`
- Created: `2025-04-02T09:17:27Z`
- Updated: `2025-11-23T04:01:47Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Core`, `File format: STEP`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Exporting the `Gear16` that loooks OK in Freecad and passes geometry check in Part workbench produces a STEP file that is not a solid, because all the bottoms of the lettering is not closed in the STEP file and it also fails the geometry check, output in the bottom box. Apologies for not cleaning up the model to absolute bare minimum. The model uses additional workbenches, so could not test in safe mode.
The lettering is done in two ways to test if sketch on surface is the culprit. If I cheange the font to a normal font the result is similar except the model falls apart since the `R` and the `6` produce an isolated thing.

Tried to export in both 1.0.0 and weekly, difference is just that weekly *in addition* produces the transparent issue.

Importing both STEP files to either 1.0.0 or weekly produces the same result in both builds, even FreeCad import does not match the object exported. Step file looks the same also in https://github.com/usnistgov/SFA and orca slicer refuses to load it.


[Archive.zip](https://github.com/user-attachments/files/19564947/Archive.zip)

### Full version info

```shell
OS: macOS 14.4.1
Architecture: arm64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: C/Default (C) [ OS: C/Default (C) ]
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * ThreadProfile 1.92.0
  * ProDarkThemePreferencePack 1.0.0
  * fcgear 1.0.0
  * Pyramids-and-Polyhedrons
  * fasteners 0.5.31
  * lattice2 1.0.0
  * ExtremeProDark 2.9.0
  * Curves 0.6.51


----------

OS: macOS Sonoma (14.4)
Architecture: arm64
Version: 1.1.0dev.40971 (Git) Conda
Build date: 2025/03/24 18:02:34
Build type: Release
Branch: main
Hash: b33c2363226a5fc1e8222a02659118c95e1a5119
Python 3.11.11, Qt 6.7.3, Coin 4.0.3, Vtk 9.3.1, IfcOpenShell 0.8.1, OCC 7.8.1
Locale: C/Default (C) [ OS: English/Slovenia (en_SI) ]
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 72/127.5/2
Installed mods: 
  * ThreadProfile 1.92.0
  * ProDarkThemePreferencePack 1.0.0
  * fcgear 1.0.0
  * Pyramids-and-Polyhedrons
  * fasteners 0.5.31
  * lattice2 1.0.0
  * ExtremeProDark 2.9.0
  * Curves 0.6.51
```

### Subproject(s) affected?

None

### Anything else?

Original object:
```
Checked object: Clone003 (Gear16)
Shape type:  Compound
Vertices:  793
Edges:  1201
Wires:  494
Faces:  451
Shells:  1
Solids:  1
CompSolids:  0
Compounds:  1
Shapes:  2942
----------
Area:  2150.94
Volume:  2800.42
Length:  4039.09
Orientation:  Forward
Global placement = Placement
Tolerance information: 
 Global Minimum: 1e-07
 Global Average: 3.1754956440603516e-05
 Global Maximum: 0.005676687551545
```

Imported STEP file:
```
Unnamed.Part__Feature (Gear16) | Shell | Invalid
  Edge444 | Boolean operation: Invalid curve on surface
  Face155 | Boolean operation: Invalid curve on surface
```
```
Checked object: Part__Feature (Gear16)
Shape type:  Shell
Vertices:  793
Edges:  1201
Wires:  452
Faces:  409
Shells:  1
Solids:  0
CompSolids:  0
Compounds:  0
Shapes:  2856
----------
Area:  2127.94
Volume:  2748.53
Mass:  2127.94
Length:  3882.28
Center of mass:  [0.02, 0.01, 7.82]
Orientation:  Forward
SymmetryAxis:  False
SymmetryPoint:  False
Moments:  [113508.84, 112113.86, 107315.69]
FirstAxisOfInertia:  [-0.11, 0.99, -0.03]
SecondAxisOfInertia:  [0.99, 0.11, 0.05]
ThirdAxisOfInertia:  [-0.05, 0.02, 1.0]
RadiusOfGyration:  [7.3, 7.26, 7.1]
Global placement = Placement
Tolerance information: 
 Global Minimum: 1e-07
 Global Average: 2.2618122396838584e-05
 Global Maximum: 0.002901250750407379
```

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
