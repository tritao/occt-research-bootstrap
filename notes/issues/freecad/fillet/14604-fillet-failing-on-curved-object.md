# #14604 — Fillet failing on curved object

- Repo: `FreeCAD/FreeCAD`
- Issue: `#14604`
- URL: https://github.com/FreeCAD/FreeCAD/issues/14604
- State: `open`
- Created: `2024-06-10T22:53:44Z`
- Updated: `2025-08-14T12:28:04Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

I made a post on the FreeCAD Facebook group at the following link for more details. Others were able to repeat the problem in there and one user recorded the failure in a video. It forces the user to search for more timely workarounds. Some were provided in the Facebook group.

https://www.facebook.com/share/p/TTg7DAY2zShmVMoZ/?mibextid=oFDknk

A fillet is failing at roughly the halfway point when filleting a circular extrusion. 

![447881186_10228262563381548_8763576716265901296_n](https://github.com/FreeCAD/FreeCAD/assets/9904340/b028c5cb-46ce-459c-a70b-a51cfe9baa0d)
![447883447_10228262565781608_7850191264976574033_n](https://github.com/FreeCAD/FreeCAD/assets/9904340/1bbe1ba4-b600-4fa1-9aaa-0475d2fdcaed)





### Full version info

```shell
It has failed on other versions I have tried as well.

OS: Windows 10 build 19045
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.36996 (Git)
Build type: Release
Branch: main
Hash: d92f74ef019fcedbdcdc32055ab2437c950ac23b
Python 3.11.9, Qt 5.15.13, Coin 4.0.2, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Installed mods: 
  * 3D_Printing_Tools
  * A2plus 0.4.64a
  * Assembly3 0.12.2
  * Assembly4 0.50.12
  * CADExchanger
  * Defeaturing 1.2.2
  * Design456 0.0.1
  * ExplodedAssembly
  * fasteners 0.5.20
  * LCInterlocking
  * QuickMeasure 2022.10.28
  * WB_Organizer 2024.1.29
```


### Subproject(s) affected?

PartDesign

### Anything else?

Here is the Facebook group mentioned above if interested.

https://www.facebook.com/share/p/TTg7DAY2zShmVMoZ/?mibextid=oFDknk

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
