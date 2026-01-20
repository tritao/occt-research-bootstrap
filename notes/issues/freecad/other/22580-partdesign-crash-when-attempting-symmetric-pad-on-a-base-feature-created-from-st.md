# #22580 — PartDesign: crash when attempting symmetric pad on a base feature created from STL (v1.1-dev)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22580`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22580
- State: `open`
- Created: `2025-07-18T23:39:58Z`
- Updated: `2025-07-26T10:37:18Z`
- Comments: `3`
- Milestone: `1.1`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Status: Needs diagnosis`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

on the attached file (compressed with 7zip as zip was i guess to big)

[grip-model.FCStd(7z).zip](https://github.com/user-attachments/files/21323777/grip-model.FCStd.7z.zip)

create a pad with the only sketch, model will disappear, then click symmetric (i think reverse also does it) freecad then crashes with the below see in console
if the original stl is required it was from here: https://www.thingiverse.com/thing:4614297

```
Program received signal SIGSEGV, Segmentation fault.
Program received signal SIGSEGV, Segmentation fault.
#0  /usr/lib/libc.so.6(+0x3def0) [0x7f677e860ef0]
#1  /tmp/.mount_freecagabOfp/usr/lib/././libTKBO.so.7.8(+0x23c18a) [0x7f6708e3c18a]
#0  /usr/lib/libc.so.6(+0x3def0) [0x7f677e860ef0]
#2  /tmp/.mount_freecagabOfp/usr/lib/././libTKBO.so.7.8(+0x23d857) [0x7f6708e3d857]
#1  /tmp/.mount_freecagabOfp/usr/lib/././libTKBO.so.7.8(+0x23c18a) [0x7f6708e3c18a]
#2  /tmp/.mount_freecagabOfp/usr/lib/././libTKBO.so.7.8(+0x23d857) [0x7f6708e3d857]
#2  /tmp/.mount_freecagabOfp/usr/lib/././libTKBO.so.7.8(+0x23d857) [0x7f6708e3d857]
#3  0x7f670c2a1db8 in OSD_ThreadPool::performJob(opencascade::handle<Standard_Failure>&, OSD_ThreadPool::JobInterface*, int) from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0x58
#3  0x7f670c2a1db8 in OSD_ThreadPool::performJob(opencascade::handle<Standard_Failure>&, OSD_ThreadPool::JobInterface*, int) from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0x58
#4  0x7f670c2a2232 in OSD_ThreadPool::EnumeratedThread::performThread() from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0x92
#4  0x7f670c2a2232 in OSD_ThreadPool::EnumeratedThread::performThread() from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0x92
#5  0x7f670c2a228a in OSD_ThreadPool::EnumeratedThread::runThread(void*) from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0xa
#5  0x7f670c2a228a in OSD_ThreadPool::EnumeratedThread::runThread(void*) from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0xa
#5  0x7f670c2a228a in OSD_ThreadPool::EnumeratedThread::runThread(void*) from /tmp/.mount_freecagabOfp/usr/lib/./libTKernel.so.7.8+0xa
#6  /usr/lib/libc.so.6(+0x957eb) [0x7f677e8b87eb]
#6  /usr/lib/libc.so.6(+0x957eb) [0x7f677e8b87eb]
#6  /usr/lib/libc.so.6(+0x957eb) [0x7f677e8b87eb]
#7  /usr/lib/libc.so.6(+0x11918c) [0x7f677e93c18c]
```

### Full version info

```shell
OS: Arch Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0dev.42564 (Git) AppImage
Build date: 2025/07/14 18:51:42
Build type: Release
Branch: main
Hash: dc2f2374b6ab3e3381653fad125b1b619bb49f7c
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.2.5, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: C/Default (C)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Turntable/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.8077/1
Installed mods: 
  * ThreadProfile 1.96.0
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
