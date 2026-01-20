# #18836 — Part: 2D Offset - Fill Offset bug using B-spline

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18836`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18836
- State: `open`
- Created: `2025-01-03T00:24:18Z`
- Updated: `2025-10-31T10:09:01Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`, `Type: Known issue`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

In a sketch create a simple B-Spline. Then in the Part WB perform a positive 2D Offset of 3mm. The offset creates fine and then tick Fill Offset. This then fills as expected. (See Image 1). However if you make it a negative 2D Offset -3mm while the Offset creates correctly (See Image 2) when you tick Fill Offset it fills the entire shape rather than just the offset. (See Image 3). Adjusting the amount of offset makes no difference. It works fine for any positive offset and fails for any negative offset.

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/New Zealand (en_NZ)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
```


### Subproject(s) affected?

None

### Anything else?

![2d offset 1](https://github.com/user-attachments/assets/159c208e-17b3-47e8-a1d8-cf0bd1fadfd9)
![2d offset 2](https://github.com/user-attachments/assets/9e84b010-ded8-439e-8cda-56508251ed39)
![2d offset 3](https://github.com/user-attachments/assets/f1a87ff6-9bd3-4083-8443-41a7ea9d3127)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
