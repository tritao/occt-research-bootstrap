# #18056 — STEP: Export to step crashes every time

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18056`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18056
- State: `closed`
- Created: `2024-11-22T03:30:16Z`
- Updated: `2025-09-25T11:39:28Z`
- Closed: `2025-09-25T11:39:27Z`
- Comments: `14`
- Milestone: `1.1`
- Labels: `Mod: Core`, `Type: Crash`, `File format: STEP`, `OS: Linux`, `Status: Confirmed`, `Status: Needs steps to reproduce`, `Priority: Critical`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

Using the newly released `./FreeCAD_1.0.0-conda-Linux-x86_64-py311.AppImage`, when I open up my FreeCAD model and try to export it as a `.step` file, FreeCAD crashes with a backtrace.

Here is the model in question (~8MB): https://github.com/peterwwillis/truckcamper/commit/3c36f2a8a087ac0808d98c156b4c919e3cebfff5#diff-ac331cf859002534c41bea9899bac767be8626762007df4f8e9ace3751610a08

Crash terminal output: <details>
```
psypete@think:~/Downloads$ ./FreeCAD_1.0.0-conda-Linux-x86_64-py311.AppImage 
FreeCAD 1.0.0, Libs: 1.0.0R39109 (Git)
(C) 2001-2024 FreeCAD contributors
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.

