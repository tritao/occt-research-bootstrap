# #19745 — Assembly: Segfault in assembly when setting "Advanced offset" for slide joint

- Repo: `FreeCAD/FreeCAD`
- Issue: `#19745`
- URL: https://github.com/FreeCAD/FreeCAD/issues/19745
- State: `closed`
- Created: `2025-02-20T23:53:47Z`
- Updated: `2025-11-05T14:28:40Z`
- Closed: `2025-11-05T14:28:40Z`
- Comments: `14`
- Labels: `Type: Bug`, `3rd party: OCC`, `Type: Crash`, `Status: Confirmed`, `Mod: Assembly`, `Status: Stale`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Joining two bodies using the slide joint in the assembly workbench allows the user to configure offsets, this is done in a separate dialog, where values for translation and center can be entered. When I press "ok" after having entered the values, FreeCAD crashes.

<details>
<summary>Backtrace</summary>

```
#0  0x00007fffc7e197ec in Extrema_GenExtCS::GlobMinCQuadric (this=this@entry=0x7fffc5a8ad30, theC=..., theNbParticles=theNbParticles@entry=48, theTUVinf=..., theTUVsup=..., theTUV=...) at ../src/Extrema/Extrema_GenExtCS.cxx:684
#1  0x00007fffc7e1b1a3 in Extrema_GenExtCS::Perform (this=this@entry=0x7fffc5a8ad30, C=..., NbT=NbT@entry=12, tmin=tmin@entry=4.9999998999999686, tsup=tsup@entry=5.0000001000000109, Tol1=Tol1@entry=9.9999999999999986e-10) at ../src/Extrema/Extrema_GenExtCS.cxx:348
#2  0x00007fffc7e1bc69 in Extrema_GenExtCS::Extrema_GenExtCS (this=this@entry=0x7fffc5a8ad30, C=..., S=..., NbT=NbT@entry=12, NbU=10, NbV=10, tmin=tmin@entry=4.9999998999999686, tsup=tsup@entry=5.0000001000000109, Umin=Umin@entry=-27.006493506493513, Usup=Usup@entry=19.993506493506487, Vmin=Vmin@entry=-18.506493506493506, Vsup=11.493506493506494, Tol1=9.9999999999999986e-10, Tol2=9.9999999999999986e-10) at ../src/Extrema/Extrema_GenExtCS.cxx:168
#3  0x00007fffc7df48a8 in Extrema_ExtCS::Perform (this=this@entry=0x7fffc5a8b570, C=..., Uinf=<optimized out>, Usup=Usup@entry=5.0000481234319221) at ../src/Extrema/Extrema_ExtCS.cxx:211
#4  0x00007fffc7df4d69 in Extrema_ExtCS::Extrema_ExtCS (this=this@entry=0x7fffc5a8b570, C=..., S=..., TolC=TolC@entry=9.9999999999999986e-10, TolS=TolS@entry=9.9999999999999986e-10) at ../src/Extrema/Extrema_ExtCS.cxx:60
#5  0x00007fffca0f9e06 in IntTools_EdgeFace::CheckTouch (this=this@entry=0x55555e6472a8, aCP=..., aTx=@0x7fffc5a8b6f8: 78.900000000000006) at ../src/IntTools/IntTools_EdgeFace.cxx:380
#6  0x00007fffca0fa6ec in IntTools_EdgeFace::MakeType (aCommonPrt=..., this=0x55555e6472a8) at ../src/IntTools/IntTools_EdgeFace.cxx:332
#7  IntTools_EdgeFace::MakeType (this=0x55555e6472a8, aCommonPrt=...) at ../src/IntTools/IntTools_EdgeFace.cxx:292
#8  0x00007fffca0fb536 in IntTools_EdgeFace::Perform (this=this@entry=0x55555e6472a8) at ../src/IntTools/IntTools_EdgeFace.cxx:565
#9  0x00007fffca1d6ead in BOPAlgo_EdgeFace::Perform (this=0x55555e647258) at ../src/BOPAlgo/BOPAlgo_PaveFiller_5.cxx:136
#10 0x00007fffca1d5c09 in BOPTools_Parallel::ContextFunctor2<NCollection_Vector<BOPAlgo_EdgeFace>, IntTools_Context>::operator() (theIndex=<optimized out>, theThreadIndex=0, this=<optimized out>) at /builddir/occt-7.7.1/src/BOPTools/BOPTools_Parallel.hxx:151
#11 OSD_ThreadPool::Job<BOPTools_Parallel::ContextFunctor2<NCollection_Vector<BOPAlgo_EdgeFace>, IntTools_Context> >::Perform (this=0x7fffffff8190, theThreadIndex=0) at /builddir/occt-7.7.1/src/OSD/OSD_ThreadPool.hxx:299
#12 0x00007fffc76b1d66 in OSD_ThreadPool::performJob (theFailure=..., theJob=0x7fffffff8190, theThreadIndex=0) at ../src/OSD/OSD_ThreadPool.cxx:286
#13 0x00007fffc76b217c in OSD_ThreadPool::EnumeratedThread::performThread (this=0x55555b61b628) at ../src/OSD/OSD_ThreadPool.cxx:326
#14 0x00007fffc76b21c9 in OSD_ThreadPool::EnumeratedThread::runThread (theTask=<optimized out>) at ../src/OSD/OSD_ThreadPool.cxx:340
#15 0x00007ffff7fb858e in start (p=0x7fffc5a8c630) at src/thread/pthread_create.c:195
#16 0x00007ffff7fc552b in __clone () at src/thread/x86_64/clone.s:22
Backtrace stopped: frame did not save the PC
```

</details>


### Full version info

```shell
OS: Void Linux (wayland)
Architecture: x86_64
Version: 1.1.0dev.40263 (Git)
Build type: Release
Branch: main
Hash: eb886449c2d63b1b5e61bf6a5b7acac61d2382e5
Python 3.13.2, Qt 6.8.1, Coin 4.0.3, Vtk 9.3.1, OCC 7.7.1
Locale: English/United States (en_US)
Stylesheet/Theme/QtStyle: FreeCAD Dark.qss/FreeCAD Dark/
Logical/physical DPI: 96/91.7275
Installed mods: 
  * freecad.gears 1.2.0
  * fasteners 0.5.21
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
