---
name: heuristics-nielsen
description: >
  Encodes Jakob Nielsen's ten usability heuristics as procedural constraints on
  on-demand user interface generation. Load this skill whenever generating,
  modifying, extending, or regenerating any user interface artifact within the
  Space to Think — including dashboards, forms, tables, charts, configuration
  panels, watchlists, alert builders, or any interactive component produced from
  dialogue. Also load when the user asks why a control behaves the way it does,
  when auditing a generated UI for usability, or when another skill (e.g.,
  accessibility-wcag, affordances-norman) requests a heuristic compliance pass.
  Apply these constraints inline during generation, not as a post-hoc audit:
  every emitted component must satisfy every applicable heuristic before it
  reaches the user.
metadata:
  version: 0.1.0
  source: >
    Nielsen, J. (1994). Heuristic evaluation. In Nielsen, J. & Mack, R.L. (Eds.),
    Usability Inspection Methods. John Wiley & Sons, 25-62. Heuristic definitions
    follow the NN/g canonical set (language refined 2020, substance unchanged
    since 1994): https://www.nngroup.com/articles/ten-usability-heuristics/
  framework: >
    Nathan Conklin, Miranda Capra, and Chris North. 2026. Automating the
    Application of HCI Principles: Skills for On-Demand UI Construction, the
    Human-AI Space to Think, and the Future of HCI. In Proceedings of The
    Future of HCI Workshop (FutureHCI ’26). ACM, New York, NY, USA, 6 pages.
  relationship-to-other-skills: >
    Composes with affordances-norman.skill.md (signifier compliance),
    accessibility-wcag.skill.md (hard accessibility constraints),
    cognitive-load-progressive-disclosure.skill.md (minimum sufficient surface),
    mixed-initiative.skill.md (agentic action instrumentation), and
    direct-manipulation.skill.md (visible objects, reversible actions).
    ability-based-personalization.skill.md may modify how this skill is applied
    for a specific user profile. Where constraints overlap, the stricter
    constraint wins.
---

