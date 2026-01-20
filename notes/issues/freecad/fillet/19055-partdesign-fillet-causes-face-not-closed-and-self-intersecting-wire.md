# #19055 — PartDesign: Fillet causes face not closed and self intersecting wire

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19055`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19055
- State: `open`
- Created: `2025-01-14T04:40:08Z`
- Updated: `2025-11-23T01:28:56Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Part Design`, `Status: Needs confirmation`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Applying a fillet on these edges 
![image](https://github.com/user-attachments/assets/7df87902-9f21-4d1b-bcec-dacaaaadde4d)
causes  face not closed and self intersecting wire
![image](https://github.com/user-attachments/assets/ed733c42-bb78-46cb-a57d-689cecf38491)

### Full version info

```shell
OS: Ubuntu Core 22 (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.1.0dev.39807 (Git) Snap 1263
Build type: Release
Branch: main
Hash: 326d1eb70b7c8582bd7a41b8f0dd5cbc8a516d91
Python 3.10.12, Qt 5.15.10, Coin 4.0.0, Vtk 7.1.1, OCC 7.7.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
```


### Subproject(s) affected?

PartDesign

### Anything else?

Project
[project.zip](https://github.com/user-attachments/files/18405401/project.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
