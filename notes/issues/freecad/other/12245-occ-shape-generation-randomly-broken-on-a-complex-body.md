# #12245 — OCC: Shape generation randomly broken on a complex body

- Repo: `FreeCAD/FreeCAD`
- Issue: `#12245`
- URL: https://github.com/FreeCAD/FreeCAD/issues/12245
- State: `open`
- Created: `2024-02-03T09:49:51Z`
- Updated: `2025-12-01T16:25:35Z`
- Comments: `24`
- Labels: `3rd party: OCC`, `Status: Needs feedback`, `Status: Needs example file`, `Status: Needs diagnosis`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

In a complex project with multiple documents depending on each other, and on a rather complex body, I'm getting recurrent corruptions in the generated shape. I am very certain they're not caused by errors in the input data (user errors). This object is all sketches and Part Design features, all sketches well defined and fully constrained. No pipes wrapping on themselves etc.

The project is unfortunately private, but I can share it with a dev together with a precise list of steps to reproduce, and I can be of any assistance that's required. I've already shared my project with @bgbsww, who has spent a lot of time looking into it, so far with no luck, but together we've ruled out all the simple potential causes.

The corruption changes when e.g. the order of objects in the body changes, and sometimes it would appear to be fixed. Strangely, even on a recompute the error would appear to be fixed, but when (for example) a spreadsheet with shared dimensions is marked for recompute and the body recomputed, the corruption would come back. All my attempts to work around this so far have been futile and I'm completely stuck working on the project until this is fixed - this is barring some radical attempts to change the body hierarchy that could possibly help and I haven't tried yet.

I tried to simplify the reproducer to be able to make it public, but the issue was the corruption seemed to be there until a very simple case, but then some random "marking for recompute" and "recompute" made it go away, making it hard to do this (there are a ton of references etc.). AFAIK @bgbsww was also so far unable to create a public reproducer.

I know this is not much to go by, but it seems to be a really nasty corruption and it'd be really great to have it fixed.

FWIW the corruption doesn't happen with @realthunder's https://github.com/realthunder/FreeCAD/releases/tag/20240123stable, at least not apparently, though I haven't spent much time with it, as there seems to be no guarantee of format compatibility (that I know of).

There's more info in the linked forum thread, but to pick a few screenshots:

Correct shape:
![1-correct-shape](https://github.com/FreeCAD/FreeCAD/assets/135954/8442ed5d-c74b-4a87-a41a-c53a191dd6d6)

An interesting case, where even a sketch would get messed up by just reordering the object (the sketch is not like this for real and I haven't even edited it). 
![3-broken-sketch](https://github.com/FreeCAD/FreeCAD/assets/135954/1d982287-84a1-444f-914f-8255695676a2)

When clicking "recompute" on the sketch, it'd fix itself (I have automatic recomputes turned off), but the object would remain broken:
![4-broken-sketch-recomputed](https://github.com/FreeCAD/FreeCAD/assets/135954/40a74076-edb9-49f6-afc3-4d9087bc16f6)


### Full version info

```shell
[code]
OS: NixOS 23.11 (Tapir) (none+awesome/none+awesome)
Word size of FreeCAD: 64-bit
Version: 0.21.2.Unknown
Build type: Release
Python 3.11.6, Qt 5.15.11, Coin 4.0.1, Vtk 9.2.6, OCC 7.6.2
Locale: English/United States (en_US)
Installed mods: 
  * Curves 0.6.5
  * Render 2023.1.0
  * Assembly4 0.50.6
[/code]
```


### Subproject(s) affected?

None

### Anything else?

https://forum.freecad.org/viewtopic.php?t=84002

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
