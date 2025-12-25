# Dossier task prompt (OCCT)

Use this prompt when working on a **type:dossier** task.

Rules:
- Do not modify anything under `occt/`.
- Put outputs in `notes/dossiers/` and `oracles/`.
- When writing notes, cite file paths and class/function names used.
- Prefer using occt-lsp MCP tools to jump to definitions/references.

Workflow:
1) Read the task, then add an “Implementation plan” section to the task via Backlog MCP.
2) Create/extend one dossier under `notes/dossiers/` for the task scope.
3) The dossier MUST include (per repo rules):
   - Purpose + high-level pipeline
   - Key classes/files (paths)
   - Core data structures + invariants (as inferred)
   - Tolerance/robustness behaviors observed in code
   - One runnable repro under `oracles/` (checked into the repo)
   - “Compare to papers / alternatives” section
4) Run the repro (or document how to run it) and record the result in the task notes.

Acceptance criteria checklist (suggested):
- [ ] Dossier created/updated in `notes/dossiers/`
- [ ] Dossier includes all required sections
- [ ] Oracle exists in `oracles/` and is runnable
- [ ] Task plan added before changes
