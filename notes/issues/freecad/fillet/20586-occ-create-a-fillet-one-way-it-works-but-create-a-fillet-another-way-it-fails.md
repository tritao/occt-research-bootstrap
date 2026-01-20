# #20586 — OCC: Create a Fillet one way- it works, but create a fillet another way it fails.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20586`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20586
- State: `open`
- Created: `2025-04-02T06:46:00Z`
- Updated: `2025-12-07T17:40:21Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Here is the post as reference:
https://forum.freecad.org/viewtopic.php?t=95965&start=11

I created a fillet on a model using a specific set of steps, and the fillet fails. I then created the same fillet using the actions in a different order, and the fillet works. And this is consistent & repeatable.

News flash- depending on which order you execute the fillet, it will either ALWAYS crash or NEVER crash the model!

I tried this:
* With just the text block selected "A_Block" and not the model on screen, click Part Fillet.
* Adjust the Radius to 0.01mm.
* Warning- no edges selected. Click radio button Fillet Parameter | Selection | Select Faces then select the top face.
* Click OK.
==> Model crashes.

Now change the step order around and it works:
* With just the text block selected, "A_Block" and not the model on screen, click Part Fillet.
* Click radio button Fillet Parameter | Selection | Select Faces then select the top face.
* Adjust the Radius to 0.01mm.
* Click OK.

Fillet now works!!?? And if I use the 2nd method, no matter how many times, it will always work! So now no need to create incremental fillets to get to the size I want!

This is the video of me trying both methods:
https://youtu.be/ZFtB_wBT0iw

[testTexDraft-001.zip](https://github.com/user-attachments/files/19562529/testTexDraft-001.zip)

### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.1.0dev.40971 (Git) Conda
Build date: 2025/03/24 18:02:34
Build type: Release
Branch: main
Hash: b33c2363226a5fc1e8222a02659118c95e1a5119
Python 3.11.11, Qt 6.7.3, Coin 4.0.3, Vtk 9.3.1, IfcOpenShell 0.8.1, OCC 7.8.1
Locale: English/Australia (en_AU)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/106.57/1.5
Installed mods: 
  * A2plus 0.4.68
  * Assembly4 0.50.18
  * Curves 0.6.58
  * fasteners 0.5.38
  * Gridfinity 0.11.4
  * InventorLoader 1.5.1
  * lattice2 1.0.0
  * sheetmetal 0.7.22
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
