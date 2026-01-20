# #18058 — Part: Refine breaks intersection curves

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18058`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18058
- State: `open`
- Created: `2024-11-22T05:41:08Z`
- Updated: `2025-09-11T18:20:02Z`
- Comments: `8`
- Labels: `Type: Bug`, `Mod: Part`, `Status: Needs feedback`, `Status: Confirmed`, `Status: Needs diagnosis`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I have experienced this issue many times during a project. What happens is that "refine" breaks the model very often for example at intersection of features, for example when two tubes intersect or when a tube and and additive pipe intersect and other similar situations. It doesn't seem to be able to manage curves on surfaces. Disabling refine on all features solves the problem despite not having clean surfaces anymore. 
![image](https://github.com/user-attachments/assets/5cd53ccf-1c9d-4d3d-9dc7-d26931e99ce8)

I attach an example file that has refine enabled. 
You can use the "check geometry" tool in the part design WB to  see lots of "Boolean operation: invalid curve on surface".
[refine.zip](https://github.com/user-attachments/files/17863439/refine.zip)
This holds true also for lastest devs.

### Full version info

```shell
OS: Ubuntu 24.10 (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * Curves 0.6.51
  * Estimate 0.1.2
  * fasteners 0.5.29
  * A2plus 0.4.68
```


### Subproject(s) affected?

None

### Anything else?

Here is the project I was working on and had plenty of these issues.
https://forum.freecad.org/viewtopic.php?p=793207#p793207

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
