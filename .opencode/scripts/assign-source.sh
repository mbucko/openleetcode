#!/usr/bin/env bash
set -euo pipefail

# assign-source.sh — resolve an assignment name or link to a fetchable source
# for @assignment analyze.
#
# Usage:
#   .opencode/scripts/assign-source.sh <name-or-link>
#
# Prints KEY=VALUE lines to stdout:
#   NAME=<output file basename, no .md>   # e.g. PM1.2, HW1, or derived from a URL
#   URL=<raw source URL to fetch>
#   KIND=<assignment|overview>
#     assignment -> a submission assignment (HWn or PMx.y)
#     overview   -> resolves to a Project README (bare PMx); NOT a submission
# Exits 0 on success. On an unresolvable/unrecognized input, or when a resolved
# raw file is confirmed missing (HTTP 404/403/410), exits 1 with a graceful
# message to stderr (no result; the caller creates no file).

BASE="https://raw.githubusercontent.com/CS3704-VT/Course/main"

verify_url() {
  # Optional existence check for name-derived URLs. Uses curl if available.
  # Only explicit "not found" HTTP codes block; network failures (000) proceed
  # so the agent's own fetch can report the outcome rather than a false error.
  local url="$1"
  if command -v curl >/dev/null 2>&1; then
    local code
    code="$(curl -s -o /dev/null -w '%{http_code}' -L --max-time 15 "$url" || true)"
    if [[ "$code" == "404" || "$code" == "403" || "$code" == "410" ]]; then
      echo "No assignment found for \"$arg\". The resolved source returned HTTP $code (it does not appear to exist)." >&2
      echo "Verify the assignment name/link (e.g. HW1, PM1.2) or provide the assignment URL / paste the body." >&2
      return 1
    fi
  fi
  return 0
}

# Normalize for matching only (names are printed in original case)
arg="$1"

# 1) Direct URL
if [[ "$arg" =~ ^https?:// ]]; then
  url="$arg"
  # Derive a name from the basename (strip trailing .md)
  name="$(basename "$url")"
  name="${name%.md}"
  kind="assignment"
  if [[ "$name" =~ [Rr][Ee][Aa][Dd][Mm][Ee]$ ]]; then
    kind="overview"
  fi
  # User-provided URLs are explicit; do not existence-block them.
  echo "NAME=$name"
  echo "URL=$url"
  echo "KIND=$kind"
  exit 0
fi

# Lowercase copy for pattern matching
lower="$(printf '%s' "$arg" | tr '[:upper:]' '[:lower:]')"

# 2) Homework: HW<n>  -> HWs/HW<n>.md
if [[ "$lower" =~ ^hw([0-9]+)$ ]]; then
  url="$BASE/HWs/HW${BASH_REMATCH[1]}.md"
  verify_url "$url" || exit 1
  echo "NAME=$arg"
  echo "URL=$url"
  echo "KIND=assignment"
  exit 0
fi

# 3) Project milestone: PM<x.y> -> Projects/Project<x>/PM<x.y>.md
#    Bare PM<x>        -> Projects/Project<x>/README.md (overview, not an assignment)
if [[ "$lower" =~ ^pm([0-9]+)([.][0-9]+)?$ ]]; then
  proj_num="${BASH_REMATCH[1]}"
  if [[ -n "${BASH_REMATCH[2]:-}" ]]; then
    # PMx.y — actual assignment
    url="$BASE/Projects/Project${proj_num}/${arg}.md"
    kind="assignment"
  else
    # PMx — project overview README, not a submission assignment
    url="$BASE/Projects/Project${proj_num}/README.md"
    kind="overview"
  fi
  verify_url "$url" || exit 1
  echo "NAME=$arg"
  echo "URL=$url"
  echo "KIND=$kind"
  exit 0
fi

# 4) Unrecognized
cat >&2 <<EOF
No assignment found for "${arg}". I couldn't resolve a source.
Check the name/link (e.g. HW1, PM1.2) or provide the assignment URL / paste the body.
EOF
exit 1
