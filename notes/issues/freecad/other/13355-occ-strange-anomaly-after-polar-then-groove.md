# #13355 — OCC: Strange anomaly after polar-then-groove

- Repo: `FreeCAD/FreeCAD`
- Issue: `#13355`
- URL: https://github.com/FreeCAD/FreeCAD/issues/13355
- State: `open`
- Created: `2024-04-07T18:51:22Z`
- Updated: `2025-02-22T07:20:08Z`
- Comments: `4`
- Labels: `Type: Bug`, `3rd party: OCC`, `Type: Has workaround`, `Type: Known issue`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

In a gear I'm designing, some (but not all!) of the points of the final part are improperly computed.  Just spitballing, but it seems to somehow be related to the polar pattern processing?

I've attached a .FCStd file that's pared down to the absolute minimum part along with a .gif circling the errors.


Also if I export this part for 3D printing, Ultimaker Cura now complains about model errors because of this.


### Full version info

```shell
[code]


--  NOTE:  Designing in release build, but ALSO happening in latest 0.22.0 devel build  --

OS: Windows 11 build 22631
Word size of FreeCAD: 64-bit
Version: 0.21.2.33771 (Git)
Build type: Release
Branch: (HEAD detached at 0.21.2)
Hash: b9bfa5c5507506e4515816414cd27f4851d00489
Python 3.10.13, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.6, OCC 7.6.3
Locale: English/United States (en_US)
Installed mods: 
  * fasteners 0.5.15
  * freecad.gears 1.2.0
[/code]
```


### Subproject(s) affected?

None

### Anything else?

![Anomaly](https://github.com/FreeCAD/FreeCAD/assets/105553353/75472028-e4a1-457a-893a-5f33d4858aaa)
[Anomaly.zip](https://github.com/FreeCAD/FreeCAD/files/14898531/Anomaly.zip)


### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
