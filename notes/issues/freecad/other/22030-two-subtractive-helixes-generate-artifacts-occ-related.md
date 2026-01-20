# #22030 — Two subtractive helixes generate artifacts (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22030`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22030
- State: `open`
- Created: `2025-06-17T03:47:57Z`
- Updated: `2025-12-07T17:40:17Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I'm trying to generate a self reversing screw using two subtractive helixes, but it seems that this particular set of steps is triggering errors in the model with multiple `Refine failed: Removing splitter failed` messages and the model with artifacts. Messing around with the height parameter of the failing helix sometimes improve the model, but its not predictable what or when it will break.

Disabling the **refine checkbox** in the Helix panel did not improve the situation. 

Link to sample file: https://www.dropbox.com/scl/fi/jmzh90ghnhma2qt8t8jqf/self_reversing_test.FCStd

![Image](https://github.com/user-attachments/assets/a939ae63-2953-441b-8899-2cdca0c47c8e)


### Full version info

```shell
OS: macOS 15.5
Architecture: arm64
Version: 1.0.1.39285 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.1)
Hash: 878f0b8c9c72c6f215833a99f2762bc3a3cf2abd
Python 3.11.12, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: C/Default (C)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * freecad.gears 1.3.0
  * fasteners 0.5.38
```

### Subproject(s) affected?

None

### Anything else?

[self_reversing_test.FCStd.zip](https://github.com/user-attachments/files/20767784/self_reversing_test.FCStd.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
