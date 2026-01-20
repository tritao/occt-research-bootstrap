# #25289 — PartDesign: OCCT crash under certain circumstances

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25289`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25289
- State: `open`
- Created: `2025-11-13T22:23:38Z`
- Updated: `2025-12-08T16:17:49Z`
- Comments: `7`
- Labels: `Mod: Part`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

There's a crashing bug in OCCT that has been fixed in their main branch, but won't be in a release [until 7.9.3 early next year](https://github.com/Open-Cascade-SAS/OCCT/discussions/828#discussioncomment-14961120).

I haven't quite figured out what edge case in FreeCAD is triggering the bug, but perhaps we can detect it in `TopoShape::makeElementShape` before calling `mkShape.Shape()` to keep FreeCAD from crashing?

<details><summary>Stack trace</summary>
<pre>
Exception Type:        EXC_BAD_ACCESS (SIGSEGV)
Exception Codes:       KERN_INVALID_ADDRESS at 0x0000000000000060
Exception Codes:       0x0000000000000001, 0x0000000000000060

Termination Reason:    Namespace SIGNAL, Code 11 Segmentation fault: 11
Terminating Process:   exc handler [13519]

VM Region Info: 0x60 is not in any region.  Bytes before following region: 4432613280
      REGION TYPE                    START - END         [ VSIZE] PRT/MAX SHRMOD  REGION DETAIL
      UNUSED SPACE AT START
--->  
      __TEXT                      108345000-108376000    [  196K] r-x/r-x SM=COW  build/debug/bin/FreeCAD

Thread 0 Crashed::  Dispatch queue: com.apple.main-thread
0   libTKBRep.7.8.1.dylib         	       0x12b0798a0 BRep_Tool::CurveOnSurface(TopoDS_Edge const&, opencascade::handle<Geom_Surface> const&, TopLoc_Location const&, double&, double&, bool*) + 112
1   libTKBRep.7.8.1.dylib         	       0x12b07975e BRep_Tool::CurveOnSurface(TopoDS_Edge const&, TopoDS_Face const&, double&, double&, bool*) + 206
2   libTKBRep.7.8.1.dylib         	       0x12b08d38b BRepAdaptor_Curve2d::Initialize(TopoDS_Edge const&, TopoDS_Face const&) + 203
3   libTKFillet.7.8.1.dylib       	       0x12bbb6c21 ChFi3d_Builder::StartSol(opencascade::handle<ChFiDS_Spine> const&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, opencascade::handle<BRepAdaptor_Curve2d>&, double&, opencascade::handle<ChFiDS_SurfData> const&, bool, int, opencascade::handle<BRepAdaptor_Surface>&, opencascade::handle<BRepAdaptor_Curve2d>&, bool&, bool&, bool&, bool&, opencascade::handle<BRepAdaptor_Surface>&, gp_Pnt2d&, bool, TopoDS_Vertex const&) const + 4097
4   libTKFillet.7.8.1.dylib       	       0x12bbb9f2b ChFi3d_Builder::PerformSetOfSurfOnElSpine(opencascade::handle<ChFiDS_ElSpine> const&, opencascade::handle<ChFiDS_Stripe>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, opencascade::handle<BRepTopAdaptor_TopolTool>&, bool) + 2779
5   libTKFillet.7.8.1.dylib       	       0x12bbbfbd4 ChFi3d_Builder::PerformSetOfKGen(opencascade::handle<ChFiDS_Stripe>&, bool) + 212
6   libTKFillet.7.8.1.dylib       	       0x12bbc460d ChFi3d_Builder::PerformSetOfSurf(opencascade::handle<ChFiDS_Stripe>&, bool) + 141
7   libTKFillet.7.8.1.dylib       	       0x12bb7dbf2 ChFi3d_Builder::Compute() + 1026
8   libTKFillet.7.8.1.dylib       	       0x12bd3830e BRepFilletAPI_MakeFillet::Build(Message_ProgressRange const&) + 46
9   libTKTopAlgo.7.8.1.dylib      	       0x12b9a8e3c BRepBuilderAPI_MakeShape::Shape() + 60
10  Part.so                       	       0x12cc8b147 Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, std::__1::vector<Part::TopoShape, std::__1::allocator<Part::TopoShape>> const&, char const*) + 151 (TopoShapeExpansion.cpp:4327)
11  Part.so                       	       0x12cc9000b Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, Part::TopoShape const&, char const*) + 75 (TopoShapeExpansion.cpp:4312)
12  Part.so                       	       0x12cc9d45a Part::TopoShape::makeElementFillet(Part::TopoShape const&, std::__1::vector<Part::TopoShape, std::__1::allocator<Part::TopoShape>> const&, double, double, char const*) + 1242 (TopoShapeExpansion.cpp:4107)
13  _PartDesign.so                	       0x14e06ce9d PartDesign::Fillet::execute() + 1293 (FeatureFillet.cpp:108)
14  libFreeCADApp.dylib           	       0x10ae29d2a App::DocumentObject::recompute() + 106 (DocumentObject.cpp:165)
15  Part.so                       	       0x12c867c85 Part::Feature::recompute() + 21 (PartFeature.cpp:107)
16  _PartDesign.so                	       0x14df1ce8a PartDesign::Feature::recompute() + 218 (Feature.cpp:93)
17  libFreeCADApp.dylib           	       0x10acf3e86 App::Document::_recomputeFeature(App::DocumentObject*) + 694 (Document.cpp:2987)
18  libFreeCADApp.dylib           	       0x10acf6cb6 App::Document::recomputeFeature(App::DocumentObject*, bool) + 246 (Document.cpp:3051)
19  libFreeCADApp.dylib           	       0x10ae2a225 App::DocumentObject::recomputeFeature(bool) + 69 (DocumentObject.cpp:201)
20  PartDesignGui.so              	       0x15182e071 PartDesignGui::TaskFilletParameters::onLengthChanged(double) + 97 (TaskFilletParameters.cpp:166)
21  PartDesignGui.so              	       0x15183008f QtPrivate::FunctorCall<QtPrivate::IndexesList<0>, QtPrivate::List<double>, void, void (PartDesignGui::TaskFilletParameters::*)(double)>::call(void (PartDesignGui::TaskFilletParameters::*)(double), PartDesignGui::TaskFilletParameters*, void**)::'lambda'()::operator()() const + 127 (qobjectdefs_impl.h:152)
22  PartDesignGui.so              	       0x15182ffa9 void QtPrivate::FunctorCallBase::call_internal<void, QtPrivate::FunctorCall<QtPrivate::IndexesList<0>, QtPrivate::List<double>, void, void (PartDesignGui::TaskFilletParameters::*)(double)>::call(void (PartDesignGui::TaskFilletParameters::*)(double), PartDesignGui::TaskFilletParameters*, void**)::'lambda'()>(void**, QtPrivate::FunctorCall<QtPrivate::IndexesList<0>, QtPrivate::List<double>, void, void (PartDesignGui::TaskFilletParameters::*)(double)>::call(void (PartDesignGui::TaskFilletParameters::*)(double), PartDesignGui::TaskFilletParameters*, void**)::'lambda'()&&) + 25 (qobjectdefs_impl.h:65)
23  PartDesignGui.so              	       0x15182ff16 QtPrivate::FunctorCall<QtPrivate::IndexesList<0>, QtPrivate::List<double>, void, void (PartDesignGui::TaskFilletParameters::*)(double)>::call(void (PartDesignGui::TaskFilletParameters::*)(double), PartDesignGui::TaskFilletParameters*, void**) + 86 (qobjectdefs_impl.h:151)
24  PartDesignGui.so              	       0x15182fe7d void QtPrivate::FunctionPointer<void (PartDesignGui::TaskFilletParameters::*)(double)>::call<QtPrivate::List<double>, void>(void (PartDesignGui::TaskFilletParameters::*)(double), PartDesignGui::TaskFilletParameters*, void**) + 77 (qobjectdefs_impl.h:199)
25  PartDesignGui.so              	       0x15182fd95 QtPrivate::QCallableObject<void (PartDesignGui::TaskFilletParameters::*)(double), QtPrivate::List<double>, void>::impl(int, QtPrivate::QSlotObjectBase*, QObject*, void**, bool*) + 165 (qobjectdefs_impl.h:570)
26  libQt6Core.6.8.3.dylib        	       0x10d6c6beb void doActivate<false>(QObject*, int, void**) + 1579
27  libFreeCADGui.dylib           	       0x10f65b008 Gui::QuantitySpinBox::valueChanged(double) + 72 (moc_QuantitySpinBox.cpp:344)
28  libFreeCADGui.dylib           	       0x10f65b51e Gui::QuantitySpinBox::updateFromCache(bool, bool) + 318 (QuantitySpinBox.cpp:697)
29  libFreeCADGui.dylib           	       0x10f65842a Gui::QuantitySpinBox::handlePendingEmit(bool) + 42 (QuantitySpinBox.cpp:679)
30  libFreeCADGui.dylib           	       0x10f658e51 Gui::QuantitySpinBox::validateInput() + 225 (QuantitySpinBox.cpp:520)
31  libFreeCADGui.dylib           	       0x10f65d39e Gui::QuantitySpinBox::focusOutEvent(QFocusEvent*) + 46 (QuantitySpinBox.cpp:1007)
32  libQt6Widgets.6.8.3.dylib     	       0x10a7623cf QWidget::event(QEvent*) + 2015
33  libQt6Widgets.6.8.3.dylib     	       0x10a651a64 QAbstractSpinBox::event(QEvent*) + 388
34  libFreeCADGui.dylib           	       0x10f65d05d Gui::QuantitySpinBox::event(QEvent*) + 29 (QuantitySpinBox.cpp:975)
35  libQt6Widgets.6.8.3.dylib     	       0x10a827948 QApplicationPrivate::notify_helper(QObject*, QEvent*) + 312
36  libQt6Widgets.6.8.3.dylib     	       0x10a8288ee QApplication::notify(QObject*, QEvent*) + 494
37  libFreeCADGui.dylib           	       0x10ea6bc81 Gui::GUIApplication::notify(QObject*, QEvent*) + 769 (GuiApplication.cpp:103)
38  libQt6Core.6.8.3.dylib        	       0x10d77c602 QCoreApplication::notifyInternal2(QObject*, QEvent*) + 162
39  libQt6Widgets.6.8.3.dylib     	       0x10a8252d7 QApplicationPrivate::setFocusWidget(QWidget*, Qt::FocusReason) + 327
40  libQt6Widgets.6.8.3.dylib     	       0x10a77cfd1 QWidget::setFocus(Qt::FocusReason) + 673
41  libQt6Widgets.6.8.3.dylib     	       0x10a77d5e7 QWidget::focusNextPrevChild(bool) + 359
42  libQt6Widgets.6.8.3.dylib     	       0x10a6496a3 QScrollArea::focusNextPrevChild(bool) + 19
43  libQt6Widgets.6.8.3.dylib     	       0x10a7628e0 QWidget::event(QEvent*) + 3312
44  libQt6Widgets.6.8.3.dylib     	       0x10a651a64 QAbstractSpinBox::event(QEvent*) + 388
45  libFreeCADGui.dylib           	       0x10f65d05d Gui::QuantitySpinBox::event(QEvent*) + 29 (QuantitySpinBox.cpp:975)
46  libQt6Widgets.6.8.3.dylib     	       0x10a827948 QApplicationPrivate::notify_helper(QObject*, QEvent*) + 312
47  libQt6Widgets.6.8.3.dylib     	       0x10a828ecc QApplication::notify(QObject*, QEvent*) + 1996
48  libFreeCADGui.dylib           	       0x10ea6bc81 Gui::GUIApplication::notify(QObject*, QEvent*) + 769 (GuiApplication.cpp:103)
49  libQt6Core.6.8.3.dylib        	       0x10d77c602 QCoreApplication::notifyInternal2(QObject*, QEvent*) + 162
50  libQt6Widgets.6.8.3.dylib     	       0x10a793637 QWidgetWindow::event(QEvent*) + 151
51  libQt6Widgets.6.8.3.dylib     	       0x10a827948 QApplicationPrivate::notify_helper(QObject*, QEvent*) + 312
52  libQt6Widgets.6.8.3.dylib     	       0x10a8288ee QApplication::notify(QObject*, QEvent*) + 494
53  libFreeCADGui.dylib           	       0x10ea6bc81 Gui::GUIApplication::notify(QObject*, QEvent*) + 769 (GuiApplication.cpp:103)
54  libQt6Core.6.8.3.dylib        	       0x10d77c602 QCoreApplication::notifyInternal2(QObject*, QEvent*) + 162
55  libQt6Gui.6.8.3.dylib         	       0x11504e8aa QGuiApplicationPrivate::processKeyEvent(QWindowSystemInterfacePrivate::KeyEvent*) + 426
56  libQt6Gui.6.8.3.dylib         	       0x114f98e3b QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) + 459
57  libQt6Gui.6.8.3.dylib         	       0x114f79571 QWindowSystemInterface::flushWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) + 289
58  libqcocoa.dylib               	       0x116acc0d5 -[QNSView(Keys) handleKeyEvent:] + 1221
59  libqcocoa.dylib               	       0x116accfc5 -[QNSView(Keys) keyDown:] + 101
60  AppKit                        	    0x7ff814b6d273 -[NSWindow(NSEventRouting) _reallySendEvent:isDelayedEvent:] + 317
61  AppKit                        	    0x7ff814b6cf15 -[NSWindow(NSEventRouting) sendEvent:] + 344
62  libqcocoa.dylib               	       0x116ad572b -[QNSWindow sendEvent:] + 1003
63  AppKit                        	    0x7ff8154a2c35 -[NSApplication(NSEventRouting) sendEvent:] + 3389
64  libqcocoa.dylib               	       0x116a7a0ec -[QNSApplication sendEvent:] + 92
65  AppKit                        	    0x7ff815005c37 -[NSApplication _handleEvent:] + 65
66  AppKit                        	    0x7ff814a06ec5 -[NSApplication run] + 654
67  libqcocoa.dylib               	       0x116a8be28 QCocoaEventDispatcher::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) + 2808
68  libQt6Core.6.8.3.dylib        	       0x10d77d296 QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) + 534
69  libQt6Core.6.8.3.dylib        	       0x10d77cefc QCoreApplication::exec() + 156
70  libFreeCADGui.dylib           	       0x10e84b2b2 (anonymous namespace)::tryRunEventLoop(Gui::GUISingleApplication&) + 514 (Application.cpp:2397)
71  libFreeCADGui.dylib           	       0x10e82e455 (anonymous namespace)::runEventLoop(Gui::GUISingleApplication&) + 21 (Application.cpp:2430)
72  libFreeCADGui.dylib           	       0x10e82dc8b Gui::Application::runApplication() + 907 (Application.cpp:2543)
73  FreeCAD                       	       0x10834a8d4 main + 6484 (MainGui.cpp:319)
74  dyld                          	    0x7ff810b24530 start + 3056
</pre>
</details>

### Full version info

```shell
OS: macOS 15.6.1
Architecture: x86_64
Version: 1.1.0dev.44221 (Git)
Build date: 2025/11/12 05:44:18
Build type: Unknown
Branch: main
Hash: 8432fab0a9d556cfd3f960c334a18e9f2a9ca0c7
Python 3.11.13, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: English/United States (en_US)
Navigation Style/Orbit Style/Rotation Mode: Touchpad/Trackball/Drag at cursor
Stylesheet/Theme/QtStyle: FreeCAD Light.qss/FreeCAD Light/
Logical DPI/Physical DPI/Pixel Ratio: 72/132.25/2
Installed mods:
  * InventorLoader 1.5.1
  * Manipulator 1.6.3
  * sheetmetal 0.7.58
```

### Subproject(s) affected?

None

### Anything else?

To reproduce the crash, open the attached sample, double-click on <b>Outer fillet</b> to bring up the fillet task, then change the radius from 1.49mm to 1.50mm and press `Tab` to update:
<img width="1200" height="851" alt="Screenshot" src="https://github.com/user-attachments/assets/bf175021-96af-4593-9a0a-c6a3725c6b1a" />
[occt-crash-sample.zip](https://github.com/user-attachments/files/23535651/occt-crash-sample.zip)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
