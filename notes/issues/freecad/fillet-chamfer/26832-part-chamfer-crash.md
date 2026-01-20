# #26832 — Part: Chamfer Crash

- Repo: `FreeCAD/FreeCAD`
- Issue: `#26832`
- URL: https://github.com/FreeCAD/FreeCAD/issues/26832
- State: `open`
- Created: `2026-01-10T22:15:41Z`
- Updated: `2026-01-11T15:26:57Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Status: Needs example file`, `Status: Needs test on dev version`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Problem description

On a fairly complex part, a chamfer that would descend below an internal corner causes FreeCAD 1.0.2 to crash (i.e. vanish completely).  Upon relaunch, the active file is **not** presented as a recovery option.


### Workbench affected?

Part

### Steps to reproduce

1. Open the attached FCStd file in FreeCAD 1.0.2
2. Select the Part workbench
3. Click the Chamfer object in the tree
Optional Path 1: 
3. Select the Chamfer tool
4. Mark Edge234
5. Click OK (accepting default 1.0 mm chamfer)
6. Crash!
Optional Path 2:
3. Select Edge234 as indicated in the attached screenshot
4. Click the Chamfer tool
5. Click OK (accepting default 1.0 mm chamfer)
6. Crash!

The crash appears to occur because the chamfer descends below the edge of the outer shelf there (Edge 17); if the chamfer width is reduced so as not to descend below that edge, the chamfer succeeds.

