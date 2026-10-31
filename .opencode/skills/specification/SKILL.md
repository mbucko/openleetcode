---
name: specification
description: Generate software specification document. When creating detailed functional and non-functional requirements.
---

> Based on the specification skill by Dr. Steven Atksinson (https://github.com/constellize/constellize-plugins-official/blob/main/plugins/constellize-design/skills/specification/SKILL.md), licensed under MIT. Adapted for the CS3704 (Intermediate Software Design and Engineering) course at Virginia Tech [Fall 2026] by Dr. Chris Brown. 

<task>
Generate a comprehensive software specification document for {{product_name}}.

The specification should include:

1. **Functional Requirements**
   - Core features and capabilities
   - User interactions and workflows
   - Data inputs and outputs
   - Business rules and logic

2. **Non-Functional Requirements**
   - Performance targets (response time, throughput)
   - Scalability requirements
   - Security requirements
   - Reliability and availability targets
   - Usability and accessibility standards

3. **System Constraints**
   - Technical constraints
   - Business constraints
   - Regulatory and compliance requirements

4. **Acceptance Criteria**
   - Measurable success criteria
   - Testing requirements
   - Quality metrics
</task>

<output-format>
Format this specification as a structured markdown document with numbered sections and subsections, following this template: https://github.com/jam01/SRS-Template

Use this structure:

# Software Specification: {{product_name}}

## 1. Functional Requirements
### 1.1 [Feature Category]
- FR-001: [Requirement description]
- FR-002: [Requirement description]

## 2. Non-Functional Requirements
### 2.1 Performance
- NFR-001: [Requirement description]

### 2.2 Security
- NFR-002: [Requirement description]

### 2.3 Scalability
- NFR-003: [Requirement description]

## 3. System Constraints
[List constraints]

## 4. Acceptance Criteria
[List measurable criteria using the Given-When-Then format (Given [initial context] → When [action taken] → Then [expected result])]
</output-format>

<instructions>
- Number all requirements with unique identifiers (FR-001, NFR-001, etc.)
- Make requirements specific, measurable, and testable
- Include rationale for complex requirements
- Prioritize requirements if possible (Must-have, Should-have, Nice-to-have)
</instructions>
