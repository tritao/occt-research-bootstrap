# #8176 — PartDesign: Broken (paradoxical/impossible) geometry generated via double rectangular pocket (due to elusive OCC bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#8176`
- URL: https://github.com/FreeCAD/FreeCAD/issues/8176
- State: `open`
- Created: `2023-01-12T20:06:30Z`
- Updated: `2025-02-22T07:22:43Z`
- Comments: `25`
- Labels: `Type: Bug`, `3rd party: OCC`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Forums discussion

_No response_

### Version

0.20 (Release)

### Full version info

```shell
OS: Fedora Linux 37 (Workstation Edition) (KDE/default)
Word size of FreeCAD: 64-bit
Version: 0.20.2.29603 (Git) AppImage
Build type: Release
Branch: (HEAD detached at 0.20.2)
Hash: 930dd9a76203a3260b1e6256c70c1c3cad8c5cb8
Python 3.10.8, Qt 5.15.4, Coin 4.0.0, Vtk 9.1.0, OCC 7.6.3
Locale: English/United States (en_US)
Installed mods: 
  * ExtremeProDark 2.6.4
```


### Subproject(s) affected?

PartDesign

### Issue description

Given:

1. Complex shape
2. Tapered pocket of two rectangles `Mount.Pocket003.Sketch011` generating trapezoid groove
3. Several additional transformations.
4. Same tapered pocket of two rectangles `Mount.Pocket010.Sketch032` breaking geometry completely.

Green arrows point to correct behavior, red to broken geometry. 

![image](https://user-images.githubusercontent.com/5355666/212169713-e8e2b7c3-e633-46c6-819c-da74997fc4fc.png)


### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
