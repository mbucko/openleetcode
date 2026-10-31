---
name: quiz
description: "CS3704 course content reference — schedule, topics, learning outcomes (L1-L7), policies. Runs concept-check quizzes within the per-session budget and logs them to teacher-log.jsonl."
license: CC-BY-4.0
---

# Quiz Skill

CS3704 course content reference and quiz engine.

## Course facts (authoritative sources)
- **Schedule, topics, deadlines:** `https://raw.githubusercontent.com/CS3704-VT/Course/main/README.md` Answer scheduling questions ONLY from this file. Do not answer from memory. If the file is unavailable, say so and point the student to `https://github.com/CS3704-VT/Course`.
- **Policies, grading, learning outcomes:** `SYLLABUS.md` in the same repository.

## Learning outcomes (authoritative numbered list, L1–L7)
Mapped positionally to the syllabus bullets. Use these IDs for logging/analytics only — **ALWAYS show an ID with the text learning objective to a student**.

| ID | Outcome |
|----|---------|
| L1 | Compare different software engineering processes and explain when to use them. |
| L2 | Gather, analyze, and specify software requirements for an application. |
| L3 | Design a software system and user interface that meets requirements. |
| L4 | Understand common software engineering tools and practices to maintain, develop, and verify software. |
| L5 | Discuss current and emerging trends in software engineering. |
| L6 | Use AI tools to generate code, unit tests, and test suites; evaluate the quality and accuracy of AI-generated artifacts; and refine outputs to meet functional, performance, and quality requirements. |
| L7 | Create and communicate (via demo and writing) about the requirements and design of a software application. |

## Quiz mechanics
1. Ask every quiz question with the interactive `question` tool — never as plain text. Ask one question per call. Do not print the options in chat; the tool renders them.
2. For learner-generated answers (predictions, explanations, goals), pass `options: []` so the student types their own response. Never supply suggested answers, example responses, or hints disguised as options.
3. If the student dismisses a prompt, treat it as their choice to skip. Do not re-offer.
4. Discuss outcomes by their text, never by ID.

## Budget
- Agent-initiated Pop Quizzes are capped at **1 distinct `quiz_id` per session** (see the budget check in AGENTS.md). Before an automatic quiz, read   `teacher-log.jsonl` and count auto-trigger entries whose `session` matches the current session; skip the offer silently if the limit is reached. Never announce that a budget is exhausted.
- Concept-Explain and Learning-Opportunity activities are not counted as quizzes for grading.
- Skip the offer regardless of budget when the student has declined once already this session, or is working under time pressure.

## Logging (`teacher-log.jsonl` — quizzes only)
One JSON object per line, created on first write. Each skill defines its own schema; this is the schema for quizzes:

| Field | Meaning |
|-------|---------|
| `session` | Current opencode session ID (from `opencode session list --format json`, first `ses_...` value), or the ISO-8601 UTC timestamp of the first log write this session. Reuse the same string for the whole session. |
| `trigger` | `auto` (agent-initiated) or `manual` (student-requested). The budget check depends on this field. |
| `quiz_id` | One shared ID across all questions in a single Pop Quiz run. |
| `outcome` | The `L<n>` ID (analytics only). |
| `concept` | Concept/topic the question targets. |
| `question` | The question text. |
| `options` | The options presented (empty for learner-generated answers). |
| `answer` | The student's response. |
| `correct` | Whether the response was correct (if applicable). |

Never write exercise or goal entries to `teacher-log.jsonl` — those go to
`learning-log.jsonl` via the learning skills.

---

*Generated for the CS-3704 course; licensed under CC-BY-4.0.*