> Based on the heuristics-nielsen skill by Nathan Conklin (https://github.com/nathanconklin/skills/blob/main/hci-design/heuristics-nielsen.skill.md), licensed under MIT. Adapted for the CS3704 (Intermediate Software Design and Engineering) course at Virginia Tech [Fall 2026] by Dr. Chris Brown. 

# Nielsen's Ten Usability Heuristics as Generation Constraints

## Purpose

Heuristic evaluation has historically been a post-hoc audit performed by human
experts on a finished interface. This skill inverts that: the ten heuristics
become inline constraints on the generator. Good HCI becomes a property of the
generation process, not a property of the shipped product. Every component in
every generated UI is checked — not only the ones a designer happened to
remember.

Because the UI is generated from dialogue inside a shared task model, the
generator has information a traditional designer never had at design time: the
user's own vocabulary, the sub-goals the dialogue has decomposed, and the
provenance of every requested capability. Several heuristics (2, 6, 10) are
satisfied by exploiting exactly this information. Use it.

## How to apply this skill

1. **Before generating**: read the shared task model — its entities, views,
   interactions, and dialogue provenance links. Extract the user's domain
   vocabulary from their dialogue turns (their nouns and verbs, not internal or
   technical jargon).
2. **During generation**: treat each constraint below as a requirement on every
   emitted component. If a planned component cannot satisfy a constraint,
   redesign the component before emitting it — do not emit and annotate.
3. **After generating**: run the verification checklist (bottom of this file)
   as a self-critique pass against your own output. Any failed check is a
   generation defect: fix and re-verify before instantiating the UI.
4. **On user query**: when the user asks why a control exists or behaves as it
   does, cite the specific heuristic constraint that produced it and the
   dialogue turn that justified it.

---

## The Ten Constraints

### 1. Visibility of system status

The design keeps users informed about what is going on through appropriate,
timely feedback.

**Generate:**
- Every user action produces visible feedback within the interaction (state
  change, confirmation, progress indication). No silent actions.
- Every data-bearing view displays data freshness (e.g., "Last updated 9:30
  AM") and its refresh behavior.
- Any operation that is asynchronous, long-running, or agent-initiated shows
  in-progress status; for waits beyond a few seconds, show determinate progress
  or a meaningful stage description rather than a bare spinner.
- Toggles, filters, and modes visibly display their current state at all times.

**Reject before emitting:** any control whose activation changes state with no
perceivable evidence; any data display with no freshness indication.

### 2. Match between system and the real world

The design speaks the user's language and follows real-world conventions.

**Generate:**
- Label every component, column, action, and message using vocabulary extracted
  from the user's dialogue turns and the task model's domain concepts — not
  schema names, internal identifiers, or developer jargon. If the user said
  "active picks," the view is titled "Active Picks," not "equity_positions."
- Order and group information to match the task's real-world structure as the
  user articulated it, not the data model's storage layout.
- Use domain-conventional formats (currency, percentages, dates, units) as the
  user's domain expects them.

**Reject before emitting:** labels that appear nowhere in the dialogue or
domain when a user-articulated term exists; raw field names surfaced to the UI.

### 3. User control and freedom

Users need clearly marked emergency exits: undo, redo, and the ability to leave
unwanted states without extended effort.

**Generate:**
- Every state-mutating action (edit, remove, configure, reorder) is reversible:
  provide undo, rollback, or restore-previous for each.
- Every user-added element (view, alert, filter, annotation) carries visible
  edit and remove affordances.
- Multi-step flows provide back/cancel at every step without losing entered
  work.
- Because the interface itself is generated and regenerable, extend this
  heuristic to the meta level: the user can revert the interface to a prior
  generation state ("undo that last change to the dashboard"), and this is
  discoverable.

**Reject before emitting:** any destructive or mutating action with no undo
path; any generated element the user cannot remove.

### 4. Consistency and standards

Users should not have to wonder whether different words, situations, or actions
mean the same thing. Follow platform and internal conventions.

**Generate:**
- Emit all components from a single consistent component library; never
  hand-roll a one-off variant of an existing pattern.
- Use one term per concept across the entire generated surface (the term the
  user used); one icon per action; one interaction pattern per operation type.
- **Cross-generation consistency (unique obligation of on-demand UI):** when
  extending or regenerating an interface, preserve existing layout positions,
  terminology, and interaction patterns unless the user's request requires
  changing them. The user's spatial memory of the workspace is part of the
  shared context — do not reshuffle what the user has already learned.
- Follow platform conventions (external consistency) for common controls so
  prior experience transfers.

**Reject before emitting:** two components performing the same operation with
different patterns; regeneration that gratuitously relocates or renames
elements the user did not ask to change.

### 5. Error prevention

The best designs prevent problems from occurring in the first place.

**Generate:**
- Every destructive action (delete, overwrite, disable a safety-relevant alert)
  requires confirmation that states the specific consequence.
- Constrain inputs at the source: use pickers, ranges, typed fields, and
  sensible defaults derived from the task model rather than free text where
  structure exists; validate inline before submission, not after.
- Distinguish slips from mistakes: prevent slips with constraints and defaults;
  prevent mistakes by presenting the current state and consequence before
  commitment (e.g., preview of what an alert will do).
- Disable or hide actions that are invalid in the current state, with an
  explanation available for why.

**Reject before emitting:** unconfirmed destructive actions; free-text inputs
for values with known structure; forms that only validate on submit.

### 6. Recognition rather than recall

Minimize memory load by making elements, actions, and options visible.

**Generate:**
- Every action is recognizable from its location, label, and icon without prior
  exposure or training — a first-time viewer of this generated interface can
  identify what each control does.
- Provide labels alongside icons; tooltips on hover/focus for anything
  compressed; visible defaults pre-filled from the dialogue rather than empty
  fields the user must remember how to complete.
- Information required by a decision is visible at the point of decision — do
  not require the user to remember values from another view (bring the value
  in, or show both).
- The provenance back-link (see heuristic 10) makes each component's purpose
  recognizable by construction: the user asked for it, and the interface says
  so.

**Reject before emitting:** unlabeled icon-only controls for non-universal
actions; workflows that require transporting remembered values between views.

### 7. Flexibility and efficiency of use

Shortcuts and accelerators — invisible to novices — speed interaction for
experts, and users can tailor frequent actions.

**Generate:**
- Data views include filter, sort, and search affordances by default.
- Provide multiple coordinated views where the task model contains multiple
  perspectives on the same entities (table + chart, list + detail).
- Support keyboard operation of frequent actions, and expose personalization
  (column choice, ordering, saved filters) where the dialogue indicates
  repeated use.
- In the on-demand paradigm, the deepest accelerator is the dialogue itself:
  every generated view remains modifiable by natural language. Make this
  visible — the interface signals that it can be asked to change.

**Reject before emitting:** data tables without filter/sort; a single forced
representation when the task model supports several; interfaces that hide
their own malleability.

### 8. Aesthetic and minimalist design

Interfaces should not contain information that is irrelevant or rarely needed;
every extra unit of information competes with the relevant units.

**Generate:**
- Apply the minimum sufficient surface policy: expose only the affordances the
  dialogue has so far justified. New capability appears the first time the
  user's articulated need entails it — not speculatively.
- Use progressive disclosure for secondary functions (configuration, advanced
  filters) behind clearly signposted expansion points.
- Establish visual hierarchy that mirrors the task model's goal structure: the
  user's primary sub-goals get primary visual weight.
- Declutter on regeneration: if a capability's justifying goal has been removed
  from the task model, propose removing its UI rather than accreting.

**Reject before emitting:** components with no corresponding sub-goal,
constraint, or information need in the task model; chrome or decoration that
carries no task information.

### 9. Help users recognize, diagnose, and recover from errors

Error messages are expressed in plain language, precisely indicate the problem,
and constructively suggest a solution.

**Generate:**
- Every error state renders in the user's domain vocabulary (heuristic 2), with
  no error codes as the primary message, and pairs the diagnosis with a
  recovery action the user can take directly from the message.
- Preserve user work through failures: inputs survive a failed submission;
  partial progress is not discarded.
- Data-dependent views degrade visibly and honestly (e.g., "Prices unavailable
  since 9:30 AM — Retry") rather than silently showing stale or empty content
  (ties to heuristic 1).

**Reject before emitting:** dead-end error states with no recovery affordance;
raw exception text surfaced to the user; failures that destroy entered work.

### 10. Help and documentation

Best case, the system needs no additional explanation; where help is needed, it
is contextual, task-focused, concrete, and concise.

**Generate:**
- Contextual help at the point of need (inline hints, "learn more" expansions)
  rather than a detached manual.
- **Provenance as documentation (unique capability of on-demand UI):** every
  generated component carries a back-link to the dialogue turn(s) that
  justified it — a "Why this exists" affordance rendering the justification in
  the user's own words ("You asked to be alerted when SPY drops 3% in a day")
  with a "View in conversation" action. This is the primary help mechanism:
  the interface documents itself through its own provenance.
- When the user asks why a control behaves as it does, cite the skill
  constraint and the dialogue turn — the same back-link, surfaced
  conversationally.

**Reject before emitting:** any component with no provenance link in the task
model; help text that describes the system's internals instead of the user's
task.

---

## Verification checklist

Run this checklist as a self-critique pass over the complete generated
interface before instantiation. Each item is written to be machine-checkable
against structured component output where possible; items marked (critic)
require judgment by an AI critic pass. A single failure blocks instantiation.

**H1 — Status**
- [ ] Every interactive component declares a feedback behavior for activation.
- [ ] Every data view declares a freshness indicator.
- [ ] Every async operation declares an in-progress state.

**H2 — Real-world match**
- [ ] Every visible label resolves to a term in the dialogue vocabulary or task
      model domain concepts; zero raw schema/field names. (critic: labels read
      naturally in the user's domain)

**H3 — Control & freedom**
- [ ] Every mutating action maps to a declared undo/rollback path.
- [ ] Every user-added element exposes edit and remove.
- [ ] Multi-step flows declare back/cancel with state preservation.

**H4 — Consistency**
- [ ] All components come from the declared component library (no ad-hoc
      variants).
- [ ] One term per concept across all labels (string-level check).
- [ ] Diff against prior generation: no unrequested relocation/renaming of
      existing elements.

**H5 — Error prevention**
- [ ] Every destructive action declares a confirmation with a specific
      consequence string.
- [ ] Every structured input uses a constrained control with a default where
      the task model provides one; inline validation declared.

**H6 — Recognition**
- [ ] No icon-only control without an accessible label and tooltip.
- [ ] (critic) A first-exposure reading of each view identifies every action's
      purpose from label + placement alone.

**H7 — Flexibility**
- [ ] Every data collection view declares filter and sort.
- [ ] Frequent actions declare keyboard operability.
- [ ] Malleability signal present (interface indicates it can be modified via
      conversation).

**H8 — Minimalism**
- [ ] Every component traces to a task-model sub-goal, constraint, or
      information need (provenance coverage = 100%).
- [ ] Secondary functions sit behind progressive disclosure. (critic: visual
      hierarchy mirrors goal priority)

**H9 — Error recovery**
- [ ] Every declared error state includes plain-language message + recovery
      action; no raw exception passthrough.
- [ ] Input-bearing components declare work preservation on failure.

**H10 — Help & provenance**
- [ ] Every component carries a dialogue back-link; "Why this exists"
      affordance renders it.
- [ ] Contextual help declared at points of likely difficulty. (critic)

## Failure handling

If a constraint genuinely cannot be satisfied (e.g., an upstream data source
provides no freshness metadata for H1), do not silently ship the violation:
surface the limitation to the user in the dialogue, record it in the task
model as a known constraint violation with rationale, and render an honest
placeholder in the UI. Uncertainty about whether a constraint applies is a
signal to ask the user rather than act (mixed-initiative principle).

## Scope notes

- These heuristics are general rules of thumb, not pixel-level guidelines;
  where a more specific skill (accessibility-wcag, affordances-norman) imposes
  a stricter, testable constraint on the same surface, the stricter constraint
  governs.
- This skill governs generation and regeneration. It can also be run in audit
  mode against an existing generated interface: execute the verification
  checklist and report violations with the responsible heuristic, the failing
  component, and a proposed regeneration fix.