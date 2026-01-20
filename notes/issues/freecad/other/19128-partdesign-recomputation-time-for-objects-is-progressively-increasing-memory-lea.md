# #19128 — PartDesign: Recomputation time for objects is progressively increasing (memory leak?) ← Problem originates from OCC

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19128`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19128
- State: `closed`
- Created: `2025-01-19T14:21:38Z`
- Updated: `2026-01-02T17:14:24Z`
- Closed: `2026-01-02T17:14:24Z`
- Comments: `23`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Priority: High`, `Mod: Materials`, `Topic: Performance`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Hi, while I was trying to measure the recomputing time, I found the recomputing time of Part Design objects gradually increased. So, I wrote a simple script to determine:
``` python
import random, timeit
obj = FreeCAD.getDocument('Unnamed1').getObject('Pad')
def test():
	obj.Length = f'{random.randint(5,15)} mm'
	obj.recompute()

print("Test start!")
for i in range(8):
	print(i, ':', timeit.timeit(test, number=100))
```
![Image](https://github.com/user-attachments/assets/edb1b170-a04a-41dc-bd82-b70906a34114)
And the result is here:
```
Test start!
0 : 0.5384760740000161
1 : 0.9025419779999879
2 : 1.2649379060000001
3 : 1.659684298000002
4 : 2.080050730000039
5 : 2.500583860000006
6 : 2.996545576000017
7 : 3.5236986630000047
```

I also tested Extrude created by Part workbench and it don't have such problem.

### Full version info

```shell
OS: Arch Linux (KDE/plasma/wayland)
Architecture: x86_64
Version: 1.0.0.39109 (Git)
Build type: Release
Branch: makepkg
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.13.0, Qt 6.8.0, Coin 4.0.3, Vtk 9.3.1, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Installed mods: 
  * Render 2024.12.15
  * Assembly4 0.50.15
  * A2plus 0.4.68
  * EasyProfileFrame
  * frameforge 0.1.0
  * CfdOF 1.29.2
  * MakerWorkbench 1.0.1
```

### Subproject(s) affected?

PartDesign

### Anything else?

I'm willing to contribute, but I only know a little about C++. If there is anything I can help, feel free to ask me. 🤗 

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
