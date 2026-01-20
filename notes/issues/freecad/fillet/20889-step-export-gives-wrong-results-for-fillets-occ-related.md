# #20889 — STEP: export gives wrong results for fillets (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#20889`
- URL: https://github.com/FreeCAD/FreeCAD/issues/20889
- State: `open`
- Created: `2025-04-20T17:11:31Z`
- Updated: `2025-11-19T22:35:38Z`
- Comments: `13`
- Milestone: `1.1`
- Labels: `Type: Bug`, `3rd party: OCC`, `File format: STEP`, `Type: Regression`, `Status: Confirmed`, `Priority: High`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

I noticed an issue with STEP files containing fillets which are created in FreeCAD. Everything looks fine in FreeCAD, but these STEP files are read incorrectly (the create a rounded edge instead of a fillet) by some CAD programs (Onshape, Rhino), while some other programs apparently have no trouble with these STEP files (Fusion, FreeCAD itself). The geometry is a boolean union of a Box and a cylinder and a fillet in between. The cylinder is either created by the extrude or revolve command. Depending on the "sign" of the extrusion direction or the revolution aixs, the STEP files are read correctly or not.

The entire problem only occurs in v1.0.0, I could not reproduce it in v0.21.1 or v0.20.2.

<img width="1071" alt="Image" src="https://github.com/user-attachments/assets/b434c61b-04ef-49e0-9407-d3816734ada1" />



### Full version info

```shell
OS: macOS 14.7.4
Architecture: arm64
Version: 1.0.0.39109 (Git) Conda
Build type: Release
Branch: (HEAD detached at 1.0.0)
Hash: 2fcc5317fe3aee96ca73475986a577719fc78e20
Python 3.11.10, Qt 5.15.15, Coin 4.0.3, Vtk 9.3.0, OCC 7.8.1
```

### Subproject(s) affected?

None

### Anything else?

_No response_

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
