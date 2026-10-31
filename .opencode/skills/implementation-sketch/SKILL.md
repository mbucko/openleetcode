---
name: implementation-sketch
description: Generate implementation sketches for gaps before coding.
---

> Based on the specification skill by Dr. Steven Atksinson (https://github.com/constellize/constellize-plugins-official/blob/main/plugins/constellize-design/skills/specification/SKILL.md), licensed under MIT. Adapted for the CS3704 (Intermediate Software Design and Engineering) course at Virginia Tech [Fall 2026] by Dr. Chris Brown. 

<task>
Create implementation sketches for each gap in $0 to guide design decisions before coding.

Sketch a rough approach for each gap identified during knowledge gathering. These sketches help think through what new functionality is actually needed, how it connects to existing components, key constraints that shaped the need, and what can be reused versus what must be generated.

The goal isn't detailed task lists, but ensuring every new piece aligns with the constellation of known systems, so design decisions stay grounded in knowledge.

Follow this process:

1. **Review approved gaps** from `llm/construction/requirements/gap-analysis.md`:
   - List all gaps marked for implementation
   - Extract constraints and integration points for each
   - Note success criteria

2. **For each gap, sketch the approach:**
   - What new functionality is actually needed (not vague)
   - How it connects to existing stars from `llm/construction/requirements/constellation-map.md`
   - Key constraints and context that shaped the need
   - What can be reused vs what must be generated
   - Design decisions and trade-offs

3. **Ground sketches in constellation knowledge:**
   - Reference specific stars by name
   - Use actual contracts, schemas, protocols from constellation map
   - Respect architectural seams documented in stars
   - Align with authentication and error-handling patterns

4. **Validate each sketch:**
   - Does this sketch address the gap's success criteria?
   - Are all referenced stars documented in the constellation map?
   - Have we identified what's reusable vs net-new?
   - Is the approach shaped by documented constraints?
</task>

<context>
**Standard Construction Folder Structure:**
This prompt reads from:
- `llm/construction/requirements/gap-analysis.md` (identified gaps)
- `llm/construction/requirements/constellation-map.md` (star catalog)
- `llm/construction/requirements/scope-lock.md` (scope governance)

And outputs to: `llm/construction/design/implementation-sketches.md`
</context>

<thinking>
Before sketching implementations, analyze:
1. What gaps are we sketching for? (Only approved gaps from PRD)
2. What stars exist that we can connect to or reuse?
3. What constraints from gap analysis must shape our approach?
4. Are we designing to close gaps, or adding features beyond scope?
</thinking>

<output-format>
Format your output as `llm/construction/design/implementation-sketches.md`:

# Implementation Sketches: $0

## Overview

**Purpose:** Rough design approaches for approved gaps, aligned with constellation

**Gaps to Sketch:** [Count] (from llm/construction/requirements/gap-analysis.md)

**Constellation Reference:** llm/construction/requirements/constellation-map.md

---

## Sketch 1: [Gap Name]

**Gap Reference:** [Section from llm/construction/requirements/gap-analysis.md]
**Priority:** [Critical/High/Medium/Low]
**Estimated Complexity:** [Simple/Moderate/Complex]

### What We're Building

**New Functionality Needed:**
[Specific description - not vague - of what this gap requires]

**Why This Gap Exists:**
[Brief recap from gap analysis - what stars don't provide this]

### Constellation Alignment

**Stars This Connects To:**
- **[Star Name]** (from llm/construction/requirements/constellation-map.md)
  - Connection: [How we integrate - protocol/contract]
  - What we reuse: [Specific capability we're leveraging]
  - Integration point: [Specific interface/API/schema]

- **[Star Name]** (from llm/construction/requirements/constellation-map.md)
  - Connection: [How we integrate]
  - What we reuse: [Specific capability]
  - Integration point: [Specific interface]

**Architectural Seams:**
[Reference relevant seams from constellation map that affect this design]

### Design Approach

**Core Design Decision:**
[The main architectural choice - e.g., "Build as middleware between Gateway and Stripe API"]

**Key Components:**
1. **[Component Name]**: [What it does, 1-2 sentences]
2. **[Component Name]**: [What it does]
3. **[Component Name]**: [What it does]

**Data Flow:**
```
[Star A] → [New Component 1] → [New Component 2] → [Star B]
          ↓
     [Star C] (for state)
```

**Reuse vs Generate:**
- ✅ **Reuse:** [Existing star] provides [specific capability]
- ✅ **Reuse:** [Existing star] provides [specific capability]
- 🔨 **Generate:** [What we must build new because no star provides it]
- 🔨 **Generate:** [What we must build new]

### Constraints Shaping This Design

**From Gap Analysis:**
- [Constraint 1 from llm/construction/requirements/gap-analysis.md]
- [Constraint 2 from llm/construction/requirements/gap-analysis.md]
- [Constraint 3 from llm/construction/requirements/gap-analysis.md]

**From Constellation:**
- [Constraint from existing star - e.g., "PostgreSQL single-writer model"]
- [Constraint from integration point]

### Trade-offs

**This Approach:**
- ✅ Pro: [Benefit aligned with constraints]
- ✅ Pro: [Benefit]
- ❌ Con: [Limitation or cost]
- ❌ Con: [Limitation]

**Alternative Considered:** [Other approach]
- Why rejected: [Reason - must reference constellation or constraints]

### Success Validation

**How This Closes the Gap:**
- [ ] Success criterion 1 (from llm/construction/requirements/gap-analysis.md)
- [ ] Success criterion 2
- [ ] Success criterion 3

**Integration Validation:**
- [ ] All referenced stars exist in llm/construction/requirements/constellation-map.md
- [ ] Integration points match documented contracts
- [ ] Design respects architectural seams

---

## Sketch 2: [Next Gap Name]

[Repeat structure]

---

## Cross-Sketch Concerns

**Shared Dependencies:**
[If multiple sketches depend on the same star or component]

**Potential Conflicts:**
[If sketches might interfere with each other]

**Implementation Order:**
[If sketches must be built in sequence due to dependencies]

---

## Validation Checklist

For each sketch above:
- [ ] Addresses a gap from llm/construction/requirements/gap-analysis.md (no scope creep)
- [ ] References only stars documented in llm/construction/requirements/constellation-map.md
- [ ] Respects constraints from gap analysis
- [ ] Identifies what's reused vs generated
- [ ] Maps to gap's success criteria
- [ ] Includes trade-off analysis
- [ ] Grounded in constellation knowledge, not generic patterns

**Ready for Implementation:** [ ]
</output-format>

<instructions>
CRITICAL: Sketches must be grounded in documented knowledge, not generic best practices.

NEVER sketch implementations that:
- Reference stars not in the constellation map
- Ignore constraints documented in gap analysis
- Add features beyond the approved gap
- Use generic patterns without constellation alignment
- Skip trade-off analysis

DO NOT:
- Create detailed task lists - keep sketches at design level
- Design in isolation from constellation map
- Assume integration points without checking documented contracts
- Skip the "reuse vs generate" analysis
- Forget to validate against gap success criteria

ALWAYS:
- Reference specific stars by name from constellation map
- Shape design around documented constraints
- Identify what can be reused from existing stars
- Analyze trade-offs of your approach
- Validate that sketch closes the gap's success criteria
- Keep sketches rough - detailed enough to guide, not prescriptive

REPEAT: Every sketch must align with the constellation. Design decisions must be shaped by documented stars, constraints, and gaps - not dropped in from other projects.
</instructions>

<examples>
✅ Good implementation sketch:
## Sketch: API Rate Limiter Between Gateway and Stripe API

**Gap Reference:** Gap 1 from llm/construction/requirements/gap-analysis.md
**Priority:** Critical
**Estimated Complexity:** Moderate

### What We're Building

**New Functionality Needed:**
Rate limiting middleware that prevents Stripe API quota exhaustion (100 req/sec limit) while queuing overflow requests, ensuring no payment failures during traffic spikes.

**Why This Gap Exists:**
API Gateway (Star) has no rate limiting capability. Stripe API (Star) enforces hard 100 req/sec limit. No middleware exists to bridge this mismatch.

### Constellation Alignment

**Stars This Connects To:**
- **API Gateway** (from llm/construction/requirements/constellation-map.md)
  - Connection: HTTP middleware layer
  - What we reuse: Existing request/response pipeline
  - Integration point: Express middleware chain (req, res, next)

- **Stripe API** (from llm/construction/requirements/constellation-map.md)
  - Connection: Wrap official Stripe SDK client
  - What we reuse: SDK's retry logic and error handling
  - Integration point: Stripe SDK methods (charges.create, etc.)

- **Redis Cache** (from llm/construction/requirements/constellation-map.md)
  - Connection: Distributed queue state storage
  - What we reuse: Sorted sets for queue, atomic operations
  - Integration point: Redis commands (ZADD, ZPOPMIN)

**Architectural Seams:**
API Gateway uses Express middleware pattern. Redis Cache uses connection pooling. Stripe API Star documents exponential backoff on 429s.

### Design Approach

**Core Design Decision:**
Build as Express middleware that wraps Stripe SDK calls, using Redis sorted sets for distributed queue with timestamps.

**Key Components:**
1. **RateLimitMiddleware**: Express middleware intercepts requests, checks Redis counter
2. **StripeQueueWrapper**: Wraps Stripe SDK methods with rate limit logic
3. **QueueProcessor**: Background worker drains queue at controlled rate

**Data Flow:**
```
API Gateway → RateLimitMiddleware → StripeQueueWrapper → Stripe API
                      ↓
                 Redis Cache (queue + counter)
                      ↓
                QueueProcessor (drainer)
```

**Reuse vs Generate:**
- ✅ **Reuse:** API Gateway's Express middleware chain
- ✅ **Reuse:** Stripe SDK's retry and error handling
- ✅ **Reuse:** Redis Cache's sorted sets and atomic operations
- 🔨 **Generate:** RateLimitMiddleware (no star provides this)
- 🔨 **Generate:** StripeQueueWrapper (no star provides this)
- 🔨 **Generate:** QueueProcessor background worker

### Constraints Shaping This Design

**From Gap Analysis:**
- Must handle 500 req/sec peak load
- Stripe enforces 100 req/sec limit
- Queueing delay <2 seconds acceptable at 90th percentile
- Must integrate with existing Redis instance (no new infrastructure)

**From Constellation:**
- Redis Cache uses connection pooling (max 10 connections)
- API Gateway has 30s request timeout
- Stripe API Star documents 429 retry behavior

### Trade-offs

**This Approach:**
- ✅ Pro: Leverages existing Redis - no new infrastructure
- ✅ Pro: Transparent to API Gateway - just middleware
- ✅ Pro: Sorted sets give us FIFO queue naturally
- ❌ Con: Background worker adds operational complexity
- ❌ Con: Requires monitoring queue depth

**Alternative Considered:** In-memory queue per instance
- Why rejected: Doesn't work across multiple API Gateway instances (not distributed), violates constraint to use existing Redis

### Success Validation

**How This Closes the Gap:**
- [ ] Handles 500 req/sec without dropping requests (queue absorbs overflow)
- [ ] Maintains 100 req/sec limit to Stripe (QueueProcessor enforces)
- [ ] Queue delay <2 seconds at 90th percentile (measurable via metrics)
- [ ] Graceful degradation if Redis unavailable (fail open to Stripe, accept 429s)

**Integration Validation:**
- [x] All referenced stars exist in llm/construction/requirements/constellation-map.md
- [x] Integration points match documented contracts (Express middleware, Stripe SDK, Redis commands)
- [x] Design respects architectural seams (connection pooling, timeouts)

---

❌ Bad implementation sketch:
## Sketch: Better Error Handling

### What We're Building

**New Functionality Needed:**
Comprehensive error handling framework for the system.

**Why This Gap Exists:**
Current error handling isn't good enough.

### Design Approach

**Core Design Decision:**
Use industry best practices for error handling.

**Key Components:**
1. **ErrorHandler**: Handles all errors
2. **Logger**: Logs errors
3. **Alerter**: Sends alerts

**Reuse vs Generate:**
- 🔨 **Generate:** Everything (need to build comprehensive framework)

### Trade-offs

**This Approach:**
- ✅ Pro: Better error handling
- ❌ Con: Takes time to build

[This is wrong because:]
- Doesn't reference specific gap from gap analysis (vague "better error handling")
- No constellation alignment - doesn't reference any stars
- No constraints from gap analysis shape this design
- Generic "best practices" approach, not grounded in knowledge
- No specific integration points documented
- Missing "reuse" analysis - claims everything is net-new
- No validation against success criteria
- This is scope creep, not addressing a documented gap]

---

✅ Good reuse analysis:
**Reuse vs Generate:**
- ✅ **Reuse:** Redis Cache's sorted sets (ZADD, ZPOPMIN) for queue implementation
- ✅ **Reuse:** API Gateway's Express middleware chain (req, res, next) for request interception
- ✅ **Reuse:** Stripe API's error handling (429 retries with exponential backoff)
- 🔨 **Generate:** RateLimitMiddleware - new component, no star provides rate limiting
- 🔨 **Generate:** QueueProcessor - new background worker to drain queue
- 🔨 **Generate:** Monitoring integration - emit metrics on queue depth

[This is good because:]
- Specific about what's reused from which star
- Includes actual methods/interfaces (ZADD, req/res/next)
- Clear about what's net-new and why (no star provides it)
- Grounded in constellation map documentation

---

❌ Bad reuse analysis:
**Reuse vs Generate:**
- ✅ **Reuse:** Database
- ✅ **Reuse:** API
- 🔨 **Generate:** New service

[This is wrong because:]
- Too vague - which database? Which API?
- Doesn't specify what capability is being reused
- Doesn't reference star names from constellation map
- Doesn't identify specific integration points
- Not grounded in documented knowledge
</examples>
