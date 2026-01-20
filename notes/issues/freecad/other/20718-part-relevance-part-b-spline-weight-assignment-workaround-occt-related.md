# #20718 — Part: Relevance Part B-spline weight assignment workaround (OCCT related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20718`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20718
- State: `open`
- Created: `2025-04-09T09:47:46Z`
- Updated: `2025-04-22T23:39:54Z`
- Comments: `2`
- Labels: `Mod: Part`, `Type: Feature`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Part has a workaround for a potential OCCT problem. I'm wondering if this is still relevant for newer OCCT versions, so I would like to track this issue in the OCCT Liaison project.



### Full version info

```shell
OS: Arch Linux (xcb)
Architecture: x86_64
Version: 1.1.0dev.41211 (Git)
Build date: 2025/04/08 20:56:21
Build type: Release
Branch: main
Hash: ce0080cbae450fd62aadd41292cfd6e17723bf3d
Python 3.13.2, Qt 6.9.0, Coin 4.0.3, Vtk , OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/92.6073/1.33333
Installed mods: 
  * OpenTheme 2024.5.16
  * Ondsel-Lens 2024.10.21.01
  * fasteners 0.5.34
  * WebTools 1.0.0
  * osh-autodoc-workbench 0.2.3
  * DynamicData 2.70.0
```

### Subproject(s) affected?

Part

### Anything else?

The commit that introduced the workaround: 324f6d3e260dd5fd114477db09d3c4557d8e1992

The log message of the commit:

Part: Geometry - BSpline - fix weight assignment
    
================================================
    
If during assignment of weights (during the for loop iteratively setting the poles) all weights
become (temporarily) equal even though weights does not have equal values
OCCT will convert all the weights (the already assigned and those not yet assigned)
to 1.0 (nonrational b-splines have 1.0 weights). This may lead to the assignment of wrong
of weight values.
    
The work-around is to temporarily set the last weight to be assigned to a value different from
the current value and the to-be-assigned value for the weight at position last-to-be-assign but one.
    
Fixes:
https://forum.freecadweb.org/viewtopic.php?p=478701#p478702

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
