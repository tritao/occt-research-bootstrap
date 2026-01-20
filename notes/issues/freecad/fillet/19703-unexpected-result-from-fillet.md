# #19703 — Unexpected result from fillet

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19703`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19703
- State: `open`
- Created: `2025-02-19T10:25:38Z`
- Updated: `2025-11-05T15:20:49Z`
- Comments: `5`
- Labels: `Type: Bug`, `3rd party: OCC`, `Status: Confirmed`, `Type: Known issue`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Tried to create fillet with 1mm between 3mm cylinder and 3mm surface, forgive my English, it is a bit hard for me to explain, but please see attached files, everything was ok until I added the edge on the other side, it looks pretty odd.

![Image](https://github.com/user-attachments/assets/45cd795e-1f7a-4beb-8f41-bc8634f822ab)

![Image](https://github.com/user-attachments/assets/7c176a0b-c820-4cb3-aa06-87544f704d29)

![Image](https://github.com/user-attachments/assets/de8cd500-68b6-4a60-9fd6-34582a30d6b7)

 Regards
Sherman

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/Australia (en_AU)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * 3DfindIT 1.2.0
  * 3D_Printing_Tools
  * A2plus 0.4.68
  * Assembly4 0.50.15
  * Curves 0.6.53
  * fcgear 1.0.0
  * lattice2 1.0.0
  * Lithophane
  * MeshRemodel 1.10.35
  * OpticsWorkbench 1.0.26
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
