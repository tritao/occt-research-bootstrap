# #26142 — Part: 3D Offset crashes on cloned body

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26142`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26142
- State: `open`
- Created: `2025-12-14T02:00:48Z`
- Updated: `2025-12-20T12:51:06Z`
- Comments: `3`
- Labels: `Mod: Part`, `Status: Needs confirmation`, `3rd party: OCC`, `Type: Crash`, `non-blocker`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

Part

### Problem description

I'm trying to create a hole in one body with another body, with a clearance.  If I clone my hole part then run Part -> 3D Offset on the clone, FreeCAD crashes.

Environment: Linux (Fedora 41 x86_64).
FreeCAD version: 1.1rc1

### Steps to reproduce

[offset-crash.zip](https://github.com/user-attachments/files/24146913/offset-crash.zip)

- Load attached file.
- Select Part Design workbench.
- Click on `InternalBody` in tree.
- Click on orange sheep to clone `InternalBody` (creates new body called `Body`)
- Expand `Body`, showing `Clone`.
- Click on `Clone`.
- Switch to Part workbench.
- Select Part -> 3D Offset.

This causes FreeCAD to segfault.


### Expected behavior

The cloned body "swells" by a specified amount.

### Actual behavior

FreeCAD crashes.

Terminal output:
```
$ ~/AppImage/FreeCAD_1.1rc1-Linux-x86_64-py311.AppImage offset-crash.FCStd 
FreeCAD 1.1.0, Libs: 1.1.0rc1R20251125 (Git shallow)
(C) 2001-2025 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

