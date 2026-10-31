#!/usr/bin/env bash
# -------------------------------------------------------------
# collect-ai-usage.sh
#   Receives one argument: a JSON string that maps questions → answers.
#   Example argument (pretty‑printed for readability):
#   {
#     "questions": [
#       {"q":"Which AI tools (other than Opencode) did you use?","a":"ChatGPT‑4, GitHub Copilot"},
#       {"q":"What model names were used?","a":"gpt‑4, codex"},
#       {"q":"For what purposes (code, debugging, docs, etc.)?","a":"code generation and debugging"},
#       {"q":"Approximate proportion of AI‑generated vs. human content?","a":"≈30 % AI‑generated"},
#       {"q":"Any other disclosures required by the AI policy?","a":"All AI‑generated snippets are marked with comments"}
#     ]
#   }
# -------------------------------------------------------------
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

# 1️⃣  Read the JSON argument (the whole argument may contain spaces, so we use "$1")
JSON_PAYLOAD="$1"

# 2️⃣  Ensure jq is available
if ! command -v jq >/dev/null 2>&1; then
    echo "Error: jq is required for collect-ai-usage.sh" >&2
    exit 1
fi

# Build the markdown block
TIMESTAMP="$(date -u +%Y-%m-%d\ %H:%M\ UTC)"
HEADER="# AI Policy Summary – $TIMESTAMP"

BLOCK="${HEADER}\n\n"

# Loop through the array of questions
COUNT=$(echo "$JSON_PAYLOAD" | jq '.questions | length')
for i in $(seq 0 $((COUNT-1))); do
    Q=$(echo "$JSON_PAYLOAD" | jq -r ".questions[$i].q")
    A=$(echo "$JSON_PAYLOAD" | jq -r ".questions[$i].a")
    BLOCK+="**Q:** ${Q}\n\n**A:** ${A}\n\n"
done

# 3️⃣  Prepend the block to ai_disclosure.md (create the file if it does not exist)
if [ -f ai_disclosure.md ]; then
    echo -e "$BLOCK$(cat ai_disclosure.md)" > ai_disclosure.md
else
    echo -e "$BLOCK" > ai_disclosure.md
fi

echo "AI‑usage summary written (or prepended) to ai_disclosure.md"
