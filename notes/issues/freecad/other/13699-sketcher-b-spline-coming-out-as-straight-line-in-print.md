# #13699 — Sketcher: B-spline coming out as straight line in print

- Repo: `FreeCAD/FreeCAD`
- Issue: `#13699`
- URL: https://github.com/FreeCAD/FreeCAD/issues/13699
- State: `closed`
- Created: `2024-04-28T20:39:12Z`
- Updated: `2025-07-21T04:16:16Z`
- Closed: `2025-07-09T00:28:53Z`
- Comments: `8`
- Labels: `Type: Bug`, `Mod: Sketcher`, `Status: Stale`, `Status: Auto-closing`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I have used a bspline to join two arcs. There are two segments to the bspline, and each segment has been made tangent to its adjoining arc. The spline looks just fine in the sketcher, but in both the part design view and the exported STEP file, it comes out as a straight line.

I've attached three images. The one from the sketcher looks fine. But other two are from the part design view and from the slicer, and both have a weird kink.

![image](https://github.com/FreeCAD/FreeCAD/assets/5619995/005eb6d7-5291-4f7e-901d-0fe35bca9adf)
![image](https://github.com/FreeCAD/FreeCAD/assets/5619995/59af3b85-4073-4922-8e05-ef08630def67)
![image](https://github.com/FreeCAD/FreeCAD/assets/5619995/1c2ae360-927e-4d56-8d0e-c4282d75c6b4)

BTW, I would be happy to upload the FCStd file here, but I get a "we don't support that file type" error. (EDIT: uploaded, see comment.)

### Full version info

```shell
[code]
OS: macOS 13.6
Word size of FreeCAD: 64-bit
Version: 0.21.2.33771 (Git)
Build type: Release
Branch: (HEAD detached at 0.21.2)
Hash: b9bfa5c5507506e4515816414cd27f4851d00489
Python 3.10.13, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.6, OCC 7.6.3
Locale: C/Default (C)
[/code]
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
