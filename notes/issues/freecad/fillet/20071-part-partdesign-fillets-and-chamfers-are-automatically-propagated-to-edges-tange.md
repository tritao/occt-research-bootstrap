# #20071 — Part/ PartDesign: Fillets and chamfers are automatically propagated to edges tangent to selection

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20071`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20071
- State: `open`
- Created: `2025-03-08T14:32:19Z`
- Updated: `2025-09-19T10:08:53Z`
- Comments: `13`
- Labels: `Mod: Part Design`, `Mod: Part`, `Type: Feature`, `Type: Has workaround`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Say you want to make a fillet on a part, along a straight edge with fillets on each side, but only along this edge:

![Image](https://github.com/user-attachments/assets/5836def9-bbc5-4581-b0cf-b6ecd525e1bd)

After activanting `PartDesign_Chamfer`, you select the edge:

![Image](https://github.com/user-attachments/assets/96a4a512-186a-43a8-ad63-a89a76477222)

You will get this:

![Image](https://github.com/user-attachments/assets/794011a7-2328-4a01-9e9d-831a55103a2c)

It is exactly the same with fillets. These features don’t allow the user to set the prolongation of selection. It is always automatically propagated in tangency. FreeCAD lacks an option to either select tangency propagation or minimal propagation. Tangency should remain the default.

The workaround for simple cases is making pockets or sweeps along a path.

### Full version info

```shell
OS: Ubuntu 24.04.1 LTS (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.1.0dev.40408 (Git) Conda AppImage
Build type: Release
Branch: main
Hash: b07caa732e63064b8851ecdda184292962d95c15
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, IfcOpenShell ..7.0, OCC 7.7.2
Locale: French/France (fr_FR)
Stylesheet/Theme/QtStyle: unset/FreeCAD Classic/Qt default
Logical/physical DPI: 96.0236/117.596
Installed mods: 
  * CosmeticThread3D
  * sheetmetal.backup1731333427.8204525 0.5.3 (Disabled)
  * Curves 0.6.59
  * CurvedShapes 1.0.13
  * sheetmetal 0.7.21
```

### Subproject(s) affected?

PartDesign

### Anything else?

Catia provides the option:

![Image](https://github.com/user-attachments/assets/0ea96c8c-ad08-4893-b095-1be22455823c)

Two propagation modes are given: tangency (default) or minimal.

From the [documentation](http://catiadoc.free.fr/online/prtug_C2/prtugbt0602.htm):

> **Propagation**
>
> Two propagation modes are available: 
>
> * **Minimal**: edges tangent to selected edges can be taken into account to some extent. The application continues chamfering beyond the selected edge whenever it cannot do otherwise. In our example below, the chamfer is computed on the selected edge and on a portion of tangent edges:
>    ![Image](https://github.com/user-attachments/assets/d60df40d-f1d8-45fa-b2cb-fafd33dc8b3a)
> * **Tangency**: the application chamfers the entire selected edge as well as its tangent edges. It continues chamfering beyond the selected edge until it encounters an edge that is non-continuous in tangency as shown in our example:
>   ![Image](https://github.com/user-attachments/assets/adf1168c-10a8-4e50-b1d6-dfa5c8f8c6cf)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
