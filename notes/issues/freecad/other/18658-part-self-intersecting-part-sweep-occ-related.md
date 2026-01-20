# #18658 — Part: Self intersecting Part::Sweep (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18658`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18658
- State: `open`
- Created: `2024-12-21T18:24:10Z`
- Updated: `2025-10-30T10:22:31Z`
- Comments: `10`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Has workaround`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Hello FreeCAD Team!

It seems that in some circumstances the Part::Sweep does not behave as expected and creates a self intersecting sweep.
The following python code shows the problem. It creates a section at the start, a section at the end, and a straight line as the spine of the sweep.

The strange thing is that depending on the size of the section the sweep will be correct or not, demonstrating that the order of the edges in each section is not the problem (as far as I can tell).


```python

import Draft
import Part
import FreeCAD as App

# Just used to colour edges to make ordering easier to see
def hex2rgb(hexcode):
    return (int(hexcode[0:2], 16), int(hexcode[2:4], 16), int(hexcode[4:6], 16))

EDGES_COLORS = [hex2rgb("5bc0eb"), hex2rgb("fde74c"), hex2rgb("9bc53d"), hex2rgb("e55934"), hex2rgb("fa7921")]
Z = 2000
L = 1000

def create_sweep(dx:int):
    # the first section of the sweep
    s1p1 = App.Vector(-dx, dx, 0)
    s1p2 = App.Vector(dx, -dx, 0)
    s1p3 = App.Vector(dx, -dx, Z)
    s1p4 = App.Vector(-dx, dx, Z)

    section_start = Draft.makeRectangle([s1p1, s1p2, s1p3, s1p4])
    section_start.ViewObject.LineColorArray = EDGES_COLORS
    section_start.MakeFace = False

    # the second section of the sweep
    s2p1 = App.Vector(L+dx,  dx, 0)
    s2p2 = App.Vector(L-dx, -dx, 0)
    s2p3 = App.Vector(L-dx, -dx, Z)
    s2p4 = App.Vector(L+dx,  dx, Z)

    section_end = Draft.makeRectangle([s2p1, s2p2, s2p3, s2p4])
    section_end.ViewObject.LineColorArray = EDGES_COLORS
    section_end.MakeFace = False

    spine = Draft.makeLine(App.Vector(0, 0, 0), App.Vector(L, 0, 0))

    # Let's create the sweep...
    sweep = App.ActiveDocument.addObject('Part::Sweep')
    sweep.Sections = [section_start, section_end]
    sweep.Spine = spine
    sweep.Solid = True
    sweep.Frenet = False

    section_start.Visibility = False
    section_end.Visibility = False
    spine.Visibility = False

    App.ActiveDocument.recompute()


# create a good sweep
create_sweep(dx=100)

# create a self-intersecting sweep
create_sweep(dx=200)

```

When creating the `dx=200` sweep it self intersect as shown in the image below
![Screenshot from 2024-12-21 19-21-08](https://github.com/user-attachments/assets/9b1dca4e-04d3-4470-831a-804deeaef18e)

I would have expected the sweep to give the same result as the  `dx=100` sweep as shown below 
![Screenshot from 2024-12-21 19-20-29](https://github.com/user-attachments/assets/350eb8b9-0b84-4706-b0fd-e57050be88b9)


Could you point me toward the problem, as I am not sure I understand what I'm doing wrong.

Thanks a lot for your help



### Full version info

```shell
OS: Ubuntu Core 22 (ubuntu:GNOME/ubuntu/xcb)
Architecture: x86_64
Version: 1.0.0.38641 +468 (Git) Snap 1202
Build type: Release
Branch: tag: 1.0.0
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.10.12, Qt 5.15.10, Coin 4.0.0, Vtk 7.1.1, OCC 7.7.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Installed mods: 
  * FreeCAD-geodata2 0.1.0
  * ExplodedAssembly
  * Help 1.0.3
  * A2plus 0.4.67
  * FreeCAD-SH3D 0.0.1
  * ArchTextures
  * Render 2024.9.25
  * lattice2 1.0.0
  * Curves 0.6.37
  * Assembly4 0.50.15
  * fasteners 0.5.29
```


### Subproject(s) affected?

Part

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
