# #14640 — Additive Loft operation causes Segmentation fault (OCC bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#14640`
- URL: https://github.com/FreeCAD/FreeCAD/issues/14640
- State: `open`
- Created: `2024-06-12T15:21:15Z`
- Updated: `2025-02-22T07:19:01Z`
- Comments: `4`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `non-blocker`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description


Additive Loft operation between a sketch and a datum line crashes FreeCAD. I know that this operation doesn't make sense, but at least it shouldn't crash FreeCAD.

Log from the crash:
```
FreeCAD 0.22.0, Libs: 0.22.0devR37707 (Git)
© Juergen Riegel, Werner Mayer, Yorik van Havre and others 2001-2024
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.
FreeCAD wouldn't be possible without FreeCAD community.
  #####                 ####  ###   ####  
  #                    #      # #   #   # 
  #     ##  #### ####  #     #   #  #   # 
  ####  # # #  # #  #  #     #####  #   # 
  #     #   #### ####  #    #     # #   # 
  #     #   #    #     #    #     # #   #  ##  ##  ##
  #     #   #### ####   ### #     # ####   ##  ##  ##

Coin warning in glxglue_isdirect(): Couldn't get current GLX context.
Program received signal SIGSEGV, Segmentation fault.
#0  /usr/lib/libc.so.6(+0x3cae0) [0x7fb3fe050ae0]
#1  0x7fb3e4c7c02c in BRep_Tool::Parameter(TopoDS_Vertex const&, TopoDS_Edge const&, double&) from /usr/lib/libTKBRep.so.7.7+0x1cc
#2  0x7fb3e4c7c593 in BRep_Tool::Parameter(TopoDS_Vertex const&, TopoDS_Edge const&) from /usr/lib/libTKBRep.so.7.7+0x23
#3  0x7fb3a8ffdaeb in BRepFill_CompatibleWires::Perform(bool) from /usr/lib/libTKBool.so.7.7+0x5ab
#4  0x7fb3aa31435a in BRepOffsetAPI_ThruSections::Build(Message_ProgressRange const&) from /usr/lib/libTKOffset.so.7.7+0x1ba
#5  0x7fb3ab3bf839 in Part::TopoShape::makeElementLoft(std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, Part::IsSolid, Part::IsRuled, Part::IsClosed, int, char const*) from /usr/lib/freecad/lib/Part.so+0x1d9
#6  0x7fb39307b21b in PartDesign::Loft::execute() from /usr/lib/freecad/lib/_PartDesign.so+0x92b
#7  0x7fb400cf8142 in App::DocumentObject::recompute() from /usr/lib/freecad/lib/libFreeCADApp.so+0xc2
#8  0x7fb400c7e364 in App::Document::_recomputeFeature(App::DocumentObject*) from /usr/lib/freecad/lib/libFreeCADApp.so+0x334
#9  0x7fb400c82d77 in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /usr/lib/freecad/lib/libFreeCADApp.so+0x647
#10  0x7fb400d6c4b6 in App::DocumentPy::recompute(_object*) from /usr/lib/freecad/lib/libFreeCADApp.so+0x2f6
#11  0x7fb400d6c64c in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /usr/lib/freecad/lib/libFreeCADApp.so+0x2c
#12  /usr/lib/libpython3.12.so.1.0(+0x1a52ed) [0x7fb3fffa52ed]
#13  /usr/lib/libpython3.12.so.1.0(_PyObject_MakeTpCall+0x2fb) [0x7fb3fff8550b]
#14  /usr/lib/libpython3.12.so.1.0(+0x8bdfa) [0x7fb3ffe8bdfa]
#15  /usr/lib/libpython3.12.so.1.0(PyEval_EvalCode+0xb7) [0x7fb40003d767]
#16  /usr/lib/libpython3.12.so.1.0(+0x2608b7) [0x7fb4000608b7]
#17  /usr/lib/libpython3.12.so.1.0(+0x25b9dc) [0x7fb40005b9dc]
#18  /usr/lib/libpython3.12.so.1.0(PyRun_StringFlags+0x6d) [0x7fb40004dedd]
#19  0x7fb40075f83e in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /usr/lib/freecad/lib/libFreeCADBase.so+0x6e
#20  0x7fb4018ffcc7 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /usr/lib/freecad/lib/libFreeCADGui.so+0x97
#21  0x7fb4018ffe63 in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /usr/lib/freecad/lib/libFreeCADGui.so+0xe3
#22  0x7fb401900007 in Gui::Command::updateActive() from /usr/lib/freecad/lib/libFreeCADGui.so+0x47
#23  /usr/lib/freecad/lib/PartDesignGui.so(+0x1387bc) [0x7fb390b387bc]
#24  /usr/lib/freecad/lib/PartDesignGui.so(+0x1439e6) [0x7fb390b439e6]
#25  0x7fb390b48120 in prepareProfileBased(PartDesign::Body*, Gui::Command*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::function<void (Part::Feature*, App::DocumentObject*)>) from /usr/lib/freecad/lib/PartDesignGui.so+0x340
#26  0x7fb390b499a2 in CmdPartDesignAdditiveLoft::activated(int) from /usr/lib/freecad/lib/PartDesignGui.so+0xf2
#27  0x7fb401904ae7 in Gui::Command::_invoke(int, bool) from /usr/lib/freecad/lib/libFreeCADGui.so+0x257
#28  0x7fb401904fdf in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /usr/lib/freecad/lib/libFreeCADGui.so+0x13f
#29  /usr/lib/libQt6Core.so.6(+0x1a17e7) [0x7fb3fe7a17e7]
#30  0x7fb3ff11b0b4 in QAction::activate(QAction::ActionEvent) from /usr/lib/libQt6Gui.so.6+0x154
#31  /usr/lib/libQt6Widgets.so.6(+0x20e7d5) [0x7fb3ff80e7d5]
#32  0x7fb3ff81b22e in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /usr/lib/libQt6Widgets.so.6+0xde
#33  0x7fb3ff943bcd in QToolButton::mouseReleaseEvent(QMouseEvent*) from /usr/lib/libQt6Widgets.so.6+0x2d
#34  0x7fb3ff74c0ce in QWidget::event(QEvent*) from /usr/lib/libQt6Widgets.so.6+0xc0e
#35  0x7fb3ff6fc55c in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /usr/lib/libQt6Widgets.so.6+0x9c
#36  0x7fb3ff701a01 in QApplication::notify(QObject*, QEvent*) from /usr/lib/libQt6Widgets.so.6+0x10a1
#37  0x7fb401899b29 in Gui::GUIApplication::notify(QObject*, QEvent*) from /usr/lib/freecad/lib/libFreeCADGui.so+0x99
#38  0x7fb3fe744e38 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /usr/lib/libQt6Core.so.6+0x158
#39  0x7fb3ff6f3e6d in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /usr/lib/libQt6Widgets.so.6+0x21d
#40  /usr/lib/libQt6Widgets.so.6(+0x162072) [0x7fb3ff762072]
#41  /usr/lib/libQt6Widgets.so.6(+0x1636b0) [0x7fb3ff7636b0]
#42  0x7fb3ff6fc55c in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /usr/lib/libQt6Widgets.so.6+0x9c
#43  0x7fb401899b29 in Gui::GUIApplication::notify(QObject*, QEvent*) from /usr/lib/freecad/lib/libFreeCADGui.so+0x99
#44  0x7fb3fe744e38 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /usr/lib/libQt6Core.so.6+0x158
#45  0x7fb3fed76cf0 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /usr/lib/libQt6Gui.so.6+0x8d0
#46  0x7fb3fede5b44 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/libQt6Gui.so.6+0x304
#47  /usr/lib/libQt6Gui.so.6(+0x5f9594) [0x7fb3ff1f9594]
#48  /usr/lib/libglib-2.0.so.0(+0x5ca89) [0x7fb3fcf0ea89]
#49  /usr/lib/libglib-2.0.so.0(+0xbe9b7) [0x7fb3fcf709b7]
#50  /usr/lib/libglib-2.0.so.0(g_main_context_iteration+0x35) [0x7fb3fcf0df95]
#51  0x7fb3fe9a28dd in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/libQt6Core.so.6+0x8d
#52  0x7fb3fe74f10e in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/libQt6Core.so.6+0x19e
#53  0x7fb3fe74945d in QCoreApplication::exec() from /usr/lib/libQt6Core.so.6+0x8d
#54  0x7fb4017a1814 in Gui::Application::runApplication() from /usr/lib/freecad/lib/libFreeCADGui.so+0xd34
#55  freecad(+0x7cca) [0x55821dd8bcca]
#56  /usr/lib/libc.so.6(+0x25c88) [0x7fb3fe039c88]
#57  /usr/lib/libc.so.6(__libc_start_main+0x8c) [0x7fb3fe039d4c]
#58  freecad(+0x80c5) [0x55821dd8c0c5]
```


### Full version info

```shell
FreeCad compiled from git source.

OS: Arch Linux (KDE/plasma)
Word size of FreeCAD: 64-bit
Version: 0.22.0dev.37707 (Git)
Build type: Release
Branch: main
Hash: b463846bea5ee34bd180d0a5072f61b3da6aab44
Python 3.12.3, Qt 6.7.1, Coin 4.0.2, Vtk 9.3.0, OCC 7.7.2
Locale: English/United States (en_US)
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
