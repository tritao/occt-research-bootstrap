# #22519 — FreeCAD crashes on Chamfer

- Repo: `FreeCAD/FreeCAD`
- Issue: `#22519`
- URL: https://github.com/FreeCAD/FreeCAD/issues/22519
- State: `open`
- Created: `2025-07-16T14:49:53Z`
- Updated: `2025-07-26T04:49:54Z`
- Comments: `9`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `OS: Linux`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

On the latest FreeCAD AppImage when I call chamfer on a relatively simple body, the application crashes with the following backtrace:

```
❯ ~/Downloads/FreeCAD_1.0.1-conda-Linux-x86_64-py311.AppImage
FreeCAD 1.0.1, Libs: 1.0.1R39285 (Git)
(C) 2001-2025 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

(qt.qpa.plugin) Could not find the Qt platform plugin "wayland" in ""
Cannot access /home/finkel/.local/share/FreeCAD/Mod/Freecad-Built-in-themes-beta/Classic light
Migrating Start Workbench to Start command... done.
Program received signal SIGSEGV, Segmentation fault.
#0  /usr/lib/libc.so.6(+0x446a0) [0x7ff7b08446a0]
#1  0x7ff78424db94 in BRep_Tool::CurveOnSurface(TopoDS_Edge const&, opencascade::handle<Geom_Surface> const&, TopLoc_Location const&, double&, double&, bool*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./libTKBRep.so.7.8+0x174
#2  0x7ff78424dc6b in BRep_Tool::CurveOnSurface(TopoDS_Edge const&, TopoDS_Face const&, double&, double&, bool*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./libTKBRep.so.7.8+0xab
#3  0x7ff78425bfa4 in BRepAdaptor_Curve2d::Initialize(TopoDS_Edge const&, TopoDS_Face const&) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./libTKBRep.so.7.8+0xf4
#4  0x7ff744347f20 in ChFi3d_Builder::StartSol(opencascade::handle<ChFiDS_Spine> const&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, opencascade::handle<BRepAdaptor_Curve2d>&, double&, opencascade::handle<ChFiDS_SurfData> const&, bool, int, opencascade::handle<BRepAdaptor_Surface>&, opencascade::handle<BRepAdaptor_Curve2d>&, bool&, bool&, bool&, bool&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, bool, TopoDS_Vertex const&) const from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/././libTKFillet.so.7.8+0xd90
#5  0x7ff74434c987 in ChFi3d_Builder::PerformSetOfSurfOnElSpine(opencascade::handle<ChFiDS_ElSpine> const&, opencascade::handle<ChFiDS_Stripe>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/././libTKFillet.so.7.8+0x6b7
#6  0x7ff744351c71 in ChFi3d_Builder::PerformSetOfKGen(opencascade::handle<ChFiDS_Stripe>&, bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/././libTKFillet.so.7.8+0xd1
#7  0x7ff744355faa in ChFi3d_Builder::PerformSetOfSurf(opencascade::handle<ChFiDS_Stripe>&, bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/././libTKFillet.so.7.8+0x6a
#8  0x7ff74431a484 in ChFi3d_Builder::Compute() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/././libTKFillet.so.7.8+0x4a4
#9  0x7ff74449abb6 in BRepFilletAPI_MakeChamfer::Build(Message_ProgressRange const&) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/././libTKFillet.so.7.8+0x36
#10  0x7ff76c669a4d in BRepBuilderAPI_MakeShape::Shape() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./libTKTopAlgo.so.7.8+0x8d
#11  0x7ff76cd08cf6 in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./Part.so+0x186
#12  0x7ff76cd08de3 in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, Part::TopoShape const&, char const*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./Part.so+0x83
#13  0x7ff76cd0ac0b in Part::TopoShape::makeElementChamfer(Part::TopoShape const&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, Part::ChamferType, double, double, char const*, Part::Flip) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./Part.so+0x32b
#14  0x7ff73c59aedd in PartDesign::Chamfer::execute() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/_PartDesign.so+0x2dd
#15  0x7ff7b2674332 in App::DocumentObject::recompute() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libFreeCADApp.so+0xc2
#16  0x7ff76cabfa5c in Part::Feature::recompute() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/lib/./Part.so+0xc
#17  0x7ff7b264927c in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libFreeCADApp.so+0x32c
#18  0x7ff7b265985c in App::Document::recomputeFeature(App::DocumentObject*, bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libFreeCADApp.so+0xfc
#19  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Core.so.5(+0x1dffbf) [0x7ff7b0fdffbf]
#20  0x7ff7b1c008c2 in QAbstractButton::toggled(bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0x30
#21  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5(+0x20167a) [0x7ff7b1c0167a]
#22  0x7ff7b1c020f1 in QAbstractButton::setChecked(bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0xff
#23  0x7ff7b1c0b9fc in QCheckBox::nextCheckState() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0x30
#24  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5(+0x201dc8) [0x7ff7b1c01dc8]
#25  0x7ff7b1c01ea7 in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0x7b
#26  0x7ff7b1b938fa in QWidget::event(QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0x122
#27  0x7ff7b1b69fca in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0xd8
#28  0x7ff7b1b6e300 in QApplication::notify(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0x65e
#29  0x7ff7b376a939 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libFreeCADGui.so+0xc9
#30  0x7ff7b0fc3158 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Core.so.5+0x8e
#31  0x7ff7b1b6d90f in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0x28b
#32  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5(+0x1a2518) [0x7ff7b1ba2518]
#33  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5(+0x1a366f) [0x7ff7b1ba366f]
#34  0x7ff7b1b69fca in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Widgets.so.5+0xd8
#35  0x7ff7b376a939 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libFreeCADGui.so+0xc9
#36  0x7ff7b0fc3158 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Core.so.5+0x8e
#37  0x7ff7b1509e3e in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Gui.so.5+0x772
#38  0x7ff7b14f66bb in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Gui.so.5+0x57
#39  /tmp/finkel/.mount_FreeCAmIhLMH/usr/plugins/platforms/../../lib/libQt5XcbQpa.so.5(+0x56173) [0x7ff7abc79173]
#40  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/./libglib-2.0.so.0(+0x5b5e6) [0x7ff7b0b1b5e6]
#41  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/./libglib-2.0.so.0(+0x5e7b7) [0x7ff7b0b1e7b7]
#42  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7ff7b0b1eece]
#43  0x7ff7b0ff35af in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Core.so.5+0x59
#44  0x7ff7b0fc0dda in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Core.so.5+0x188
#45  0x7ff7b0fc4ea5 in QCoreApplication::exec() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libQt5Core.so.5+0xfb
#46  0x7ff7b36c96c4 in Gui::Application::runApplication() from /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/../lib/libFreeCADGui.so+0x8a4
#47  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/freecad(+0x78b7) [0x56482b81e8b7]
#48  /usr/lib/libc.so.6(+0x27bcb) [0x7ff7b0827bcb]
#49  /usr/lib/libc.so.6(__libc_start_main+0x8b) [0x7ff7b0827c8b]
#50  /tmp/finkel/.mount_FreeCAmIhLMH/usr/bin/freecad(+0x7c2a) [0x56482b81ec2a]
```

I observe the same behaviour in flatpak

### Full version info

```shell
OS: CachyOS (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.0.1.39285 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.1)
Hash: 878f0b8c9c72c6f215833a99f2762bc3a3cf2abd
Python 3.11.12, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * Dracula 0.0.8
  * Freecad-Built-in-themes-beta 1.2.2
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
