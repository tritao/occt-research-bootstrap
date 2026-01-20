# #19255 — "BRep_API: command not done" is not a clear or actionable error message

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19255`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19255
- State: `open`
- Created: `2025-01-26T15:01:19Z`
- Updated: `2025-11-10T09:36:15Z`
- Comments: `13`
- Labels: `Topic: User Interface`, `Type: Feature`, `3rd party: OCC`, `Help wanted`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

As someone new to this sort of CAD tool in general and FreeCAD in particular, I find it frustrating that seemingly basic tools such as Thickness, Chamfer and so on can produce the inscrutable "command not done" error and don't provide any context on what the underlying issue might be.

From my own searching I can see that one very common cause is the relationship with wall thickness.

It seems to me that it would be valuable to bubble up this context from the underlying operation and provide some directive advice to the user: in other words, if it is due to wall thickness, include that in the message and suggest an appropriate course of action, and/or output a link to an FAQ or wiki page or something that can explain it in more detail.

### Full version info

```shell
OS: Ubuntu Core 22 (KDE/plasmawayland/xcb)
Architecture: x86_64
Version: 1.0.0.38641 +468 (Git) Snap 1248
Build type: Release
Branch: tag: 1.0.0
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.10.12, Qt 5.15.10, Coin 4.0.0, Vtk 7.1.1, OCC 7.7.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * Behave-Dark-Colors 0.1.1
  * fasteners 0.5.36
  * FreeCAD-themes 2025.1.7
```

### Subproject(s) affected?

None

### Anything else?

I understand that these tools are likely not at all simple in their implementation, so please don't construe this as me being critical of how they work and what they are capable of. 

I also recognize that it may not be possible for a tool to tell you precisely why it didn't work out. If that is the case, I think it would still be worthwhile to suggest at the most likely reason in the error message that results from the failed operation, so that the user experience is a bit more smooth.

Thank you for creating this software: I think that it is amazing despite having a fairly brutal learning curve.

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
