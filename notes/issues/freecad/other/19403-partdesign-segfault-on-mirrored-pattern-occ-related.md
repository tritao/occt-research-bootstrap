# #19403 — PartDesign: Segfault on mirrored pattern (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19403`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19403
- State: `open`
- Created: `2025-02-04T15:02:09Z`
- Updated: `2025-12-06T10:50:02Z`
- Comments: `7`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Problem description

[idc 20-pin mold.zip](https://github.com/user-attachments/files/18658963/idc.20-pin.mold.zip)

1. Open attached file.
2. Left-click AdditiveLoft in the model tree.
3. Part Design > Apply a pattern > Mirrored. Crash.

```
(gdb) bt
#0  0x00007fff7a8f3e0f in Geom2d_Curve::Value(double) const () from /usr/lib/libTKG2d.so.7.8
#1  0x00007fff7956d6d0 in BOPAlgo_PaveFiller::FillPaves(int, int, int, NCollection_List<opencascade::handle<BOPDS_PaveBlock> > const&, opencascade::handle<BOPDS_PaveBlock> const&) () from /usr/lib/libTKBO.so.7.8
#2  0x00007fff7956e33f in BOPAlgo_PaveFiller::ProcessDE(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#3  0x00007fff795364de in BOPAlgo_PaveFiller::PerformInternal(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#4  0x00007fff7952da43 in BOPAlgo_PaveFiller::Perform(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#5  0x00007fff794d5d15 in BRepAlgoAPI_BuilderAlgo::IntersectShapes(NCollection_List<TopoDS_Shape> const&, Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#6  0x00007fff794d62dd in BRepAlgoAPI_BooleanOperation::Build(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#7  0x00007fff7b5973d4 in Part::TopoShape::makeElementBoolean(char const*, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*, double) () from /home/morgan/programs/freecad/lib/Part.so
#8  0x00007fff7490c1e9 in PartDesign::Transformed::execute() () from /home/morgan/programs/freecad/lib/_PartDesign.so
#9  0x00007ffff490912a in App::DocumentObject::recompute() () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#10 0x00007fff7b317c1b in Part::Feature::recompute() () from /home/morgan/programs/freecad/lib/Part.so
#11 0x00007ffff48925c4 in App::Document::_recomputeFeature(App::DocumentObject*) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#12 0x00007ffff489710f in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#13 0x00007ffff49789e9 in App::DocumentPy::recompute(_object*) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#14 0x00007ffff4978b03 in App::DocumentPy::staticCallback_recompute(_object*, _object*) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#15 0x00007ffff3994a72 in cfunction_call (func=0x7fff74a69030, args=0x7ffff3cf15e8 <_PyRuntime+88296>, kwargs=0x0) at Objects/methodobject.c:551
#16 0x00007ffff395d02c in _PyObject_MakeTpCall (tstate=0x7ffff3d20e90 <_PyRuntime+283024>, callable=0x7fff74a69030, args=<optimized out>, nargs=<optimized out>, keywords=0x0) at Objects/call.c:242
#17 0x00007ffff3975beb in _PyEval_EvalFrameDefault (tstate=<optimized out>, frame=<optimized out>, throwflag=<optimized out>) at Python/generated_cases.c.h:813
#18 0x00007ffff3a40ce5 in PyEval_EvalCode (co=0x7fffa1975230, globals=<optimized out>, locals=0x7fffec20bc80) at Python/ceval.c:601
#19 0x00007ffff3a62870 in run_eval_code_obj (tstate=tstate@entry=0x7ffff3d20e90 <_PyRuntime+283024>, co=co@entry=0x7fffa1975230, globals=globals@entry=0x7fffec20bc80, locals=locals@entry=0x7fffec20bc80) at Python/pythonrun.c:1337
#20 0x00007ffff3a5cc7a in run_mod (mod=mod@entry=0x5555561d74b8, filename=filename@entry=0x7ffff3ce4578 <_PyRuntime+34936>, globals=globals@entry=0x7fffec20bc80, locals=locals@entry=0x7fffec20bc80, flags=flags@entry=0x0, arena=arena@entry=0x7fff751df690, interactive_src=0x0, generate_new_source=0)
    at Python/pythonrun.c:1422
#21 0x00007ffff3a5068e in _PyRun_StringFlagsWithName (str=<optimized out>, name=0x7ffff3ce4578 <_PyRuntime+34936>, start=<optimized out>, globals=0x7fffec20bc80, locals=0x7fffec20bc80, flags=0x0, generate_new_source=0) at Python/pythonrun.c:1221
#22 0x00007ffff435fea6 in Base::InterpreterSingleton::runString[abi:cxx11](char const*) () from /home/morgan/programs/freecad/lib/libFreeCADBase.so
#23 0x00007ffff5541107 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#24 0x00007ffff554128c in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#25 0x00007ffff5541411 in Gui::Command::updateActive() () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#26 0x00007fff73f32265 in finishFeature(Gui::Command const*, App::DocumentObject*, App::DocumentObject*, bool, bool) () from /home/morgan/programs/freecad/lib/PartDesignGui.so
#27 0x00007fff73f34398 in std::_Function_handler<void (App::DocumentObject*, std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> >), CmdPartDesignMirrored::activated(int)::{lambda(App::DocumentObject*, std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> >)#1}>::_M_invoke(std::_Any_data const&, App::DocumentObject*&&, std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> >&&) () from /home/morgan/programs/freecad/lib/PartDesignGui.so
#28 0x00007fff73f35e8b in prepareTransformed(PartDesign::Body*, Gui::Command*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::function<void (App::DocumentObject*, std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> >)>) ()
   from /home/morgan/programs/freecad/lib/PartDesignGui.so
#29 0x00007fff73f36583 in CmdPartDesignMirrored::activated(int) () from /home/morgan/programs/freecad/lib/PartDesignGui.so
#30 0x00007ffff55478de in Gui::Command::_invoke(int, bool) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#31 0x00007ffff5547d66 in Gui::Command::invoke(int, Gui::Command::TriggerSource) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#32 0x00007ffff15b1b29 in ?? () from /usr/lib/libQt6Core.so.6
#33 0x00007ffff1f67484 in QAction::activate(QAction::ActionEvent) () from /usr/lib/libQt6Gui.so.6
#34 0x00007ffff26e2bf9 in ?? () from /usr/lib/libQt6Widgets.so.6
#35 0x00007ffff26e4c03 in ?? () from /usr/lib/libQt6Widgets.so.6
#36 0x00007ffff254f816 in QWidget::event(QEvent*) () from /usr/lib/libQt6Widgets.so.6
#37 0x00007ffff24fe78a in QApplicationPrivate::notify_helper(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#38 0x00007ffff2502a26 in QApplication::notify(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#39 0x00007ffff54da468 in Gui::GUIApplication::notify(QObject*, QEvent*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#40 0x00007ffff1557ac8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#41 0x00007ffff24f613d in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) () from /usr/lib/libQt6Widgets.so.6
#42 0x00007ffff2569d62 in ?? () from /usr/lib/libQt6Widgets.so.6
#43 0x00007ffff256ae40 in ?? () from /usr/lib/libQt6Widgets.so.6
#44 0x00007ffff24fe78a in QApplicationPrivate::notify_helper(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#45 0x00007ffff54da468 in Gui::GUIApplication::notify(QObject*, QEvent*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#46 0x00007ffff1557ac8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#47 0x00007ffff1bf0196 in QWindowPrivate::forwardToPopup(QEvent*, QWindow const*) () from /usr/lib/libQt6Gui.so.6
#48 0x00007ffff1b87cc8 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) () from /usr/lib/libQt6Gui.so.6
#49 0x00007ffff1c02b44 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Gui.so.6
#50 0x00007fffebc88c67 in ?? () from /usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6
#51 0x00007fffeddcc559 in g_main_dispatch (context=0x7fffe4000f30) at ../glib/glib/gmain.c:3357
#52 0x00007fffede2f257 in g_main_context_dispatch_unlocked (context=0x7fffe4000f30) at ../glib/glib/gmain.c:4208
#53 g_main_context_iterate_unlocked.isra.0 (context=context@entry=0x7fffe4000f30, block=block@entry=1, dispatch=dispatch@entry=1, self=<optimized out>) at ../glib/glib/gmain.c:4273
#54 0x00007fffeddcba55 in g_main_context_iteration (context=0x7fffe4000f30, may_block=1) at ../glib/glib/gmain.c:4338
#55 0x00007ffff17c22fd in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Core.so.6
#56 0x00007ffff1561ee6 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Core.so.6
#57 0x00007ffff1558f4f in QCoreApplication::exec() () from /usr/lib/libQt6Core.so.6
#58 0x00007ffff53f2c63 in Gui::Application::runApplication() () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#59 0x000055555555bf6d in main ()
```

If you do the same but use MultiTransform > Add mirrored transformation, it crashes with this:
```
Thread 1 "FreeCAD" received signal SIGSEGV, Segmentation fault.
0x00007fff7a8f3e0f in Geom2d_Curve::Value(double) const () from /usr/lib/libTKG2d.so.7.8
(gdb) bt
#0  0x00007fff7a8f3e0f in Geom2d_Curve::Value(double) const () from /usr/lib/libTKG2d.so.7.8
#1  0x00007fff7956d6d0 in BOPAlgo_PaveFiller::FillPaves(int, int, int, NCollection_List<opencascade::handle<BOPDS_PaveBlock> > const&, opencascade::handle<BOPDS_PaveBlock> const&) () from /usr/lib/libTKBO.so.7.8
#2  0x00007fff7956e33f in BOPAlgo_PaveFiller::ProcessDE(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#3  0x00007fff795364de in BOPAlgo_PaveFiller::PerformInternal(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#4  0x00007fff7952da43 in BOPAlgo_PaveFiller::Perform(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#5  0x00007fff794d5d15 in BRepAlgoAPI_BuilderAlgo::IntersectShapes(NCollection_List<TopoDS_Shape> const&, Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#6  0x00007fff794d62dd in BRepAlgoAPI_BooleanOperation::Build(Message_ProgressRange const&) () from /usr/lib/libTKBO.so.7.8
#7  0x00007fff7b5973d4 in Part::TopoShape::makeElementBoolean(char const*, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*, double) () from /home/morgan/programs/freecad/lib/Part.so
#8  0x00007fff7310c1e9 in PartDesign::Transformed::execute() () from /home/morgan/programs/freecad/lib/_PartDesign.so
#9  0x00007ffff490912a in App::DocumentObject::recompute() () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#10 0x00007fff7b317c1b in Part::Feature::recompute() () from /home/morgan/programs/freecad/lib/Part.so
#11 0x00007ffff48925c4 in App::Document::_recomputeFeature(App::DocumentObject*) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#12 0x00007ffff489710f in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#13 0x00007ffff48982c3 in App::Document::recomputeFeature(App::DocumentObject*, bool) () from /home/morgan/programs/freecad/lib/libFreeCADApp.so
#14 0x00007fff7287c32f in PartDesignGui::ViewProviderTransformed::recomputeFeature(bool) () from /home/morgan/programs/freecad/lib/PartDesignGui.so
#15 0x00007fff727f94b5 in PartDesignGui::TaskMultiTransformParameters::finishAdd(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&) () from /home/morgan/programs/freecad/lib/PartDesignGui.so
#16 0x00007fff727fa221 in PartDesignGui::TaskMultiTransformParameters::onTransformAddMirrored() () from /home/morgan/programs/freecad/lib/PartDesignGui.so
#17 0x00007ffff15b1b29 in ?? () from /usr/lib/libQt6Core.so.6
#18 0x00007ffff1f67484 in QAction::activate(QAction::ActionEvent) () from /usr/lib/libQt6Gui.so.6
#19 0x00007ffff26e2bf9 in ?? () from /usr/lib/libQt6Widgets.so.6
#20 0x00007ffff26e4c03 in ?? () from /usr/lib/libQt6Widgets.so.6
#21 0x00007ffff254f816 in QWidget::event(QEvent*) () from /usr/lib/libQt6Widgets.so.6
#22 0x00007ffff24fe78a in QApplicationPrivate::notify_helper(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#23 0x00007ffff2502a26 in QApplication::notify(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#24 0x00007ffff54da468 in Gui::GUIApplication::notify(QObject*, QEvent*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#25 0x00007ffff1557ac8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#26 0x00007ffff24f613d in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) () from /usr/lib/libQt6Widgets.so.6
#27 0x00007ffff2569d62 in ?? () from /usr/lib/libQt6Widgets.so.6
#28 0x00007ffff256ae40 in ?? () from /usr/lib/libQt6Widgets.so.6
#29 0x00007ffff24fe78a in QApplicationPrivate::notify_helper(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#30 0x00007ffff54da468 in Gui::GUIApplication::notify(QObject*, QEvent*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#31 0x00007ffff1557ac8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#32 0x00007ffff1b8752b in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) () from /usr/lib/libQt6Gui.so.6
#33 0x00007ffff1c02b44 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Gui.so.6
#34 0x00007fffebc88c67 in ?? () from /usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6
#35 0x00007fffeddcc559 in g_main_dispatch (context=0x7fffe4000f30) at ../glib/glib/gmain.c:3357
#36 0x00007fffede2f257 in g_main_context_dispatch_unlocked (context=0x7fffe4000f30) at ../glib/glib/gmain.c:4208
#37 g_main_context_iterate_unlocked.isra.0 (context=context@entry=0x7fffe4000f30, block=block@entry=1, dispatch=dispatch@entry=1, self=<optimized out>) at ../glib/glib/gmain.c:4273
#38 0x00007fffeddcba55 in g_main_context_iteration (context=0x7fffe4000f30, may_block=1) at ../glib/glib/gmain.c:4338
#39 0x00007ffff17c22fd in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Core.so.6
#40 0x00007ffff1561ee6 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Core.so.6
#41 0x00007ffff26e92b9 in ?? () from /usr/lib/libQt6Widgets.so.6
#42 0x00007ffff26e958f in QMenu::exec(QList<QAction*> const&, QPoint const&, QAction*, QWidget*) () from /usr/lib/libQt6Widgets.so.6
#43 0x00007ffff254f3cb in QWidget::event(QEvent*) () from /usr/lib/libQt6Widgets.so.6
#44 0x00007ffff25ee138 in QFrame::event(QEvent*) () from /usr/lib/libQt6Widgets.so.6
#45 0x00007ffff1554a08 in QCoreApplicationPrivate::sendThroughObjectEventFilters(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#46 0x00007ffff24fe77a in QApplicationPrivate::notify_helper(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#47 0x00007ffff2503de8 in QApplication::notify(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#48 0x00007ffff54da468 in Gui::GUIApplication::notify(QObject*, QEvent*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#49 0x00007ffff1557ac8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#50 0x00007ffff2569ee0 in ?? () from /usr/lib/libQt6Widgets.so.6
#51 0x00007ffff256ae40 in ?? () from /usr/lib/libQt6Widgets.so.6
#52 0x00007ffff24fe78a in QApplicationPrivate::notify_helper(QObject*, QEvent*) () from /usr/lib/libQt6Widgets.so.6
#53 0x00007ffff54da468 in Gui::GUIApplication::notify(QObject*, QEvent*) () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#54 0x00007ffff1557ac8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) () from /usr/lib/libQt6Core.so.6
#55 0x00007ffff1b8752b in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) () from /usr/lib/libQt6Gui.so.6
#56 0x00007ffff1c02b44 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Gui.so.6
#57 0x00007fffebc88c67 in ?? () from /usr/lib/qt6/plugins/platforms/../../../libQt6XcbQpa.so.6
#58 0x00007fffeddcc559 in g_main_dispatch (context=0x7fffe4000f30) at ../glib/glib/gmain.c:3357
#59 0x00007fffede2f257 in g_main_context_dispatch_unlocked (context=0x7fffe4000f30) at ../glib/glib/gmain.c:4208
#60 g_main_context_iterate_unlocked.isra.0 (context=context@entry=0x7fffe4000f30, block=block@entry=1, dispatch=dispatch@entry=1, self=<optimized out>) at ../glib/glib/gmain.c:4273
#61 0x00007fffeddcba55 in g_main_context_iteration (context=0x7fffe4000f30, may_block=1) at ../glib/glib/gmain.c:4338
#62 0x00007ffff17c22fd in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Core.so.6
#63 0x00007ffff1561ee6 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) () from /usr/lib/libQt6Core.so.6
#64 0x00007ffff1558f4f in QCoreApplication::exec() () from /usr/lib/libQt6Core.so.6
#65 0x00007ffff53f2c63 in Gui::Application::runApplication() () from /home/morgan/programs/freecad/lib/libFreeCADGui.so
#66 0x000055555555bf6d in main ()
```

![Image](https://github.com/user-attachments/assets/ee36e3ce-db1a-47e4-8e78-09ed4ab13f14)

### Full version info

```shell
OS: Manjaro Linux (KDE/plasma/xcb)
Architecture: x86_64
Version: 1.1.0dev.40080 (Git)
Build type: Release
Branch: main
Hash: 5528ec58f69fae60fdaf7f780035cfa59477b8cc
Python 3.13.1, Qt 6.8.1, Coin 4.0.3, Vtk 9.4.1, OCC 7.8.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical/physical DPI: 96/108.888
Installed mods: 
  * OpenDark 2023.12.17
  * A2plus 0.4.68
  * fasteners 0.5.34
  * Woodworking 0.21.2.33771
  * CurvedShapes 1.0.13
  * Curves 0.6.53
```
