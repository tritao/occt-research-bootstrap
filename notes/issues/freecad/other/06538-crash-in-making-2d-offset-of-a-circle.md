# #6538 — [crash] in making 2D offset of a circle

- Repo: `FreeCAD/FreeCAD`
- Issue: `#6538`
- URL: https://github.com/FreeCAD/FreeCAD/issues/6538
- State: `open`
- Created: `2022-03-09T17:34:11Z`
- Updated: `2025-08-13T15:18:52Z`
- Comments: `29`
- Labels: `Type: Bug`, `Mod: Part`, `3rd party: OCC`, `Type: Crash`, `Type: Has workaround`, `Help wanted`, `no-auto-close`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Forums discussion

https://forum.freecadweb.org/viewtopic.php?p=577963#p577963

### Version

0.20 (Development)

### Full version info

```shell
OS: Windows 10 Version 2009
Word size of FreeCAD: 64-bit
Version: 0.20.27990 (Git)
Build type: Release
Branch: master
Hash: c596c2fe3de933a00ba4245931e8e7bc3093832d
Python 3.8.6+, Qt 5.15.2, Coin 4.0.1, OCC 7.5.3
Locale: German/Germany (de_DE)
Installed mods:
```


### Subproject(s) affected?

Part

### Issue description

- take this simple file that contains a circle in a sketch: https://forum.freecadweb.org/download/file.php?id=182301
- create a 2D offset using the part WB and use "-0.1 mm" as offset
result: as soon as you entered "-0.1" and then click out of the line edit of the task dialog FC crashes with illegal storage access in "BRepOffsetAPI_MakeOffset"
