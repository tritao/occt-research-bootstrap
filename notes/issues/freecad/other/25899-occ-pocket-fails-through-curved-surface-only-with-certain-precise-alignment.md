# #25899 — OCC: Pocket fails through curved surface only with certain precise alignment.

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25899`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25899
- State: `open`
- Created: `2025-12-02T20:27:47Z`
- Updated: `2025-12-07T12:25:19Z`
- Comments: `3`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

I'm trying to demonstrate how to use FreeCAD to replicate a design someone else made in OpenSCAD, intending to show a parsimonious design. In doing so, I found a case where the Pocket operation fails. I do not know the extent of the failure.

The OpenSCAD design is this:

```
    module donut_with_lobes() {
    outer_diameter = 70;
    inner_diameter = 30;
    protrusion = 15;
    lob_count = 5;
    round_radius = 1;
    hex_diameter = 13;
    hex_depth = 5;
    torus_diameter = ((outer_diameter - inner_diameter) / 2);
    R = ((outer_diameter - torus_diameter) / 2);
    hex_correction = hex_diameter / cos(30) + 0.2; // 0.2 mm tolerance

    union() {
        difference() {
            union() {
                rotate_extrude(angle = 360)
                    translate([R, 0, 0])
                        circle(r = torus_diameter / 2, $fn = 100);
                translate([0, 0, -torus_diameter / 2])
                    cylinder(h = torus_diameter / 2, r = outer_diameter / 2 - torus_diameter / 2, $fn = 100);
                translate([0, 0, -torus_diameter / 2])
                    cylinder(h = torus_diameter / 2, r = inner_diameter / 2, $fn = 100);
                translate([0, 0, -torus_diameter/2-protrusion])
                    cylinder(h = torus_diameter/2+protrusion, r = inner_diameter / 2, $fn = 100);
            }
            translate([0, 0, -torus_diameter/2-protrusion - 0.1])
                cylinder(h = hex_depth, d = hex_correction, $fn = 6);
            translate([0, 0, -torus_diameter/2-protrusion - 0.1])
                cylinder(h = torus_diameter/2+protrusion+0.2, d = 8.5, $fn = 24);
            
            for (i = [0 : lob_count-1]) {
                rotate([0, 0, i * 360 / lob_count])
                    translate([R + torus_diameter / 2, 0, -torus_diameter])
                        cylinder(h = torus_diameter * 2, r = torus_diameter / 2, $fn = 50);
            }
        }
    }

    }

    donut_with_lobes();
```

This renders like this:

<img width="1452" height="1060" alt="Image" src="https://github.com/user-attachments/assets/a5110185-cac6-41bd-bf62-474ceede1160" />

However, when I try to cut out the knob grip using the same geometry, the pocket operation silently fails to pocket. (I would not be surprised if this is actually an OpenCASCADE bug, but I don't know.)

### Steps to reproduce

Open [Knob.zip](https://github.com/user-attachments/files/23889895/Knob.zip) renamed as a FCStd file.

### Expected behavior

I expect this:

<img width="1330" height="1295" alt="Image" src="https://github.com/user-attachments/assets/8e7bd092-a9c2-4ee0-9764-d8780c384e6b" />

However, I get this:

<img width="1330" height="1295" alt="Image" src="https://github.com/user-attachments/assets/3fe548fe-05fc-4134-83fe-d773e6752996" />

### Actual behavior

By changing the sketch to offset the circular sketch wire by a miniscule offset, I get approximately what I expect:

<img width="1393" height="1436" alt="Image" src="https://github.com/user-attachments/assets/cbf1f6c0-21ad-497c-b179-839d838a96a1" />

This change is in [KnobWorks.zip](https://github.com/user-attachments/files/23889954/KnobWorks.zip)

### Development version About Info (in Safe Mode)

```shell
OS: Fedora Linux 41 (Toolbx Container Image) (GNOME/gnome/wayland)
Architecture: x86_64
Version: 1.1.0rc1.44359 (Git)
Build date: 2025/11/26 22:59:22
Build type: Unknown
Branch: releases/FreeCAD-1-1
Hash: c5c336927d8d55d0d805d9b1b62933adb3cde598
Python 3.13.2, Qt 6.8.2, Coin 4.0.2, Vtk 9.2.6, boost 1_83, Eigen3 3.4.0, PySide 6.8.2.1
shiboken 6.8.2.1, SMESH 7.7.1.0, xerces-c 3.2.5, OCC 7.8.0
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/225.585/1.25
Installed mods: 
  * Assembly4 0.50.15
  * Curves 0.6.47
  * sheetmetal 0.3.0
  * ExplodedAssembly
  * fasteners 0.5.29
  * MeshRemodel 1.8919.0
  * Pyramids-and-Polyhedrons
  * dxf_library
  * lattice2 1.0.0
  * boltsfc 2022.11.5
  * parts_library
  * Defeaturing 1.2.2
  * A2plus 0.4.67
  * CurvedShapes 1.0.10
  * Manipulator 1.6.0
  * Pyramids-and-Polyhedrons.backup1696298372.5270553 (Disabled)
  * Assembly3 0.12.2
  * DynamicData 2.63.0
  * freecad.gears 1.3.0
```

### Last known good version (optional)

```shell

```
