# #5566 — Add visual indication (progress bar) when long tasks are performed

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5566`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5566
- State: `open`
- Created: `2022-02-07T15:50:16Z`
- Updated: `2025-06-02T21:23:46Z`
- Comments: `13`
- Labels: `Topic: User Interface`, `Type: Feature`, `3rd party: OCC`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=1176

* **Reporter:** project4
* **Date submitted:** 7/12/2013
* **FreeCAD version:** 0.13
* **Category:** Feature
* **Status:** new
* **Tags:** 


# Original report text

I think there is a need to add a visual indication when something long is done by the program (like recalculation of the whole object for example).

An icon in the status bar of the main window might be a good idea.

I didn't try to work with really complex designs yet, but was experiencing some lags already...
An indication might be a bonus to the user experience.

# Other bug information

* **Priority:** normal
* **Severity:** feature
* **Category:** Feature
* **Updated:** 2/6/2021


# Discussion from Mantis ticket

### Comment by wmayer 2013-07-12 19:49
For many operations where the number of steps is known we show a progress bar (heavily used e.g. in the Mesh module).

With OCC this is hardly possible because the algorithms there doesn't support a progress bar. The only exception I know of is the STEP/IGES importer.

As long as you don't need an animated icon this should be no problem. Otherwise all the used OCC algorithms need to be moved into worker threads.



---

### Comment by project4 2013-07-13 05:09
I don't know what OCC means, but I think if it's a long algorithm, it should be run apart from the GUI processing.
This way it might be easier to break the process into multi-thread implementation when needed, which might speed up the whole thing alot for complex parts.

My thought was to add a simple icon that changes the color when something is processing... a flashing one might be even better.
Showing a progress bar when possible is even better.


---

### Comment by wmayer 2013-07-13 08:02
OCC is the abbreviation for OpenCascade -- the CAD kernel. Unfortunately, most of the algorithms in OCC can't be multi-threaded because internally many global variables are used and thus makes it impossible in many situations to work with more than one thread.

Furthermore, threads should only be used if it's known that the operations will take a long time because spawning a thread is an expensive operation and thus should be avoided for fast operations which will take e.g. less the 1-2 sec.

A flashing icon is an absolutely no-go IMHO. Then I prefer something more decent like for example the animated icon of Firefox that appears when loading a heavy web page.


---

### Comment by project4 2013-07-13 08:42
We are talking about the same thing... Animated icon showing a progress is a very good solution.

Thanks for OCC explanation.
If it's a separate project, than someone might optimize it one day...


---

### Comment by clel 2017-01-10 15:28
If this is still relevant - another possibility would be to show a small bar moving from side to side or cycling through the progress bar.


---

### Comment by Kunda1 2018-06-12 19:36
An example of a progress bar in an FC macro can be seen in https://forum.freecadweb.org/viewtopic.php?f=22&t=28831&p=238026#p238391


---

### Comment by Kunda1 2018-09-28 00:13
Also in the Lithophane WB: https://github.com/furti/FreeCAD-Lithophane/commit/3446e5038977c53021ead4571f8a408797ea1cae
