# #27000 — Part: Projecting a regular pentagonal surface onto the surface of a sphere does not work

- Repo: `FreeCAD/FreeCAD`
- Issue: `#27000`
- URL: https://github.com/FreeCAD/FreeCAD/issues/27000
- State: `open`
- Created: `2026-01-18T02:50:38Z`
- Updated: `2026-01-18T14:16:51Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Problem description

When a regular pentagon is projected onto the surface of a sphere, it becomes 5 points and a ring.

**Workflow:**
1. Generate a sphere with a radius of 50mm.

2. Switch to Draft Workbench, draw a regular pentagon with an inscribed circle radius of 10mm, and change the pentagon's position to make it float above the sphere.

3. Generate a plane from the pentagon.

4. Apply Part_ProjectionOnSurface. The projection result is that the five vertices of the pentagon are projected onto the surface of the sphere, with a ring passing through these five projection points, instead of the pentagonal surface I expected.

<img width="1437" height="910" alt="Image" src="https://github.com/user-attachments/assets/181059bb-4738-4df5-8f4f-685e978a472e" />

** My Attempts:**
When I changed the radius of the regular pentagon from 10mm to 20mm, something interesting happened: a green pentagon appeared on the surface of the sphere.

<img width="1455" height="887" alt="Image" src="https://github.com/user-attachments/assets/43b0d6bd-a302-439a-88cd-c18791c594fb" />


I quickly realized something was wrong; the green pentagon was broken at one vertex, not closed—very strange! Then I changed the radius of the pentagon to 30mm, and this time the projection returned to five points and a ring, which was very frustrating.

<img width="1450" height="898" alt="Image" src="https://github.com/user-attachments/assets/9026e7f8-a30e-4604-9f63-49dd53281ef2" />

 I don't know where I went wrong. I would greatly appreciate guidance, thank you!


**Full version info**


OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: Chinese/China (zh_CN)
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/Fusion
Installed mods: 
  * Curves 0.6.70
  * FreeCAD-Pyramids-and-Polyhedrons-master




### Workbench affected?

None

### Steps to reproduce

[10.zip](https://github.com/user-attachments/files/24693181/10.zip)

### Expected behavior

1. I want to know why the projection failed.

2. Why does the radius of the pentagon affect the projection result?

3. Why is the projected pentagon not closed when the radius of the pentagon is 20mm?


### Actual behavior

<img width="812" height="664" alt="Image" src="https://github.com/user-attachments/assets/4de11384-108c-4fe9-ad1d-14afba5f8389" />

### Development version About Info (in Safe Mode)

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.2.0dev.20260113 (Git shallow)
Build date: 2026/01/13 22:48:50
Build type: Release
Branch: (HEAD detached at 4cc0a1b)
Hash: 4cc0a1b718735be10261d936066cf1382dd51884
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: Chinese/China (zh_CN)
Navigation Style/Orbit Style/Rotation Mode: CAD/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.6656/1
Installed mods: 
  * Curves 0.6.70
  * FreeCAD-Pyramids-and-Polyhedrons-master
```

### Last known good version (optional)

```shell

```
