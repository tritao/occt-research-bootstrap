# #18108 — PartDesign: Additive Helix with negative Cone Angle breaks with height over one revolution

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18108`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18108
- State: `open`
- Created: `2024-11-24T15:39:53Z`
- Updated: `2025-09-01T14:01:15Z`
- Comments: `23`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Regression`, `Status: Confirmed`, `Topic: Helix`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I am trying to edit this model in FC 1.0: https://www.printables.com/model/826091

Here is what the file looks like in 0.21.2: 
![image](https://github.com/user-attachments/assets/c947f974-9b63-4dee-b6ae-f1cfc86add12)

When opening the file in 1.0 the threads are reversed, they go down and expand outward. Also the settings of the helix:
![image](https://github.com/user-attachments/assets/a60f5635-8cdd-46b4-8981-63e8c82c50d0)

Playing around with the settings, the helix is correct up to (not including) a height of 6.0mm, which is exactly one revolution:
![image](https://github.com/user-attachments/assets/a50fc853-e2bd-4902-b32d-0d282eac90f9)



### Full version info

```shell
OS: KDE Flatpak runtime (GNOME/gnome/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Flatpak
Build type: Release
Branch: (HEAD detached at 2fcc531)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 6.7.3, Coin 4.0.3, Vtk 9.2.6, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Installed mods: 
  * fasteners 0.5.31

Also tried this on Windows, same result
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
