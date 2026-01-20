# #15102 — Reliable crash when changing chamfer size

- Repo: `FreeCAD/FreeCAD`
- Issue: `#15102`
- URL: https://github.com/FreeCAD/FreeCAD/issues/15102
- State: `closed`
- Created: `2024-07-02T01:30:19Z`
- Updated: `2025-10-29T10:48:44Z`
- Closed: `2025-10-29T10:48:44Z`
- Comments: `41`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Type: Regression`, `Status: Confirmed`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I'm not sure how to describe the issue other than to provide a sample file and steps to reproduce.

1. Load the attached FCStd file.
2. Double click what I have named "glitchy chamfer".
3. Edit the size and set it to 3.9.

FreeCAD crashes every time.

[try3.FCStd.zip](https://github.com/user-attachments/files/16060494/try3.FCStd.zip)


### Full version info

```shell
OS: macOS 13.6
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.37898 (Git)
Build type: Release
Branch: main
Hash: 308013fb975ec3bf0dc5cb616ef76a4095e71cc5
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US) [ OS: C/Default (C) ]
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
