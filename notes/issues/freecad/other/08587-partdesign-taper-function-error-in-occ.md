# #8587 — PartDesign: Taper function error (in OCC)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#8587`
- URL: https://github.com/FreeCAD/FreeCAD/issues/8587
- State: `open`
- Created: `2023-02-22T16:08:46Z`
- Updated: `2025-11-25T13:07:27Z`
- Comments: `10`
- Labels: `Mod: Part Design`, `Mod: Part`, `3rd party: OCC`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Forums discussion

http://forum.freecadweb.org:80/viewtopic.php?f=13&t=75281

### Version

0.20 (Release)

### Full version info

```shell
[code]
OS: Windows 10 Version 2009
Word size of FreeCAD: 64-bit
Version: 0.20.2.29177 +426 (Git)
Build type: Release
Branch: (HEAD detached from 0.20.2)
Hash: 930dd9a76203a3260b1e6256c70c1c3cad8c5cb8
Python 3.8.10, Qt 5.15.2, Coin 4.0.1, Vtk 8.2.0, OCC 7.6.3
Locale: German/Switzerland (de_CH)
[/code]
```


### Subproject(s) affected?

PartDesign

### Issue description

The taper function has an error.
Depending on where the hole is, the taper jumps from negative to positive.
If you move the large hole to the left, the taper changes from positive to negative
It seems to be a bug in the FC software


### Anything else?

![Picture_1](https://user-images.githubusercontent.com/122787106/220684675-04e2fdbe-e5f9-4a93-bfb6-e46c13cc1b36.PNG)
![Picture_2](https://user-images.githubusercontent.com/122787106/220684716-f3f28211-0803-4012-85b5-dc9cc7c5c1cd.PNG)
[TaperError.zip](https://github.com/FreeCAD/FreeCAD/files/10805928/TaperError.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
