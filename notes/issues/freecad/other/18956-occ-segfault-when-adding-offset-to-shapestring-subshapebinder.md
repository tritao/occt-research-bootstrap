# #18956 — OCC: Segfault when adding offset to shapestring subshapebinder

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18956`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18956
- State: `open`
- Created: `2025-01-08T19:52:54Z`
- Updated: `2025-11-19T18:33:24Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Topic: Shapebinder`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I wanted to offset a ShapeString, but it resulted in a segfault. To reproduce:

1. Part Design: Create Body and Sketch, draw a simple rectangle and create a Pad
2. Draft: add ShapeString, place it on the Pad
3. Part Design: Create a SubShapeBinder of the ShapeString, which brings Binder object inside Body
4. Try to add 1mm offset in Binder -> Data -> Offset. This reports a segfault in the console of FreeCAD
5. Set offset back to 0mm, and then try to set it to 1mm again. Now FreeCAD crashes completely.

Attaching segfault.FCSTD, which is ready for step 4. Just set offset to 1, then 0, and then 1 again.

Discovered in FreeCAD v1.0.0, reproduced in latest weekly build.




### Full version info

```shell
OS: Ubuntu 22.04.5 LTS (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.1.0dev.39786 (Git) Conda AppImage
Build type: Release
Branch: main
Hash: 013eb6e6353ab6e5077ab4696653c9b493442638
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/unset/Qt default
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
