# #16654 — Part: Fillet fails on refined shape, where it succeeds on same edges before refinement

- Repo: `FreeCAD/FreeCAD`
- Issue: `#16654`
- URL: https://github.com/FreeCAD/FreeCAD/issues/16654
- State: `open`
- Created: `2024-09-19T06:22:48Z`
- Updated: `2025-11-25T14:33:24Z`
- Comments: `8`
- Labels: `Type: Bug`, `Mod: Part`, `Type: Known issue`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

The fillet fails if the same edges are picked on the refined shape. I believe this is a different bug than #5799  because the geometry check passes. 

Hopefully this will be useful for troubleshooting: [Fillet example.zip](https://github.com/user-attachments/files/17054454/Fillet.example.zip) 

The model is based on a drawing from one of the solidworks competitions. 


### Full version info

```shell
OS: Debian GNU/Linux 12 (bookworm) (KDE/plasma)
Word size of FreeCAD: 64-bit
Version: 1.0.0RC1.38642 (Git) AppImage
Build type: Release
Branch: (HEAD detached at 1.0rc1)
Hash: 60a251354e203bdb924e2190fb9f5e18b48d7362
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Installed mods: 
  * fasteners 0.5.28
  * Curves 0.6.47
  * POV-Ray-Rendering
  * lattice2 1.0.0
  * Assembly4 1.27.10
  * kicadStepUpMod
  * kicadStepUpMod.backup1699473187.113371 10.17.1
  * fcgear 1.0.0
  * Silk 0.1.5
  * Alternate_OpenSCAD 1.0.0
  * CurvedShapes 1.0.9
  * sheetmetal 0.4.25
  * freecad.gears 1.0.0
```


### Subproject(s) affected?

Part

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