[Dremel Circle Jig-Crash.zip](https://github.com/user-attachments/files/24546692/Dremel.Circle.Jig-Crash.zip)

<img width="665" height="422" alt="Image" src="https://github.com/user-attachments/assets/c097dcb5-8d29-4803-a98b-1ff94c0b0de3" />

### Expected behavior

Any of the following:
- FreeCAD does not crash and:
   - The chamfer is not created,or
   - The part disappears (as is the common result of Part Design operational failures), or
   - The chamfer is created, generating a cutout below the problematic edge (ideal)

### Actual behavior

FreeCAD crashes (the application is forcibly terminated).

1.1rc2 Safe Mode seg fault dump:
```
Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x3c050) [0x7f9f96a5b050]
#1  0x7f9f68a0db94 in BRep_Tool::CurveOnSurface(TopoDS_Edge const&, opencascade::handle<Geom_Surface> const&, TopLoc_Location const&, double&, double&, bool*) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKBRep.so.7.8+0x174
#2  0x7f9f68a0dc6b in BRep_Tool::CurveOnSurface(TopoDS_Edge const&, TopoDS_Face const&, double&, double&, bool*) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKBRep.so.7.8+0xab
#3  0x7f9f68a1bfa4 in BRepAdaptor_Curve2d::Initialize(TopoDS_Edge const&, TopoDS_Face const&) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKBRep.so.7.8+0xf4
#4  0x7f9f68f47f20 in ChFi3d_Builder::StartSol(opencascade::handle<ChFiDS_Spine> const&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, opencascade::handle<BRepAdaptor_Curve2d>&, double&, opencascade::handle<ChFiDS_SurfData> const&, bool, int, opencascade::handle<BRepAdaptor_Surface>&, opencascade::handle<BRepAdaptor_Curve2d>&, bool&, bool&, bool&, bool&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, bool, TopoDS_Vertex const&) const from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKFillet.so.7.8+0xd90
#5  0x7f9f68f4c8f4 in ChFi3d_Builder::PerformSetOfSurfOnElSpine(opencascade::handle<ChFiDS_ElSpine> const&, opencascade::handle<ChFiDS_Stripe>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, bool) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKFillet.so.7.8+0x624
#6  0x7f9f68f51c71 in ChFi3d_Builder::PerformSetOfKGen(opencascade::handle<ChFiDS_Stripe>&, bool) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKFillet.so.7.8+0xd1
#7  0x7f9f68f55faa in ChFi3d_Builder::PerformSetOfSurf(opencascade::handle<ChFiDS_Stripe>&, bool) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKFillet.so.7.8+0x6a
#8  0x7f9f68f1a484 in ChFi3d_Builder::Compute() from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKFillet.so.7.8+0x4a4
#9  0x7f9f6909abb6 in BRepFilletAPI_MakeChamfer::Build(Message_ProgressRange const&) from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKFillet.so.7.8+0x36
#10  0x7f9f63069a4d in BRepBuilderAPI_MakeShape::Shape() from /tmp/.mount_FreeCAeAejDG/usr/lib/libTKTopAlgo.so.7.8+0x8d
#11  0x7f9f6950fd19 in Part::Chamfer::execute() from /tmp/.mount_FreeCAeAejDG/usr/lib/Part.so+0xa59
#12  0x7f9f9a7a137b in App::DocumentObject::recompute() from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADApp.so+0x6b
#13  0x7f9f69524aaa in Part::Feature::recompute() from /tmp/.mount_FreeCAeAejDG/usr/lib/Part.so+0xa
#14  0x7f9f9a75495c in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADApp.so+0x2bc
#15  0x7f9f9a752af8 in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADApp.so+0xba8
#16  0x7f9f10dc0af3 in PartGui::DlgFilletEdges::accept() from /tmp/.mount_FreeCAeAejDG/usr/lib/PartGui.so+0xd73
#17  0x7f9f10dc1b4a in PartGui::TaskChamferEdges::accept() from /tmp/.mount_FreeCAeAejDG/usr/lib/PartGui.so+0xa
#18  0x7f9f9d380daf in Gui::TaskView::TaskView::accept() from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADGui.so+0x6f
#19  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6(+0x31684a) [0x7f9f9731684a]
#20  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6(+0x3d86f9) [0x7f9f985d86f9]
#21  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6(+0x31684a) [0x7f9f9731684a]
#22  0x7f9f98656727 in QAbstractButton::clicked(bool) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0x47
#23  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6(+0x47be80) [0x7f9f9867be80]
#24  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6(+0x4adba7) [0x7f9f986adba7]
#25  0x7f9f986add6d in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0xbd
#26  0x7f9f987c3864 in QWidget::event(QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0xa64
#27  0x7f9f987b3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0x88
#28  0x7f9f987b4cbd in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0xdad
#29  0x7f9f9cf85408 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADGui.so+0x78
#30  0x7f9f9735fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6+0x17a
#31  0x7f9f987bbe7c in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0x1ec
#32  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6(+0x5be8c7) [0x7f9f987be8c7]
#33  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6(+0x5c5440) [0x7f9f987c5440]
#34  0x7f9f987b3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Widgets.so.6+0x88
#35  0x7f9f9cf85408 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADGui.so+0x78
#36  0x7f9f9735fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6+0x17a
#37  0x7f9f979d1970 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Gui.so.6+0x810
#38  0x7f9f97a31e14 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Gui.so.6+0xb4
#39  /tmp/.mount_FreeCAeAejDG/usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6(+0x58f90) [0x7f9f933dcf90]
#40  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/./libglib-2.0.so.0(+0x5bde6) [0x7f9f94306de6]
#41  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/./libglib-2.0.so.0(+0x5f0a7) [0x7f9f9430a0a7]
#42  /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7f9f9430a81e]
#43  0x7f9f970f6b12 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6+0x72
#44  0x7f9f9739747c in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6+0x25c
#45  0x7f9f973977da in QCoreApplication::exec() from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libQt6Core.so.6+0x9a
#46  0x7f9f9ceac75d in Gui::Application::runApplication() from /tmp/.mount_FreeCAeAejDG/usr/bin/../lib/libFreeCADGui.so+0xd5d
#47  /tmp/.mount_FreeCAeAejDG/usr/bin/freecad(+0x9bb5) [0x55f080ff5bb5]
#48  /lib/x86_64-linux-gnu/libc.so.6(+0x2724a) [0x7f9f96a4624a]
#49  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x85) [0x7f9f96a46305]
#50  /tmp/.mount_FreeCAeAejDG/usr/bin/freecad(+0x8cb9) [0x55f080ff4cb9]
```

### Development version About Info (in Safe Mode)

```shell
OS: Debian GNU/Linux 12 (bookworm) (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.1.0rc2.20260108 (Git shallow) AppImage
Build date: 2026/01/08 12:03:27
Build type: Release
Branch: (HEAD detached at 0c7935c)
Hash: 0c7935c755bd9531f7061be31fab8788742a44b7
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.4, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: CAD/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.5973/1
```

### Last known good version (optional)

```shell

```
