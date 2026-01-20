# #25169 — Part: Boolean Common – Failure (Empty Result)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25169`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25169
- State: `open`
- Created: `2025-11-08T17:02:16Z`
- Updated: `2025-11-09T07:16:14Z`
- Comments: `9`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

**Description:**
I have two extrusions that overlap partially. When performing a Common operation on them, the operation fails and returns an empty result.

**Details:**
Both extrusions are defined using splines.

**Steps to Reproduce:**

1. Open the attached file.
3. Perform a Common operation on the two extrusions.

**Result:**
The operation fails and produces an empty result.

**Expected Result:**
The Common operation should succeed and return the overlapping volume.

**Workaround:**
If I slightly extend one of the extrusion (Extrusion169) so that it overlaps fully the other extrusion, the Common operation succeeds.

**Other checks:**
<del>- Boolean Intersection works</del> - Update, the Boolean Intersection is not empty but it is not correct. 
<del>- Boolean Union works</del> - Update, the Boolean Union is not empty but it is not correct.

**Attachment:**
An example file demonstrating the issue is attached.






### Full version info

```shell
OS: Windows 11 build 26100
Architecture: x86_64
Version: 1.0.2.39319 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.2)
Hash: 256fc7eff3379911ab5daf88e10182c509aa8052
Python 3.11.13, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
```

### Subproject(s) affected?

Part

### Anything else?

[BugEmptyPartEmptyCommon.zip](https://github.com/user-attachments/files/23433239/BugEmptyPartEmptyCommon.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
