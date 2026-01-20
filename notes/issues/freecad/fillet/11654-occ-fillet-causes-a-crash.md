# #11654 — OCC: Fillet causes a crash

- Repo: `FreeCAD/FreeCAD`
- Issue: `#11654`
- URL: https://github.com/FreeCAD/FreeCAD/issues/11654
- State: `open`
- Created: `2023-12-05T10:22:44Z`
- Updated: `2025-12-13T11:31:34Z`
- Comments: `14`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Topic: Fillets`, `non-blocker`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

FreeCAD crashes when trying to add a fillet to this edge:

![image](https://github.com/FreeCAD/FreeCAD/assets/42166884/0ae1d296-5b63-493a-a143-ed274bd1fc2d)
[fender_crash_repro.zip](https://github.com/FreeCAD/FreeCAD/files/13558632/fender_crash_repro.zip)


Logs from running FreeCAD from the CLI:

<details>

```
    Program received signal SIGSEGV, Segmentation fault.
    #0  /lib/x86_64-linux-gnu/libc.so.6(+0x42520) [0x7effbc242520]
    #1  0x7efeea4b6184 in Geom2dAPI_ProjectPointOnCurve::Init(gp_Pnt2d const&, opencascade::handle<Geom2d_Curve> const&) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./libTKGeomAlgo.so.7+0x14
    #2  0x7efeea4b641d in Geom2dAPI_ProjectPointOnCurve::Geom2dAPI_ProjectPointOnCurve(gp_Pnt2d const&, opencascade::handle<Geom2d_Curve> const&) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./libTKGeomAlgo.so.7+0x3d
    #3  0x7eff03d5def5 in ChFi3d_Builder::PerformIntersectionAtEnd(int) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./libTKFillet.so.7+0x2b85
    #4  0x7eff03d04e23 in ChFi3d_Builder::PerformFilletOnVertex(int) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./libTKFillet.so.7+0x4f3
    #5  0x7eff03d05df3 in ChFi3d_Builder::Compute() from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./libTKFillet.so.7+0xed3
    #6  0x7eff03e9569e in BRepFilletAPI_MakeFillet::Build(Message_ProgressRange const&) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./libTKFillet.so.7+0x2e
    #7  0x7eff76762d9e in PartDesign::Fillet::execute() from /tmp/.mount_FreeCAy2k7Ix/usr/lib/_PartDesign.so+0x8ee
    #8  0x7effbe0411c2 in App::DocumentObject::recompute() from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADApp.so+0xc2
    #9  0x7efeeba6968c in Part::Feature::recompute() from /tmp/.mount_FreeCAy2k7Ix/usr/lib/./Part.so+0xc
    #10  0x7effbe01b2bc in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADApp.so+0x2fc
    #11  0x7effbe02788c in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADApp.so+0x61c
    #12  0x7effbe0a5d1e in App::DocumentPy::recompute(_object*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADApp.so+0x2ee
    #13  0x7effbe0a5e34 in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADApp.so+0x24
    #14  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(+0x148c18) [0x7effbe548c18]
    #15  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(_PyObject_MakeTpCall+0x27b) [0x7effbe541f0b]
    #16  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(_PyEval_EvalFrameDefault+0x5453) [0x7effbe53ddc3]
    #17  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(+0x1de9b0) [0x7effbe5de9b0]
    #18  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(PyEval_EvalCode+0x8c) [0x7effbe5de8fc]
    #19  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(+0x20db43) [0x7effbe60db43]
    #20  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(+0x208efa) [0x7effbe608efa]
    #21  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libpython3.10.so.1.0(PyRun_StringFlags+0x7d) [0x7effbe60125d]
    #22  0x7effbdb38eec in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADBase.so+0x6c
    #23  0x7effbed2d024 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x94
    #24  0x7effbed2d1b3 in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0xe3
    #25  0x7effbed2d2d4 in Gui::Command::updateActive() from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x44
    #26  0x7efee38eb0b6 in finishFeature(Gui::Command const*, App::DocumentObject*, App::DocumentObject*, bool, bool) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/PartDesignGui.so+0x2f6
    #27  0x7efee38ecb24 in finishDressupFeature(Gui::Command const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, Part::Feature*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, bool) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/PartDesignGui.so+0x684
    #28  0x7efee38fbe6e in makeChamferOrFillet(Gui::Command*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/PartDesignGui.so+0xde
    #29  0x7efee38fc10b in CmdPartDesignFillet::activated(int) from /tmp/.mount_FreeCAy2k7Ix/usr/lib/PartDesignGui.so+0x4b
    #30  0x7effbed35f98 in Gui::Command::_invoke(int, bool) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x2a8
    #31  0x7effbed36354 in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x134
    #32  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Core.so.5(+0x1dff9b) [0x7effbc9dff9b]
    #33  0x7effbd565136 in QAction::triggered(bool) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0x32
    #34  0x7effbd566c20 in QAction::activate(QAction::ActionEvent) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0xc6
    #35  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5(+0x2036cb) [0x7effbd6036cb]
    #36  0x7effbd6037a7 in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0x79
    #37  0x7effbd69c0d0 in QToolButton::mouseReleaseEvent(QMouseEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0xa
    #38  0x7effbd594202 in QWidget::event(QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0x134
    #39  0x7effbd56a087 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0xd9
    #40  0x7effbd56e36d in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0x663
    #41  0x7effbecea339 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x99
    #42  0x7effbc9c2a18 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Core.so.5+0x8e
    #43  0x7effbd56d981 in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0x283
    #44  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5(+0x1a338d) [0x7effbd5a338d]
    #45  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5(+0x1a4505) [0x7effbd5a4505]
    #46  0x7effbd56a087 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Widgets.so.5+0xd9
    #47  0x7effbecea339 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x99
    #48  0x7effbc9c2a18 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Core.so.5+0x8e
    #49  0x7effbcf0956e in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Gui.so.5+0x6b6
    #50  0x7effbcef6091 in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Gui.so.5+0x57
    #51  /tmp/.mount_FreeCAy2k7Ix/usr/plugins/platforms/../../lib/libQt5XcbQpa.so.5(+0x5672c) [0x7effb777872c]
    #52  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_dispatch+0x2ad) [0x7effbaf1538d]
    #53  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/./libglib-2.0.so.0(+0x5d649) [0x7effbaf15649]
    #54  /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7effbaf156de]
    #55  0x7effbc9f3d50 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Core.so.5+0x5c
    #56  0x7effbc9c05d8 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Core.so.5+0x180
    #57  0x7effbc9c47af in QCoreApplication::exec() from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libQt5Core.so.5+0x107
    #58  0x7effbec50bfe in Gui::Application::runApplication() from /tmp/.mount_FreeCAy2k7Ix/usr/bin/../lib/libFreeCADGui.so+0x1e3e
    #59  /tmp/.mount_FreeCAy2k7Ix/usr/bin/freecad(+0x8620) [0x55d93906c620]
    #60  /lib/x86_64-linux-gnu/libc.so.6(+0x29d90) [0x7effbc229d90]
    #61  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x80) [0x7effbc229e40]
    #62  /tmp/.mount_FreeCAy2k7Ix/usr/bin/freecad(+0x8981) [0x55d93906c981]
```

</details>

### Full version info

```shell
OS: Ubuntu 22.04.3 LTS (ubuntu:GNOME/ubuntu)
Word size of FreeCAD: 64-bit
Version: 0.21.1.33694 (Git) AppImage
Build type: Release
Branch: (HEAD detached at 0.21.1)
Hash: f6708547a9bb3f71a4aaade12109f511a72c207c
Python 3.10.12, Qt 5.15.8, Coin 4.0.0, Vtk 9.2.5, OCC 7.6.3
Locale: English/United States (en_US)
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
