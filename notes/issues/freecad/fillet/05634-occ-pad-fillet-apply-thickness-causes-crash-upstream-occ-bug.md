# #5634 — OCC: Pad → Fillet → Apply Thickness causes crash (upstream OCC bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5634`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5634
- State: `open`
- Created: `2022-02-07T16:23:32Z`
- Updated: `2025-11-24T21:27:04Z`
- Comments: `19`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Topic: Thickness`, `Status: Confirmed`, `Help wanted`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=2325

* **Reporter:** joostn
* **Date submitted:** 11/1/2015
* **FreeCAD version:** 0.15
* **Category:** Bug
* **Status:** assigned
* **Tags:** #ready-for-migration, OCC 7.2.1, OCC Bug, OCC NotOnRoadmap, upstream


# Original report text

See attached project and steps below:

# Additional information

OS: Mac OS X
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.15.4671 (Git)
Branch: releases/FreeCAD-0-15
Hash: 244b3aef360841646cbfe80a1b225c8b39c8380c
Python version: 2.7.9
Qt version: 4.8.6
Coin version: 4.0.0a

I've also tried with a daily build:

OS: Mac OS X
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.16.5846 (Git)
Build type: Unknown
Branch: master
Hash: 71be79e09e293bd2ccb1470981f07807be4c04fb
Python version: 2.7.10
Qt version: 4.8.7
Coin version: 3.1.3
OCC version: 6.7.0


# Steps to reproduce

- Open test3.FCStd
- Switch to Part workbench
- highlight a face of the 'Fillet' solid (I tried the topmost flat face as displayed)
- select the Apply Thickness tool

Bang! crash.

# Other bug information

* **Priority:** normal
* **Severity:** crash
* **Category:** Bug
* **OS: 10.11 10.11**
* **Platform:** Mac
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by wmayer 2016-02-28 20:47
```
TKG3dd.dll!Geom_TrimmedCurve::Geom_TrimmedCurve(const Handle_Geom_Curve & C={...}, const double U1=0.00000000000000000, const double U2=1.5707963267949001, const bool Sense=true)  Line 80 + 0x1d bytes	C++
TKOffsetd.dll!BRepOffset_Tool::TryProject(const TopoDS_Face & F1={...}, const TopoDS_Face & F2={...}, const TopTools_ListOfShape & Edges={...}, TopTools_ListOfShape & LInt1={...}, TopTools_ListOfShape & LInt2={...}, const TopAbs_State Side=TopAbs_IN, const double TolConf=4.9999999999999998e-007)  Line 1983 + 0x49 bytes	C++
TKOffsetd.dll!BRepOffset_Inter3d::ContextIntByArc(const TopTools_IndexedMapOfShape & ContextFaces={...}, const bool InSide=false, const BRepOffset_Analyse & Analyse={...}, const BRepAlgo_Image & InitOffsetFace={...}, BRepAlgo_Image & InitOffsetEdge={...})  Line 864	C++
TKOffsetd.dll!BRepOffset_MakeOffset::Intersection3D(BRepOffset_Inter3d & Inter={...})  Line 2591	C++
TKOffsetd.dll!BRepOffset_MakeOffset::MakeOffsetShape()  Line 727	C++
TKOffsetd.dll!BRepOffset_MakeOffset::MakeThickSolid()  Line 792	C++
TKOffsetd.dll!BRepOffsetAPI_MakeThickSolid::Build()  Line 72	C++
TKOffsetd.dll!BRepOffsetAPI_MakeThickSolid::BRepOffsetAPI_MakeThickSolid(const TopoDS_Shape & S={...}, const TopTools_ListOfShape & ClosingFaces={...}, const double Offset=1.0000000000000000, const double Tol=9.9999999999999995e-008, const BRepOffset_Mode Mode=BRepOffset_Skin, const bool Intersection=false, const bool SelfInter=false, const GeomAbs_JoinType Join=GeomAbs_Arc)  Line 60 + 0xd bytes	C++
Part_d.pyd!Part::TopoShape::makeThickSolid(const TopTools_ListOfShape & remFace={...}, double offset=1.0000000000000000, double tol=9.9999999999999995e-008, bool intersection=false, bool selfInter=false, short offsetMode=0, short join=0)  Line 2099 + 0xa2 bytes	C++
Part_d.pyd!Part::Thickness::execute()  Line 605 + 0x64 bytes	C++
```
That's a bug in the OCC library.



---

### Comment by jmaustpc 2016-03-01 15:11
Still crashes here with the OCE from tanderson, OCE patches over OCC 6.9.1 

OS: Ubuntu 12.04.5 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.16.6523 (Git)
Build type: Release
Branch: master
Hash: ecd6517cb00fcf05edd41a38b3ce1fa8b16ec3ad
Python version: 2.7.3
Qt version: 4.8.2
Coin version: 3.1.3
OCC version: 6.9.1.oce-0.18-dev


---

### Comment by wmayer 2016-03-14 19:52
Might be related: http://forum.freecadweb.org/viewtopic.php?f=3&t=14677


---

### Comment by Kunda1 2017-05-12 12:32
joostn do you mind re-uploading the attachment? It didn't survive are previous tracker backup restore.


---

### Comment by joostn 2017-05-12 13:21
I hope this is the file (it has the same name).


---

### Comment by Kunda1 2017-08-21 11:07
normandc do you mind weighing in ?


---

### Comment by wmayer 2017-09-02 11:27
With occ7.2 it still crashes and shows the identical stack trace.


---

### Comment by Kunda1 2018-09-13 20:09
chrisb would you please test to see if issue is still present. Thanks!


---

### Comment by Kunda1 2019-04-24 11:53
Adding to 0.19 roadmap so that bug gets attention


---

### Comment by abdullah 2020-06-07 14:55
I have reported the bug upstream and provided a possible patch to avoid the segfault:
https://tracker.dev.opencascade.org/view.php?id=31601

Kunda1
For your administration ;)


---

### Comment by sfornengo 2020-08-14 17:00
Can we hope this 4 years bug to be solve in a near future ?
I can see proposed patch but always testing newer version never solve the problem...
This bug really kills Freecad experience and adoption because it prevents the realization of even simple shells that are the most common operation for boxes and enclose cases...
So we have no workaround than using another 3D CAD... Really too bad !


---

### Comment by Kunda1 2020-08-21 20:52
Added to https://forum.freecadweb.org/viewtopic.php?f=10&t=20264&p=425392#p425392


---

### Comment by sfornengo 2020-11-17 10:34
I am coming back on this issue with the following example showing a weird behavior that can lead to better understand the bug.
In the following example, removing the face without fillet and trying to create a thickness of 1mm inward leads to the famous bug...
But if first of all I create a thickness of 0mm inward I obtain a new solid that then enables to create a thickness of 1mm inward without leading to the bug.
So the bug could be on freecad side ?


---

### Comment by andergrin 2020-11-18 13:22
When I do the same steps (thickness of 0 mm inward), the body is also rotating 90 degrees on the x axis
As I understand it, problems arise when there are chamfer (or fillets) in the part. When a wall is created inward, the chamfer also scales, and at some point it seems to invert and create self-intersections. I more or less learned how to bypass this problem by adding fillets to the chamfers or chamfers to the fillets, but this is not the solution to the problem, because it takes a long time to guess the right values.
```OS: Windows 10 (10.0)
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.19.22960 (Git)
Build type: Release
Branch: master
Hash: c5a4b01d2e4218bcc0eb6650337650a6c65ef0e4
Python version: 3.8.6
Qt version: 5.12.5
Coin version: 4.0.0
OCC version: 7.4.0
Locale: Ukrainian/Ukraine (uk_UA)
```




---

### Comment by andergrin 2020-11-18 13:40
Here, I managed to make desired (2,4 mm) inward thickness and chamfers, but I have to add Fillet001 to apply Thickness
[example file](https://tracker.freecadweb.org/file_download.php?file_id=2562&type=bug)
