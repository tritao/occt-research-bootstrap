# #6203 — [Problem] TechDraw: not drawing all lines in view

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6203`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6203
- State: `open`
- Created: `2022-02-07T20:49:08Z`
- Updated: `2025-11-14T12:16:37Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: TechDraw`, `3rd party: OCC`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=4639

* **Reporter:** run_the_race
* **Date submitted:** 4/20/2021
* **FreeCAD version:** 0.19
* **Category:** Bug
* **Status:** feedback
* **Tags:** #pending-forum, #ready-for-migration, OCC Bug


# Original report text

TechDraw is missing some lines in the isometric view

![image](https://github.com/FreeCAD/FreeCAD/assets/4140247/94bffdad-1373-4da5-bab3-f5dadbadc656)  
missing vertical lines - ub techdraw

![image](https://github.com/FreeCAD/FreeCAD/assets/4140247/494e0dcf-8bdf-4cad-85de-904363e26d34)  
missing vertical lines - printed

# Steps to reproduce

1. Open the attached file raspberry_pi_4b.FCStd [raspberry_pi_4b.FCStd.gz](https://github.com/FreeCAD/FreeCAD/files/11713080/raspberry_pi_4b.FCStd.gz)
2. Open "Page" item in the tree browser
3. Look at the isometric view.
4. Notice some of the 40way header pins are missing vertical lines, as shown by the attached images.

# FreeCAD Info

```
OS: Windows 10 Version 2004
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
Locale: English/United Kingdom (en_GB)

```

# Other bug information

* **Priority:** normal
* **Severity:** minor
* **Category:** Bug
* **OS: Windows 10 2004**
* **Platform:** PC
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by Kunda1 2021-04-21 18:26
it's 'TechDraw' not 'tech draw'. Edited ticket.
I'll start a discussion for you on the forum.



---

### Comment by Kunda1 2021-04-21 18:27
Discussion at https://forum.freecadweb.org/viewtopic.php?f=35&t=57994


---

### Comment by wandererfan 2021-12-30 20:35
Some of the overlapping vertical lines for the pins are being treated as "hard hidden" instead of "hard visible".  Only part of the edge is hidden - does OCC not split the edge into visible and invisible portions before classifying??


---

### Comment by wandererfan 2022-01-02 17:18
is there a connection with 4564 short and/or overlapping lines not drawn??


---

### Comment by wandererfan 2022-01-06 18:26
using the perspective projector with a long focal length shows all the lines (also gives a better result for #6161).  

this has come up before, but I can't find an upstream ticket.
