# #19329 — TechDraw: Crashing and sluggishness when inserting views of a simple part

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19329`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19329
- State: `open`
- Created: `2025-01-30T23:46:25Z`
- Updated: `2025-09-21T11:05:51Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: TechDraw`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Performance`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I am experiencing issues in TechDraw when trying to create views ("Insert View" button) with a **specific part**. It takes TechDraw an absurd amount of time to generate the view (regardless of if you choose front, side, isometric, etc). After the view has been generated, FreeCAD also becomes slightly sluggish (depending on the computer specs). I tested this on three separate computers:

1. Thinkpad X220 Intel i5 Sandy Bridge 16GB RAM with Debian 12
2. Thinkpad T420 Intel i7 Ivy Bridge 16GB RAM with Debian 12
3. Desktop Computer Intel i7-6700 with Windows 10

This part is part of a larger assembly I am working on which generates the views in TechDraw without any issues if the problem part is removed. As soon as the problem part is reintroduced, it is even more sluggish and caused the RAM on my X220 to surpass 16GB resulting in a crash of the entire system. So I was able to isolate these issues to be caused by this single part. I have also re-drawn it many times and it is still has the same issues.

The part itself is quite simple. Just a sketch that is revolved around Z axis. Another two sketches and then holes are pocketed through the part. Finally, two radial pattern operations on the two pockets to propagate the holes around the cylindrical part.

**Steps to recreate the problem:**
1. Open FreeCAD.
2. Create a new, completely blank empty file.
3. Run "testpart2.FCMacro" macro (attached in .txt).
3. Move to TechDraw Workbench.
4. Insert Default Page.
5. Select "Body" from the workspace tree, then select "Insert View".
6. Observe the time taken to generate the view.

**NOTES:**
1. After selecting "Body" and "Insert View", if you select "Cancel" in the Insert View window before selecting "Apply" and or "OK" causes FreeCAD to crash.
2. Pressing "Apply" and "OK" same as NOTE 1 before the view preview is generated will not crash FreeCAD. However, if you then try to delete the TechDraw page, or close FreeCAD, it will crash FreeCAD.

### Full version info

```shell
OS: Windows 10 build 19045
Architecture: x86_64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/Australia (en_AU)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods:
* quetzal-master 1.0.1
```

### Subproject(s) affected?

TechDraw

### Anything else?

[testpart2.txt](https://github.com/user-attachments/files/18610022/testpart2.txt)

Forum Post: https://forum.freecad.org/viewtopic.php?p=808058#p808058

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
