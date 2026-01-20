# #18735 — Core: STEP File Import Takes Excessive Time

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18735`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18735
- State: `open`
- Created: `2024-12-26T10:19:18Z`
- Updated: `2025-11-06T12:25:20Z`
- Comments: `25`
- Labels: `Type: Bug`, `Mod: Core`, `3rd party: OCC`, `File format: STEP`, `Status: Confirmed`, `Help wanted`, `Topic: Helix`, `Topic: Performance`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

The issue lies in the performance of importing STEP files.
I tested it in SolidWorks, and the attached file is imported in 1 minute, with a dialog window accompanying the process.

In FreeCAD, it takes 1 hour!! , and the software seems to freeze during the operation.

Additionally, after importing the file, if I save it in FreeCAD format, it takes a very long time to open again when I try to load it.

This is important to resolve as it is a key factor preventing a transition to FreeCAD.

Exemple: Reading Step File from Solidowrks
![image](https://github.com/user-attachments/assets/996f776f-26a4-4876-82b8-8accd4056f0d)

Import STEP FILE to test:
[EixoY.zip](https://github.com/user-attachments/files/18251682/EixoY.zip)

Model Imported: 
![image](https://github.com/user-attachments/assets/40633e9e-d932-4ff9-b246-08b3fc45e8ff)




### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.39708 (Git) Conda
Build type: Release
Branch: main
Hash: 173ff4da1ef4f075d56c0dc617d1bf00d5f49d4b
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: Portuguese/Portugal (pt_PT)
Stylesheet/Theme/QtStyle: OpenLight.qss/OpenLight/Fusion
Installed mods: 
  * OpenTheme 2024.9.1
  * sheetmetal 0.5.6
```


### Subproject(s) affected?

File formats

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
