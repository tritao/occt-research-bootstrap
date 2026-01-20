# #19831 — Sketcher: Create external Intersection geometry not working with complex surfaces

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19831`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19831
- State: `closed`
- Created: `2025-02-24T18:59:15Z`
- Updated: `2025-03-12T00:18:41Z`
- Closed: `2025-03-12T00:18:40Z`
- Comments: `1`
- Labels: `Type: Feature`, `Mod: Sketcher`, `Status: In Fork / Addon available`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

The issue is that most of the times sketcher cannot make an intersection of complex surfaces built from B-Splines with sketch plane. In test example there is gordon surface, but I've seeing same issue with some lofts if profiles are B-splines and/or they are not in line. 

![Image](https://github.com/user-attachments/assets/3276f578-e3c9-405b-81c4-877446f89ec8)

 On a screenshot sketch has a circle just for visual representation where sketch is placed. When Intersection tool used to add external intersection result is an error in the report view:

![Image](https://github.com/user-attachments/assets/e53a2888-bddb-4917-b85e-f8cb58aba809)

I tested exact same file in Linkstage3 and it works just fine:

![Image](https://github.com/user-attachments/assets/2a40a590-e00c-494e-acc4-a2a144c7aa17)

I did some research, and looks like part of the code that handle b-spline edge projection (assuming BRepAlgoAPI_Section is working just fine and we get edge for projection) is not handling some cases. I'm talking about code starting here:

https://github.com/FreeCAD/FreeCAD/blob/c0569a35b8639c7642bfa33a2fa052c3b49f0bea/src/Mod/Sketcher/App/SketchObject.cpp#L8966

TopExp_Explorer could not find any edges here so projection fails. 

Looks like Linkstage3 has more complex code there:

https://github.com/realthunder/FreeCAD/blob/4458d9f3b869132b8f3e90e2d066aa0ea5c0a218/src/Mod/Sketcher/App/SketchObject.cpp#L8876

Will try to dig in there - maybe part of that code should be ported.

Test file (remove .zip): 

[intersection with surface.FCStd.zip](https://github.com/user-attachments/files/18948445/intersection.with.surface.FCStd.zip)

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.40176 (Git) Conda
Build type: Release
Branch: main
Hash: 2745f436026b6f1fb84dbaaf89ea22b5fb4c2295
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/Fusion
Logical/physical DPI: 96/92.6073
Installed mods: 
  * AirPlaneDesign 0.4.1
  * CurvedShapes 1.0.13
  * Curves 0.6.58
  * fasteners 0.5.37
  * Foamcut 0.1.6
  * freecad.gears 1.3.0
  * Marz 0.1.15
  * OpenTheme 2024.9.1
  * PieMenu 1.11.2
```

### Subproject(s) affected?

Sketcher

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
