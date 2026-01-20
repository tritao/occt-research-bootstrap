# #6319 — Crash when creating sweep (fix pending on the upstream release of OCC 7.8)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6319`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6319
- State: `open`
- Created: `2022-02-07T22:14:58Z`
- Updated: `2025-03-16T07:20:40Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Crash`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=1926

* **Reporter:** wvmarle
* **Date submitted:** 1/17/2015
* **FreeCAD version:** 
* **Category:** Bug
* **Status:** acknowledged
* **Tags:** #ready-for-migration, OCC 7.7, OCC Bug, sweep, upstream


# Original report text

Crash when creating a sweep.

# Additional information

OS: Linux Mint 17 Qiana
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.15.4484 (Git)
Branch: master
Hash: f72c802f5daa378298ffbfc3f3a17ec2d35c1816
Python version: 2.7.6
Qt version: 4.8.6
Coin version: 4.0.0a
OCC version: 6.7.1


# Steps to reproduce

Parts toolbox, select Sweep tool
Add Wire, Wire001, Wire002 for the sweep
Select the ellipse for sweep path
Create the sweep: crash

Probably I'm doing something illegal here by having the ellipse extend a little beyond the Wire and Wire002, but nevertheless it shouldn't crash.

Making it a complete ellipse solves the problem, it only crashes when the ellipse is an arc.

# Other bug information

* **Priority:** normal
* **Severity:** crash
* **Category:** Bug
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by cox 2015-01-17 15:25
EDIT -Disregard this comment. I can reproduce

http://forum.freecadweb.org/viewtopic.php?f=3&t=9358#p75957

OS: "Arch Linux"
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.15.4495 (Git)
Branch: master
Hash: 1f44226882071790a86a16f86bfacda0e7a5a880
Python version: 2.7.9
Qt version: 4.8.6
Coin version: 3.1.3
OCC version: 6.7.1





---

### Comment by shoogen 2015-01-17 16:12
I created an example for DRAWEXE from the attached file and uploaded it as sweep-arc2.zip to http://tracker.dev.opencascade.org/view.php?id=24909


---

### Comment by shoogen 2015-04-09 21:10
test http://forum.freecadweb.org/viewtopic.php?f=3&t=10445&p=84239#p84161  before closing the ticket.


---

### Comment by Kunda1 2017-01-11 11:55
Upstream ticket was bumped to OCC 7.2 roadmap.

Edit: tagged as 'upstream' and 'OCC 7.2' to indicate that this issue should be re-examined when 7.2 is released




---

### Comment by Kunda1 2017-08-21 11:04
Upstream ticket was was bumped to OCC 7.2.1 roadmap. Tagged ticket "OCC 7.2.1"


---

### Comment by Kunda1 2018-03-03 10:52
Upstream ticket was was bumped to OCC 7.4 roadmap. Notated in OCC bugtracker list: https://forum.freecadweb.org/viewtopic.php?f=10&t=20264


---

### Comment by Kunda1 2019-09-01 19:35
Upstream ticket was was bumped to OCC 7.5 roadmap. 
Tagged this ticket OCC7.5
Notated in OCC bugtracker list: https://forum.freecadweb.org/viewtopic.php?f=10&t=20264


---

### Comment by Kunda1 2020-10-08 13:47
Upstream ticket was was bumped to OCC 7.6 roadmap.
Tagged this ticket OCC7.6
Notated in OCC bugtracker list: https://forum.freecadweb.org/viewtopic.php?f=10&t=20264


---

### Comment by Kunda1 2022-01-15 12:58
Upstream ticket was was bumped to OCC 7.7 roadmap.
Tagged this ticket OCC7.6
Notated in OCC bugtracker list: https://forum.freecadweb.org/viewtopic.php?f=10&t=20264
