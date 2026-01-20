# #23765 — Pocket: Null shape .  On Thickness  use

- Repo: `FreeCAD/FreeCAD`
- Issue: `#23765`
- URL: https://github.com/FreeCAD/FreeCAD/issues/23765
- State: `open`
- Created: `2025-09-09T07:37:14Z`
- Updated: `2025-09-11T12:52:06Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Error:   Pocket: Null shape

1. Create restangle  on XY plane
2.  Create  Pad  with  -2 taper angle
3. Create Thickness  from XY side  ( 2 mm  to outwars)
4. Create Sketch on side
5.  Try to use Pocket

https://github.com/user-attachments/assets/9f3d6432-fd0f-4ec6-8551-d5a444895658

### Full version info

```shell
OS: Linux Mint 22.1 (X-Cinnamon/cinnamon/xcb)
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: Russian/Russia (ru_RU)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * fasteners 0.5.38
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
