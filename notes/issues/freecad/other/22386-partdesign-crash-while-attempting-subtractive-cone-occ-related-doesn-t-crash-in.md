# #22386 — PartDesign: crash while attempting subtractive cone (OCC related; doesn't crash in OCC 8.0.0.rc1-7aa85582ad)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22386`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22386
- State: `open`
- Created: `2025-07-08T00:46:23Z`
- Updated: `2025-09-27T23:39:23Z`
- Comments: `4`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `3rd party: Addon/Macro`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

while experimenting with threadprofile workbench (found via addons)
i selected the circle sketch in the attached body then did subtracted cone in the part design workbench
it crashes instantly
[crash.FCStd.zip](https://github.com/user-attachments/files/21112079/crash.FCStd.zip)

console output:
```
FreeCAD 1.1.0, Libs: 1.1.0devR42474 (Git)
(C) 2001-2025 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

Detected locale "C" with character encoding "ANSI_X3.4-1968", which is not UTF-8.
Qt depends on a UTF-8 locale, and has switched to "C.UTF-8" instead.
If this causes problems, reconfigure your locale. See the locale(1) manual
for more information.
/home/runner/work/FreeCAD-Bundle/FreeCAD-Bundle/conda/linux/AppDir/usr/share/libdrm/amdgpu.ids: No such file or directory
Program received signal SIGSEGV, Segmentation fault.
#0  /usr/lib/libc.so.6(+0x3def0) [0x7f1e3b460ef0]
#1  0x7f1dc42f8b7a in BOPDS_DS::ShapeInfo(int) const from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0x1a
#2  0x7f1dc42f8baa in BOPDS_DS::Shape(int) const from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0xa
#3  0x7f1dc430256a in BOPDS_DS::IsValidShrunkData(opencascade::handle<BOPDS_PaveBlock> const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0xca
#4  0x7f1dc43b3711 in BOPAlgo_PaveFiller::ForceInterfEF(NCollection_IndexedMap<opencascade::handle<BOPDS_PaveBlock>, NCollection_DefaultHasher<opencascade::handle<BOPDS_PaveBlock> > > const&, Message_ProgressRange const&, bool) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0x4e1
#5  0x7f1dc43b9dc6 in BOPAlgo_PaveFiller::PutSEInOtherFaces(Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0x3f6
#6  0x7f1dc43cf47b in BOPAlgo_PaveFiller::MakeBlocks(Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0x2b8b
#7  0x7f1dc438e591 in BOPAlgo_PaveFiller::PerformInternal(Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0xf21
#8  0x7f1dc438f1de in BOPAlgo_PaveFiller::Perform(Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0x4e
#9  0x7f1dc42eda28 in BRepAlgoAPI_BuilderAlgo::IntersectShapes(NCollection_List<TopoDS_Shape> const&, Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0x138
#10  0x7f1dc42ebe57 in BRepAlgoAPI_BooleanOperation::Build(Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/././libTKBO.so.7.8+0xcf7
#11  0x7f1dc9b8c09e in FCBRepAlgoAPI_BooleanOperation::Build(Message_ProgressRange const&) from /tmp/.mount_freecaHnOHLA/usr/lib/./Part.so+0x7e
#12  0x7f1dc9b272dc in Part::TopoShape::makeElementBoolean(char const*, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*, double) from /tmp/.mount_freecaHnOHLA/usr/lib/./Part.so+0x63c
#13  0x7f1d56f268af in PartDesign::FeaturePrimitive::execute(TopoDS_Shape const&) from /tmp/.mount_freecaHnOHLA/usr/lib/_PartDesign.so+0x32f
#14  0x7f1d56f2770c in PartDesign::Cone::execute() from /tmp/.mount_freecaHnOHLA/usr/lib/_PartDesign.so+0x27c
#15  0x7f1e3d8afd32 in App::DocumentObject::recompute() from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADApp.so+0xc2
#16  0x7f1dc98bbc7c in Part::Feature::recompute() from /tmp/.mount_freecaHnOHLA/usr/lib/./Part.so+0xc
#17  0x7f1e3d88afec in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADApp.so+0x32c
#18  0x7f1e3d893d14 in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADApp.so+0x634
#19  0x7f1e3d91528c in App::DocumentPy::recompute(_object*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADApp.so+0x3ac
#20  0x7f1e3d9154a4 in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADApp.so+0x24
#21  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(+0x1faeb8) [0x7f1e3dffaeb8]
#22  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(_PyObject_MakeTpCall+0x2b4) [0x7f1e3dfd9c04]
#23  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(_PyEval_EvalFrameDefault+0x6e7) [0x7f1e3dfe53c7]
#24  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(+0x29ef1d) [0x7f1e3e09ef1d]
#25  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(PyEval_EvalCode+0xa4) [0x7f1e3e09e914]
#26  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(+0x2bced3) [0x7f1e3e0bced3]
#27  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(+0x2b8aea) [0x7f1e3e0b8aea]
#28  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libpython3.11.so.1.0(PyRun_StringFlags+0x69) [0x7f1e3e0acfe9]
#29  0x7f1e3d3b9428 in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADBase.so+0x68
#30  0x7f1e3ebc1cc4 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0x94
#31  0x7f1e3ebc1e4f in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0xdf
#32  0x7f1e3ebc1fd4 in Gui::Command::updateActive() from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0x44
#33  0x7f1d4fb5ec78 in CmdPrimtiveCompSubtractive::activated(int) from /tmp/.mount_freecaHnOHLA/usr/lib/PartDesignGui.so+0x668
#34  0x7f1e3ebcad7f in Gui::Command::_invoke(int, bool) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0x21f
#35  0x7f1e3ebcb12f in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0x12f
#36  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6(+0x31684a) [0x7f1e3bb1684a]
#37  0x7f1e3c5cf214 in QActionGroup::triggered(QAction*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0x44
#38  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6(+0x31684a) [0x7f1e3bb1684a]
#39  0x7f1e3c5ca8c7 in QAction::triggered(bool) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0x47
#40  0x7f1e3c5cddc6 in QAction::activate(QAction::ActionEvent) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0xf6
#41  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x3cf445) [0x7f1e3cdcf445]
#42  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x449332) [0x7f1e3ce49332]
#43  0x7f1e3cfc3864 in QWidget::event(QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0xa64
#44  0x7f1e3cfb3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x88
#45  0x7f1e3cfb4cbd in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0xdad
#46  0x7f1e3eb69be9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0xc9
#47  0x7f1e3bb5fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x17a
#48  0x7f1e3cfbbe7c in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x1ec
#49  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x5bee09) [0x7f1e3cfbee09]
#50  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x5c5440) [0x7f1e3cfc5440]
#51  0x7f1e3cfb3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x88
#52  0x7f1e3eb69be9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0xc9
#53  0x7f1e3bb5fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x17a
#54  0x7f1e3c1d1970 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0x810
#55  0x7f1e3c231e14 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0xb4
#56  /tmp/.mount_freecaHnOHLA/usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6(+0x58f90) [0x7f1e36a45f90]
#57  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/./libglib-2.0.so.0(+0x5b646) [0x7f1e3a1bf646]
#58  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/./libglib-2.0.so.0(+0x5e817) [0x7f1e3a1c2817]
#59  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7f1e3a1c2f2e]
#60  0x7f1e3b8f6b12 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x72
#61  0x7f1e3bb9747c in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x25c
#62  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x446bb0) [0x7f1e3ce46bb0]
#63  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x2f7068) [0x7f1e3ccf7068]
#64  0x7f1e3ccf766c in QToolButton::mousePressEvent(QMouseEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x1dc
#65  0x7f1e3cfc388c in QWidget::event(QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0xa8c
#66  0x7f1e3cfb3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x88
#67  0x7f1e3cfb4cbd in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0xdad
#68  0x7f1e3eb69be9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0xc9
#69  0x7f1e3bb5fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x17a
#70  0x7f1e3cfbbe7c in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x1ec
#71  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x5be8c7) [0x7f1e3cfbe8c7]
#72  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6(+0x5c5440) [0x7f1e3cfc5440]
#73  0x7f1e3cfb3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Widgets.so.6+0x88
#74  0x7f1e3eb69be9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0xc9
#75  0x7f1e3bb5fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x17a
#76  0x7f1e3c1d1970 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0x810
#77  0x7f1e3c231e14 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Gui.so.6+0xb4
#78  /tmp/.mount_freecaHnOHLA/usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6(+0x58f90) [0x7f1e36a45f90]
#79  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/./libglib-2.0.so.0(+0x5b646) [0x7f1e3a1bf646]
#80  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/./libglib-2.0.so.0(+0x5e817) [0x7f1e3a1c2817]
#81  /tmp/.mount_freecaHnOHLA/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7f1e3a1c2f2e]
#82  0x7f1e3b8f6b12 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x72
#83  0x7f1e3bb9747c in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x25c
#84  0x7f1e3bb977da in QCoreApplication::exec() from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libQt6Core.so.6+0x9a
#85  0x7f1e3eac2d06 in Gui::Application::runApplication() from /tmp/.mount_freecaHnOHLA/usr/bin/../lib/libFreeCADGui.so+0x7d6
#86  /tmp/.mount_freecaHnOHLA/usr/bin/freecad(+0x6d34) [0x56240743cd34]
#87  /usr/lib/libc.so.6(+0x276b5) [0x7f1e3b44a6b5]
#88  /usr/lib/libc.so.6(__libc_start_main+0x89) [0x7f1e3b44a769]
#89  /tmp/.mount_freecaHnOHLA/usr/bin/freecad(+0x703b) [0x56240743d03b]
```

### Full version info

```shell
OS: Arch Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0dev.42474 (Git) AppImage
Build date: 2025/07/04 04:10:37
Build type: Release
Branch: main
Hash: 927d302401caad6a9e518584e0665ae9f61509f2
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
