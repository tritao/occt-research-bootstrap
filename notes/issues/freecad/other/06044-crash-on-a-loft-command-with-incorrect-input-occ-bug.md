# #6044 — Crash on a loft command with incorrect input (OCC bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6044`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6044
- State: `open`
- Created: `2022-02-07T19:34:31Z`
- Updated: `2025-03-16T07:20:44Z`
- Comments: `2`
- Labels: `Type: Bug`, `Mod: Core`, `3rd party: OCC`, `Type: Crash`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=4311

* **Reporter:** BruceL
* **Date submitted:** 4/11/2020
* **FreeCAD version:** 
* **Category:** Bug
* **Status:** acknowledged
* **Tags:** #ready-for-migration, OCC 7.5, OCC Bug, OCC NotOnRoadmap, upstream


# Original report text

I'm experience a crash on 0.19-20406 Appimage. But with an admittedly wrong user input, but I would think that the program should complain to me instead of crashing. Lofting and adding the section that was used to start the loft will crash FreeCAD.

Thank you in advance for you time.

Forum post: https://forum.freecadweb.org/viewtopic.php?f=8&t=45013&p=386183#p386183

Note: this ticket is be tracked via [OCC bugs in the bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264&start=40) forum thread

# Additional information

```
Reading failed from embedded file: PartShape.bin (0 bytes, 2 bytes compressed)
6.79e-07 <App> Document.cpp(3715): Failed to recompute crash#AdditiveLoft: Loft: At least one section is needed
Recompute failed! Please check report view.
0.0035612 <App> Document.cpp(3715): Failed to recompute crash#AdditiveLoft: Loft: At least one section is needed
Recompute failed! Please check report view.
3.67836 <App> Document.cpp(3715): Failed to recompute crash#AdditiveLoft: Loft could not be built
3.7744 Tree.cpp(293): [TreeView] duplicate child item crash#AdditiveLoft.Sketch
3.77562 Tree.cpp(293): [ComboView] duplicate child item crash#AdditiveLoft.Sketch
Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x3b7e0) [0x7f5d0350e7e0]
#1  /tmp/.mount_FreeCAhwE8MW/usr/lib/./libTKTopAlgo.so.7(+0x17a177) [0x7f5cdbfcd177]
#2  0x7f5cdbfcdb72 in BRepLib::EncodeRegularity(TopoDS_Shape const&, double) from /tmp/.mount_FreeCAhwE8MW/usr/lib/./libTKTopAlgo.so.7+0x152
#3  0x7f5cdd607c26 in BRepOffsetAPI_ThruSections::Build() from /tmp/.mount_FreeCAhwE8MW/usr/lib/./libTKOffset.so.7+0xd16
#4  0x7f5c6afae337 in PartDesign::Loft::execute() from /tmp/.mount_FreeCAhwE8MW/usr/lib/_PartDesign.so+0x7f7
#5  0x7f5d0529956e in App::DocumentObject::recompute() from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADApp.so+0x9e
#6  0x7f5cddd6818c in Part::Feature::recompute() from /tmp/.mount_FreeCAhwE8MW/usr/lib/Part.so+0xc
#7  0x7f5d0522fded in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADApp.so+0x2fd
#8  0x7f5d0528904c in App::Document::recomputeFeature(App::DocumentObject*, bool) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADApp.so+0xdc
#9  0x7f5c6a4cd2b2 in PartDesignGui::TaskLoftParameters::onSelectionChanged(Gui::SelectionChanges const&) from /tmp/.mount_FreeCAhwE8MW/usr/lib/PartDesignGui.so+0x122
#10  0x7f5d0618286e in Gui::SelectionObserver::_onSelectionChanged(Gui::SelectionChanges const&) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x4e
#11  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so(+0x5cc47c) [0x7f5d05ede47c]
#12  0x7f5d06190917 in Gui::SelectionSingleton::slotSelectionChanged(Gui::SelectionChanges const&) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x2b7
#13  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so(+0x5cc47c) [0x7f5d05ede47c]
#14  0x7f5d06191566 in Gui::SelectionSingleton::notify(Gui::SelectionChanges&&) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0xf6
#15  0x7f5d0619a762 in Gui::SelectionSingleton::addSelection(char const*, char const*, char const*, float, float, float, std::vector<Gui::SelectionSingleton::SelObj, std::allocator<Gui::SelectionSingleton::SelObj> > const*, bool) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x7e2
#16  0x7f5d05f74891 in Gui::SoFCUnifiedSelection::setSelection(std::vector<Gui::SoFCUnifiedSelection::PickedInfo, std::allocator<Gui::SoFCUnifiedSelection::PickedInfo> > const&, bool) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x8f1
#17  0x7f5d05f75dd1 in Gui::SoFCUnifiedSelection::handleEvent(SoHandleEventAction*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x141
#18  0x7f5d048a923a in SoAction::traverse(SoNode*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x6a
#19  0x7f5d04a9384b in SoChildList::traverse(SoAction*, int, int) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0xeb
#20  0x7f5d04aeb378 in SoGroup::doAction(SoAction*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x58
#21  0x7f5d04b08b3a in SoSeparator::doAction(SoAction*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x2a
#22  0x7f5d048a923a in SoAction::traverse(SoNode*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x6a
#23  0x7f5d048b3960 in SoHandleEventAction::beginTraversal(SoNode*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x70
#24  0x7f5d048aa0a2 in SoAction::apply(SoNode*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x442
#25  0x7f5d04ab379b in SoEventManager::processEvent(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libCoin.so.80+0x15b
#26  0x7f5d05ff8fee in SIM::Coin3D::Quarter::QuarterWidget::processSoEvent(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x1e
#27  0x7f5d06001d6a in SIM::Coin3D::Quarter::SoQTQuarterAdaptor::processSoEvent(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x5a
#28  0x7f5d0603bf3a in Gui::View3DInventorViewer::processSoEventBase(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0xa
#29  0x7f5d060118ca in Gui::BlenderNavigationStyle::processSoEvent(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x22a
#30  0x7f5d0600cea8 in Gui::NavigationStyle::processEvent(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0xf8
#31  0x7f5d0603bea5 in Gui::View3DInventorViewer::processSoEvent(SoEvent const*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x65
#32  0x7f5d05fefe05 in SIM::Coin3D::Quarter::EventFilter::eventFilter(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x185
#33  0x7f5d039ebb6d in QCoreApplicationPrivate::sendThroughObjectEventFilters(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Core.so.5+0xd1
#34  0x7f5d0421781a in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5+0xce
#35  0x7f5d0421c095 in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5+0x79d
#36  0x7f5d05d1bae9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x89
#37  0x7f5d039ee186 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Core.so.5+0x88
#38  0x7f5d0421b53f in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5+0x283
#39  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5(+0x1af554) [0x7f5d04252554]
#40  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5(+0x1b03a6) [0x7f5d042533a6]
#41  0x7f5d0421782a in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5+0xde
#42  0x7f5d0421d3f1 in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Widgets.so.5+0x1af9
#43  0x7f5d05d1bae9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x89
#44  0x7f5d039ee186 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Core.so.5+0x88
#45  0x7f5d03d9440b in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Gui.so.5+0x6d3
#46  0x7f5d03d94ff7 in QGuiApplicationPrivate::processWindowSystemEvent(QWindowSystemInterfacePrivate::WindowSystemEvent*) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Gui.so.5+0x175
#47  0x7f5d03d81dd4 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Gui.so.5+0x64
#48  /tmp/.mount_FreeCAhwE8MW/usr/plugins/platforms/../../lib/libQt5XcbQpa.so.5(+0x5af0e) [0x7f5cff8cbf0e]
#49  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_dispatch+0x2e8) [0x7f5d00ac39d8]
#50  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/./libglib-2.0.so.0(+0x51c21) [0x7f5d00ac3c21]
#51  /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7f5d00ac3cae]
#52  0x7f5d03a1d42b in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Core.so.5+0x63
#53  0x7f5d039eabc1 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Core.so.5+0x187
#54  0x7f5d039eea39 in QCoreApplication::exec() from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libQt5Core.so.5+0x105
#55  0x7f5d05c944ea in Gui::Application::runApplication() from /tmp/.mount_FreeCAhwE8MW/usr/bin/../lib/libFreeCADGui.so+0x155a
#56  /tmp/.mount_FreeCAhwE8MW/usr/bin/freecad(main+0x74d) [0x561431e1e7cd]
#57  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xeb) [0x7f5d034f9e0b]
#58  /tmp/.mount_FreeCAhwE8MW/usr/bin/freecad(+0x451f) [0x561431e1f51f]
```

