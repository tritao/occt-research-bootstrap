# #5783 — Crash with STEP export (Upstream OCC bug)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5783`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5783
- State: `open`
- Created: `2022-02-07T17:45:36Z`
- Updated: `2025-09-21T10:27:15Z`
- Comments: `9`
- Labels: `Type: Bug`, `Status: Duplicate`, `3rd party: OCC`, `Type: Crash`, `File format: STEP`, `Type: Has workaround`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=3435

* **Reporter:** fhackenberger
* **Date submitted:** 4/19/2018
* **FreeCAD version:** 0.18
* **Category:** Bug
* **Status:** confirmed
* **Tags:** #pending, #ready-for-migration, OCC 7.6, OCC Bug, STEP, upstream


# Original report text

Freecad crashes when exporting the (only) part in the attached project as a .step file.

OS: Ubuntu 16.04.4 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.13515 (Git)
Build type: None
Branch: releases/FreeCAD-0-17
Hash: e17b340949b75a226cc7d89989b0aa238ccfc75f
Python version: 2.7.12
Qt version: 4.8.7
Coin version: 4.0.0a
OCC version: 7.2.0
Locale: English/UnitedKingdom (en_GB)


# Additional information

I exported the part as an IGES, re-imported it and then everything is fine.

```
$ freecad --log-file -
FreeCAD 0.17, Libs: 0.17R13515 (Git)
© Juergen Riegel, Werner Mayer, Yorik van Havre 2001-2018
  #####                 ####  ###   ####  
  #                    #      # #   #   # 
  #     ##  #### ####  #     #   #  #   # 
  ####  # # #  # #  #  #     #####  #   # 
  #     #   #### ####  #    #     # #   # 
  #     #   #    #     #    #     # #   #  ##  ##  ##
  #     #   #### ####   ### #     # ####   ##  ##  ##

Mod pluginloader InitGui.py starting ...
pluginmanager config file /home/fhackenberger/.FreeCAD//Mod/plugins/pluginloaderconfig.yaml
pluginmanager userconfig file /usr/lib/freecad/Mod/plugins/myconfig.yaml
userconfigfile not available
IOError: [Errno 2] No such file or directory: '/usr/lib/freecad/Mod/plugins/myconfig.yaml'

pluginmanager userconfig file /usr/lib/freecad/Mod/plugins/myconfig.yaml
userconfigfile not available and cannot be created
IOError: [Errno 2] No such file or directory: '/usr/lib/freecad/Mod/plugins/myconfig.yaml'

Mod pluginloader InitGui.py done
gentoolbars ...
My Macros done
My Workbenches done
Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x354b0) [0x7f190abe04b0]
#1  0x7f18e3ac65ff in TopoDSToStep_MakeStepFace::Init(TopoDS_Face const&, TopoDSToStep_Tool&, opencascade::handle<Transfer_FinderProcess> const&) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x1a7f
#2  0x7f18e3ab8573 in TopoDSToStep_Builder::Init(TopoDS_Shape const&, TopoDSToStep_Tool&, opencascade::handle<Transfer_FinderProcess> const&) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x503
#3  0x7f18e3ab8fe8 in TopoDSToStep_Builder::TopoDSToStep_Builder(TopoDS_Shape const&, TopoDSToStep_Tool&, opencascade::handle<Transfer_FinderProcess> const&) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x38
#4  /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7(+0x260cfc) [0x7f18e3abecfc]
#5  0x7f18e3abf60f in TopoDSToStep_MakeManifoldSolidBrep::TopoDSToStep_MakeManifoldSolidBrep(TopoDS_Solid const&, opencascade::handle<Transfer_FinderProcess> const&) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x5f
#6  0x7f18e3adfe1c in STEPControl_ActorWrite::TransferShape(opencascade::handle<Transfer_Finder> const&, opencascade::handle<StepShape_ShapeDefinitionRepresentation> const&, opencascade::handle<Transfer_FinderProcess> const&, opencascade::handle<TopTools_HSequenceOfShape> const&, bool) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x1e7c
#7  0x7f18e3ae5057 in STEPControl_ActorWrite::Transfer(opencascade::handle<Transfer_Finder> const&, opencascade::handle<Transfer_FinderProcess> const&) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x2e7
#8  0x7f18e6406317 in Transfer_ActorOfFinderProcess::Transferring(opencascade::handle<Transfer_Finder> const&, opencascade::handle<Transfer_ProcessForFinder> const&) from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0x67
#9  0x7f18e6411696 in Transfer_ProcessForFinder::TransferProduct(opencascade::handle<Transfer_Finder> const&) from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0xc6
#10  0x7f18e641357c in Transfer_ProcessForFinder::Transferring(opencascade::handle<Transfer_Finder> const&) from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0x1cc
#11  0x7f18e6413da6 in Transfer_ProcessForFinder::Transfer(opencascade::handle<Transfer_Finder> const&) from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0x26
#12  /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7(+0x177c53) [0x7f18e6497c53]
#13  0x7f18e6498758 in XSControl_Controller::TransferWriteShape(TopoDS_Shape const&, opencascade::handle<Transfer_FinderProcess> const&, opencascade::handle<Interface_InterfaceModel> const&, int) const from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0x78
#14  0x7f18e3ae68b4 in STEPControl_Controller::TransferWriteShape(TopoDS_Shape const&, opencascade::handle<Transfer_FinderProcess> const&, opencascade::handle<Interface_InterfaceModel> const&, int) const from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0xc4
#15  0x7f18e64b22fa in XSControl_TransferWriter::TransferWriteShape(opencascade::handle<Interface_InterfaceModel> const&, TopoDS_Shape const&) from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0x15a
#16  0x7f18e64b9c0e in XSControl_WorkSession::TransferWriteShape(TopoDS_Shape const&, bool) from /usr/lib/x86_64-linux-gnu/libTKXSBase.so.7+0x3e
#17  0x7f18e3aef501 in STEPControl_Writer::Transfer(TopoDS_Shape const&, STEPControl_StepModelType, bool) from /usr/lib/x86_64-linux-gnu/libTKSTEP.so.7+0x1c1
#18  0x7f18c6386030 in STEPCAFControl_Writer::Transfer(STEPControl_Writer&, NCollection_Sequence<TDF_Label> const&, STEPControl_StepModelType, char const*, bool) from /usr/lib/x86_64-linux-gnu/libTKXDESTEP.so.7+0xa70
#19  0x7f18c63867b6 in STEPCAFControl_Writer::Transfer(opencascade::handle<TDocStd_Document> const&, STEPControl_StepModelType, char const*) from /usr/lib/x86_64-linux-gnu/libTKXDESTEP.so.7+0xa6
#20  0x7f18d8178c0a in ImportGui::Module::exporter(Py::Tuple const&) from /usr/lib/freecad/lib/ImportGui.so+0xdca
#21  0x7f18d817209a in Py::ExtensionModule<ImportGui::Module>::invoke_method_varargs(void*, Py::Tuple const&) from /usr/lib/freecad/lib/ImportGui.so+0x3a
#22  /usr/lib/freecad/lib/libFreeCADBase.so(method_varargs_call_handler+0x16c) [0x7f190ccfe62c]
#23  /usr/lib/x86_64-linux-gnu/libpython2.7.so.1.0(PyEval_EvalFrameEx+0x8a51) [0x7f190c7a6971]
#24  /usr/lib/x86_64-linux-gnu/libpython2.7.so.1.0(PyEval_EvalCodeEx+0x85c) [0x7f190c8dc05c]
#25  /usr/lib/x86_64-linux-gnu/libpython2.7.so.1.0(PyEval_EvalCode+0x19) [0x7f190c79dda9]
#26  /usr/lib/x86_64-linux-gnu/libpython2.7.so.1.0(PyRun_StringFlags+0x76) [0x7f190c8181f6]
#27  0x7f190cd2e916 in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /usr/lib/freecad/lib/libFreeCADBase.so+0x66
#28  0x7f190d84c3fd in Gui::Command::runCommand(Gui::Command::DoCmd_Type, char const*) from /usr/lib/freecad/lib/libFreeCADGui.so+0x4d
#29  0x7f190d7dee96 in Gui::Application::exportTo(char const*, char const*, char const*) from /usr/lib/freecad/lib/libFreeCADGui.so+0x3a6
#30  0x7f190d857ef0 in StdCmdExport::activated(int) from /usr/lib/freecad/lib/libFreeCADGui.so+0x530
#31  0x7f190d85063c in Gui::Command::invoke(int) from /usr/lib/freecad/lib/libFreeCADGui.so+0x7c
#32  0x7f190b6ac010 in QMetaObject::activate(QObject*, QMetaObject const*, int, void**) from /usr/lib/x86_64-linux-gnu/libQtCore.so.4+0x4d0
#33  0x7f190bbbed62 in QAction::triggered(bool) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x42
#34  0x7f190bbc00b3 in QAction::activate(QAction::ActionEvent) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x83
#35  /usr/lib/x86_64-linux-gnu/libQtGui.so.4(+0x6219fd) [0x7f190c0219fd]
#36  /usr/lib/x86_64-linux-gnu/libQtGui.so.4(+0x625de9) [0x7f190c025de9]
#37  0x7f190bc1b8d0 in QWidget::event(QEvent*) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x2a0
#38  0x7f190c029ffb in QMenu::event(QEvent*) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x6b
#39  0x7f190bbc4fdc in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x8c
#40  0x7f190bbcc0d6 in QApplication::notify(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x476
#41  0x7f190d82b464 in Gui::GUIApplication::notify(QObject*, QEvent*) from /usr/lib/freecad/lib/libFreeCADGui.so+0x54
#42  0x7f190b69790d in QCoreApplication::notifyInternal(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQtCore.so.4+0x8d
#43  0x7f190bbcb6dd in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x14d
#44  /usr/lib/x86_64-linux-gnu/libQtGui.so.4(+0x249d7c) [0x7f190bc49d7c]
#45  0x7f190bc48c83 in QApplication::x11ProcessEvent(_XEvent*) from /usr/lib/x86_64-linux-gnu/libQtGui.so.4+0x16b3
#46  /usr/lib/x86_64-linux-gnu/libQtGui.so.4(+0x272542) [0x7f190bc72542]
#47  /lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_dispatch+0x2a7) [0x7f1904300197]
#48  /lib/x86_64-linux-gnu/libglib-2.0.so.0(+0x4a3f0) [0x7f19043003f0]
#49  /lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_iteration+0x2c) [0x7f190430049c]
#50  0x7f190b6c82ae in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/x86_64-linux-gnu/libQtCore.so.4+0x7e
#51  /usr/lib/x86_64-linux-gnu/libQtGui.so.4(+0x272616) [0x7f190bc72616]
#52  0x7f190b69618f in QEventLoop::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/x86_64-linux-gnu/libQtCore.so.4+0x3f
#53  0x7f190b6964f5 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/x86_64-linux-gnu/libQtCore.so.4+0x1b5
#54  0x7f190b69c4b9 in QCoreApplication::exec() from /usr/lib/x86_64-linux-gnu/libQtCore.so.4+0x99
#55  0x7f190d7e4240 in Gui::Application::runApplication() from /usr/lib/freecad/lib/libFreeCADGui.so+0x15b0
#56  freecad(main+0x8b4) [0x403804]
#57  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0) [0x7f190abcb830]
#58  freecad(_start+0x29) [0x404a49]
```

