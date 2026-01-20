# #17392 — PartDesign: Applying a pattern to a curved pipe can produce incorrect geometry (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17392`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17392
- State: `open`
- Created: `2024-10-21T19:26:50Z`
- Updated: `2025-12-06T11:14:10Z`
- Comments: `14`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Known issue`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Applying a PartDesign pattern (polar pattern, linear pattern, mirror) to a pipe can sometimes lead to incorrect geometry.

The basic shape of the additive pipe:
![BaseShape](https://github.com/user-attachments/assets/6c18d230-afd6-4422-857e-c7594370231b)
The pipe after applying a linear pattern of 40 mm overall length, 2 occurences, along the BaseX axis:
![LinearPattern](https://github.com/user-attachments/assets/7b9df368-0663-4167-b1a4-ef738c86984d)
The pipe after applying a Mirror pattern around the YZ-plane:
![Mirror](https://github.com/user-attachments/assets/f09f9781-e354-4059-9dd0-f645447b2464)
The pipe after applying a 360 deg total angle, 2 occurences Polar pattern around the base Z-axis:
![PolarPattern](https://github.com/user-attachments/assets/2ded347a-1fae-427e-ab64-6109c87ea89f)

Strangely enough, this problem does not occur if a different order is applied, where the bent section is removed from the guide-line sketch, then the pattern is applied, and then the bend section is reintroduced. In this case, instead the following (correct) result is obtained:
![PolarCorrect](https://github.com/user-attachments/assets/a2318834-61e7-4897-8c96-be98f956249f)


### Full version info

```shell
System 1:
OS: Manjaro Linux (KDE/plasma)
Word size of FreeCAD: 64-bit
Version: 1.0.0RC2.38806 (Git) AppImage
Build type: Release
Branch: (HEAD detached at 1.0rc2)
Hash: 3d63fc6c2f665a8d5e6468845a419bcac80756c7
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: C/Default (C) [ OS: English/United Kingdom (en_GB) ]
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods:
  * A2plus 0.4.68

System 2 (used for verification by running Macro's):
OS: macOS Mojave (10.14)
Word size of FreeCAD: 64-bit
Version: 1.0.0RC2.38806 (Git)
Build type: Release
Branch: (HEAD detached at 1.0rc2)
Hash: 3d63fc6c2f665a8d5e6468845a419bcac80756c7
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: C/Default (C) [ OS: C/Default (C) ]
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * Render 2024.9.25 (Disabled)
  * A2plus 0.4.68
  * Curves 0.6.50
```


### Subproject(s) affected?

PartDesign

### Anything else?

The following zip file contains both the .FCStd file, and the .FCMacro file that creates bugged geometry.
[PipeTest.zip](https://github.com/user-attachments/files/17465734/PipeTest.zip)
The following macro does successfully create the polar pattern:
[Run7.FCMacro.zip](https://github.com/user-attachments/files/17466048/Run7.FCMacro.zip)
Please note: This macro is slightly modified from a recorded macro, since the recorded macro could not be run without errors. The steps taken are the same between the original (recorded) macro, and this version.

The following file contains the .FCStd file which has the bugged geometry, as created in Release Candidate 2.
[PipeTestBugged.zip](https://github.com/user-attachments/files/17465794/PipeTestBugged.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
