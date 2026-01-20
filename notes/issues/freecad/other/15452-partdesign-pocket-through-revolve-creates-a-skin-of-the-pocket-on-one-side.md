# #15452 — PartDesign: Pocket through revolve creates a "skin" of the pocket on one side

- Repo: `FreeCAD/FreeCAD`
- Issue: `#15452`
- URL: https://github.com/FreeCAD/FreeCAD/issues/15452
- State: `open`
- Created: `2024-07-15T22:48:28Z`
- Updated: `2025-10-07T00:26:50Z`
- Comments: `10`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

When pocketing a circle through a revolve it produces an 'extruded skin' on one side of the pocket.
I tried with a second body, creating pad of a circle, and pocketing another sketch through it and it worked okay.


### Full version info

```shell
OS: Linux Mint 21 (MATE/mate)
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.38127 (Git) AppImage
Build type: Release
Branch: main
Hash: 9868533d8d0ef1f569cbde538b7a31350db503bd
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: English/New Zealand (en_NZ)
Installed mods: 
  * Help 1.0.3
  * fcgear 1.0.0
  * ExplodedAssembly
  * Curves 0.6.41
  * lattice2 1.0.0
  * FeedsAndSpeeds 0.5.0
  * sheetmetal 0.2.59
  * InventorLoader 1.4.0
```


### Subproject(s) affected?

None

### Anything else?

**ReportView**
10:18:57  Cannot find icon: Sketcher_Pointer_Create_Ellipse
10:19:17  Reading failed from embedded file: StringHasher.Table.txt (1403 bytes, 293 bytes compressed)
10:19:17  <ElementMap> <string>(1): No hasherRef
10:19:17  <ElementMap> <string>(1): No hasherRef
10:19:17  <ElementMap> <string>(1): No hasherRef
10:19:17  <ElementMap> <string>(1): No hasherRef
10:19:17  <ElementMap> <string>(1): No hasherRef

**PythonConsole - I replaced hash with H so the formatting stays sensible**
Python 3.11.9 | packaged by conda-forge | (main, Apr 19 2024, 18:53:30) [GCC 12.3.0] on linux
Type 'help', 'copyright', 'credits' or 'license' for more information.
>>> H Gui.runCommand('Std_Workbench',1)
>>> H Gui.runCommand('Std_ViewStatusBar',1)
>>> HHH Begin command Std_Open
>>> FreeCAD.openDocument('/home/mee-cee/Documents/3D Printing/FreeCad/SinkPlug.FCStd')
>>> H App.setActiveDocument("SinkPlug")
>>> H App.ActiveDocument=App.getDocument("SinkPlug")
>>> H Gui.ActiveDocument=Gui.getDocument("SinkPlug")
>>> HHH End command Std_Open
>>> H Gui.runCommand('Std_About',0)
>>> 
[plug.zip](https://github.com/user-attachments/files/16241049/plug.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