# Steps to reproduce

1.  Open the attached project
2.  Select the only part
3.  Click File->Export
4.  Choose 'STEP with colors' as File format
5.  Click save
6.  Freecad crashes with a segfault


# Other bug information

* **Priority:** normal
* **Severity:** crash
* **Category:** Bug
* **OS: Ubuntu 16.04**
* **Platform:** Linux
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by @luzpaz 2018-04-20 21:47
Please open a forum thread in the help section of the forum and link this ticket to it + vice versa



---

### Comment by fhackenberger 2018-04-25 07:44
Confirmed by [bejant](https://forum.freecadweb.org/viewtopic.php?f=3&t=28341&p=229941#p229910) on the forum. Could you please change the status of this bug?


---

### Comment by @wwmayer 2018-09-27 21:13
This is a bug in TopoDSToStep_MakeStepFace::Init:

```
      else { // Copy the Curve2d which might be changed
	//C2d = CA.CurveOnSurface().GetCurve().Curve();
	//C2d = Handle(Geom2d_Curve)::DownCast(C2d->Copy());
	C2d = Handle(Geom2d_Curve)::DownCast(C2d->Copy());
      }
```


The handle C2d is null and dereferencing it causes a segfault.




---

### Comment by @luzpaz 2019-02-27 21:39
Forum thread: https://forum.freecadweb.org/viewtopic.php?f=3&t=28341


---

### Comment by @chennes 2020-12-06 01:08
In that forum thread, easyw-fc posted a workaround: the crash only occurs if "Write out curves in parametric space of surface" is selected in Preferences->Import-Export->Step. If this is disabled the crash does not occur. I have tested and verified that the crash a) still occurs, so has not been fixed upstream as of OCC 7.5.0, and b) Unchecking that preference does eliminate the crash. If we want to "fix" this on our end, it seems that we could change the default for the curves in parametric space option to false. easyw-fc's post says that "p-curves are sort of 'abandoned' by OCC".

```
OS: Windows 10 Version 2004
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.19.23237 (Git)
Build type: Debug
Branch: master
Hash: 71726a11d0844f263dad636fb98bb996a479e007
Python version: 3.8.6+
Qt version: 5.15.1
Coin version: 4.0.1
OCC version: 7.5.0
Locale: English/United States (en_US)
```

---

### Comment by @luzpaz 2020-12-31 12:44
Tracking this via [OCC bugs in the bugtracker](https://forum.freecadweb.org/viewtopic.php?f=10&t=20264&start=40) forum thread


---

### Comment by @luzpaz 2022-01-15 13:21
user1234 writes in https://forum.freecadweb.org/viewtopic.php?p=534386#p534386
> When i open the file crash-step-export.fcstd and make a geometry check, the geometry is invalid. This is a common error of many exporters, i get that regularly from many manufacturers.
> 
> With the Defeaturing of the Part Workbench, i deleted the round surface, that was invalid and then the area is fine (with the bore, means no area is missing). Then the checks are good and exports and imports fine.
