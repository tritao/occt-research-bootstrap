# #20633 — Part: findPlane regression (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20633`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20633
- State: `closed`
- Created: `2025-04-04T12:12:33Z`
- Updated: `2025-09-01T15:47:33Z`
- Closed: `2025-09-01T15:47:33Z`
- Comments: `9`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Regression`, `Status: Confirmed`, `Status: Solution proposed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

The findPlane method fails to find a plane for faces that are obviously flat and changing the tolerance does not have any effect. This is a regression introduced in V1.0 AFAICT.

1. Open the attached file.
2. Select one of the slanted faces.
3. Invoke [Std_SendToPythonConsole](https://wiki.freecad.org/Std_SendToPythonConsole).
4. Paste this in the Python console: `sub.findPlane()`
5. Result: no plane is returned.
6. Try again with a very high tolerance: `sub.findPlane(1)`
7. Result: again no plane is returned.

Note: I am using a Linux version of the latest dev for testing as the Windows version will not start on Windows 8.

[pd-shp-020.FCStd.zip](https://github.com/user-attachments/files/19604164/pd-shp-020.FCStd.zip) (remove the .zip extension)

### Full version info

```shell
OS: Ubuntu 22.04.5 LTS (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.1.0dev.40971 (Git) Conda
Build date: 2025/03/24 18:02:34
Build type: Release
Branch: main
Hash: b33c2363226a5fc1e8222a02659118c95e1a5119
Python 3.11.11, Qt 6.7.3, Coin 4.0.3, Vtk 9.3.1, IfcOpenShell 0.8.1, OCC 7.8.1
Locale: Dutch/Netherlands (nl_NL)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/86.1283/1
Installed mods:
```

### Subproject(s) affected?

Part

### Anything else?

Problem does not occur in V021:
```
OS: Windows 8 build 9600
Word size of FreeCAD: 64-bit
Version: 0.21.2.33771 (Git)
Build type: Release
Branch: (HEAD detached at 0.21.2)
Hash: b9bfa5c5507506e4515816414cd27f4851d00489
Python 3.10.13, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.6, OCC 7.6.3
Locale: C/Default (C) [ OS: Dutch/Netherlands (nl_NL) ]
Installed mods:
```

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
