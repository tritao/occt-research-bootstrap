# #18445 — PartDesign: Crash when groove around the wrong axis 

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18445`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18445
- State: `closed`
- Created: `2024-12-12T12:57:41Z`
- Updated: `2025-09-21T12:21:29Z`
- Closed: `2025-09-21T12:21:29Z`
- Comments: `16`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Type: Crash`, `OS: Linux`, `Status: Confirmed`, `Type: Known issue`, `Topic: Wayland`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

when trying to groove it defaults to groove around the vertical axis which in this case is the z-axis. this results in freecad crashing
![groove_bug](https://github.com/user-attachments/assets/d2b4eda4-8399-4df0-b023-51c2112d4641)

here is the output in the terminal:
```
FreeCAD 1.1.0, Libs: 1.1.0devR39560 (Git)                                                                                                                                                       
(C) 2001-2024 FreeCAD contributors                                                                                                                                                              
FreeCAD is free and open-source software licensed under the terms of LGPL2+ license.                                                                                                            
                                                                                                                                                                                                
(qt.qpa.plugin) Could not find the Qt platform plugin "wayland" in ""                                                                                                                           
Program received signal SIGSEGV, Segmentation fault.                                                                                                                                            
#0  /usr/lib/libc.so.6(+0x3f8c0) [0x7fdedd2558c0]                                                                                                                                               
#1  0x7fdedf4b7d74 in Data::ElementNameComparator::operator()(Data::MappedName const&, Data::MappedName const&) const from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADApp.so+0x24        
#2  0x7fde9250b40c in std::_Rb_tree<Data::MappedName, std::pair<Data::MappedName const, Part::NameInfo>, std::_Select1st<std::pair<Data::MappedName const, Part::NameInfo> >, Data::ElementNameC
omparator, std::allocator<std::pair<Data::MappedName const, Part::NameInfo> > >::_M_get_insert_hint_unique_pos(std::_Rb_tree_const_iterator<std::pair<Data::MappedName const, Part::NameInfo> >,
 Data::MappedName const&) from /tmp/.mount_FreeCADdKFel/usr/lib/./Part.so+0x5c                                                                                                                  
#3  0x7fde92518c84 in Part::TopoShape::makeShapeWithElementMap(TopoDS_Shape const&, Part::TopoShape::Mapper const&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char 
const*) from /tmp/.mount_FreeCADdKFel/usr/lib/./Part.so+0x4ff4                                                                                                                                  
#4  0x7fde9251a48e in Part::TopoShape::makeElementShape(BRepBuilderAPI_MakeShape&, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*) from /tmp/.mount_FreeCADd
KFel/usr/lib/./Part.so+0x11e                                                                                                                                                                    
#5  0x7fde925314b3 in Part::TopoShape::makeElementBoolean(char const*, std::vector<Part::TopoShape, std::allocator<Part::TopoShape> > const&, char const*, double) from /tmp/.mount_FreeCADdKFel
/usr/lib/./Part.so+0xa33                                                                                                                                                                        
#6  0x7fde3cf48ffc in PartDesign::Groove::execute() from /tmp/.mount_FreeCADdKFel/usr/lib/_PartDesign.so+0xa0c                                                                                  
#7  0x7fdedf276972 in App::DocumentObject::recompute() from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADApp.so+0xc2                                                                       
#8  0x7fde922cc22c in Part::Feature::recompute() from /tmp/.mount_FreeCADdKFel/usr/lib/./Part.so+0xc                                                                                            
#9  0x7fdedf24e7bc in App::Document::_recomputeFeature(App::DocumentObject*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADApp.so+0x32c
#10  0x7fdedf25af3d in App::Document::recompute(std::vector<App::DocumentObject*, std::allocator<App::DocumentObject*> > const&, bool, bool*, int) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/
libFreeCADApp.so+0x5fd                                                                                                                                                                          
#11  0x7fdedf2dc471 in App::DocumentPy::recompute(_object*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADApp.so+0x301
#12  0x7fdedf2dc594 in App::DocumentPy::staticCallback_recompute(_object*, _object*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADApp.so+0x24
#13  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(+0x206068) [0x7fdedfa06068]   
#14  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(_PyObject_MakeTpCall+0x26c) [0x7fdedf9e5b5c]
#15  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(_PyEval_EvalFrameDefault+0x6f2) [0x7fdedf9f1532]
#16  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(+0x2abd1d) [0x7fdedfaabd1d]   
#17  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(PyEval_EvalCode+0xa4) [0x7fdedfaab794]
#18  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(+0x2cabf3) [0x7fdedfacabf3]   
#19  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(+0x2c669a) [0x7fdedfac669a]   
#20  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libpython3.11.so.1.0(PyRun_StringFlags+0x69) [0x7fdedfaba9c9]
#21  0x7fdeded4668c in Base::InterpreterSingleton::runString[abi:cxx11](char const*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADBase.so+0x6c
#22  0x7fdee03bb994 in Gui::Command::_runCommand(char const*, int, Gui::Command::DoCmd_Type, char const*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0x94
#23  0x7fdee03bbb23 in Gui::Command::_doCommand(char const*, int, Gui::Command::DoCmd_Type, char const*, ...) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0xe3
#24  0x7fdee03bbd04 in Gui::Command::updateActive() from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0x44
#25  0x7fde3c500206 in finishFeature(Gui::Command const*, App::DocumentObject*, App::DocumentObject*, bool, bool) from /tmp/.mount_FreeCADdKFel/usr/lib/PartDesignGui.so+0x1d6
#26  /tmp/.mount_FreeCADdKFel/usr/lib/PartDesignGui.so(+0x10187c) [0x7fde3c50187c]              
#27  /tmp/.mount_FreeCADdKFel/usr/lib/PartDesignGui.so(+0x10ce83) [0x7fde3c50ce83]              
#28  0x7fde3c510e96 in prepareProfileBased(PartDesign::Body*, Gui::Command*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::function<void (Part::F
eature*, App::DocumentObject*)>) from /tmp/.mount_FreeCADdKFel/usr/lib/PartDesignGui.so+0x356   
#29  0x7fde3c51205b in CmdPartDesignGroove::activated(int) from /tmp/.mount_FreeCADdKFel/usr/lib/PartDesignGui.so+0xbb
#30  0x7fdee03c538f in Gui::Command::_invoke(int, bool) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0x23f
#31  0x7fdee03c577f in Gui::Command::invoke(int, Gui::Command::TriggerSource) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0x12f
#32  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Core.so.5(+0x2eb6f2) [0x7fdedd6eb6f2]        
#33  0x7fdede56a462 in QAction::triggered(bool) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0x32
#34  0x7fdede56ce2b in QAction::activate(QAction::ActionEvent) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0xab
#35  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5(+0x25d29a) [0x7fdede65d29a]
#36  0x7fdede65d3d7 in QAbstractButton::mouseReleaseEvent(QMouseEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0xe7
#37  0x7fdede74610a in QToolButton::mouseReleaseEvent(QMouseEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0xa
#38  0x7fdede5aec08 in QWidget::event(QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0x178
#39  0x7fdede5703ae in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0x7e
#40  0x7fdede578262 in QApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0x13a2
#41  0x7fdee036bdd9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0xc9
#42  0x7fdedd6b6b28 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Core.so.5+0x108
#43  0x7fdede5763eb in QApplicationPrivate::sendMouseEvent(QWidget*, QMouseEvent*, QWidget*, QWidget*, QWidget**, QPointer<QWidget>&, bool, bool) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/l
ibQt5Widgets.so.5+0x1ab                         
#44  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5(+0x1c6e6f) [0x7fdede5c6e6f]     
#45  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5(+0x1ca0c9) [0x7fdede5ca0c9]     
#46  0x7fdede5703ae in QApplicationPrivate::notify_helper(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Widgets.so.5+0x7e
#47  0x7fdee036bdd9 in Gui::GUIApplication::notify(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0xc9
#48  0x7fdedd6b6b28 in QCoreApplication::notifyInternal2(QObject*, QEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Core.so.5+0x108
#49  0x7fdeddd353ec in QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent*) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Gui.so.5+0x84c
#50  0x7fdeddd0b0bc in QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Gui.so.5+0xac
#51  /tmp/.mount_FreeCADdKFel/usr/plugins/platforms/../../lib/libQt5XcbQpa.so.5(+0x64bea) [0x7fded80d2bea]
#52  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/./libglib-2.0.so.0(+0x5bad7) [0x7fdedbf10ad7]      
#53  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/./libglib-2.0.so.0(+0x5eac7) [0x7fdedbf13ac7]      
#54  /tmp/.mount_FreeCADdKFel/usr/bin/../lib/./libglib-2.0.so.0(g_main_context_iteration+0x2e) [0x7fdedbf140ce]
#55  0x7fdedd70aa36 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Core.so.5+0x66
#56  0x7fdedd6b570b in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Core.so.5+0x11b
#57  0x7fdedd6bd212 in QCoreApplication::exec() from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libQt5Core.so.5+0x82
#58  0x7fdee02cc3ed in Gui::Application::runApplication() from /tmp/.mount_FreeCADdKFel/usr/bin/../lib/libFreeCADGui.so+0x89d
#59  /tmp/.mount_FreeCADdKFel/usr/bin/freecad(+0x78b7) [0x55777f3568b7]
#60  /usr/lib/libc.so.6(+0x29c4c) [0x7fdedd23fc4c]                                              
#61  /usr/lib/libc.so.6(__libc_start_main+0x85) [0x7fdedd23fd05]                                
#62  /tmp/.mount_FreeCADdKFel/usr/bin/freecad(+0x7c2a) [0x55777f356c2a]
```
**steps to reproduce**
1.extract the archive and open the file "groove_bug.FCStd" with freecad
[groove_bug.tar.gz](https://github.com/user-attachments/files/18111740/groove_bug.tar.gz)
2.select the last sketch which is called "groove this" and then click groove


### Full version info

```shell
OS: Void Linux (labwc:wlroots/xcb)
Architecture: x86_64
Version: 1.1.0dev.39560 (Git) Conda AppImage
Build type: Release
Branch: main
Hash: 1c35d08d87bb6dec7cb5adf51b2ed460ce43096d
Python 3.11.9, Qt 5.15.13, Coin 4.0.3, Vtk 9.2.6, OCC 7.7.2
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/Fusion
Installed mods: 
  * freecad.gears 1.2.0
  * CfdOF 1.25.17
```


### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
