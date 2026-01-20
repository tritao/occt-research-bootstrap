# #23818 — PartDesign: Crash when doing a chamfer on an edge connected to a fillet (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#23818`
- URL: https://github.com/FreeCAD/FreeCAD/issues/23818
- State: `open`
- Created: `2025-09-10T14:54:06Z`
- Updated: `2025-11-11T10:45:16Z`
- Comments: `4`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

FC Crashing when chamfering an edge connected to a fillet.

The Part/Body is not valid if you check geometry.
But this should not break FC, right?

Sample file: [crash_chamfer.FCStd.zip](https://github.com/user-attachments/files/22257459/crash_chamfer.FCStd.zip)

This is the edge I want to chamfer.

<img height="365" alt="Image" src="https://github.com/user-attachments/assets/db8eb45a-b7e9-4016-95fa-5429966c38aa" />


### Full version info

```shell
OS: Ubuntu 25.04 (ubuntu:GNOME/ubuntu-xorg/xcb)
Architecture: x86_64
Version: 1.1.0dev.43411 (Git)
Build date: 2025/09/10 13:35:35
Build type: Release
Branch: main
Hash: 8aa527119b6254515bae2f29abe951b60fa2dcb1
Python 3.13.3, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.0, boost 1_83, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, SMESH 7.7.1.0, xerces-c 3.2.4, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Touchpad/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: OpenDark.qss/OpenDark/
Logical DPI/Physical DPI/Pixel Ratio: 96/94.0767/1
Installed mods: 
  * Assembly4.1 0.60.2.1
  * Cables 0.2.1
  * CurvesWB 0.6.64
  * FreeCAD-render 2024.12.15
  * sheetmetal 0.7.24
  * DynamicData 2.74.0
  * InventorLoader 1.5.1
  * diff-tools 0.1.0
  * ose-piping
  * OpenTheme 2025.5.20
  * fasteners 0.5.41
  * osh-autodoc-workbench 0.2.3
  * freecad-povray-render
  * OpticsWorkbench 1.2.2
  * lattice2 1.0.0
  * kicadStepUpMod 11.7.3
```

### Subproject(s) affected?

None

### Anything else?

Dump

```c++
FreeCAD/build on  main [!] took 20m 10.4s …
➜ ./bin/FreeCAD
FreeCAD 1.1.0, Libs: 1.1.0devR43411 (Git)
(C) 2001-2025 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

During initialization the error "No module named 'PySide6.QtSvg'" occurred in /home/lheck/FreeCAD/build/Mod/CAM/InitGui.py
Look into the log file for further information
During initialization the error "[Errno 2] No such file or directory: '"/home/lheck/FreeCAD/build/bin/python" -m pip install "/home/lheck/.local/share/FreeCAD/Mod/InventorLoader/./libs/xlrd-1.2.0.tar.gz"'" occurred in /home/lheck/.local/share/FreeCAD/Mod/InventorLoader/./InitGui.py
Look into the log file for further information
Path WB not found
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Extrusion: end face of tapered along extrusion is empty
This means most probably that the along taper angle is too large or small.
Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x458d0) [0x7bc1ed6458d0]
#1  0x7bc185fd5c7d in Geom2dAPI_ProjectPointOnCurve::Init(gp_Pnt2d const&, opencascade::handle<Geom2d_Curve> const&) from /lib/x86_64-linux-gnu/libTKGeomAlgo.so.7.8+0x1d
#2  0x7bc185fd75d7 in Geom2dAPI_ProjectPointOnCurve::Geom2dAPI_ProjectPointOnCurve(gp_Pnt2d const&, opencascade::handle<Geom2d_Curve> const&) from /lib/x86_64-linux-gnu/libTKGeomAlgo.so.7.8+0x47
#3  0x7bc186f25412 in ChFi3d_Builder::PerformIntersectionAtEnd(int) from /lib/x86_64-linux-gnu/libTKFillet.so.7.8+0x2982
#4  0x7bc186f1c547 in ChFi3d_Builder::PerformOneCorner(int, bool) from /lib/x86_64-linux-gnu/libTKFillet.so.7.8+0x3a17
#5  0x7bc186ecf8ee in ChFi3d_Builder::PerformFilletOnVertex(int) from /lib/x86_64-linux-gnu/libTKFillet.so.7.8+0x50e
#6  0x7bc186ed1a42 in ChFi3d_Builder::Compute() from /lib/x86_64-linux-gnu/libTKFillet.so.7.8+0xaa2
#7  0x7bc18703589d in BRepFilletAPI_MakeChamfer::Build(Message_ProgressRange const&) from /lib/x86_64-linux-gnu/libTKFillet.so.7.8+0x2d
#8  0x7bc188da6590 in BRepBuilderAPI_MakeShape::Shape() from /lib/x86_64-linux-gnu/libTKTopAlgo.so.7.8+0x50
#9  0x7bc1895c346d in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*) from /home/lheck/FreeCAD/build/Mod/Part/Part.so+0x7d
#10  0x7bc1895c3622 in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, Part::TopoShape const&, char const*) from /home/lheck/FreeCAD/build/Mod/Part/Part.so+0x82
#11  0x7bc1895c5492 in Part::TopoShape::makeElementChamfer(Part::TopoShape const&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, Part::ChamferType, double, double, char const*, Part::Flip) from /home/lheck/FreeCAD/build/Mod/Part/Part.so+0x4e2
#12  0x7bc0edfbce0e in PartDesign::Chamfer::execute() from /home/lheck/FreeCAD/build/Mod/PartDesign/_PartDesign.so+0x4be
#13  0x7bc1f097b73a in App::DocumentObject::recompute() from /home/lheck/FreeCAD/build/lib/libFreeCADApp.so+0xba
#14  0x7bc18933a32f in Part::Feature::recompute() from /home/lheck/FreeCAD/build/Mod/Part/Part.so+0xf
#15  0x7bc1f092806c in App::Document::_recomputeFeature(App::DocumentObject*) from /home/lheck/FreeCAD/build/lib/libFreeCADApp.so+0x31c
#16  0x7bc1f092d7ef in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /home/lheck/FreeCAD/build/lib/libFreeCADApp.so+0x60f
#17  0x7bc1f09e7df3 in App::DocumentPy::recompute(_object*) from /home/lheck/FreeCAD/build/lib/libFreeCADApp.so+0x3a3
#18  0x7bc1f09e7f7b in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /home/lheck/FreeCAD/build/lib/libFreeCADApp.so+0x2b
#19  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(+0x177591) [0x7bc1efb77591]
#20  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(_PyObject_MakeTpCall+0x1c6) [0x7bc1efb11d06]
#21  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(_PyEval_EvalFrameDefault+0x10a7) [0x7bc1efc4ca87]
#22  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(PyEval_EvalCode+0xd7) [0x7bc1efc4b8f7]
#23  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(+0x2c9d71) [0x7bc1efcc9d71]
#24  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(+0x2c9f66) [0x7bc1efcc9f66]
#25  /lib/x86_64-linux-gnu/libpython3.13.so.1.0(PyRun_StringFlags+0x78) [0x7bc1efcca968]
#26  0x7bc1f03ea8f6 in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /home/lheck/FreeCAD/build/lib/libFreeCADBase.so+0x66
#27  0x7bc1f1a1578b in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0x8b
#28  0x7bc1f1a15910 in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0xe0
#29  0x7bc1f1a15aa5 in Gui::Command::updateActive() from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0x45
#30  /home/lheck/FreeCAD/build/Mod/PartDesign/PartDesignGui.so(+0x183a05) [0x7bc0ed983a05]
#31  0x7bc0ed984cf2 in finishDressupFeature(Gui::Command const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, Part::Feature*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, bool) from /home/lheck/FreeCAD/build/Mod/PartDesign/PartDesignGui.so+0x552
#32  0x7bc0ed98e6fe in makeChamferOrFillet(Gui::Command*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) from /home/lheck/FreeCAD/build/Mod/PartDesign/PartDesignGui.so+0xde
#33  0x7bc0ed98ea6a in CmdPartDesignChamfer::activated(int) from /home/lheck/FreeCAD/build/Mod/PartDesign/PartDesignGui.so+0x4a
#34  0x7bc1f1a1a317 in Gui::Command::_invoke(int, bool) from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0x227
#35  0x7bc1f1a1a796 in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0x126
#36  /lib/x86_64-linux-gnu/libQt6Core.so.6(+0x1e2129) [0x7bc1edfe2129]
#37  0x7bc1eeb8e264 in QAction::triggered(bool) from /lib/x86_64-linux-gnu/libQt6Gui.so.6+0x44
#38  0x7bc1eeb939e9 in QAction::activate(QAction::ActionEvent) from /lib/x86_64-linux-gnu/libQt6Gui.so.6+0x129
#39  /lib/x86_64-linux-gnu/libQt6Widgets.so.6(+0x2c9822) [0x7bc1ef2c9822]
#40  0x7bc1ef2d6efd in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0xed
#41  0x7bc1ef4021cc in QToolButton::mouseReleaseEvent(QMouseEvent*) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0x2c
#42  0x7bc1ef1f295c in QWidget::event(QEvent*) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0xc4c
#43  0x7bc1ef1980c8 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0x88
#44  0x7bc1ef19e406 in QApplication::notify(QObject*, QEvent*) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0x1036
#45  0x7bc1f1991ce8 in Gui::GUIApplication::notify(QObject*, QEvent*) from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0xc8
#46  0x7bc1edf813f0 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /lib/x86_64-linux-gnu/libQt6Core.so.6+0x150
#47  0x7bc1ef191ff6 in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0x1f6
#48  /lib/x86_64-linux-gnu/libQt6Widgets.so.6(+0x20aaa1) [0x7bc1ef20aaa1]
#49  /lib/x86_64-linux-gnu/libQt6Widgets.so.6(+0x20e06f) [0x7bc1ef20e06f]
#50  0x7bc1ef1980c8 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /lib/x86_64-linux-gnu/libQt6Widgets.so.6+0x88
#51  0x7bc1f1991ce8 in Gui::GUIApplication::notify(QObject*, QEvent*) from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0xc8
#52  0x7bc1edf813f0 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /lib/x86_64-linux-gnu/libQt6Core.so.6+0x150
#53  0x7bc1ee7d91bf in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /lib/x86_64-linux-gnu/libQt6Gui.so.6+0x3cf
#54  0x7bc1ee83e60c in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /lib/x86_64-linux-gnu/libQt6Gui.so.6+0xac
#55  /lib/x86_64-linux-gnu/libQt6XcbQpa.so.6(+0x62446) [0x7bc1e78ab446]
#56  /lib/x86_64-linux-gnu/libglib-2.0.so.0(+0x66de2) [0x7bc1edcf7de2]
#57  /lib/x86_64-linux-gnu/libglib-2.0.so.0(+0xd81f8) [0x7bc1edd691f8]
#58  /lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_iteration+0x33) [0x7bc1edcf8223]
#59  0x7bc1ee1e6c63 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /lib/x86_64-linux-gnu/libQt6Core.so.6+0x73
#60  0x7bc1edf8bd5b in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /lib/x86_64-linux-gnu/libQt6Core.so.6+0x1ab
#61  0x7bc1edf84f7e in QCoreApplication::exec() from /lib/x86_64-linux-gnu/libQt6Core.so.6+0xae
#62  0x7bc1f18a101a in Gui::Application::runApplication() from /home/lheck/FreeCAD/build/lib/libFreeCADGui.so+0xa0a
#63  ./bin/FreeCAD(+0x78df) [0x5a19b54648df]
#64  /lib/x86_64-linux-gnu/libc.so.6(+0x2a578) [0x7bc1ed62a578]
#65  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x8b) [0x7bc1ed62a63b]
#66  ./bin/FreeCAD(+0x7c35) [0x5a19b5464c35]
```

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
