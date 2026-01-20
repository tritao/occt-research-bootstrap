# #9760 — [Problem] Regression on toNurbs() (Update: fixed in OCCT 7.9.0)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#9760`
- URL: https://github.com/FreeCAD/FreeCAD/issues/9760
- State: `closed`
- Created: `2023-06-11T17:41:12Z`
- Updated: `2025-06-09T00:52:51Z`
- Closed: `2025-06-09T00:52:49Z`
- Comments: `34`
- Labels: `Type: Bug`, `3rd party: OCC`, `Type: Regression`, `Status: Stale`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Version

0.21 (Development)

### Full version info

```shell
[code]
OS: macOS 13.2.1
Word size of FreeCAD: 64-bit
Version: 0.21.0.33380 (Git)
Build type: Release
Branch: master
Hash: 16b06993e23eabd411586c7908be08ad8f609ce0
Python 3.11.3, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.2, OCC 7.7.1
Locale: C/Default (C)
Installed mods: 
  * MeshRemodel 1.8919.0
  * DynamicData 2.46.0
  * lattice2.backup1682566094.626239 1.0.0 (Disabled)
  * fcgear 1.0.0
  * workfeature
  * Pyramids-and-Polyhedrons
  * QuickMeasure-main
  * GDML 1.8.0
  * offline-documentation
  * Manipulator 1.5.0
  * fasteners 0.4.56
  * lattice2 1.0.0
  * CurvedShapes 1.0.4
  * Alternate_OpenSCAD 1.0.0
  * toSketch 1.0.1
  * Help 1.0.3
  * Curves 0.6.10
[/code]
```


### Subproject(s) affected?

None

### Problem description

If you select a bspline edge and send it to the Python console then


```
>>> c = sub.toNurbs().Edges[0]
>>> c.Curve
Traceback (most recent call last):
  File "<input>", line 1, in <module>
Base.FreeCADError: Unknown exception while reading attribute 'Curve' of object 'TopoShape'
```

the created edge has no underlying Curve.  This breaks  JoinCurves in the Curves WB and likely other things.  It may be associated with OCC 7.7.x. See forum https://forum.freecad.org/viewtopic.php?p=687077#p687077

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
