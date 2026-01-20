# #19795 — Support STEP AP242 ed1/ed2/ed3/ed4

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19795`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19795
- State: `open`
- Created: `2025-02-23T10:54:16Z`
- Updated: `2025-09-29T19:42:32Z`
- Comments: `12`
- Milestone: `1.2`
- Labels: `Mod: Core`, `Type: Feature`, `3rd party: OCC`, `File format: STEP`, `Priority: High`, `GSoC`, `Mod: Assembly`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Currently, FreeCAD can export and import .STEP files but has no support for the newest STEP standards defined in **ISO 10303-242** [edition 2 and edition 3](http://www.ap242.org/edition-2.html) and the upcoming [edition 4](http://www.ap242.org/edition-4.html) with **ISO/FDIS 10303-242**. Not even [edition 1 ](http://www.ap242.org/ap242ed1.html)is supported fully by FreeCAD (kinematics, PDM,...). AP242 support is critical for enabling FreeCAD to be integrated in any product life cycle workflow in the industry, which relies on this exchange format throughout the entire supply chain.

242 Edition 2/3 support besides geometric data also important pipeline date for commercial use, like 3D PMI (3D annotations and tolerances), additive manufacturing, electrical harnesses and 3D composite design.

242 Edition 4 extends support of edition 2/3 with more features for 3D PMI and assembly data, including joint and connection information which the integrated Assembly WB should be able to work with on import and export.


### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.40122 (Git) Conda
Build type: Release
Branch: main
Hash: c1dddaeadc68cc9f05f1312dc1c6789820cfdd5d
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Locale: German/Germany (de_DE)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Logical/physical DPI: 96/133.772
Installed mods: 

```

### Subproject(s) affected?

Core

### Anything else?

Overview of all STEP application protocols:
https://en.wikipedia.org/wiki/ISO_10303#Coverage_of_STEP_Application_Protocols_.28AP.29
https://en.wikipedia.org/wiki/ISO_10303-21

CAx recommended practices and domain models:
https://www.mbx-if.org/home/cax/recpractices/

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
