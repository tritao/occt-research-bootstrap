# #23498 — CAM: CAMTests.TestPathOpUtil.TestPathOpUtil.test46 / test47 fail with OCC 7.9.1 and 7.9.2

- Repo: `FreeCAD/FreeCAD`
- Issue: `#23498`
- URL: https://github.com/FreeCAD/FreeCAD/issues/23498
- State: `open`
- Created: `2025-08-31T11:20:55Z`
- Updated: `2025-12-02T23:28:59Z`
- Comments: `10`
- Labels: `Mod: CAM`, `3rd party: OCC`, `Mod: Test`, `Type: Regression`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

```
[   41s] ERROR: test46 (CAMTests.TestPathOpUtil.TestPathOpUtil.test46)
[   41s] Check offsetting multiple inside edges.
[   41s] ----------------------------------------------------------------------
[   41s] Traceback (most recent call last):
[   41s]   File "/usr/lib64/FreeCAD/Mod/CAM/CAMTests/TestPathOpUtil.py", line 795, in test46
[   41s]     wire = PathOpUtil.offsetWire(Part.Wire(lEdges), obj.Shape, 2, True)
[   41s]   File "/usr/lib64/FreeCAD/Mod/CAM/Path/Op/Util.py", line 348, in offsetWire
[   41s]     debugWire("outside", Part.Wire(outside))
[   41s]                          ~~~~~~~~~^^^^^^^^^
[   41s] Part.OCCError: BRep_API: command not done
[   41s] 
[   41s] ======================================================================
```
Likewise for test47

I have debugged the issue to some degree, see screenshot:

<img width="1223" height="872" alt="Image" src="https://github.com/user-attachments/assets/e5ddb3de-3af3-4b24-b5c4-5b6beb322901" />

The screenshot shows the original shape, the `common` wire (last==6th segment green), and one of the original, oriented, segments (`owire`) in yellow (remaining `owire` segments hidden).

So for, this seems correct.

Due to the `isInside` check:  
https://github.com/FreeCAD/FreeCAD/blob/3b76d77ed8ab31ffeca69064e2925f17774f087c/src/Mod/CAM/Path/Op/Util.py#L337

the yellow highlighted `owire` segment would be omitted from the `outside` wire list, as one of its vertices coincedes with the `common` vertices. The same is true for all other wires of `owire`.

The resulting `outside` list is empty, and `Part.Wire(outside)` ^= `Part.Wire([])` then trows the OCC exception.

### Full version info

```shell
OS: openSUSE Tumbleweed (KDE/plasmawayland/wayland)
Architecture: x86_64
Version: 1.0.2.Unknown
Build type: Release
Python 3.13.5, Qt 6.9.1, Coin 4.0.3, Vtk 9.4.1, OCC 7.9.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/breeze
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
