# #18290 — Crash when trying to fillet/chamfer this surface

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18290`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18290
- State: `open`
- Created: `2024-12-04T05:13:08Z`
- Updated: `2025-08-14T14:52:00Z`
- Comments: `3`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `OS: Linux`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Freecad 1.0 crashes whenever I try to chamfer the surface in the screenshot. Its 100% reproducible.

![image](https://github.com/user-attachments/assets/7df35f62-b5c6-4463-be5b-c7e958e61235)


### Full version info

```shell
OS: Ubuntu Core 22 (GNOME/gnome/xcb)
Architecture: x86_64
Version: 1.0.0.38641 +468 (Git) Snap 1202
Build type: Release
Branch: tag: 1.0.0
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.10.12, Qt 5.15.10, Coin 4.0.0, Vtk 7.1.1, OCC 7.7.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * fasteners 0.5.33
  * A2plus 0.4.68
```


### Subproject(s) affected?

None

### Anything else?

Link to the project file: https://github.com/naddeoa/forum-files/blob/master/humidity%20sensor%20holder.FCStd (not sure how to attach it)

Here is the segfault 

```
⟩ snap run freecad
FreeCAD 1.0.0, Libs: 1.0.0R38641 +468 (Git)
(C) 2001-2024 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

Adding snap-specific PYTHONPATH to sys.path: /home/anthony/snap/freecad/common/.local/lib/python3.10/site-packages:/snap/freecad/1202/lib/python3.10/site-packages:/snap/freecad/1202/usr/lib/python3/dist-packages
Qt: Session management error: Could not open network socket
connect failed: No such file or directory
Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x42520) [0x78cc04c00520]
#1  0x78cbebf54564 in BRep_Tool::CurveOnSurface(TopoDS_Edge const&, opencascade::handle<Geom_Surface> const&, TopLoc_Location const&, double&, double&, bool*) from /snap/freecad/1202/usr/lib/libTKBRep.so.7.7+0x174
#2  0x78cbebf54642 in BRep_Tool::CurveOnSurface(TopoDS_Edge const&, TopoDS_Face const&, double&, double&, bool*) from /snap/freecad/1202/usr/lib/libTKBRep.so.7.7+0xb2
#3  0x78cbebf62a6b in BRepAdaptor_Curve2d::Initialize(TopoDS_Edge const&, TopoDS_Face const&) from /snap/freecad/1202/usr/lib/libTKBRep.so.7.7+0xdb
#4  0x78cbd8bf9a36 in ChFi3d_Builder::StartSol(opencascade::handle<ChFiDS_Spine> const&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, opencascade::handle<BRepAdaptor_Curve2d>&, double&, opencascade::handle<ChFiDS_SurfData> const&, bool, int, opencascade::handle<BRepAdaptor_Surface>&, opencascade::handle<BRepAdaptor_Curve2d>&, bool&, bool&, bool&, bool&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, bool, TopoDS_Vertex const&) const from /snap/freecad/1202/usr/lib/libTKFillet.so.7.7+0xd06
#5  0x78cbd8bfecab in ChFi3d_Builder::PerformSetOfSurfOnElSpine(opencascade::handle<ChFiDS_ElSpine> const&, opencascade::handle<ChFiDS_Stripe>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, bool) from /snap/freecad/1202/usr/lib/libTKFillet.so.7.7+0x63b
#6  0x78cbd8c01558 in ChFi3d_Builder::PerformSetOfKGen(opencascade::handle<ChFiDS_Stripe>&, bool) from /snap/freecad/1202/usr/lib/libTKFillet.so.7.7+0x108
#7  0x78cbd8c069a9 in ChFi3d_Builder::PerformSetOfSurf(opencascade::handle<ChFiDS_Stripe>&, bool) from /snap/freecad/1202/usr/lib/libTKFillet.so.7.7+0x69
#8  0x78cbd8bcbb5e in ChFi3d_Builder::Compute() from /snap/freecad/1202/usr/lib/libTKFillet.so.7.7+0x42e
#9  0x78cbd8d5d111 in BRepFilletAPI_MakeChamfer::Build(Message_ProgressRange const&) from /snap/freecad/1202/usr/lib/libTKFillet.so.7.7+0x31
#10  0x78cbe8d03d8d in BRepBuilderAPI_MakeShape::Shape() from /snap/freecad/1202/usr/lib/libTKTopAlgo.so.7.7+0x8d
#11  0x78cbdafbf376 in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*) from /snap/freecad/1202/usr/lib/Part.so+0x86
#12  0x78cbdafbf514 in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, Part::TopoShape const&, char const*) from /snap/freecad/1202/usr/lib/Part.so+0x84
#13  0x78cbdafc15ff in Part::TopoShape::makeElementChamfer(Part::TopoShape const&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, Part::ChamferType, double, double, char const*, Part::Flip) from /snap/freecad/1202/usr/lib/Part.so+0x39f
#14  0x78cbcc2b6fce in PartDesign::Chamfer::execute() from /snap/freecad/1202/usr/lib/_PartDesign.so+0x2ee
#15  0x78cc06fde5da in App::DocumentObject::recompute() from /snap/freecad/1202/usr/lib/libFreeCADApp.so+0xba
#16  0x78cbdad5b9cd in Part::Feature::recompute() from /snap/freecad/1202/usr/lib/Part.so+0xd
#17  0x78cc06f788ed in App::Document::_recomputeFeature(App::DocumentObject*) from /snap/freecad/1202/usr/lib/libFreeCADApp.so+0x38d
#18  0x78cc06f8021b in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /snap/freecad/1202/usr/lib/libFreeCADApp.so+0x65b
#19  0x78cc0704f658 in App::DocumentPy::recompute(_object*) from /snap/freecad/1202/usr/lib/libFreeCADApp.so+0x2e8
#20  0x78cc0704f79c in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /snap/freecad/1202/usr/lib/libFreeCADApp.so+0x2c
#21  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(+0x128008) [0x78cc06597008]
#22  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(_PyObject_MakeTpCall+0x8c) [0x78cc0654eadc]
#23  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(_PyEval_EvalFrameDefault+0x9dbc) [0x78cc064eaa1c]
#24  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(+0x1c23af) [0x78cc066313af]
#25  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(PyEval_EvalCode+0xbe) [0x78cc0662c3de]
#26  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(+0x20c4cd) [0x78cc0667b4cd]
#27  /snap/freecad/1202/usr/lib/x86_64-linux-gnu/libpython3.10.so.1.0(PyRun_StringFlags+0x79) [0x78cc0667c4f9]
#28  0x78cc06b9518c in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /snap/freecad/1202/usr/lib/libFreeCADBase.so+0x6c
#29  0x78cc07ae465c in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0x8c
#30  0x78cc07ae47e7 in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0xe7
#31  0x78cc07ae4917 in Gui::Command::updateActive() from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0x47
#32  0x78cbc25788d5 in finishFeature(Gui::Command const*, App::DocumentObject*, App::DocumentObject*, bool, bool) from /snap/freecad/1202/usr/lib/PartDesignGui.so+0x1c5
#33  0x78cbc257bf57 in finishDressupFeature(Gui::Command const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, Part::Feature*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, bool) from /snap/freecad/1202/usr/lib/PartDesignGui.so+0x6c7
#34  0x78cbc258a766 in makeChamferOrFillet(Gui::Command*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) from /snap/freecad/1202/usr/lib/PartDesignGui.so+0xd6
#35  0x78cbc258ab00 in CmdPartDesignChamfer::activated(int) from /snap/freecad/1202/usr/lib/PartDesignGui.so+0x50
#36  0x78cc07aeaf46 in Gui::Command::_invoke(int, bool) from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0x246
#37  0x78cc07aeb406 in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0x126
#38  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Core.so.5(+0x2f48f4) [0x78cc053448f4]
#39  0x78cc05e9fc26 in QAction::triggered(bool) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x46
#40  0x78cc05ea291c in QAction::activate(QAction::ActionEvent) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0xac
#41  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5(+0x26496a) [0x78cc05f9e96a]
#42  0x78cc05f9eac7 in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0xf7
#43  0x78cc0609d74e in QToolButton::mouseReleaseEvent(QMouseEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0xe
#44  0x78cc05ee994e in QWidget::event(QEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x20e
#45  0x78cc05ea6763 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x83
#46  0x78cc05eae3a4 in QApplication::notify(QObject*, QEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0xa84
#47  0x78cc07a879b0 in Gui::GUIApplication::notify(QObject*, QEvent*) from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0xd0
#48  0x78cc0530ce4a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x13a
#49  0x78cc05eace87 in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x1b7
#50  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5(+0x1c91cb) [0x78cc05f031cb]
#51  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5(+0x1cc525) [0x78cc05f06525]
#52  0x78cc05ea6763 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x83
#53  0x78cc07a879b0 in Gui::GUIApplication::notify(QObject*, QEvent*) from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0xd0
#54  0x78cc0530ce4a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x13a
#55  0x78cc057351e7 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Gui.so.5+0x687
#56  0x78cc05708dbc in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Gui.so.5+0xac
#57  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/qt5/plugins/platforms/../../../libQt5XcbQpa.so.5(+0x76f5e) [0x78cbfedd4f5e]
#58  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_dispatch+0x26b) [0x78cc02dc1d3b]
#59  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0(+0xab258) [0x78cc02e17258]
#60  /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_iteration+0x33) [0x78cc02dbf3e3]
#61  0x78cc05366338 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x68
#62  0x78cc0530b76b in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x12b
#63  0x78cc05313d14 in QCoreApplication::exec() from /snap/freecad/1202/kf5/usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x94
#64  0x78cc079c2c88 in Gui::Application::runApplication() from /snap/freecad/1202/usr/lib/libFreeCADGui.so+0x6b8
#65  /snap/freecad/1202/usr/bin/FreeCAD(+0x9791) [0x63dc61181791]
#66  /lib/x86_64-linux-gnu/libc.so.6(+0x29d90) [0x78cc04be7d90]
#67  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x80) [0x78cc04be7e40]
#68  /snap/freecad/1202/usr/bin/FreeCAD(+0x9b55) [0x63dc61181b55]

```

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