/home/runner/work/FreeCAD/FreeCAD/package/rattler-build/.pixi/envs/default/share/libdrm/amdgpu.ids: No such file or directory
Program received signal SIGSEGV, Segmentation fault.
#0  /lib64/libc.so.6(+0x1a450) [0x7f8089954450]
#1  0x7f80061d16c7 in BRepClass3d_SClassifier::Perform(BRepClass3d_SolidExplorer&, gp_Pnt const&, double) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKTopAlgo.so.7.8+0x47
#2  0x7f8006173565 in BRepCheck_Solid::Minimum() from /tmp/.mount_FreeCANNALNo/usr/lib/libTKTopAlgo.so.7.8+0x1555
#3  0x7f8006171dfc in BRepCheck_Solid::BRepCheck_Solid(TopoDS_Solid const&) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKTopAlgo.so.7.8+0x2c
#4  0x7f8006156911 in BRepCheck_Analyzer::Put(TopoDS_Shape const&, bool) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKTopAlgo.so.7.8+0xa1
#5  0x7f800615772a in BRepCheck_Analyzer::Init(TopoDS_Shape const&, bool) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKTopAlgo.so.7.8+0x8a
#6  0x7f8007360b62 in BRepOffset_MakeOffset::MakeSolid(Message_ProgressRange const&) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKOffset.so.7.8+0x482
#7  0x7f800736249e in BRepOffset_MakeOffset::MakeOffsetShape(Message_ProgressRange const&) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKOffset.so.7.8+0x6ce
#8  0x7f80072d920b in BRepOffsetAPI_MakeOffsetShape::PerformByJoin(TopoDS_Shape const&, double, double, BRepOffset_Mode, bool, bool, GeomAbs_JoinType, bool, Message_ProgressRange const&) from /tmp/.mount_FreeCANNALNo/usr/lib/libTKOffset.so.7.8+0x8b
#9  0x7f80097e409b in Part::TopoShape::makeElementOffset(Part::TopoShape const&, double, double, bool, bool, short, Part::JoinType, Part::FillType, char const*) from /tmp/.mount_FreeCANNALNo/usr/lib/Part.so+0xbb
#10  0x7f800951cad7 in Part::Offset::execute() from /tmp/.mount_FreeCANNALNo/usr/lib/Part.so+0x1d7
#11  0x7f808db9e7ab in App::DocumentObject::recompute() from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADApp.so+0x6b
#12  0x7f8009521e8a in Part::Feature::recompute() from /tmp/.mount_FreeCANNALNo/usr/lib/Part.so+0xa
#13  0x7f808db51d8c in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADApp.so+0x2bc
#14  0x7f808db4ff28 in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADApp.so+0xba8
#15  0x7f808dc160e6 in App::DocumentPy::recompute(_object*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADApp.so+0x346
#16  0x7f808dc0e6a8 in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADApp.so+0x48
#17  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(+0x1faeb8) [0x7f808c3faeb8]
#18  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(_PyObject_MakeTpCall+0x2b4) [0x7f808c3d9c04]
#19  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(_PyEval_EvalFrameDefault+0x6e7) [0x7f808c3e53c7]
#20  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(+0x29ef1d) [0x7f808c49ef1d]
#21  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(PyEval_EvalCode+0xa4) [0x7f808c49e914]
#22  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(+0x2bced3) [0x7f808c4bced3]
#23  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(+0x2b8aea) [0x7f808c4b8aea]
#24  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libpython3.11.so.1.0(PyRun_StringFlags+0x69) [0x7f808c4acfe9]
#25  0x7f808d580091 in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADBase.so+0x71
#26  0x7f808fdf2d51 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0xa1
#27  0x7f808fdf2bdf in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0xdf
#28  0x7f808fdf478d in Gui::Command::updateActive() from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0x3d
#29  0x7f7fb1d7d91a in CmdPartOffset::activated(int) from /tmp/.mount_FreeCANNALNo/usr/lib/PartGui.so+0x24a
#30  0x7f808fdf17fa in Gui::Command::_invoke(int, bool) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0x23a
#31  0x7f808fdf1570 in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0x150
#32  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Core.so.6(+0x31684a) [0x7f808a11684a]
#33  0x7f808abca8c7 in QAction::triggered(bool) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Gui.so.6+0x47
#34  0x7f808abcddc6 in QAction::activate(QAction::ActionEvent) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Gui.so.6+0xf6
#35  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6(+0x3cf445) [0x7f808b3cf445]
#36  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6(+0x449332) [0x7f808b449332]
#37  0x7f808b5c3864 in QWidget::event(QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6+0xa64
#38  0x7f808b5b3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6+0x88
#39  0x7f808b5b4cbd in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6+0xdad
#40  0x7f808fd8d3c8 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0x78
#41  0x7f808a15fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Core.so.6+0x17a
#42  0x7f808b5bbe7c in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6+0x1ec
#43  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6(+0x5bee09) [0x7f808b5bee09]
#44  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6(+0x5c5440) [0x7f808b5c5440]
#45  0x7f808b5b3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Widgets.so.6+0x88
#46  0x7f808fd8d3c8 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0x78
#47  0x7f808a15fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Core.so.6+0x17a
#48  0x7f808a7d1970 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Gui.so.6+0x810
#49  0x7f808a831e14 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Gui.so.6+0xb4
#50  /tmp/.mount_FreeCANNALNo/usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6(+0x58f90) [0x7f80786eaf90]
#51  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/./libglib-2.0.so.0(+0x5b646) [0x7f8087108646]
#52  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/./libglib-2.0.so.0(+0x5e817) [0x7f808710b817]
#53  /tmp/.mount_FreeCANNALNo/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7f808710bf2e]
#54  0x7f8089ef6b12 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Core.so.6+0x72
#55  0x7f808a19747c in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Core.so.6+0x25c
#56  0x7f808a1977da in QCoreApplication::exec() from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libQt6Core.so.6+0x9a
#57  0x7f808fcb51ad in Gui::Application::runApplication() from /tmp/.mount_FreeCANNALNo/usr/bin/../lib/libFreeCADGui.so+0xd5d
#58  /tmp/.mount_FreeCANNALNo/usr/bin/freecad(+0x9bb5) [0x56512a8b1bb5]
#59  /lib64/libc.so.6(+0x3448) [0x7f808993d448]
#60  /lib64/libc.so.6(__libc_start_main+0x8b) [0x7f808993d50b]
#61  /tmp/.mount_FreeCANNALNo/usr/bin/freecad(+0x8cb9) [0x56512a8b0cb9]
$
```
There should be no set of inputs or user actions which can crash an app.  

### Development version About Info (in Safe Mode)

Crash in 1.1rc1 still occurs in safe mode.

Crash also occurs in Development Build weekly-2025.12.10.

Info from 1.1rc1

```
OS: Fedora Linux 41 (Forty One) (X-Cinnamon/cinnamon/xcb)
Architecture: x86_64
Version: 1.1.0rc1.20251125 (Git shallow) AppImage
Build date: 2025/11/25 17:53:08
Build type: Release
Branch: (HEAD detached at 5376760)
Hash: 53767601ea65de7cd9f6590e7d5856afc0841635
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/Australia (en_AU)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.5973/1
```

### Last known good version (optional)

```shell

```
