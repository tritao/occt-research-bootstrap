# #10494 — Sketcher/PartDesign: Pocket doesn't throw error when used on invalid sketch containing B-spline

- Repo: `FreeCAD/FreeCAD`
- Issue: `#10494`
- URL: https://github.com/FreeCAD/FreeCAD/issues/10494
- State: `open`
- Created: `2023-09-02T12:50:48Z`
- Updated: `2025-11-18T13:13:57Z`
- Comments: `15`
- Labels: `Type: Bug`, `Mod: Part Design`, `Mod: Sketcher`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Helix`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Can't create pocket with this very specific sketch, I suspect it has to do with the bspline
[M12.FCStd.zip](https://github.com/FreeCAD/FreeCAD/files/12503994/M12.FCStd.zip)

https://github.com/FreeCAD/FreeCAD/assets/12400097/740968d3-318d-4f0e-94ac-64495c80dc9c



### Full version info

```shell
OS: Ubuntu Core 22 (ubuntu:GNOME/ubuntu)
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.34091 (Git) Snap 758
Build type: Release
Branch: master
Hash: a2735416e1189566329b327d99f115ced7071b86
Python 3.10.12, Qt 5.15.10, Coin 4.0.0, Vtk 7.1.1, OCC 7.7.1
Locale: English/United States (en_US)
Installed mods: 
  * Help 1.0.3
```


### Subproject(s) affected?

Part Design, Sketcher

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
