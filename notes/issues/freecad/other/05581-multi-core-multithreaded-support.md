# #5581 — Multi-core/Multithreaded support

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5581`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5581
- State: `open`
- Created: `2022-02-07T15:51:44Z`
- Updated: `2025-05-19T12:09:07Z`
- Comments: `37`
- Labels: `Mod: Core`, `Type: Feature`, `3rd party: OCC`, `Help wanted`, `Topic: Performance`, `no-auto-close`
- Assignees: `tritao`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=1415

* **Reporter:** Pauvres_honteux
* **Date submitted:** 2/16/2014
* **FreeCAD version:** 
* **Category:** Feature
* **Status:** new
* **Tags:** multithreading


# Original report text

Hi, I'm not sure if FC currently is utilizing multiple cores/threads simultaneously, but it would be of huge benefit for the future when one could, at least in theory, move a feature (point, line, plane) in the resulting body and see the whole result updated in real time.

E.G. a casting whos shape depends upon an irregular hole pattern.
Or upon step changing a common draft angle parameter reflects its impact in real time.
Or moving holes and depressions in sheet metal and see the result in real time really enhances your understanding of that specific part you're working on.

And your customers will get a better understanding of how a particular change/demand will impact the end result which in the end cut costly time - a lot.

Regards Pauvres_honteux

# Additional information

Had this in the "Open discussion" before but it was apparently the wrong place.

# Other bug information

* **Priority:** normal
* **Severity:** minor
* **Category:** Feature
* **Updated:** 2/6/2021


# Discussion from Mantis ticket

### Comment by Pauvres_honteux 2014-02-23 18:22
This might be a starting point for learning parallel computing?
http://www.parallella.org/Introduction/

Regards Pauvres_honteux



---

### Comment by wmayer 2014-02-23 20:40
For parallel computing Qt already offers e.g. the (low-level) QThread class, QThreadPool or the high-level API QtConcurrent which we make use here and there.

The problem is not that we don't know how to parallelize it's more the lack of OCC to support it. At the moment there are only a few algorithms that are ready to use in separate threads.


---

### Comment by shoogen 2014-05-18 16:46
One improvemnt would be, that a recompute only blocks when applying changes to the GUI (changing QT elements or the scenegraph) and not while performing computations inside OCCT.


---

### Comment by Pauvres_honteux 2014-05-19 02:52
Hi Shoogen, I get a feeling there's a vital word (for me) missing in your comment [~4690] "...only blocks when applying..." ? Should there have been a word before or after "blocks" ?




---

### Comment by wbraun 2014-07-31 08:24
From my experience in an engineering company routinely working with complex models containing many parts, I strongly support parallel processing. The commercial CAD systems I know are all more or less single threaded Windows applications. As Processors these days no longer get faster, but have more cores instead, the only way to significantly improve productivity of CAD when working with complex projects seems to be to go parallel.
With Linux effortlessly scaling from an Arduino to supercomputers and an eight core workstation being available for 500 €, a truly parallel computing CAD system running on Linux could be a killer.
My experience with the commercial systems was that upgrading a several year old version on several year old PCs to the current version with carefully single-thred-performance-optimized PCs did not result in a noticeable performance increase. Loading and processing times of complex assemblies remained unchanged. A huge investment for nothing and very frustrating.




---

### Comment by Kunda1 2017-02-02 01:07
Linked https://tracker.freecad.org/view.php?id=2750
