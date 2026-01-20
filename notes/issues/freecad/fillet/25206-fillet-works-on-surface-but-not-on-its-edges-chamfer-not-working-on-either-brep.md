# #25206 — Fillet works on surface but not on its edges - chamfer not working on either - BRep_API: Command not done

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25206`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25206
- State: `open`
- Created: `2025-11-10T09:09:08Z`
- Updated: `2025-11-11T19:06:50Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Known issue`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

When trying to apply any fillet or chamfer to the inner edges of this model, the operation fails with BRep_API: Command not done error. However, if using the inner surfaces of the model, the fillet operation succeeds, though the chamfer still fails.

<img width="1729" height="1585" alt="Image" src="https://github.com/user-attachments/assets/3c4e5780-39da-43f9-81fa-d215210d07a2" />

<img width="1945" height="1627" alt="Image" src="https://github.com/user-attachments/assets/83f17abb-5a80-479c-9f05-bb66425cd54f" />

<img width="1729" height="1585" alt="Image" src="https://github.com/user-attachments/assets/bcac0fd9-97bc-4d55-8335-e4b5d6b7925d" />

Even though the fillet succeeds, it creates a strange artifact on the top left junction between faces:

<img width="3458" height="3170" alt="Image" src="https://github.com/user-attachments/assets/3ffe1ed0-10cb-4f27-ae3e-ac9d24c158a0" />

<img width="1729" height="1585" alt="Image" src="https://github.com/user-attachments/assets/3d1a75a7-c7f6-49d4-9fa9-d2fa6938a5a0" />

The fillet also cannot be extended to more than 1.4mm, though a larger filet should be possible considering the size of the supporting surfaces.

### Full version info

```shell
OS: CachyOS (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.0.2.39319 (Git)
Build type: Release
Branch: makepkg
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.13.7, Qt 6.10.0, Coin 4.0.5, Vtk 9.5.2, OCC 7.9.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Installed mods: 
  * freecad.gears 1.3.0
  * ThreadProfile 1.97.0
  * Defeaturing 1.2.9
```

### Subproject(s) affected?

PartDesign

### Anything else?

Model file:
[model_chamfer_issue.zip](https://github.com/user-attachments/files/23449721/model_chamfer_issue.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
