# #18357 — Ubuntu 24.04: OCCT lib dependency issue when having KiCAD installed in parallel

- Repo: `FreeCAD/FreeCAD`
- Issue: `#18357`
- URL: https://github.com/FreeCAD/FreeCAD/issues/18357
- State: `closed`
- Created: `2024-12-08T15:05:29Z`
- Updated: `2025-12-05T16:07:20Z`
- Closed: `2025-12-05T16:07:20Z`
- Comments: `11`
- Labels: `Mod: Core`, `Status: Needs confirmation`, `3rd party component`, `3rd party: OCC`, `OS: Linux`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [X] I have searched the existing issues

### Problem description

KiCAD (still) ship their own Opencascade libs not following the Y2038 naming scheme with the "t64" at the end as the Debian packages do. This reults in an unresolvable dependency issue (at occt-misc) when one wants to install both KiCAD and FreeCAD. I will try to file a bug over at KiCAD as well.

I know, one may argue "it's KiCADs bad, they should fix it etc pp" but I think the easiest fix would be to allow also the KiCAD OCCT libraries. 
Using whatever, flatpak, appimage, .. is also not an option.

I solved it by manually manipulating ```libfreecad-python3-0.20_0.21.2+dfsg1~202407140123~ubuntu24.04.1_amd64.deb```'s control file by adding ```|libocct-xxx-7.6``` to all the OCCT lib dependencies.
So far, I could not see any issues.

### Full version info

```shell
Version 2:0.21.2+dfsg1~202407140123~ubuntu24.04.1 from https://launchpad.net/~freecad-maintainers/+archive/ubuntu/freecad-stable/
```


### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [X] I agree to follow this project's Code of Conduct
