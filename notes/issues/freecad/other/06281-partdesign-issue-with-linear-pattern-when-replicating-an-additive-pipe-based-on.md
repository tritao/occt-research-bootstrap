# #6281 — PartDesign: Issue with Linear Pattern when replicating an Additive Pipe based on an elliptical path

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6281`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6281
- State: `open`
- Created: `2022-02-07T21:56:12Z`
- Updated: `2025-12-25T00:29:47Z`
- Comments: `12`
- Labels: `Type: Bug`, `Mod: Core`, `Mod: Part Design`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=4781

* **Reporter:** @vectronic
* **Date submitted:** 11/8/2021
* **FreeCAD version:** 0.2
* **Category:** Bug
* **Status:** new
* **Tags:** Part Design


# Original report text

I am trying to use Linear Pattern to duplicate a flange on a pin. The flange is created using an additive pipe which uses a path sketch involving an ellipse.

This doesn't work.

I have queried in the forum to see if this was:

- a known bug (doesn't seem to be)
- more experienced users can get it to work (they can't)
- more experienced users thought it might be a bug (they do)

Forum link: https://forum.freecadweb.org/viewtopic.php?f=3&t=63409

I have taken my sample from the forum, improved it based on their feedback and simplified it a lot more. I have also included a comparison of using a circle (instead of an ellipse) for the additive pipe path and this seems to work fine with the linear pattern feature.


In the linear-pattern-attempt-1.FCStd you will see:


* attempt-1-01.png : Linear pattern of a pin and a flange based on a circular path is rendered.
* attempt-1-02.png : Another flange based on an elliptical path is added to the first pin.
* attempt-1-03.png : When another linear pattern for the elliptical flange is added, the result is not as expected.





In the linear-pattern-attempt-2.FCStd you will see:


* attempt-2-01.png : A pin with a circular flange and elliptical flange is created first.
* attempt-2-02.png : If I try to create a linear pattern involving all of these at once (the pin, the circular flange and the elliptical flange) the linear pattern dialog displays an unexpected error.
* attempt-2-03.png : The final result is not as expected.




# Additional information

~Screenshots: https://f001.backblazeb2.com/file/vectronic-public/freecad/screenshots.zip~
**attempt-1-01**
<img width="902" alt="attempt-1-01" src="https://user-images.githubusercontent.com/4140247/159126807-afbb2a82-bae3-416f-afc4-9a2775de73c0.png">

**attempt-1-02**
<img width="905" alt="attempt-1-02" src="https://user-images.githubusercontent.com/4140247/159126809-0f53fbce-5c13-4a58-8f36-022c88db882a.png">

**attempt-1-03**
<img width="903" alt="attempt-1-03" src="https://user-images.githubusercontent.com/4140247/159126810-969aef50-4acf-458a-9d90-880a499522cd.png">

**attempt-2-01**
<img width="997" alt="attempt-2-01" src="https://user-images.githubusercontent.com/4140247/159126811-72cae113-5c9b-4b7e-9dfa-0605ab6932a8.png">
**attempt-2-02**
<img width="1322" alt="attempt-2-02" src="https://user-images.githubusercontent.com/4140247/159126813-61230e7b-62fa-45a6-a7d5-1bf55687e865.png">

**attempt-2-03**
<img width="1018" alt="attempt-2-03" src="https://user-images.githubusercontent.com/4140247/159126816-38638eaa-8eef-4224-ae22-718d7eddd6ee.png">


~Sample models: https://f001.backblazeb2.com/file/vectronic-public/freecad/models.zip~
[models.zip](https://github.com/FreeCAD/FreeCAD/files/8309521/models.zip)


# Steps to reproduce

Open the linear-pattern-attempt-1.FCStd file and observe that:

- the linear pattern using the feature of an additive pipe based on a circle path sketch IS rendered.
- the linear pattern using the feature of an additive pipe based on an ellipse path sketch IS NOT rendered.

OR

Open the linear-pattern-attempt-2.FCStd file and observe that the linear pattern including both additive pipes is rendered incorrectly.sketch is not rendered.


# FreeCAD Info

```
OS: macOS 10.16
Word size of FreeCAD: 64-bit
Version: 0.20.Unknown
Build type: Release
Python version: 3.9.7
Qt version: 5.12.9
Coin version: 4.0.0
OCC version: 7.5.3
Locale: C/Default (C)

```

# Other bug information

* **Priority:** normal
* **Severity:** major
* **Category:** Bug
* **OS: MacOS 11.6**
* **Platform:** Intel
* **Updated:** 11/8/2021
