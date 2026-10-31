#!/usr/bin/env bash
set -euo pipefail

# submit-file.sh — packages a single deliverable file together with the AI disclosure file.
# Usage: .opencode/scripts/submit-file.sh <deliverable-file>

if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <deliverable-file>"
  exit 1
fi

DELIVERABLE="$1"
if [ ! -f "$DELIVERABLE" ]; then
  echo "Error: Deliverable file '$DELIVERABLE' not found."
  exit 1
fi

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

TIMESTAMP="$(date +%Y%m%d-%H%M%S)"
SUBMIT_DIR="cs3704-submission-$TIMESTAMP"
ZIP="cs3704-submission-$TIMESTAMP.zip"

# Prepare submission directory
rm -rf "$SUBMIT_DIR"
mkdir -p "$SUBMIT_DIR"

# Copy deliverable
cp "$DELIVERABLE" "$SUBMIT_DIR/"
# Copy AI disclosure if present
if [ -f ai_disclosure.md ]; then
  cp ai_disclosure.md "$SUBMIT_DIR/"
fi

# Create zip
if command -v zip >/dev/null 2>&1; then
  (cd "$ROOT" && zip -rq "$ZIP" "$SUBMIT_DIR")
else
  tar -czf "$ZIP" -C "$ROOT" "$SUBMIT_DIR"
fi

echo "Submission package created: $ZIP"
