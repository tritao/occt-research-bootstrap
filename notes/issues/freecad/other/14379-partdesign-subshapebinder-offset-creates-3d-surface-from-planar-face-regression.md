# #14379 — PartDesign: Subshapebinder offset creates 3D surface from planar face (Regression)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#14379`
- URL: https://github.com/FreeCAD/FreeCAD/issues/14379
- State: `open`
- Created: `2024-05-29T22:51:36Z`
- Updated: `2025-12-10T00:11:01Z`
- Comments: `19`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part Design`, `Type: Regression`, `Status: Confirmed`, `Topic: Shapebinder`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Adding an offset value on a subshape binder produces an unexpected result.  FreeCAD file attached.

Here's the subshape binder initially (bound to the face of the body:
![image](https://github.com/FreeCAD/FreeCAD-Bundle/assets/51497368/6d052df5-c691-4c9d-8c4b-e77bff683358)

And here it is after applying a 1mm offset:
![image](https://github.com/FreeCAD/FreeCAD-Bundle/assets/51497368/01d9f635-df7c-4399-8341-e073c3b15184)


### Full version info

```shell
Using 0.22 dev build, full details below:
OS: Windows 11 build 22631
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.37543 (Git)
Build type: Release
Branch: main
Hash: 3eb45b045cdda9d5bfe11baba2567a1df90f064c
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: English/Australia (en_AU)
Installed mods: 
  * A2plus 0.4.60n
  * A2plus.backup1693449725.06262 (Disabled)
  * Curves 0.6.13
  * Curves.backup1693449730.5624967 0.6.13 (Disabled)
  * Defeaturing 1.2.0
  * Defeaturing.backup1693449735.7019093 (Disabled)
  * fasteners.backup1695592281.051254 0.4.63 (Disabled)
  * Manipulator 1.5.0
```


### Subproject(s) affected?

None

### Anything else?

[SubshapebinderOffset.zip](https://github.com/FreeCAD/FreeCAD/files/15491563/SubshapebinderOffset.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
