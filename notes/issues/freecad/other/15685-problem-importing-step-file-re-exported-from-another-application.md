# #15685 — Problem importing STEP file (re-exported from another application)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#15685`
- URL: https://github.com/FreeCAD/FreeCAD/issues/15685
- State: `open`
- Created: `2024-07-30T09:01:48Z`
- Updated: `2025-11-17T03:56:30Z`
- Comments: `13`
- Labels: `Type: Bug`, `Status: Needs confirmation`, `3rd party: OCC`, `File format: STEP`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

FreeCAD can't open a re-exported STEP file (exported.step in the attached ZIP file) from another application, but other apps are able to open it (for example, Rhino 7, evaluation version).

FreeCAD doesn't give any warning or error about the import process (neither in a message dialog, nor in the report panel, nor in the Python Console) and nothing appears in the Model tree view or in the main 3D view.

The original file (original.step in the ZIP file) works.

As said before, Rhino 7 is able to open either the original file and the re-exported file as can be seen in this photo:

![bug](https://github.com/user-attachments/assets/b0081942-b63d-4316-96b2-ba36155b2018)

It seems the difference between the two files is about the STEP schema used: the working one is `AUTOMOTIVE_DESIGN`, while the non working one is `CONFIG_CONTROL_DESIGN`. I don't know the STEP file format, though, so I can't say whether that is the reason for the bug.

Another difference is that original has a PRODUCT line while the re-exported one has not.

NOTE: The bug is also present on Linux via the latest FreeCAD flatpak available on flathub.

### Full version info

```shell
OS: Windows 10 build 19045
Word size of FreeCAD: 64-bit
Version: 0.21.2.33771 (Git)
Build type: Release
Branch: releases/FreeCAD-0-21
Hash: b9bfa5c5507506e4515816414cd27f4851d00489
Python 3.8.10, Qt 5.15.2, Coin 4.0.1, Vtk 8.2.0, OCC 7.6.3
Locale: Italian/Italy (it_IT)
Installed mods: 
  * lattice2 1.0.0
```


### Subproject(s) affected?

None

### Anything else?

[steps.zip](https://github.com/user-attachments/files/16425001/steps.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
