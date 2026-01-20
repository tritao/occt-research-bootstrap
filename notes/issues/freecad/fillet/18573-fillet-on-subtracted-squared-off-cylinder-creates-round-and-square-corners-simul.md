# #18573 — Fillet on subtracted squared off cylinder creates round and square corners simultaneously

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18573`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18573
- State: `open`
- Created: `2024-12-17T12:57:21Z`
- Updated: `2025-12-18T22:15:31Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Has workaround`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

As I subrtracted a square off a cylinder on the middle axis and tried to add a fillet on the resulting edges, the corners of the fillet became weird as you can see in the picture. Find the file attached. 
![image](https://github.com/user-attachments/assets/838208bc-155a-40a2-aacd-813a757a9844)
[Fillet_Cylinder.zip](https://github.com/user-attachments/files/18165755/Fillet_Cylinder.zip)

I would prefer to have only edged corners. It is reproduceable. 
Is there a solution for that? 

### Full version info

```shell
OS: Debian GNU/Linux 12 (bookworm) (GNOME/gnome/xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: German/Germany (de_DE)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * Assembly3 0.12.2
  * InventorLoader 1.4.0
  * CAM
  * Manipulator 1.5.7
  * Curves 0.6.45
  * sheetmetal 0.4.24
  * fasteners 0.5.18
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
