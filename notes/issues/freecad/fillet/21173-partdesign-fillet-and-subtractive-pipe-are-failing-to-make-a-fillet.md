# #21173 — PartDesign: Fillet and Subtractive Pipe are failing to make a fillet.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21173`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21173
- State: `open`
- Created: `2025-05-06T19:52:43Z`
- Updated: `2026-01-08T17:44:17Z`
- Comments: `18`
- Labels: `Type: Bug`, `Mod: Part Design`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I have this simple but irregular shape that I am failing to add a fillet.
File: [test_Body_top_fillet.FCStd.zip](https://github.com/user-attachments/files/20070769/test_Body_top_fillet.FCStd.zip)

Side view

![Image](https://github.com/user-attachments/assets/7120fe1f-e62c-40e6-8eed-4cc70b81a372)

Front view

![Image](https://github.com/user-attachments/assets/daeacab9-d8a5-4fc9-9acd-8356b76564db)

I want to make a fillet around this highlight edge..

![Image](https://github.com/user-attachments/assets/49c81581-82d5-4d26-be74-545037a9ce12)

The fillet tool is not working, no matter the radius of the fillet.

The Subtractive Pipe tool with something like this is also failing.

![Image](https://github.com/user-attachments/assets/703eff38-6eac-4318-aa47-6c793b2d9b97)

![Image](https://github.com/user-attachments/assets/bcea286d-d446-4c46-942d-dbf5de1c883e)

It is doing something, but not the right thing, see.

![Image](https://github.com/user-attachments/assets/10049e76-2b84-4b0a-8706-3aaf19e1f3c8)

I don't even have the "Allow multiple solidis" enabled in the settings.

![Image](https://github.com/user-attachments/assets/305e04bc-d816-4322-8d45-f8ad56dc5569)

To make it simpler, I am not even using a complicated path for the pipe tool
I am using this flat square with rounded corners.

![Image](https://github.com/user-attachments/assets/bad343ba-f3fd-42f0-8382-0214ab5882db)


Is it a bug?
Is there any workaround that I can use to make this filet?


### Full version info

```shell
OS: Ubuntu 25.04 (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.41573 (Git)
Build date: 2025/05/05 17:45:01
Build type: Release
Branch: main
Hash: 3189030c11010631e726dbe350e9077dc84109bb
Python 3.11.12, Qt 6.7.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 
shiboken , xerces-c 3.2.5, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/
Logical DPI/Physical DPI/Pixel Ratio: 96/145.143/1
Installed mods: 
  * Assembly4 0.50.19-dev
  * sheetmetal 0.7.22
  * DynamicData 2.74.0
  * Curves 0.6.61
  * InventorLoader 1.5.1
  * diff-tools 0.1.0
  * ose-piping
  * OpenTheme 2024.9.1
  * fasteners 0.5.38
  * Curves.backup1746105636.3777354 0.6.60 (Disabled)
  * osh-autodoc-workbench 0.2.3
  * OpticsWorkbench 1.2.0
  * lattice2 1.0.0
  * kicadStepUpMod 11.6.9
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
