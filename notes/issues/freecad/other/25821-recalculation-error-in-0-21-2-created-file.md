# #25821 — Recalculation error in 0.21.2-created file

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25821`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25821
- State: `closed`
- Created: `2025-11-30T12:24:16Z`
- Updated: `2025-12-22T17:17:29Z`
- Closed: `2025-12-22T17:17:28Z`
- Comments: `21`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part Design`, `Blocker`, `Type: Regression`, `Status: Confirmed`
- Assignees: `kadet1090`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part Design

### Problem description

I encountered a new recalculation error using the same file as in Issue #17184 (RealExample.zip).
This seems to be a minor problem, but it may represent another regression.

File reference:
https://github.com/FreeCAD/FreeCAD/issues/17184#issuecomment-2409049909

Details:

In the LeftTop body, the attachment of HoleAxis_4 fails because Revolution006:Edge79 cannot be found at that location.
In 1.1.0rc1, the same edge is split into two edges (Edge35 and Edge36).

<img width="2187" height="959" alt="Image" src="https://github.com/user-attachments/assets/2a52275f-77a3-4675-bfe7-e978655b859d" />

I confirmed that this issue occurs in both 1.1.0rc1 and 1.2.0dev-20251126.
In the 1.0.x series, testing is not possible, most likely because #17489 was not effectively backported. The problem from #17184 still persists in 1.0.2.

The file was originally created in the 0.21.x series. Since this file was not editable in 1.0.x, 1.1.0rc1 is the first release version after 0.21.2 where editing becomes possible.

### Steps to reproduce

1. Open file
2. Recompute
3. Error occurs at HoleAxis_4


### Expected behavior

- The file should recompute successfully without errors.
- In the LeftTop body, the attachment of HoleAxis_4 should correctly reference the intended edge of Revolution006.
- The edge should remain stable (not split) so that the attachment can resolve properly.

### Actual behavior

- Recalculation fails with an error: Revolution006:Edge79 cannot be found at that location.
- In 1.1.0rc1, the same edge is split into two edges (Edge35 and Edge36), breaking the attachment.
- As a result, the recompute operation cannot complete for HoleAxis_4.

### Development version About Info (in Safe Mode)

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.2.0dev.20251126 (Git shallow)
Build date: 2025/11/26 00:30:17
Build type: Release
Branch: (HEAD detached at de230cf)
Hash: de230cfaa75433441366ad09a4d5fda828e7bfdb
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: Japanese/Japan (ja_JP)
Navigation Style/Orbit Style/Rotation Mode: TinkerCAD/Trackball/Object center
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/93.1131/1.5
Installed mods: 
  * Assembly4 0.50.18
  * CfdOF 1.30.2
  * CfdOF_fork 1.30.4
  * fasteners 0.5.38
```

### Last known good version (optional)

```shell

```
