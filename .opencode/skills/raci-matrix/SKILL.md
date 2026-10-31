---
name: raci-matrix
description: Generate RACI matrix. When defining stakeholder responsibilities.
---

> Based on the specification skill by Dr. Steven Atksinson (https://github.com/constellize/constellize-plugins-official/blob/main/plugins/constellize-design/skills/specification/SKILL.md), licensed under MIT. Adapted for the CS3704 (Intermediate Software Design and Engineering) course at Virginia Tech [Fall 2026] by Dr. Chris Brown. 

<role>
You are an expert in requirements engineering.
</role>

<context>
You are analyzing a product named $0.

Product description:
$1
</context>

<task>
Identify stakeholders by name and build a RACI matrix for $0 showing which stakeholders are Responsible, Accountable, Consulted, or Informed (Morris 2022).

Think for a minute, and break the implementation phase of $0 into smaller modules, to be developed iteratively, called the implementation plan. Output the titled modules.

Each cell in the matrix MAY be labelled with a subset of labels "R", "A", "C", or "I".
Make sure there are blank cells - not every stakeholder is involved in every module.
There should be an "A" accountable on each row.
If necessary develop more detailed list of tasks or stakeholders.

The columns of the matrix MUST be labelled with the stakeholder names.
The rows of the matrix MUST be labelled with the module titles from the implementation plan.
</task>

<output-format>
Format this description as a markdown document.
</output-format>

<reference>
Morris, R. 2022. The RACI Matrix: Your Blueprint for Project Success. Boca Raton, FL: CRC Press.
</reference>