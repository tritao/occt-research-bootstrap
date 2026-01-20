# #5799 — OCC: fillet fails on cut torus

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5799`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5799
- State: `open`
- Created: `2022-02-07T17:47:09Z`
- Updated: `2025-12-07T12:21:40Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Core`, `3rd party: OCC`, `Status: Confirmed`, `Help wanted`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=3554

* **Reporter:** bzipitidoo
* **Date submitted:** 8/6/2018
* **FreeCAD version:** 0.17
* **Category:** Bug
* **Status:** feedback
* **Tags:** Part


# Original report text

Been using python scripting to make parts.  Fillet is finicky.  Sometimes it works.  Sometimes it gives an error message:

Part.OCCError: BRep_API: command not done

and the fillet fails.  It can fail on a simple piece, but work on a more complicated shape that is other shapes fused with the simple piece.

Investigating, the simplest fail I found so far is a cut down torus-- sliced in half like a bagel, then cut in half again.  See the included python script.

# Additional information

OS: "PCLinuxOS"
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.13528 (Git) AppImage
Build type: None
Branch: releases/FreeCAD-0-17
Hash: 5c3f7bf8ec51e2c7187789f7edba71a7aa82a88b
Python version: 2.7.6
Qt version: 4.8.6
Coin version: 4.0.0a
OCC version: 7.3.0
Locale: English/UnitedStates (en_US)


# Steps to reproduce

```python
#makeFillet fails in this python script:

import math
import Part
from FreeCAD import Base

DEG2RAD = math.pi/180.0
rd = 72
origin = Base.Vector(0,0,0)
znorm = Base.Vector(0,0,1)
xnorm = Base.Vector(1,0,0)

boxcorner = Base.Vector(-rd*2,-rd*2,-rd*2)
cutbox = Part.makeBox(rd*4,rd*2,rd*4,boxcorner,znorm)

fulltorus = Part.makeTorus(rd-4,4,origin,xnorm,0,360)
halftorus = fulltorus.cut(cutbox)

basecyl = Part.makeCylinder(rd+2,9,origin,xnorm)
halftorus = halftorus.cut(basecyl)

#This fillet fails
filletht = halftorus.makeFillet(0.2, halftorus.Edges)
```



# Other bug information

* **Priority:** normal
* **Severity:** minor
* **Category:** Bug
* **OS: Linux kernel 4.11.8**
* **Platform:** PC
* **Updated:** 2/6/2021


# Discussion from Mantis ticket

### Comment by @luzpaz 2018-08-07 12:01
bzipitidoo please test this on 0.18dev as well (there is an [appimage](https://github.com/FreeCAD/FreeCAD/releases/tag/0.18_pre)). Also please, per our guidelines (yellow banner at the top) post to our forums before opening a ticket. 



---

### Comment by bzipitidoo 2018-08-07 13:29
I tested this script with makeFillet on version 0.18.14220 and 0.18_Conda Appimages.  The problem with makeFillet is present in both 0.18 versions.


---

### Comment by @luzpaz 2018-08-07 15:36
please open a forum thread and post this ticket to it to start a discussion. thanks


---

### Comment by normandc 2018-09-02 21:47
For the Python challenged, an actual FreeCAD document would be nice. I'm an experienced CAD user, I can troubleshoot models, but I need a model to do it - a python script might as well be Mandarin to me. I don't speak Mandarin. And running the aforementioned script produces zero visible result in the 3D view.


---

### Comment by @wwmayer 2018-10-04 09:15
Attached is a project file with the half torus. Now go to Part, select the fillet tool and select all edges. Use a radius of 0.2.
[0003554.zip](https://github.com/FreeCAD/FreeCAD/files/8792223/0003554.zip)


---

### Comment by @luzpaz 2018-11-07 00:51
Forum thread: https://forum.freecadweb.org/viewtopic.php?f=8&t=32087


---

### Comment by normandc 2018-11-11 05:37
The problem seems to be with the inner circular edge of the half torus. Without it, all other edges fillet successfully.

A workaround is to cut the torus slightly bigger or smaller than half. If the minor radius of the torus is 4mm, cut 0.001 from the midplane, either side works - all fillets succeed.

I would surmise that this is an OCC issue...

OS: Ubuntu 18.04.1 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.18.15169 (Git)
Build type: Release
Branch: master
Hash: 7d197ce829600e308dd0e85aeb1a4ac9376ff286
Python version: 2.7.15rc1
Qt version: 4.8.7
Coin version: 4.0.0a
OCC version: 7.3.0
Locale: French/Canada (fr_CA)
