# #21097 — Part: Refine operation breaks threaded shapes

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21097`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21097
- State: `closed`
- Created: `2025-05-01T21:10:19Z`
- Updated: `2025-11-29T09:35:56Z`
- Closed: `2025-11-29T09:35:56Z`
- Comments: `16`
- Labels: `Type: Bug`, `Mod: Part`, `Type: Regression`, `Status: Confirmed`, `Type: Known issue`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

1. Select PlateBody
2. CTRL-Select Threaded Rod from PlateBody
3. In part WB issue boolean cut operation

FreeCAD 1.1dev crashes. I tested this on 1.0 and it works (although opening the same project in 1.0 gives errors).

I tried to use freecad-daily / appimage builds but they are currently in a state where even creating new project fails. The 1.1dev version that I use is few months old since Flatpak does not seem to be regularly updated.

[Holder2.FCStd.zip](https://github.com/user-attachments/files/20005001/Holder2.FCStd.zip)

### Full version info

```shell
04d2bcbf45ab96f3895ac3d0e8b5ae9becbaf5cd
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
