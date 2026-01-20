# #19383 — Filleting on pockets on domes with flat tops is broken

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19383`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19383
- State: `open`
- Created: `2025-02-03T13:33:35Z`
- Updated: `2025-11-03T00:38:42Z`
- Comments: `2`
- Labels: `Type: Bug`, `3rd party: OCC`, `Status: Confirmed`, `Type: Known issue`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I just started and dunno the technical words so here's a pic:
![Image](https://github.com/user-attachments/assets/8fc43b2e-3070-426a-8e91-7806af803b68)
Possibly related to #17845?

To reproduce: 
1. Make a dome with a flat top, I tested revolve and filleted cylinder. Doesn't happen on fully round domes.
2. Make a pocket that touches the flat top 
![Image](https://github.com/user-attachments/assets/9a3d9456-3e9e-42e3-9b98-f017ba5ccb1d)

3. Fillet or chamfer the pocket 
![Image](https://github.com/user-attachments/assets/e9302cbb-956f-4a14-8bb5-5c386555f198)
![Image](https://github.com/user-attachments/assets/0dcc37b1-4b89-434a-9829-f9de4746305b)

### Full version info

```shell
OS: Arch Linux (xcb)
Architecture: x86_64
Version: 1.0.0.39109 (Git)
Build type: Release
Branch: makepkg
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.13.1, Qt 6.8.2, Coin 4.0.3, Vtk 9.4.1, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
```

### Subproject(s) affected?

PartDesign

### Anything else?

here's 3 examples

[filletbug0.zip](https://github.com/user-attachments/files/18642778/filletbug0.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
