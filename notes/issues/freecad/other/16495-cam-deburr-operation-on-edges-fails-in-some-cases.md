# #16495 — CAM: Deburr operation on edges fails in some cases

- Repo: `FreeCAD/FreeCAD`
- Issue: `#16495`
- URL: https://github.com/FreeCAD/FreeCAD/issues/16495
- State: `open`
- Created: `2024-09-12T22:40:23Z`
- Updated: `2025-08-24T15:48:33Z`
- Comments: `9`
- Labels: `Type: Bug`, `Mod: CAM`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

The deburr operation fails when used on edges in some specific cases. I could not figure out what exactly causes the failure. In the attached sample file [cam_deburr_issue.zip](https://github.com/user-attachments/files/16986044/cam_deburr_issue.zip) I'm trying to deburr a simple edge consisting of two ellipse arcs joined by a straight line. All lines are on z=0. Not sure what else to check...

The issue is quite annoying because in some cases it works and changing a minor detail on the model suddenly causes the failure. Here is the error log:

```00:41:28  pyException: Traceback (most recent call last):
  File "/usr/lib/freecad/Mod/CAM/PathScripts/PathUtils.py", line 70, in new_function
    res = function(*args, **kwargs)
          ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/usr/lib/freecad/Mod/CAM/Path/Op/Base.py", line 788, in execute
    result = self.opExecute(obj)
             ^^^^^^^^^^^^^^^^^^^
  File "/usr/lib/freecad/Mod/CAM/Path/Op/Deburr.py", line 380, in opExecute
    wire = PathOpUtil.offsetWire(w, base.Shape, offset, True, side)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/usr/lib/freecad/Mod/CAM/Path/Op/Util.py", line 395, in offsetWire
    debugWire("left", Part.Wire(leftSideEdges))
                      ^^^^^^^^^^^^^^^^^^^^^^^^
<class 'Part.OCCError'>: BRep_API: command not done
00:41:28  Deburr: BRep_API: command not done
```


### Full version info

```shell
OS: Arch Linux (KDE/plasma)
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.38402 (Git)
Build type: Release
Branch: main
Hash: 441fbdd064796fb412e35287a532d7fa98b6449e
Python 3.12.5, Qt 6.7.2, Coin 4.0.2, Vtk 9.3.1, OCC 7.8.1
Locale: English/United States (en_US) [ OS: English/United States (en_US) ]
Installed mods: 
  * kicadStepUpMod 11.2.7
  * dodo 1.0.1
  * sheetmetal 0.4.24
  * fcgear 1.0.0
  * fasteners 0.5.27
  * Assembly4 0.50.15
  * Curves 0.6.45
  * lattice2 1.0.0
```


### Subproject(s) affected?

CAM

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
