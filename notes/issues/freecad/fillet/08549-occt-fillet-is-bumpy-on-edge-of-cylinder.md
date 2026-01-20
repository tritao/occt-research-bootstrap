# #8549 — OCCT: Fillet is bumpy on edge of cylinder

- Repo: `FreeCAD/FreeCAD`
- Issue: `#8549`
- URL: https://github.com/FreeCAD/FreeCAD/issues/8549
- State: `open`
- Created: `2023-02-19T23:52:25Z`
- Updated: `2025-06-10T15:42:26Z`
- Comments: `28`
- Labels: `Mod: Core`, `3rd party: OCC`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Forums discussion

_No response_

### Version

0.20 (Release)

### Full version info

```shell
Current Released Version

[code]
OS: Windows 10 Version 2009
Word size of FreeCAD: 64-bit
Version: 0.20.2.29177 +426 (Git)
Build type: Release
Branch: (HEAD detached from 0.20.2)
Hash: 930dd9a76203a3260b1e6256c70c1c3cad8c5cb8
Python 3.8.10, Qt 5.15.2, Coin 4.0.1, Vtk 8.2.0, OCC 7.6.3
Locale: English/Australia (en_AU)
[/code]

AND 

Weekly Build Version

[code]
OS: Windows 10 Version 2009
Word size of FreeCAD: 64-bit
Version: 0.21.0.31847 (Git)
Build type: Release
Branch: master
Hash: 502ef8c9ba619671b5137833851a7ebbbab24bf0
Python 3.8.10, Qt 5.15.2, Coin 4.0.1, Vtk 8.2.0, OCC 7.6.3
Locale: English/Australia (en_AU)
[/code]
```


### Subproject(s) affected?

Other (specify in description)

### Issue description

It is very easy to reproduce. Create a cylinder with radius 25 mm and default height (10 mm). Pick any edge or face and create a fillet with default radius (1 mm). The filleted edge will show the bumps. I have experimented with different radii and the bumps are present with a 10 mm radius cylinder (barely visible) up to 64 mm radius. Using a 65 mm radius cylinder, the bumps disappear and the fillet is fine.

This issue also happens when the fillet is reduced to 0.5 mm radius or increased to 2 mm radius, or set anywhere inbetween.

The problem is reproducible in the Part Design workbench and the Part workbench.

### Anything else?

![image](https://user-images.githubusercontent.com/125834902/219982980-a49db3ed-af8c-454c-851e-bbac75fc85a1.png)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
