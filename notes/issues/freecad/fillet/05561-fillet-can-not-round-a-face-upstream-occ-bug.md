# #5561 — Fillet can not round a face (upstream OCC bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5561`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5561
- State: `open`
- Created: `2022-02-07T15:49:06Z`
- Updated: `2025-12-30T11:31:52Z`
- Comments: `8`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Help wanted`, `Priority: High`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=938

* **Reporter:** ghia
* **Date submitted:** 1/1/2013
* **FreeCAD version:** 0.12
* **Category:** Bug
* **Status:** assigned
* **Tags:** #ready-for-migration, fillet, OCC Bug, OCC NotOnRoadmap, upstream


# Original report text

See file in addendum of mantis bug #[937](https://tracker.freecad.org/view.php?id=937)

While the shape is 20 mm thick, you can not place 2 fillets of 10 mm 
Fillet001 which is 9 mm can not be set to 10

# Additional information

This ticket is being tracked from [OCC Bugs in the Bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264&p=156236#p156236) forum thread.

# Other bug information

* **Priority:** normal
* **Severity:** minor
* **Category:** Bug
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by wmayer 2013-07-02 03:37
Could be a float vs. double precision issue. Should be checked once the double-precision branch is merged into master.



---

### Comment by tanderson69 2013-09-23 17:29
I tried this with the current assembly branch (has float to double change) and there was no change.

I also tried this with the OCC DRAWEXE and witnessed the same behavior.

also searched OCC forum. Here is one thread.
http://www.opencascade.org/org/forum/thread_21317/?forum=3

//OCC rant removed




---

### Comment by wmayer 2015-01-14 13:34
http://tracker.dev.opencascade.org/view.php?id=25478


---

### Comment by Kunda1 2020-12-31 12:02
Can someone test with OCC 7.5.0 ?

Edit: Please remember to update the relationship with Feature #5569 if this ticket is resolved.
