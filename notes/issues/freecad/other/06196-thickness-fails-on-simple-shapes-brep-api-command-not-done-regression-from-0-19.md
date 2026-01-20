# #6196 — Thickness fails on simple shapes (BRep_API command not done) - regression from 0.19.24267

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6196`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6196
- State: `open`
- Created: `2022-02-07T20:48:55Z`
- Updated: `2026-01-07T09:02:28Z`
- Comments: `10`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Regression`, `Topic: Thickness`, `Help wanted`, `Priority: High`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=4624

* **Reporter:** DocFingo
* **Date submitted:** 4/8/2021
* **FreeCAD version:** 0.19
* **Category:** Bug
* **Status:** new
* **Tags:** 


# Original report text

Thickness operations with **Arc** or **Tangent** join types fail on predominantly concave shapes.
Message is ***BRep_API: command not done***. This happens for any positive Thickness value.

Changing join type to **Intersection** solves the issue, but does not yield the desired part.

This is a potential regression from 0.19.24267 where the issue seemed to be (mostly?) fixed, see reproduction steps below.

A Thickness problem in conjunction with OCC 7.5 was previously reported [here](https://tracker.freecadweb.org/view.php?id=4332) by user AlStu, with forum discussions [here](https://forum.freecadweb.org/viewtopic.php?f=3&t=45642&p=391223&hilit=thickness+limitation#p391223).
~However OCC 7.5 is present in both~ OCC has been upgraded from 7.3 in 0.19.24267 to 7.5 in 0.19.24276, both show different results.

# Additional information

***This is the previous 0.19.24267 version I used for the comparison:***
OS: Windows 10 (10.0)
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.19.24267 (Git)
Build type: Release
Branch: master
Hash: b2ca86d8d72b636011a73394bf9bcdedb3b109b7
Python version: 3.6.8
Qt version: 5.12.1
Coin version: 4.0.0a
OCC version: 7.3.0
Locale: English/Germany (en_DE)

# Steps to reproduce

Part workbench: Make a simple extrusion from a sketch with concave outer shape.
Apply Thickness while selecting the top face. Try different Join types.

To test the potential regression from 0.19.24267, open the attached FCstd file.
Press F5 to recompute the solution.
0.19.24267 -> Thickness is computed successfully except for the sharp-edged shape.
0.19.24276 -> Thickness (Arc/Tangent join type) fails for 3 out of 4 shapes. Deleting and re-applying thickness yields BRep_API: command not done

# FreeCAD Info

```
OS: Windows 10 Version 2009
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.19.24276 (Git)
Build type: Release
Branch: releases/FreeCAD-0-19
Hash: a88db11e0a908f6e38f92bfc5187b13ebe470438
Python version: 3.8.6+
Qt version: 5.15.1
Coin version: 4.0.1
OCC version: 7.5.0
Locale: English/Germany (en_DE)
```

# Other bug information

* **Priority:** normal
* **Severity:** major
* **Category:** Bug
* **OS: Windows 10 Enterprise 10.0.19042**
* **Platform:** Core i5-8350U (x64, 8GB RAM)
* **Updated:** 4/9/2021
