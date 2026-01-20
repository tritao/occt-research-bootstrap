# #16644 — Part: Crash when changing edge to be too small for fillet

- Repo: `FreeCAD/FreeCAD`
- Issue: `#16644`
- URL: https://github.com/FreeCAD/FreeCAD/issues/16644
- State: `open`
- Created: `2024-09-18T18:37:05Z`
- Updated: `2025-11-05T00:03:20Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Part`, `Type: Crash`, `Status: Confirmed`, `Topic: Fillets`, `non-blocker`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I have attached a crash report and a document. I get a crash when I try to make the edge for a fillet too small.

Steps to reproduce:
- Navigate to Cut > Fusion001 > Extrude003 > Sketch003
- Change radius of circle to 1.5mm
- Close the sketcher

[fillet crash.txt.zip](https://github.com/user-attachments/files/17048737/fillet.crash.txt.zip)
[board stencil holder.FCStd.zip](https://github.com/user-attachments/files/17048738/board.stencil.holder.FCStd.zip)

It seems that 1.5mm is the sweet spot for this crash. Other radii fail in more graceful ways.

### Full version info

```shell
OS: macOS 14.6.1
Word size of FreeCAD: 64-bit
Version: 1.1.0dev.38768 (Git)
Build type: Release
Branch: main
Hash: 758674d40be45e365f4148fb2a5ea6bd6f93bc74
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US) [ OS: C/Default (C) ]
Stylesheet/Theme/QtStyle: unset/Classic/Qt default
Installed mods: 
  * Curves 0.6.44
```


### Subproject(s) affected?

Part

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
