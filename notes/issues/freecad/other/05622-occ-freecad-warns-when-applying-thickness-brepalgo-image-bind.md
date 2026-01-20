# #5622 — OCC: FreeCAD warns when applying thickness "BRepAlgo_Image::Bind"

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5622`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5622
- State: `open`
- Created: `2022-02-07T16:22:09Z`
- Updated: `2026-01-11T11:23:19Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Core`, `3rd party: OCC`, `Topic: Thickness`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=2041

* **Reporter:** @PLChris  
* **Date submitted:** 4/7/2015
* **FreeCAD version:** 0.14
* **Category:** Bug
* **Status:** confirmed
* **Tags:** #ready-for-migration, OCC Bug, upstream


# Original report text

FreeCAD crashes when applying thickness to the selected surface of a lofted part. 

<b>EDIT: Jan 23 2017</b>
Not crashing in 0.17. It shows an alert instead: <code>BRepAlgo_Image::Bind</code>

<b>EDIT: Jan 24 2017</b>
Other users are reporting that this is still a crash bug but are still using version that is inferior to OCC 7.0

<b>EDIT: Mar 25 2017</b>
Using freecad-daily with OCCT 7.1.0, no crash and no error: the Thickness completes, but the result is unchanged from the Loft (no shelling operation is done). Part Check geometry reports the solid as invalid.



# Additional information

Other members checked the error via the forum: http://forum.freecadweb.org/viewtopic.php?f=3&t=10382

Note: This ticket is being tracked via [OCC Bugs in the Bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264) forum thread

# Steps to reproduce

Open the file uploaded to the forum: http://forum.freecadweb.org/download/file.php?id=12633 , select part workbench, select the surface and click the thickness icon.
```
OS: Ubuntu 16.04.2 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.10611 (Git)
Build type: None
Branch: master
Hash: 44a9ecd25f27ec3efe52c9de9c95ef2b3e19dd17
Python version: 2.7.12
Qt version: 4.8.7
Coin version: 4.0.0a
OCC version: 7.1.0
```

# Other bug information

* **Priority:** low
* **Severity:** minor
* **Category:** Bug
* **OS: Ubuntu 14.04**
* **Platform:** Linux, Mac, Windows
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by shoogen 2015-04-08 08:21
```
pload MODELING
restore thickness-crash1-tcl-Loft001-00-section.brep Loft001-00-section
restore thickness-crash1-tcl-Loft001-01-section.brep Loft001-01-section
thrusections Loft001 1 0 Loft001-00-section Loft001-01-section
explode Loft001 F
offsetparameter 1e-7 p a
offsetload Loft001 1 Loft001_2
offsetperform Thickness
donly Thickness
```


---

### Comment by @luzpaz 2017-01-23 23:16
per @PLChris in https://forum.freecadweb.org/viewtopic.php?f=3&t=10382&start=10#p155463
> Not crashing in 0.17. It shows an alert instead: `BRepAlgo_Image::Bind.`

```
OS: Mac OS X
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.9586 (Git)
Build type: Release
Branch: (detached from 0e2cf2e)
Hash: 0e2cf2ebcaaa50723de608cf030af740cb6ad548
Python version: 2.7.13
Qt version: 4.8.7
Coin version: 3.1.3
OCC version: 7.0.0
```

---

### Comment by @luzpaz 2017-03-25 11:38
Per normandc in https://forum.freecadweb.org/viewtopic.php?f=3&t=10382&start=10#p167101
> Using freecad-daily with OCCT 7.1.0, no crash and no error: the Thickness completes, but the result is unchanged from the Loft (no shelling operation is done). Part Check geometry reports the solid as invalid.

```
OS: Ubuntu 16.04.2 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.10611 (Git)
Build type: None
Branch: master
Hash: 44a9ecd25f27ec3efe52c9de9c95ef2b3e19dd17
Python version: 2.7.12
Qt version: 4.8.7
Coin version: 4.0.0a
OCC version: 7.1.0
```

---

### Comment by @luzpaz 2017-12-06 22:27
wmayer please advise. Is this still an upstream OCC issue ?


---

### Comment by @wwmayer 2019-01-18 23:00
For me it works only when selecting Face5 (with OCCT 7.0 and 7.2). But when selecting any other face it fails and the error message is: `BRepAlgo_Image::Bind`
