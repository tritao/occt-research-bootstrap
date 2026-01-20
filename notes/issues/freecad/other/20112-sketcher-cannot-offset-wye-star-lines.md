# #20112 — Sketcher: cannot offset wye/star lines

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20112`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20112
- State: `open`
- Created: `2025-03-10T18:09:49Z`
- Updated: `2025-03-10T18:59:57Z`
- Comments: `0`
- Labels: `Type: Feature`, `Mod: Sketcher`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Draw 3 lines connected at a point:

![Image](https://github.com/user-attachments/assets/28393f4a-a034-49c4-9b77-701fddb06643)

With them all selected, use Sketcher_offset, but the result only uses one line segment:
![Image](https://github.com/user-attachments/assets/d773a5a0-c55b-46c4-813d-b331bd348ea1)

I expected to get a shape like the following in one step:
![Image](https://github.com/user-attachments/assets/638d0d23-5727-4d76-b216-099c14bf8eb6)

Another workaround is to double up the lines as in screenshot below. The skeleton lines must not intersect and the quasi-repeated points in the middle have to be close but not coincident. 
![Image](https://github.com/user-attachments/assets/4b5f3c6d-f227-44ad-9919-6eb220b510bb)

### Full version info

```shell
OS: Debian GNU/Linux trixie/sid (default/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/Canada (en_CA)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Qt default
Installed mods: 
  * CfdOF 1.29.4
  * sheetmetal 0.6.13
```

### Subproject(s) affected?

Sketcher

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
