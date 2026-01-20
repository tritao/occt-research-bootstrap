# #17829 — PartDesign: Chamfering end of helix-created inner thread using grove tool results in broken face

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17829`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17829
- State: `open`
- Created: `2024-11-12T23:09:14Z`
- Updated: `2025-12-06T12:49:16Z`
- Comments: `7`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Type: Has workaround`, `Status: Confirmed`, `Topic: Helix`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

When cutting end of inner threads created with helix (tapering edges) using grove, result is broken inner face inside hole.

### Full version info

```shell
OS: Windows 10 build 19045
Word size of FreeCAD: 64-bit
Version: 1.0.0RC2.38806 (Git)
Build type: Release
Branch: (HEAD detached at 1.0rc2)
Hash: 3d63fc6c2f665a8d5e6468845a419bcac80756c7
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: Polish/Poland (pl_PL)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * fasteners 0.5.30
  * OpenTheme 2024.9.1
```


### Subproject(s) affected?

PartDesign

### Anything else?

1. I created simple circle pad with hole inside
![obraz](https://github.com/user-attachments/assets/1636ad36-f311-4663-aa02-16fe93f61cc3)

2. Created ACME-like thread with helix tool
![obraz](https://github.com/user-attachments/assets/be162a32-1e84-4bc9-93ae-51a5145979a8)
![obraz](https://github.com/user-attachments/assets/7d4c8007-e79d-4475-8fce-0b27226bd992)

3. Next tried to cut one side using grove, making tapered end - and result was ok.
![obraz](https://github.com/user-attachments/assets/c8b7339d-9e93-4709-a5b7-37cf34635e14)

4. Tried to do the same on other end using mirror feature with datum plane in middle of object - results with error, broken face (selected).
![obraz](https://github.com/user-attachments/assets/34ef2656-ced7-4160-9e0c-d9c854b165b4)
![obraz](https://github.com/user-attachments/assets/35bbe4f3-4a08-44bb-8a9f-e1e2b1648135)



I've tried also making independent sketch and grove other side - but result are the same.
Sometimes with specific cutting profile, cut completes without problem, but mostly this problem exist.
When thread profile crated with helix tool does not begin at bottom of hole (eg. 1mm higher) cuts using grove ends without problem.

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
