# #17338 — Part: Boolean Union / Fusion fills spaces where no part exists

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17338`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17338
- State: `open`
- Created: `2024-10-19T11:52:14Z`
- Updated: `2025-02-22T07:13:16Z`
- Comments: `12`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Known issue`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

On the Part workbench, doing a simple Boolean fusion between two valid solid shapes results in a union that has filled in regions where none of the shapes contain solid areas. See example where thread gaps are filled in after union of thread with solid cylinder.

![UnionProblem](https://github.com/user-attachments/assets/a9661ea7-8c66-4dfd-8be1-2fa41b99130a)

This problem only occurred with transition to v.1.0 RC - it does not happen with v0.2.

Here is a link to the FreeCAD file in case you wish to confirm the problem:

[Thread_Union_Test_FreeCAD_File ](https://drive.google.com/file/d/13kxA1OhlJIx_qQGXIUhFUd49cRi0nXWD/view?usp=sharing)

Details: Part -> Check Geometry on the thread component shows no invalid components and the Sketch is fully constrained (also, this union worked perfectly well with older versions of FreeCAD).
No errors, warnings or messages in the Report View.

Comment: Please note. I am aware that there may well be many alternative or even 'better / more correct' ways of making a solid thread than fusing a cylinder with a sweep solid but this is how I do it (and have hundreds of these in my PUMA model files which all worked fine till RC1.0 so it would be impractical to go back and re-do them all in some alternative way).
The issue is one of the Boolean operation not working as expected rather than how to achieve the specific shape illustrated in the example given. Also, I am aware that the cylinder intersects the thread at the periphery - but this is deliberate - and worked fine in all previous versions of FreeCAD - as a Boolean Union of two solids would be expected to work. Thanks.


### Full version info

```shell
OS: Arch Linux (LXDE/LXDE)
Word size of FreeCAD: 64-bit
Version: 1.0.0RC2.38806 (Git)
Build type: Release
Branch: makepkg
Hash: 3d63fc6c2f665a8d5e6468845a419bcac80756c7
Python 3.12.7, Qt 6.8.0, Coin 4.0.3, Vtk 9.3.1, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Installed mods: 
  * fasteners 0.5.29
  * OpticsWorkbench 1.0.24
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
