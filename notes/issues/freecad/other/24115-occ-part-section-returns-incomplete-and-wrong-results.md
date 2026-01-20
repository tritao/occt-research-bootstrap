# #24115 — OCC: `part.section` returns incomplete (and wrong) results

- Repo: `FreeCAD/FreeCAD`
- Issue: `#24115`
- URL: https://github.com/FreeCAD/FreeCAD/issues/24115
- State: `open`
- Created: `2025-09-21T18:56:06Z`
- Updated: `2026-01-06T07:41:16Z`
- Comments: `14`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Here's a simple shape (i've tried to simplify it further, but `section` works more frequently (fails to fail) if its much simpler):

<img width="653" height="541" alt="Image" src="https://github.com/user-attachments/assets/1182b7fa-63d4-43be-bebb-c2377641beaf" />

I iteratively try to find the `section` of a cylinder with these top faces, and draw ones that show only partial results.

Here's what I expect, and most of the time it works like this:

<img width="791" height="418" alt="Image" src="https://github.com/user-attachments/assets/156be814-b77d-4ea1-977b-75e06c8ce612" />

Here are some failure cases, happening about 1:100. Note, it's not just when cylinder-faces have overlapping edges, sometimes the cylinder is in the middle of face, completely contained, and we get a partial result.

<img width="571" height="568" alt="Image" src="https://github.com/user-attachments/assets/304df540-83a9-41df-8336-0ba637593868" />

Here's the file (renamed `.FCStd -> .py` for github upload):

[t25_incomplete_section.py](https://github.com/user-attachments/files/22453812/t25_incomplete_section.py)

Here's the code you can run in the console to find bad sections:

```python
import math
import random

def sample_circle(outer_radius, inner_radius=5):
    # Sample angle uniformly
    theta = random.random() * 2 * math.pi

    # Sample radius with correct distribution for uniform area sampling
    # We need to account for the "hole" in the middle
    u = random.random()
    r_squared = inner_radius**2 + u * (outer_radius**2 - inner_radius**2)
    r = math.sqrt(r_squared)

    # Convert to Cartesian coordinates
    x = r * math.cos(theta)
    y = r * math.sin(theta)
    return x, y

part_radius = 100
tool_radius = 6
tool_height = 100

faces = FreeCAD.ActiveDocument.getObject('Binder').Shape

def find_bad_sections(n_tries=100):
    n_found = 0
    for _ in range(n_tries):
        x, y = sample_circle(part_radius - tool_radius, tool_radius + 5)  # 5mm is inner hole
        cyl = Part.makeCylinder(
            tool_radius,
            tool_height,
            FreeCAD.Vector(x, y, -tool_height/2),
            FreeCAD.Vector(0, 0, 1)
        )
        section = faces.section(cyl)
        section.tessellate(0.01)

        min_len = 2 * 3.14159 * tool_radius * 0.95
        if section.Length < min_len:  # len smaller than cross section of cylinder
            n_found += 1
            Part.show(section)  # show partial sections

        # Part.show(section)  # show all sections

    if n_found == 0:
        print('No bad sections found')
    else:
        print(f'found {n_found} bad sections and drew them')

find_bad_sections(500)


```
 

My "is bad" code simply checks if the section has a length smaller than a cross section of the cylinder. In practice, I can't do this since the cylinder may be hanging over a face edge, so the true part-cyl section will actually be smaller than that.

Any ideas how to fix this, or at least identify failure cases so I can retry?

(
and PS here's another `section` bug I found on the journey:
https://github.com/FreeCAD/FreeCAD/issues/24111
and OCC reports a possibly related (?) issue
https://github.com/Open-Cascade-SAS/OCCT/issues/275
)

### Full version info

```shell
OS: Debian GNU/Linux 12 (bookworm) (GNOME/gnome/xcb)
Architecture: x86_64
Version: 1.1.0dev.14555 (Git shallow) AppImage
Build date: 2025/09/02 21:58:19
Build type: Release
Branch: main
Hash: 04e085cba3b43d1e09aedd4445824a6eb46e45b6
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: TinkerCAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/fusion
Logical DPI/Physical DPI/Pixel Ratio: 96/127.628/1
Installed mods: 
  * ZFace
  * CurvedShapes 1.0.13
  * Curves 0.6.68
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
