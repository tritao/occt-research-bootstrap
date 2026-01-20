# #21003 — OCC: Unable to add "Fillet" to a mirrored element created by a shaped Additive Pipe on a wire

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21003`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21003
- State: `open`
- Created: `2025-04-25T16:41:38Z`
- Updated: `2025-11-25T07:15:36Z`
- Comments: `5`
- Labels: `Type: Bug`, `Mod: Part Design`, `3rd party: OCC`, `Status: Confirmed`, `Topic: Fillets`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Saw this asked about on the FreeCAD subreddit here:
https://www.reddit.com/r/FreeCAD/comments/1k26mcd/unable_to_add_fillet_to_a_mirrored_element/
Even though fillets are known to be temperamental I thought it may be worth making an issue for.

The users were trying to make a fillet between two mirrored Additive Pipe shapes and were unable to do it in freecad even when making a simple copy but were able to export to STEP and use LSPrepost to add the fillet then re-import the step.  Maybe its an OpenCASCADE issue but it equally might not be.  I recommend reading the thread linked above.

### Full version info

```shell
Seems to be FreeCAD 1.0
```

### Subproject(s) affected?

PartDesign

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
