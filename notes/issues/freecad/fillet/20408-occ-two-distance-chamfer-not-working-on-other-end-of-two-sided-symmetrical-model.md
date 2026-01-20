# #20408 — OCC: Two-distance Chamfer not working on other end of two-sided, symmetrical model

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20408`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20408
- State: `open`
- Created: `2025-03-24T03:54:08Z`
- Updated: `2025-11-19T22:13:05Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

The issue is documented on the FC forums here:
https://forum.freecad.org/viewtopic.php?p=818069#p818069

One end of the model has been successfully chamfered in one hit however the other end will not chamfer in an expected format.

What we are seeing:
* Attempt to chamfer just the long straight edges results in a mis-matched & unwanted chamfer.

No matter which edge we choose, the final result is a mess. I do not think this is one of those chamfer/fillet issues as we already have a fully chamfered end on this model and we are performing the same action on the other end of the same model so it should chamfer the same way with the same result.

FC version 1.0.0 (rev 39109) responds the same way.
FC version 0.21.2 (rev 33771) responds the same way.

![Image](https://github.com/user-attachments/assets/63e270bd-4b34-4e4a-8d04-eaef79c52ef4)

![Image](https://github.com/user-attachments/assets/97102bad-b392-4fe0-b66c-81ea165519ff)

There is a fix however, you have to chamfer each edge on its own!? And the order in which you perform each chamfer is also important:
* Perform chamfer on Edge11 first.
* Perform a new chamfer on Edge8 next.
* Perform the next chamfer on Edge3 next.

The original FC model and my "fixed" model are both in the FC forum topic mentioned.

[RodConnector.zip](https://github.com/user-attachments/files/19480058/RodConnector.zip)

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.40504 (Git) Conda
Build type: Release
Branch: main
Hash: 855ad6c70904f911b2ce7114dd1a5bc24da98bd1
Python 3.11.11, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, IfcOpenShell 0.0.0, OCC 7.8.1
Locale: English/Australia (en_AU)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Qt default
Logical/physical DPI: 96/106.57
Installed mods: 
  * A2plus 0.4.68
  * Assembly4 0.50.15
  * Curves 0.6.58
  * fasteners 0.5.36
  * Gridfinity 0.8.0
  * lattice2 1.0.0
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