/home/runner/work/FreeCAD-Bundle/FreeCAD-Bundle/conda/linux/AppDir/usr/share/libdrm/amdgpu.ids: No such file or directory
<Import> ExportOCAF2.cpp(387): SlideInCamper1#FinalBaseMesh has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#FinalBaseMesh002 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#FinalBaseMesh001 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group019 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group028 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#LinkGroup has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group083 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group057 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group060 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group069 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group085 has null shape
<Import> ExportOCAF2.cpp(387): SlideInCamper1#Group086 has null shape
Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x45320) [0x7108a6e45320]
#1  /tmp/.mount_FreeCAAagBpo/usr/lib/././libTKXDESTEP.so.7.7(+0x89291) [0x7108809c7291]
#2  /tmp/.mount_FreeCAAagBpo/usr/lib/././libTKXDESTEP.so.7.7(+0x8a078) [0x7108809c8078]
#3  0x7108809c99e1 in STEPCAFControl_Writer::writeColors(opencascade::handle<XSControl_WorkSession> const&, NCollection_Sequence<TDF_Label> const&) from /tmp/.mount_FreeCAAagBpo/usr/lib/././libTKXDESTEP.so.7.7+0x9e1
#4  0x7108809e6dff in STEPCAFControl_Writer::transfer(STEPControl_Writer&, NCollection_Sequence<TDF_Label> const&, STEPControl_StepModelType, char const*, bool, Message_ProgressRange const&) from /tmp/.mount_FreeCAAagBpo/usr/lib/././libTKXDESTEP.so.7.7+0x17ef
#5  0x7108809e726f in STEPCAFControl_Writer::Transfer(opencascade::handle<TDocStd_Document> const&, STEPControl_StepModelType, char const*, Message_ProgressRange const&) from /tmp/.mount_FreeCAAagBpo/usr/lib/././libTKXDESTEP.so.7.7+0x20f
#6  0x710880b4f117 in Import::WriterStep::write(opencascade::handle<TDocStd_Document>) const from /tmp/.mount_FreeCAAagBpo/usr/lib/./Import.so+0x137
#7  /tmp/.mount_FreeCAAagBpo/usr/lib/ImportGui.so(+0x33eaa) [0x710880bcbeaa]
#8  /tmp/.mount_FreeCAAagBpo/usr/lib/ImportGui.so(+0x2f32d) [0x710880bc732d]
#9  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADBase.so(method_keyword_call_handler+0x374) [0x7108a8adc774]
#10  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(+0x20603d) [0x7108a980603d]
#11  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(_PyObject_MakeTpCall+0x26c) [0x7108a97e5b5c]
#12  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(_PyEval_EvalFrameDefault+0x6f2) [0x7108a97f1532]
#13  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(+0x2abd1d) [0x7108a98abd1d]
#14  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(PyEval_EvalCode+0xa4) [0x7108a98ab794]
#15  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(+0x2cabf3) [0x7108a98cabf3]
#16  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(+0x2c669a) [0x7108a98c669a]
#17  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libpython3.11.so.1.0(PyRun_StringFlags+0x69) [0x7108a98ba9c9]
#18  0x7108a8b4641c in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADBase.so+0x6c
#19  0x7108aa1b6ba4 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0x94
#20  0x7108aa0a8646 in Gui::Application::exportTo(char const*, char const*, char const*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0x526
#21  0x7108aa1d3514 in StdCmdExport::activated(int) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0x694
#22  0x7108aa1c059f in Gui::Command::_invoke(int, bool) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0x23f
#23  0x7108aa1c098f in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0x12f
#24  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Core.so.5(+0x2eb6f2) [0x7108a74eb6f2]
#25  0x7108a836a462 in QAction::triggered(bool) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0x32
#26  0x7108a836ce2b in QAction::activate(QAction::ActionEvent) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0xab
#27  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5(+0x2e12e2) [0x7108a84e12e2]
#28  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5(+0x2e8c34) [0x7108a84e8c34]
#29  0x7108a83aec08 in QWidget::event(QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0x178
#30  0x7108a83703ae in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0x7e
#31  0x7108a8378262 in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0x13a2
#32  0x7108aa169559 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0xc9
#33  0x7108a74b6b28 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Core.so.5+0x108
#34  0x7108a83763eb in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0x1ab
#35  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5(+0x1c72a5) [0x7108a83c72a5]
#36  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5(+0x1ca0c9) [0x7108a83ca0c9]
#37  0x7108a83703ae in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Widgets.so.5+0x7e
#38  0x7108aa169559 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0xc9
#39  0x7108a74b6b28 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Core.so.5+0x108
#40  0x7108a7b353ec in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Gui.so.5+0x84c
#41  0x7108a7b0b0bc in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Gui.so.5+0xac
#42  /tmp/.mount_FreeCAAagBpo/usr/plugins/platforms/../../lib/libQt5XcbQpa.so.5(+0x64bea) [0x7108a1421bea]
#43  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/./libglib-2.0.so.0(+0x5bad7) [0x7108a5b10ad7]
#44  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/./libglib-2.0.so.0(+0x5eac7) [0x7108a5b13ac7]
#45  /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7108a5b140ce]
#46  0x7108a750aa36 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Core.so.5+0x66
#47  0x7108a74b570b in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Core.so.5+0x11b
#48  0x7108a74bd212 in QCoreApplication::exec() from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libQt5Core.so.5+0x82
#49  0x7108aa0c8744 in Gui::Application::runApplication() from /tmp/.mount_FreeCAAagBpo/usr/bin/../lib/libFreeCADGui.so+0x8a4
#50  /tmp/.mount_FreeCAAagBpo/usr/bin/freecad(+0x78b7) [0x6157e7f148b7]
#51  /lib/x86_64-linux-gnu/libc.so.6(+0x2a1ca) [0x7108a6e2a1ca]
#52  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x8b) [0x7108a6e2a28b]
#53  /tmp/.mount_FreeCAAagBpo/usr/bin/freecad(+0x7c2a) [0x6157e7f14c2a]
```
</details>

---

Unrelated, but these other exports also fail:

**WebGL:** CPU spikes and application does not return no matter how long I let it spin. If I hit Ctrl+C on the command line, an error window will pop up and I can continue using the app. 

An error in the console is:
```
22:25:19  pyException: Traceback (most recent call last):
  File "<string>", line 21, in <module>
  File "/tmp/.mount_FreeCAmmohnk/usr/Mod/BIM/importers/importWebGL.py", line 822, in export
    if objdata['floats'][f] == verts[v]:
       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
<class 'KeyboardInterrupt'>: <unknown exception data>
```

**OpenCAD:** I get the error:

```
'App.DocumentObjectGroup' object has no attribute 'Shape'
```


---


### Full version info

```shell
FreeCAD 1.0.0 Revision: 39109 (Git)

Library versions:
boost    1_82
Coin3D   4.0.3
Eigen3   3.4.0
OCC      7.7.2
Qt       5.15.13
Python   3.11.9
PySide   5.15.8
shiboken 5.15.8
SMESH    9.8.0.2
VTK      9.2.6
xerces-c 3.2.5
```

This is on Ubuntu 24.04.1 LTS, on a Lenovo ThinkPad Z13 G1


### Subproject(s) affected?

None

### Anything else?



### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
