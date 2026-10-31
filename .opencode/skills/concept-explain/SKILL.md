---
name: concept-explain
description: Provides a brief definition of a software‑engineering concept — grounded in the CS‑3704 lecture slides when available — and follows it with a short interactive knowledge‑check (2‑3 questions). Designed for on‑demand student requests or automatic teachable‑moment triggers.
license: CC-BY-4.0
---

# Concept‑Explain Skill

## How it works (for agents that load this skill)
1. **Input** – The invoking agent must supply a `concept` name that appears in the CS‑3704 curriculum. Valid concepts are those listed in `.opencode/topics/allowed-concepts.txt`, concepts extracted automatically from the official Course schedule (`Course/README.md`), **or** concepts covered by the lecture PDFs hosted at `resources/lectures/*.pdf` in the external Course repository (matched by filename or extracted text). Additionally, any slide‑summary markdown files placed locally in `.opencode/topics/` (one heading per file) are also considered valid.
2. **Resolve the lecture source (hybrid lookup)** – Prefer lecture content when it is available:
   - **Curated map first** – Read `.opencode/topics/concept-lecture-map.json` and look up the `concept`. It maps concepts to candidate lecture PDF filenames (casing/format may differ from the concept name, e.g. `Software Process II.pdf` for "Agile").
   - **Runtime fallback** – If the map has no entry for the concept, run `.opencode/scripts/fetch-lecture.sh match <concept>` (fast filename‑token scoring) and pick the top‑ranked file(s). Use `.opencode/scripts/fetch-lecture.sh match --text <concept>` for a deeper scan that downloads each lecture and counts in‑text mentions.
   - **Misses** – If a mapped or matched file turns out to be missing (fetch returns an error), re‑run `match` to find an alternative before falling back to a local blurb.
3. **Fetch and extract the lecture details** – Run `.opencode/scripts/fetch-lecture.sh dump "<filename>"`. This downloads the PDF to a temp directory, extracts its text layer with `pdftotext`, prints the extracted text to stdout, and prints the temp text‑file path to stderr. For long decks, search/grep the temp text for concept‑relevant sections (definitions, phases, examples) instead of reading the whole deck into context.
4. **Compose the explanation (lecture content is primary)** – Synthesize a concise, content‑rich explanation from the extracted lecture details. Distill the material; do **not** paste raw slide text verbatim.
5. **Fallback when no lecture is available** – If no lecture can be fetched or extracted (e.g. the `resources/lectures/` directory is not published yet in the Course repo, the file is missing, or the network/tooling is unavailable), use the local `resources/<concept>.md` file (a 2‑3 sentence description). If that file is also missing, reply:
   > "I don’t have a ready definition for that concept yet; let me know another term you’d like explained."
   Never fabricate lecture content.
6. **Display** – Show the composed explanation to the student (plain text; no formatting needed beyond what is in the material).
7. **Interactive check** – Ask **2‑3** follow‑up questions using the `question` tool (one per call). The questions should probe understanding of the definition and the lecture material (e.g., "When would you choose Agile over Waterfall?", "What phase of the SDLC follows implementation?").
8. **Logging** – Each question is logged to a dedicated file `concept-explain-log.jsonl` (located at the repository root). The entry includes a unique `quiz_id` for the whole concept‑explain session, a `log` value of `concept-explain`, the `concept` field, a `source` field describing where the explanation came from (`lecture:<filename>` or `local-blurb`), the question text, and the student's answer. A single summary entry is also written to `teacher‑log.jsonl` with `trigger: "manual"` (so it does **not** count toward the automatic‑quiz budget).
9. **Budget** – The concept‑explain interaction writes a manual entry to `teacher‑log.jsonl` (trigger: "manual"), so it does **not** consume the automatic‑quiz budget. Agents may still check the budget if they wish, but the manual entry is ignored by the budget‑checking logic.

## Agent requirements
- Lecture fetching uses `.opencode/scripts/fetch-lecture.sh`, which requires **bash** (for `curl`/`pdftotext`) plus `python3`. All current invokers (`dcbrown`, `build`, `assignment`, `plan`) already allow `bash` and `webfetch`. If the invoking agent has no `bash` permission, skip the lecture lookup and rely on the local-blurb fallback (step 5), without fabricating lecture material.
- No files are written into the repo: the script only uses temp files under `/tmp`.

## Example workflow (pseudocode for the agent)
```
skill({name: "concept-explain"})
concept = "Agile"
map = read(".opencode/topics/concept-lecture-map.json")   // hybrid lookup
if map has concept:
    candidates = map[concept]
else:
    candidates = run(".opencode/scripts/fetch-lecture.sh match " + concept)
found = ""
for file in candidates:
    content = run('.opencode/scripts/fetch-lecture.sh dump "' + file + '"')   // extracted text (stdout)
    if content is non-empty: found = content + (file); break
if found: source = "lecture:" + file
else:     found = read("resources/" + concept + ".md"); source = "local-blurb"
// show synthesized explanation (from lecture if found, else blurb)
question({questions:[{question: <explanation>, header: "Definition of " + concept, options: []}]})
// ask follow‑up questions grounded in the explanation
question({questions:[{question: "When is Agile most appropriate?", header: "Agile suitability", options: []}]})
question({questions:[{question: "What is a key ceremony in Scrum?", header: "Scrum ceremony", options: []}]})
// log each question to concept-explain-log.jsonl with source = <source>
```

## When to invoke
- **Student‑initiated**: The student asks an agent “Explain Agile” or “What is the SDLC?” – the agent loads this skill with the appropriate concept name.
- **Automatic teachable moments**: After a student creates a new artifact that belongs to a particular SDLC phase (e.g., a requirements document), the owning agent (`@requirements`) can automatically call this skill with the matching concept (e.g., `SDLC‑Requirements`).

## Resources
- Lecture content (primary): `resources/lectures/*.pdf` in `https://github.com/CS3704-VT/Course`, via `.opencode/scripts/fetch-lecture.sh`.
- Local fallback blurbs: one file per concept under `resources/`.
- Curated concept → lecture mapping: `.opencode/topics/concept-lecture-map.json`.
If both a lecture and a local blurb are unavailable, the agent should reply:
> "I don’t have a ready definition for that concept yet; let me know another term you’d like explained."

---

*Generated for the CS‑3704 course; licensed under CC‑BY‑4.0.*
