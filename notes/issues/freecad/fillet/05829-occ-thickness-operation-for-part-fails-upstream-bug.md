# #5829 — OCC: Thickness operation for part fails (upstream bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5829`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5829
- State: `open`
- Created: `2022-02-07T17:51:08Z`
- Updated: `2025-11-22T11:53:34Z`
- Comments: `4`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Topic: Thickness`, `Status: Confirmed`, `Help wanted`, `Priority: High`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=3670

* **Reporter:** 0kko
* **Date submitted:** 11/5/2018
* **FreeCAD version:** 0.17
* **Category:** Bug
* **Status:** confirmed
* **Tags:** #ready-for-migration, OCC Bug, OCC NotOnRoadmap, upstream


# Original report text

Thickness operation in Part and Part Design -workbences fails with: "BRep_API: command not done."

# Additional information

Binaries tested with "case.fcstd"

FreeCAD-0.17.13541.9948ee4.glibc2.17-x86_64.AppImage
FreeCAD-0.17.13541.9948ee4.glibc2.17-x86_64.AppImage

Note: Issue is reproducible on latest v0.19 since the bug is with upstream OCCT
This ticket is being tracked via [OCC Bugs in the Bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264) forum thread

# Steps to reproduce

Select "face 8" in "case.fcstd".
Try to do "Thickness"

# Other bug information

* **Priority:** normal
* **Severity:** minor
* **Category:** Bug
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by @luzpaz 2018-11-05 18:37
0kko Please check with 0.18_pre appImage to see if you can recreate. https://github.com/FreeCAD/FreeCAD/releases/tag/0.18_pre
(make sure you backup you file before doing so as 0.18 is not backward compatible if you open said file in 0.17 again)

BTW, your ticket does not follow our guidelines stated in the enormous banner at the top of this page. We ask for people to report their issues on the forum first, many times they don't even make it to the tracker because they either get solved, or there is an open ticket already (there are exceptions). You also tested this on 0.17 yet you labeled this 0.18. + we have no idea what OS or OS version you are running. Guidelines are there for a reason, thank you.



---

### Comment by normandc 2018-11-11 05:58
It is no surprise that the Thickness operation fails - look at the corners at the joint between the wedge and the box. The fillet created a deep cavity at the four corners.

While this may look like a separate and legitimate bug (a fillet causing a crease between slanted corners), fixing it does not solve the thickness issue. The thickness command is notoriously weak. It is most probably an upstream (OCC) issue over which the FreeCAD team has no control.

It is indeed exasperating that some people are completely blind to the f***ing huge yellow banner at the top. IMO we should start ruthlessly closing reports that do not comply with rules. Enough with this.




---

### Comment by @PLChris 2020-12-22 00:33
File is lost, and it was as Normand guessed most probably an OCC issue anyway.


---

### Comment by @wwmayer 2020-12-22 11:53
https://forum.freecadweb.org/viewtopic.php?f=8&t=53514&p=460091#p460091


---

### Comment by @luzpaz 2020-12-22 12:13
Reopening and tracking via [OCC Bugs in the Bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264) forum thread


---

### Comment by @luzpaz 2020-12-22 12:15
Re-uploaded attachment since previous one was broken. Thanks wmayer ;)
[case.zip](https://github.com/FreeCAD/FreeCAD/files/8782350/case.zip)

for reference: [original mantisBT attached file](https://tracker.freecad.org/file_download.php?file_id=2585&type=bug)

---

### Comment by @luzpaz 2022-01-23 00:34
I can't find face8 in the attached file ???
@PLChris care to check?