# Steps to reproduce

1. Create a new file
2. Go to part design workbench
3. Draw a simple sketch on XY plane, ie a rectangle
4. Draw another simple sketch either on a different plane, or on a parallel plane
5. select one sketch
6. click additive loft
7. Click add section
8. click on the first sketch (yes, this is wrong).
9. Click add section
10. click on the second sketch.
11. Crash.

# FreeCAD Info

```
OS: Debian GNU/Linux bullseye/sid (GNOME/gnome)
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.19.20406 (Git) AppImage
Build type: Release
Branch: master
Hash: bb45a2b01f9aafeae00cdf60c87b43fc36ad28ad
Python version: 3.8.2
Qt version: 5.12.5
Coin version: 4.0.0
OCC version: 7.4.0
Locale: English/Canada (en_CA)
```

# Other bug information

* **Priority:** low
* **Severity:** crash
* **Category:** Bug
* **OS:  Debian GNU/Linux bullseye/sid**
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by @chennes 2020-11-12 04:16
The bug is really in OCC ([https://forum.freecadweb.org/viewtopic.php?f=8&t=45013&p=447258#p447258](https://forum.freecadweb.org/viewtopic.php?f=8&t=45013&p=447258#p447258)) -- do we want to try to work around it, at least this exact incarnation, by preventing the original profile from being selected as a section?

---

### Comment by @luzpaz 2020-12-31 12:25
Tracking this via [OCC bugs in the bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264&start=40) forum thread


---

### Comment by @luzpaz 2022-01-15 13:51
This needs an upstream ticket
