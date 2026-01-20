# #25868 — 1.1rc1 - crash on fillet size change (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#25868`
- URL: https://github.com/FreeCAD/FreeCAD/issues/25868
- State: `open`
- Created: `2025-12-01T20:41:12Z`
- Updated: `2025-12-06T11:10:55Z`
- Comments: `7`
- Labels: `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Workbench affected?

None

### Problem description

repeatable crash with attached model

```
FreeCAD 1.2.0, Libs: 1.2.0devR20251126 (Git shallow)
(C) 2001-2025 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

Detected locale "C" with character encoding "ANSI_X3.4-1968", which is not UTF-8.
Qt depends on a UTF-8 locale, and has switched to "C.UTF-8" instead.
If this causes problems, reconfigure your locale. See the locale(1) manual
for more information.
/home/runner/work/FreeCAD/FreeCAD/package/rattler-build/.pixi/envs/default/share/libdrm/amdgpu.ids: No such file or directory
Reading failed from embedded file: Sketch.InternalShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Pad.SuppressedShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Sketch001.InternalShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Pocket.SuppressedShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Sketch002.InternalShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Pocket001.SuppressedShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Sketch003.InternalShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Pad001.SuppressedShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Mirrored.SuppressedShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Sketch004.InternalShape.bin (0 bytes, 2 bytes compressed)
Reading failed from embedded file: Hole.SuppressedShape.bin (0 bytes, 2 bytes compressed)
<PartDesign> FeatureDressUp.cpp(206): spool_holder#Fillet: skip edge  that is not C0 continuous
<PartDesign> FeatureDressUp.cpp(206): spool_holder#Fillet: skip edge  that is not C0 continuous
<PartDesign> FeatureDressUp.cpp(206): spool_holder#Fillet: skip edge  that is not C0 continuous
Program received signal SIGSEGV, Segmentation fault.
#0  /usr/lib/libc.so.6(+0x3e4d0) [0x7fa5afa3e4d0]
#1  0x7fa5697e32de in TopoDS_Iterator::Next() from /tmp/.mount_freecaEnInCB/usr/lib/libTKBRep.so.7.8+0x2e
#2  0x7fa567447b71 in TopOpeBRepBuild_Builder::MakeFaces(TopoDS_Shape const&, TopOpeBRepBuild_FaceBuilder&, NCollection_List<TopoDS_Shape>&) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x521
#3  0x7fa5673c98dd in TopOpeBRepBuild_Builder::SplitFace1(TopoDS_Shape const&, TopAbs_State, TopAbs_State) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x2cd
#4  0x7fa5673c8de5 in TopOpeBRepBuild_Builder::SplitShapes(TopOpeBRepTool_ShapeExplorer&, TopAbs_State, TopAbs_State, TopOpeBRepBuild_ShapeSet&, bool) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x445
#5  0x7fa5673c9401 in TopOpeBRepBuild_Builder::FillShape(TopoDS_Shape const&, TopAbs_State, NCollection_List<TopoDS_Shape> const&, TopAbs_State, TopOpeBRepBuild_ShapeSet&, bool) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x241
#6  0x7fa5673cac4f in TopOpeBRepBuild_Builder::SplitSolid(TopoDS_Shape const&, TopAbs_State, TopAbs_State) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x24f
#7  0x7fa5673c8afe in TopOpeBRepBuild_Builder::SplitShapes(TopOpeBRepTool_ShapeExplorer&, TopAbs_State, TopAbs_State, TopOpeBRepBuild_ShapeSet&, bool) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x15e
#8  0x7fa5674449b4 in TopOpeBRepBuild_Builder::MergeShapes(TopoDS_Shape const&, TopAbs_State, TopoDS_Shape const&, TopAbs_State) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x254
#9  0x7fa567445064 in TopOpeBRepBuild_Builder::MergeSolid(TopoDS_Shape const&, TopAbs_State) from /tmp/.mount_freecaEnInCB/usr/lib/libTKBool.so.7.8+0x54
#10  0x7fa569d1bb84 in ChFi3d_Builder::Compute() from /tmp/.mount_freecaEnInCB/usr/lib/libTKFillet.so.7.8+0x1ba4
#11  0x7fa569e9ca76 in BRepFilletAPI_MakeFillet::Build(Message_ProgressRange const&) from /tmp/.mount_freecaEnInCB/usr/lib/libTKFillet.so.7.8+0x36
#12  0x7fa567069a4d in BRepBuilderAPI_MakeShape::Shape() from /tmp/.mount_freecaEnInCB/usr/lib/libTKTopAlgo.so.7.8+0x8d
#13  0x7fa56a5e0a75 in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*) from /tmp/.mount_freecaEnInCB/usr/lib/Part.so+0x75
#14  0x7fa56a5f4223 in Part::TopoShape::makeElementFillet(Part::TopoShape const&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, double, double, char const*) from /tmp/.mount_freecaEnInCB/usr/lib/Part.so+0x153
#15  0x7fa56302717f in PartDesign::Fillet::execute() from /tmp/.mount_freecaEnInCB/usr/lib/_PartDesign.so+0x28f
#16  0x7fa5b3d9e79b in App::DocumentObject::recompute() from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADApp.so+0x6b
#17  0x7fa56a321e8a in Part::Feature::recompute() from /tmp/.mount_freecaEnInCB/usr/lib/Part.so+0xa
#18  0x7fa562f6f3f0 in PartDesign::Feature::recompute() from /tmp/.mount_freecaEnInCB/usr/lib/_PartDesign.so+0x160
#19  0x7fa5b3d51d7c in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADApp.so+0x2bc
#20  0x7fa5b3d53f87 in App::Document::recomputeFeature(App::DocumentObject*, bool) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADApp.so+0xd7
#21  0x7fa4f1b5077f in PartDesignGui::TaskDressUpParameters::updateFeature(PartDesign::DressUp*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&) from /tmp/.mount_freecaEnInCB/usr/lib/PartDesignGui.so+0x11f
#22  0x7fa4f1b500ad in PartDesignGui::TaskDressUpParameters::referenceSelected(Gui::SelectionChanges const&, QListWidget*) from /tmp/.mount_freecaEnInCB/usr/lib/PartDesignGui.so+0x48d
#23  0x7fa5b658b5a7 in Gui::SelectionObserver::_onSelectionChanged(Gui::SelectionChanges const&) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x27
#24  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x2030f49) [0x7fa5b6230f49]
#25  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x20303ef) [0x7fa5b62303ef]
#26  0x7fa5b65907ca in Gui::SelectionSingleton::slotSelectionChanged(Gui::SelectionChanges const&) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x1da
#27  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x2030f49) [0x7fa5b6230f49]
#28  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x20303ef) [0x7fa5b62303ef]
#29  0x7fa5b658f240 in Gui::SelectionSingleton::notify(Gui::SelectionChanges&&) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x180
#30  0x7fa5b6594cfe in Gui::SelectionSingleton::addSelection(char const*, char const*, char const*, float, float, float, std::vector<Gui::SelectionSingleton::SelObj, std::allocator<Gui::SelectionSingleton::SelObj> > const*, bool) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0xd3e
#31  0x7fa5b62e73d8 in Gui::SoFCUnifiedSelection::setSelection(std::vector<Gui::SoFCUnifiedSelection::PickedInfo, std::allocator<Gui::SoFCUnifiedSelection::PickedInfo> > const&, bool) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x1588
#32  0x7fa5b62e83ea in Gui::SoFCUnifiedSelection::handleEvent(SoHandleEventAction*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x1ea
#33  0x7fa5b1cd54e8 in SoAction::traverse(SoNode*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0x68
#34  0x7fa5b1e8cb9a in SoChildList::traverse(SoAction*, int, int) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0xea
#35  0x7fa5b1edc348 in SoGroup::doAction(SoAction*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0x58
#36  0x7fa5b1ef713a in SoSeparator::doAction(SoAction*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0x2a
#37  0x7fa5b1cd54e8 in SoAction::traverse(SoNode*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0x68
#38  0x7fa5b1cdf26c in SoHandleEventAction::beginTraversal(SoNode*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0xac
#39  0x7fa5b1cd61ba in SoAction::apply(SoNode*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0x2ea
#40  0x7fa5b1ea8ad2 in SoEventManager::actuallyProcessEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libCoin.so.80+0x72
#41  0x7fa5b6395db9 in SIM::Coin3D::Quarter::QuarterWidget::processSoEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x19
#42  0x7fa5b639d166 in SIM::Coin3D::Quarter::SoQTQuarterAdaptor::processSoEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x86
#43  0x7fa5b63fa2bd in Gui::NavigationStyle::processSoEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x4d
#44  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x220bd83) [0x7fa5b640bd83]
#45  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x220b78f) [0x7fa5b640b78f]
#46  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so(+0x220819f) [0x7fa5b640819f]
#47  0x7fa5b6406aaf in Gui::GestureNavigationStyle::processSoEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x39f
#48  0x7fa5b63f9df5 in Gui::NavigationStyle::processEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x95
#49  0x7fa5b63bcf53 in Gui::View3DInventorViewer::processSoEvent(SoEvent const*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0xb3
#50  0x7fa5b639001f in SIM::Coin3D::Quarter::EventFilter::eventFilter(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x12f
#51  0x7fa5b035f8de in QCoreApplicationPrivate::sendThroughObjectEventFilters(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Core.so.6+0x7e
#52  0x7fa5b17b3e38 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Widgets.so.6+0x78
#53  0x7fa5b17b4aff in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Widgets.so.6+0xbef
#54  0x7fa5b5f76958 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x78
#55  0x7fa5b035fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Core.so.6+0x17a
#56  0x7fa5b17bbe7c in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Widgets.so.6+0x1ec
#57  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Widgets.so.6(+0x5be8c7) [0x7fa5b17be8c7]
#58  /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Widgets.so.6(+0x5c5440) [0x7fa5b17c5440]
#59  0x7fa5b17b3e48 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Widgets.so.6+0x88
#60  0x7fa5b5f76958 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0x78
#61  0x7fa5b035fb8a in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Core.so.6+0x17a
#62  0x7fa5b09d1970 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Gui.so.6+0x810
#63  0x7fa5b0a31e14 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Gui.so.6+0xb4
#64  /tmp/.mount_freecaEnInCB/usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6(+0x58f90) [0x7fa5ac656f90]
#65  /tmp/.mount_freecaEnInCB/usr/bin/../lib/./libglib-2.0.so.0(+0x5b646) [0x7fa5ad8a6646]
#66  /tmp/.mount_freecaEnInCB/usr/bin/../lib/./libglib-2.0.so.0(+0x5e817) [0x7fa5ad8a9817]
#67  /tmp/.mount_freecaEnInCB/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7fa5ad8a9f2e]
#68  0x7fa5b00f6b12 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Core.so.6+0x72
#69  0x7fa5b039747c in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Core.so.6+0x25c
#70  0x7fa5b03977da in QCoreApplication::exec() from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libQt6Core.so.6+0x9a
#71  0x7fa5b5e9e73d in Gui::Application::runApplication() from /tmp/.mount_freecaEnInCB/usr/bin/../lib/libFreeCADGui.so+0xd5d
#72  /tmp/.mount_freecaEnInCB/usr/bin/freecad(+0x9bb5) [0x559fdd2d7bb5]
#73  /usr/lib/libc.so.6(+0x27635) [0x7fa5afa27635]
#74  /usr/lib/libc.so.6(__libc_start_main+0x89) [0x7fa5afa276e9]
#75  /tmp/.mount_freecaEnInCB/usr/bin/freecad(+0x8cb9) [0x559fdd2d6cb9]
```

[spool-holder.FCStd.zip](https://github.com/user-attachments/files/23864527/spool-holder.FCStd.zip)

### Steps to reproduce

open the attached model, just choose the fillet at the end and increase it to 2mm

### Expected behavior

not crash

### Actual behavior

crash

### Development version About Info (in Safe Mode)

```shell
OS: Arch Linux (XFCE/xfce/xcb)
Architecture: x86_64
Version: 1.2.0dev.20251126 (Git shallow) AppImage
Build date: 2025/11/26 00:30:17
Build type: Release
Branch: (HEAD detached at de230cf)
Hash: de230cfaa75433441366ad09a4d5fda828e7bfdb
Python 3.11.14, Qt 6.8.3, Coin 4.0.3, Vtk 9.3.1, boost 1_86, Eigen3 3.4.0, PySide 6.8.3
shiboken 6.8.3, xerces-c 3.3.0, IfcOpenShell 0.8.2, OCC 7.8.1
Locale: C/Default (C)
Navigation Style/Orbit Style/Rotation Mode: Gesture/Rounded Arcball/Window center
Stylesheet/Theme/QtStyle: FreeCAD.qss/FreeCAD Dark/
Logical DPI/Physical DPI/Pixel Ratio: 96/81.8077/1
```

### Last known good version (optional)

```shell

```
