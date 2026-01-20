# #5642 — Crash when creating loft between two sketches

- Repo: `FreeCAD/FreeCAD`
- Issue: `#5642`
- URL: https://github.com/FreeCAD/FreeCAD/issues/5642
- State: `open`
- Created: `2022-02-07T16:24:47Z`
- Updated: `2025-05-15T18:58:33Z`
- Comments: `11`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

Issue imported from https://tracker.freecad.org/view.php?id=2461

* **Reporter:** taiyo_uk
* **Date submitted:** 3/2/2016
* **FreeCAD version:** 0.15
* **Category:** Bug
* **Status:** confirmed
* **Tags:** #ready-for-migration, OCC 7.3, OCC Bug, upstream


# Original report text

Crating a loft between two sketches causes FreeCAD to segfault in Fedora 23 x86_64, and to produce this error in Windows 7 64-bit: "ACCESS VIOLATION at address 0x00000010 during 'READ' operation"

This only happens for certain sketches such as those included in the attached file.

[loft-sigsegv.zip](https://github.com/FreeCAD/FreeCAD/files/8674158/loft-sigsegv.zip)

# Additional information

Changing the order of the two sketches has no effect. Selecting the closed option produces a different error in Windows: "TCollection_DataMap::ChangeFind"

# Steps to reproduce

1. Open the attached file in FreeCAD
2. Create a loft using the two sketches
3. The crash happens when clicking the OK button in the loft dialog.

# Other bug information

* **Priority:** normal
* **Severity:** minor
* **Category:** Bug
* **OS: Windows Windows 7 64 bit**
* **Platform:** x86_64
* **Updated:** 1/24/2022


# Discussion from Mantis ticket

### Comment by taiyo_uk 2016-03-02 11:20
Version information:

OS: Windows 7
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.15.4671 (Git)
Branch: releases/FreeCAD-0-15
Hash: 244b3aef360841646cbfe80a1b225c8b39c8380c
Python version: 2.7.8
Qt version: 4.8.6
Coin version: 4.0.0a
OCC version: 6.8.0.oce-0.17



---

### Comment by taiyo_uk 2016-03-03 07:22
The same problem happens on the latest (at the time of writing) git build, this is what happens on Fedora:

*** Abort *** an exception was raised, but no catch was found.
	... The exception is:SIGSEGV 'segmentation violation' detected. Address 0

Version information:

OS: Linux
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.16.6538 (Git)
Build type: Release
Branch: master
Hash: 57c783e5b0f4da8611f5b1f26dc7499a5979e574
Python version: 2.7.10
Qt version: 4.8.7
Coin version: 3.1.3


---

### Comment by normandc 2016-03-06 20:04
I can confirm the problem here.

OS: Ubuntu 14.04.4 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.16.6557 (Git)
Build type: None
Branch: master
Hash: 948ccac021b15aff3c7a3b033c508e7ec9b123d6
Python version: 2.7.6
Qt version: 4.8.6
Coin version: 4.0.0a
OCC version: 6.8.0.oce-0.17

But I suspect this is due to your sketches having a different number of segments - this is bound for trouble when creating lofts. This is probably an OCC issue (the geometric kernel FreeCAD uses) that the FreeCAD devs have no control of.

A workaround is to add very short line segments to the second sketch so it has the same number of segments as the first sketch. Then the loft succeeds (see attached "loft-test_normandc1.fcstd" file). Another would be to create this model in two separate operations: first create a prism of the outer volume with a Pad, then create a loft representing the volume you want to be cut from the prism, and apply a boolean cut. This way the model will have planar faces rather than BSpline ones on which sketches cannot be mapped.

Next time, please report modeling issues to the FreeCAD forum first, so to determine if it's a FreeCAD bug, or a bug in OCC which the devs can't do anything about. http://forum.freecadweb.org/viewtopic.php?f=3&t=5236

I wonder if the crash can be avoided, and an error thrown instead.




---

### Comment by @luzpaz 2017-01-26 21:55
Forum thread: https://forum.freecadweb.org/viewtopic.php?f=10&t=20258


---

### Comment by @luzpaz 2017-12-15 20:36
taiyo_uk do you still have the attachment for this ticket? Bugtracker shows it's missing.

---

### Comment by hirnsalat 2018-06-08 23:53
Ran into the same problem, apparently it still exists in 0.17. How to reproduce: Go to Part Design workbench, load attached file, create an additive loft, add sections from top to bottom. FreeCAD should crash with a segmentation fault.

OS: "Manjaro Linux"
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.13522 (Git) AppImage
Build type: None
Branch: releases/FreeCAD-0-17
Hash: 3bb5ff4e70c0c526f2d9dd69b1004155b2f527f2
Python version: 2.7.6
Qt version: 4.8.6
Coin version: 4.0.0a
OCC version: 7.2.0
Locale: English/UnitedKingdom (en_GB)

Also tested on a friend's Mac, which crasches too:

OS: Mac OS X
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.13519 (Git)
Build type: Release
Branch: (HEAD detached at 1a8b868)
Hash: 1a8b868018f45ea486c0023fdbfeb06febc1fb89
Python version: 2.7.14
Qt version: 5.10.1
Coin version: 4.0.0a
OCC version: 7.2.0
Locale: English/Austria (en_AT)




---

### Comment by @luzpaz 2018-06-08 23:58
hirnsalat Thanks for testing. Can you also test with OCC7.3 when it becomes available ?
Also please also report your findings to the [dedicated forum thread](https://forum.freecadweb.org/viewtopic.php?f=10&t=20258)


---

### Comment by @wwmayer 2018-09-30 15:27
That's a regression in OCCT 7.2. When using OCCT 7.0 it doesn't create a loft but reports an appropriate error message and does not crash.


---

### Comment by @maidenone 2019-01-20 20:04
Is this issue resolved now? or is there another "exceptions in occt" ticket that can replace this?


---

### Comment by @wwmayer 2019-01-20 21:01
It was hirnsalat you said that it crashes with OCCT 7.2. But I've just tested it and I get it working when I also select the Ruled surface option. Without it an error message pops up but I don't get a crash. I have tested this with OCCT 7.0 and 7.2.


---

### Comment by normandc 2019-02-09 20:16
I get a crash when I add the third section with the version below using OCC 7.3.0.

```Program received signal SIGSEGV, Segmentation fault.
#0  /lib/x86_64-linux-gnu/libc.so.6(+0x3ef20) [0x7f7bc5f14f20]
#1  /usr/lib/x86_64-linux-gnu/libTKTopAlgo.so.7(+0x17bcb5) [0x7f7b7e043cb5]
#2  0x7f7b7e04477e in BRepLib::EncodeRegularity(TopoDS_Shape const&, double) from /usr/lib/x86_64-linux-gnu/libTKTopAlgo.so.7+0x14e
#3  0x7f7b7cd22da8 in BRepOffsetAPI_ThruSections::Build() from /usr/lib/x86_64-linux-gnu/libTKOffset.so.7+0xd28
#4  0x7f7b1e4a3c2b in PartDesign::Loft::execute() from /home/normand2/compilation/FreeCAD/freecad-build2/Mod/PartDesign/_PartDesign.so+0x7db
#5  0x7f7bc83c3265 in App::DocumentObject::recompute() from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADApp.so+0x155
#6  0x7f7b827aabdb in Part::Feature::recompute() from /home/normand2/compilation/FreeCAD/freecad-build2/Mod/Part/Part.so+0xb
#7  0x7f7bc8377544 in App::Document::_recomputeFeature(App::DocumentObject*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADApp.so+0xb4
#8  0x7f7bc837f013 in App::Document::recomputeFeature(App::DocumentObject*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADApp.so+0x83
#9  0x7f7b1e0691d0 in PartDesignGui::TaskLoftParameters::onSelectionChanged(Gui::SelectionChanges const&) from /home/normand2/compilation/FreeCAD/freecad-build2/Mod/PartDesign/PartDesignGui.so+0x120
#10  0x7f7bc8ed09c6 in Gui::SelectionObserver::_onSelectionChanged(Gui::SelectionChanges const&) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x56
#11  0x7f7bc8edebbf in boost::signals2::detail::signal_impl<void (Gui::SelectionChanges const&), boost::signals2::optional_last_value<void>, int, std::less<int>, boost::function<void (Gui::SelectionChanges const&)>, boost::function<void (boost::signals2::connection const&, Gui::SelectionChanges const&)>, boost::signals2::mutex>::operator()(Gui::SelectionChanges const&) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x20f
#12  0x7f7bc8ed8f81 in Gui::SelectionSingleton::addSelection(char const*, char const*, char const*, float, float, float) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x281
#13  0x7f7bc8d4237a in Gui::SoFCUnifiedSelection::handleEvent(SoHandleEventAction*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0xd3a
#14  0x7f7bc5722504 in SoAction::traverse(SoNode*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x64
#15  0x7f7bc58c2008 in SoChildList::traverse(SoAction*, int, int) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0xd8
#16  0x7f7bc59114e6 in SoGroup::doAction(SoAction*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x56
#17  0x7f7bc592b967 in SoSeparator::doAction(SoAction*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x27
#18  0x7f7bc5722504 in SoAction::traverse(SoNode*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x64
#19  0x7f7bc572be48 in SoHandleEventAction::beginTraversal(SoNode*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x68
#20  0x7f7bc5722a82 in SoAction::apply(SoNode*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x372
#21  0x7f7bc58de8a0 in SoEventManager::actuallyProcessEvent(SoEvent const*) from /usr/lib/x86_64-linux-gnu/libCoin.so.80c+0x60
#22  0x7f7bc8db590e in SIM::Coin3D::Quarter::QuarterWidget::processSoEvent(SoEvent const*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x1e
#23  0x7f7bc8dbe5c6 in SIM::Coin3D::Quarter::SoQTQuarterAdaptor::processSoEvent(SoEvent const*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x56
#24  0x7f7bc8de8179 in Gui::View3DInventorViewer::processSoEventBase(SoEvent const*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x9
#25  0x7f7bc8dd118e in Gui::GestureNavigationStyle::processSoEvent(SoEvent const*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0xabe
#26  0x7f7bc8dc8418 in Gui::NavigationStyle::processEvent(SoEvent const*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0xf8
#27  0x7f7bc8de80f3 in Gui::View3DInventorViewer::processSoEvent(SoEvent const*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x63
#28  0x7f7bc8dacd45 in SIM::Coin3D::Quarter::EventFilter::eventFilter(QObject*, QEvent*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x185
#29  0x7f7bc6af268c in QCoreApplicationPrivate::sendThroughObjectEventFilters(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x7c
#30  0x7f7bc7107805 in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x75
#31  0x7f7bc710f64f in QApplication::notify(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x7ff
#32  0x7f7bc8b88a48 in Gui::GUIApplication::notify(QObject*, QEvent*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x88
#33  0x7f7bc6af29a8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x118
#34  0x7f7bc710e622 in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool) from /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x1d2
#35  /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5(+0x1ae14b) [0x7f7bc716114b]
#36  /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5(+0x1b07ba) [0x7f7bc71637ba]
#37  0x7f7bc710782c in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x9c
#38  0x7f7bc710f0f4 in QApplication::notify(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5+0x2a4
#39  0x7f7bc8b88a48 in Gui::GUIApplication::notify(QObject*, QEvent*) from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x88
#40  0x7f7bc6af29a8 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x118
#41  0x7f7bc2a1d523 in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5+0x6f3
#42  0x7f7bc2a1eff5 in QGuiApplicationPrivate::processWindowSystemEvent(QWindowSystemInterfacePrivate::WindowSystemEvent*) from /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5+0x135
#43  0x7f7bc29f62eb in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5+0xab
#44  /usr/lib/x86_64-linux-gnu/libQt5XcbQpa.so.5(+0x9d1c0) [0x7f7bb615a1c0]
#45  /usr/lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_dispatch+0x2e7) [0x7f7bc0d74387]
#46  /usr/lib/x86_64-linux-gnu/libglib-2.0.so.0(+0x4c5c0) [0x7f7bc0d745c0]
#47  /usr/lib/x86_64-linux-gnu/libglib-2.0.so.0(g_main_context_iteration+0x2c) [0x7f7bc0d7464c]
#48  0x7f7bc6b4b8ef in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x5f
#49  0x7f7bc6af09ea in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x13a
#50  0x7f7bc6af9a84 in QCoreApplication::exec() from /usr/lib/x86_64-linux-gnu/libQt5Core.so.5+0x94
#51  0x7f7bc8b0dfab in Gui::Application::runApplication() from /home/normand2/compilation/FreeCAD/freecad-build2/lib/libFreeCADGui.so+0x133b
#52  ./FreeCAD(main+0x6ad) [0x5588702ee48d]
#53  /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xe7) [0x7f7bc5ef7b97]
#54  ./FreeCAD(_start+0x2a) [0x5588702ef1ea]
```

OS: Ubuntu 18.04.1 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.18.15816 (Git)
Build type: Release
Branch: master
Hash: 7ee0e4d43909ec688299b8498b240cccf8362c47
Python version: 3.6.7
Qt version: 5.9.5
Coin version: 4.0.0a
OCC version: 7.3.0
Locale: French/Canada (fr_CA)


---

### Comment by normandc 2019-02-09 20:21
No crash with OCC 7.1.0 with this version. An error message appears in a pop up when pressing OK:
[quote]BRepFill :: profiles are inconsistent[/quote]

OS: Ubuntu 18.04.1 LTS
Word size of OS: 64-bit
Word size of FreeCAD: 64-bit
Version: 0.17.13509 (Git) AppImage
Build type: None
Branch: master
Hash: 0258808ccb6ba3bd5ea9312f79cd023f1a8671b7
Python version: 2.7.6
Qt version: 4.8.6
Coin version: 4.0.0a
OCC version: 7.1.0
Locale: French/Canada (fr_CA)


---

### Comment by @wwmayer 2019-02-23 20:29
I don't have OCCT 7.3 to this but according to the call stack this anyway must be a bug in OCCT, then.
