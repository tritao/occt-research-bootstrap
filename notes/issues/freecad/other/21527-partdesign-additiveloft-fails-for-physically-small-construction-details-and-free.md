# #21527 — PartDesign: AdditiveLOFT Fails for (physically) small construction details (and FreeCad  internally "Fails"). No problems observed for Big/Bigger construction details (OCC related)

- Repo: `FreeCAD/FreeCAD`
- Issue: `#21527`
- URL: https://github.com/FreeCAD/FreeCAD/issues/21527
- State: `open`
- Created: `2025-05-22T22:20:11Z`
- Updated: `2025-10-11T10:35:06Z`
- Comments: `5`
- Labels: `Mod: Part Design`, `Status: Needs confirmation`, `3rd party: OCC`, `Type: Crash`
- Source: https://github.com/orgs/FreeCAD/projects/32/views/1
- Extracted: `2026-01-19T22:09:31+00:00`

## Body

### Is there an existing issue for this?

- [x] I have searched the existing issues

### Problem description

Iam working on "Air-Pipe-Duct"-component (to be 3D printed), and therefore Iam facing Critical problem of AdditiveLOFT feature Crashing and Failing => Blocking to finish my work. 
I would be very thanksfull to receive advice and feedback a) what Iam doing wrongly b) If there is workaround.

I have prepared DEMO FreeCad project to trigger Failure of AdditiveLOFT function Crash (because of smallconstruction Details). 
Small Construction details are unfortunatelly mandatory for my Design (it is detail how GLUE will be filled in gap between two components). 

Example FreeCAD project is TRIGGERING problem using Spreadsheet/Table.Variable (name = kill multiplier).
for Values/numbers Same as 0.98 there are NO problems, for Values/numbers smaller then 0.98 there is Crash.

For my Desing I want and I need usage of SMALL number (Target is 0.33 upto 0.6), and Examples for "Working" Multiplier 2 and Multiplier 5 are attached.  Those pictures shows only DETAIL of my Design, which triggers Issue. 

Observed symptoms:
* BRep_API : Command Not Done.  [See attachment]

To help with improvements (and analyzis with AdditiveLOFT function), I would like to additionally comment related Symptoms observed:
* NColecion_DataMap:find
* BRepFill requlation profile inconsistent
* Body Tipshape is Empty
*  Lost link during loading ( BUT Iam using healthy SSD disk!)
*  python Exception traceback 

For those additional Issues I do NOT have easy reproducible File, but I have just attached project where I have seen those troubles.  Please note, that I tryied recreating new sketches to avoid what I believed MAY trigger issue, but I did not created those problems intentionally.... (I still do not know WHAT exactly I did wrong.)

Thank you very much in advance for understanding. 

### Full version info

```shell
Problem confirmed on 2025/5/20 Released Weekly Build
Problem confirmed on 2025/5/13 Released Weekly Build

Official 1.0.1 Release Complains:
** Cannot create object 'Origin001': ('App::Point' is not a document object type)
**  <PropertyLinks> PropertyLinks.cpp(1013): Lost link to .........  while loading, maybe an object was not loaded correctly
** Extension is not a python addable version: 'Gui::ViewProviderGeoFeatureGroupExtension'
```

### Subproject(s) affected?

None

### Anything else?

[BUG-Report-DEMO-Please-use-killmult_Parametr_to_KILL_or_WORK_OK.zip](https://github.com/user-attachments/files/20400969/BUG-Report-DEMO-Please-use-killmult_Parametr_to_KILL_or_WORK_OK.zip)

![Image](https://github.com/user-attachments/assets/85822ba7-f5bf-4b85-aff5-2592cb4dc519)
![Image](https://github.com/user-attachments/assets/c1aba76a-4624-4578-9397-30b06028b8b5)

[BUG-extra-addtional-problematic-project-example.zip](https://github.com/user-attachments/files/20401276/BUG-extra-addtional-problematic-project-example.zip)

![Image](https://github.com/user-attachments/assets/e66e08bb-59df-49e1-be7b-1e779ef24512)

![Image](https://github.com/user-attachments/assets/b572cf90-53fd-4156-be7c-cb53b53f2cec)

![Image](https://github.com/user-attachments/assets/9760ea61-8279-4cfb-964f-9c3fcc2dd0e6)

![Image](https://github.com/user-attachments/assets/b352604c-b694-44e3-8d55-01ac9af2fe53)

### Code of Conduct

- [x] I agree to follow this project's Code of Conduct
