---
name: submit
description: "Packages the session's work for Canvas submission: writes a session summary and produces the cs3704-submission package via .opencode/scripts/submit-package.sh."
license: CC-BY-4.0
---

# Submit Skill

Prepares a Canvas-ready submission package for CS3704 coursework.

## Workflow
1. Confirm with the student what is being submitted (assignment, project milestone, or session work) and anything they want included.
2. **Collect AI‑usage disclosures** – the skill will ask five mandatory questions (AI tools used, model names, purposes, proportion of AI‑generated content, and any other required disclosures). The answers are written to `ai_disclosure.md` in the repository root, with a timestamped "AI Policy Summary" heading. This step is performed via the `question` tool and the helper script `./.opencode/scripts/collect-ai-usage.sh`.
3. Write a session summary (`session-summary.md`) covering what was done, key decisions, and artifacts produced.
4. Run `./.opencode/scripts/submit-package.sh ai_disclosure.md [extra files...]` to package the submission. Any extra files/dirs passed as arguments are copied into the package.
5. Report the output path and how to upload it to Canvas.

## Artifacts
- `session-summary.md` — human-readable summary of the session.
- `session-*.json` / `session-*.md` — session transcripts (auto-exported on submit).
- `cs3704-submission-<timestamp>.zip` — the packaged submission.

## Notes
- Submission artifacts are gitignored (see `.gitignore`).
- Anything affecting a grade, a deadline, or an integrity question goes to Dr. Brown (dcbrown@vt.edu) — never imply a grading decision.

---

*Generated for the CS-3704 course; licensed under CC-BY-4.0.*

## AI‑usage questionnaire (agent‑side)
```json
{
  "questions": [
    {
      "question": "Which AI tools did you use?",
      "header": "AI Tool(s)",
      "options": [{"label": "Enter answer", "description": ""}],
      "multiple": false
    },
    {
      "question": "What models were used?",
      "header": "Model name(s)",
      "options": [{"label": "Enter answer", "description": ""}],
      "multiple": false
    },
    {
      "question": "For what purposes (code generation, debugging, documentation, etc.)?",
      "header": "Purpose(s)",
      "options": [{"label": "Enter answer", "description": ""}],
      "multiple": false
    },
    {
      "question": "Approximate proportion of AI‑generated vs. human‑written content?",
      "header": "Proportion",
      "options": [{"label": "Enter answer", "description": ""}],
      "multiple": false
    },
    {
      "question": "Any other disclosures required by the AI policy?",
      "header": "Additional disclosures",
      "options": [{"label": "Enter answer", "description": ""}],
      "multiple": false
    }
  ]
}
```

