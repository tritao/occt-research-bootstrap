# #22652 — Sketcher: Offset creating extra lines and points

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22652`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22652
- State: `open`
- Created: `2025-07-21T19:53:35Z`
- Updated: `2025-10-19T14:39:22Z`
- Comments: `5`
- Labels: `Status: Needs confirmation`, `Mod: Sketcher`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

When offsetting a single line I end up with the closed loop as previously reported (#13367). I also get split lines as shown on the screenshot below. New points (red dots) appear on the newly offsetted vertical lines indicating that two lines were created on each side. I expected only one line per side and the arcs, top and bottom. Please advise.

<img width="314" height="410" alt="Image" src="https://github.com/user-attachments/assets/b407bf0e-674b-48bf-bac1-12a9ea5ffda4" />

### Full version info

```shell
OS: Ubuntu 24.04.2 LTS (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.0.1.39285 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.1)
Hash: 878f0b8c9c72c6f215833a99f2762bc3a3cf2abd
Python 3.11.12, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
