# #21665 — [Problem] Fillet breaks on tapered surfaces depending on the angle

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21665`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21665
- State: `open`
- Created: `2025-05-30T20:52:37Z`
- Updated: `2025-10-29T10:05:36Z`
- Comments: `6`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Fillet on tapered pad breaks depending on very slight changes to the taper angle.

I've attached a file (rename to remove the .zip extension!): [lozenge-fillet-test.FCStd.zip](https://github.com/user-attachments/files/20526621/lozenge-fillet-test.FCStd.zip)
Just change the Taper Angle in `Pad` to -3 (or to -2.9) from the current -2.8 and watch the `Fillet` break. If you look at the geometry of the `Fillet`, it's far from anything that might cause problems (like being close to edges). The taper angle at which the Fillet breaks seems unaffected by other geometry changes (like small changes to the various specified lengths in the sketches or even the angles in Revolution).

This is not a (recent?) regression as I've checked and the issue is present in 1.0.0 and 0.21.2.

Many other CAD tools can handle this sort of fillet as shown by RotarySMP on https://www.youtube.com/watch?v=WLT5lDbNEcg&t=477

### Full version info

```shell
OS: Ubuntu 20.04.6 LTS (Unity:Unity7:ubuntu/unity/xcb)
Architecture: x86_64
Version: 1.0.1.39285 (Git) Conda AppImage
Build type: Release
Branch: (HEAD detached at 1.0.1)
Hash: 878f0b8c9c72c6f215833a99f2762bc3a3cf2abd
Python 3.11.12, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
Locale: English/United Kingdom (en_GB)
Stylesheet/Theme/QtStyle: unset/Dark modern/Qt default
Installed mods: 
  * Curves 0.6.45
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
