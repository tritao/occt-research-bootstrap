# #17845 — Radius on curved shape problem

- Repo: `FreeCAD/FreeCAD`
- Issue: `#17845`
- URL: https://github.com/FreeCAD/FreeCAD/issues/17845
- State: `open`
- Created: `2024-11-13T20:22:32Z`
- Updated: `2025-04-09T13:32:42Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Status: Needs test on stable version`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

when I try to execute a radius on the curved shape of the solid, two unwanted bodies are formed. I attach a photo
![1](https://github.com/user-attachments/assets/2fa1df23-dc6b-4442-92f2-ff23aa184d43)
![2](https://github.com/user-attachments/assets/36febace-fb15-487b-9b9c-e95830e52e59)
![3](https://github.com/user-attachments/assets/fcb5f647-10a1-49f5-bb46-8fa6a8767cbb)


### Full version info

```shell
OS: Windows 10 build 19042
Architecture: x86_64
Version: 1.1.0dev.39141 (Git)
Build type: Release
Branch: main
Hash: 4bd80bdcbb97d6038bc7030aed9ecebf57f4e428
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: Italian/Italy (it_IT)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * A2plus 0.4.68
  * Behave-Dark-Colors 0.1.1
  * CamScripts
  * ExplodedAssembly
  * fasteners 0.5.29
  * FeedsAndSpeeds 0.5.0
  * Freecad-Built-in-themes-beta 1.2.2
  * FreeCAD-themes 2024.7.24
  * OpenTheme 2024.9.1
  * PieMenu 1.8.0
  * ProDarkThemePreferencePack 1.0.0
  * QuickMeasure 2022.10.28
  * Render 2024.9.25
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
