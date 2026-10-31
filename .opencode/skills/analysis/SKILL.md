---
name: analysis
description: Generate use cases for requirements analysis. Use when analyzing functional requirements.
---

> Based on the specification skill by Dr. Steven Atksinson (https://github.com/constellize/constellize-plugins-official/blob/main/plugins/constellize-design/skills/specification/SKILL.md), licensed under MIT. Adapted for the CS3704 (Intermediate Software Design and Engineering) course at Virginia Tech [Fall 2026] by Dr. Chris Brown. 

# Analysis Skill

Produces requirements-analysis artifacts: text use cases and the UML diagrams that
describe them. The **structure and notation live in templates** under `docs/templates/`;
read the matching template and follow it exactly rather than inventing a format.

## Artifacts and their templates

| Artifact | Template to read and follow |
|----------|-----------------------------|
| Text use case | `docs/templates/use-case.md` |
| Use case diagram (UML, ASCII) | `docs/templates/use-case-diagram.md` |
| Sequence diagram (UML, ASCII) | `docs/templates/sequence-diagram.md` |

## How to work

1. Determine which artifact(s) the requester wants (use case text, use case diagram,
   sequence diagram, or several).
2. Read the matching template file(s) with the `read` tool.
3. Fill in every placeholder, following the template's structure and notation.
4. **Return** the completed content. Do not write files — the phase-2 agents are
   read-only; `build`/the parent agent writes the artifact to the agreed location
   (e.g. `docs/requirements/<name>-use-cases.md`).

## Diagrams

Use **ASCII/text only** — never attempt to render an image. The templates define the
exact notation (actors, system boundary, lifelines, activation bars, message arrows,
class boxes, relationship arrows, multiplicities) and include worked examples. Keep any
accompanying table consistent with the diagram.

<task>
Generate a comprehensive set of use cases for {{product_name}}, plus use case diagrams
and/or sequence diagrams where requested.

Each use case includes:

1. **Actor** — something with behavior that interacts with the system (user, external
   system, organization, ...).
2. **Scenario** — a specific sequence of actions and interactions between the actor and
   the system to achieve a goal.
3. **Preconditions** — what must be true before the use case can be initiated
   (noteworthy system state, not "the user has power").
4. **Postconditions** — what must be true after the use case completes.

Follow `docs/templates/use-case.md` for the text format and the diagram templates above
for the UML views.
</task>

<instructions>
- Number all use cases with unique identifiers (UC-001, UC-002, etc.)
- Make requirements specific, measurable, and testable
- Use ASCII/text diagrams only; do not attempt to render images
- Keep each diagram and its accompanying table consistent
</instructions>
