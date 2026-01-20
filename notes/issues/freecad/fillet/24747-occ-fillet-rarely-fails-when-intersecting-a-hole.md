# #24747 — OCC: Fillet rarely fails when intersecting a hole

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24747`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24747
- State: `open`
- Created: `2025-10-19T19:45:12Z`
- Updated: `2025-11-19T22:41:03Z`
- Comments: `1`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

<img width="1981" height="943" alt="Image" src="https://github.com/user-attachments/assets/3eec8181-7bbf-4f01-b4fc-1a0f7365243c" />
The selected face shows the fault created by the fillet. It should look like the other bow tie.
This causes the entire section to be missing when slicing. The bug only starts to occur with a large fillet radius ( ~7.60mm)

This only occurs on 1 of 6*4 Pockets. So there might be something very odd going on. The broken hex is on camera 0 the second from the top in the center.

In case that is relevant: putting a little fillet on all edges also returned an access violation error. A restart and recompute did not change behavior

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/Fusion
```

### Subproject(s) affected?

PartDesign

### Anything else?

[bottleHolderBuggyFillet.zip](https://github.com/user-attachments/files/22992281/bottleHolderBuggyFillet.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
