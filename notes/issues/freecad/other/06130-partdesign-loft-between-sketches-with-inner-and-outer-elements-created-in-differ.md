# #6130 — PartDesign: Loft between sketches with inner and outer elements created in different order results in bad 3D geometry

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6130`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6130
- State: `open`
- Created: `2022-02-07T20:37:24Z`
- Updated: `2025-11-15T08:10:33Z`
- Comments: `10`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=4498

* **Reporter:** robotarmy
* **Date submitted:** 11/21/2020
* **FreeCAD version:** 
* **Category:** Bug
* **Status:** new
* **Tags:** #pending-forum, Loft


# Original report text

When creating a loft, the order the sketch elements are created should not matter, but it does. 

Take the case of lofting between two sketches, with two circles each, for example, to make a kind of cylinder. In one sketch the inside was created first, and in the other sketch the outside was created first, the loft tries to cross over itself resulting in zero thickness geometry and a 'black part'. 

See forum post https://forum.freecadweb.org/viewtopic.php?p=449244#p449244
See updated limitations on wiki page for PartDesign Loft: https://wiki.freecadweb.org/index.php?title=PartDesign_AdditiveLoft&type=revision&diff=794134&oldid=763800

Thanks!

# Steps to reproduce

See attached file

# FreeCAD Info

```
OS: macOS 10.15
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.19.22756 (Git)
Build type: Release
Branch: master
Hash: ce87f586ee36ffe8ebcdcd3947ced4ab389ae795
Python version: 3.8.6
Qt version: 5.12.5
Coin version: 4.0.0
OCC version: 7.4.0
Locale: C/Default (C)
```

# Other bug information

* **Priority:** normal
* **Severity:** feature
* **Category:** Bug
* **OS: Mac OS 10.15.7 (19H2)**
* **Platform:** x86
* **Updated:** 2/6/2021
