#!/usr/bin/env bash
set -euo pipefail

# submit-link.sh — verifies git state and prepares a link submission.
# It ensures the working tree is clean, all commits are pushed, and stages the AI disclosure file.
# It then prints the repository URL and latest commit SHA for the student to paste into Canvas.

# Ensure we are at repo root
ROOT="$(git rev-parse --show-toplevel)"
cd "$ROOT"

# 1. Check for clean working tree
git status --porcelain | grep -q . && {
  echo "Error: Working tree is not clean. Please commit or stash changes before submitting via link."
  exit 1
}

# 2. Ensure a remote exists
REMOTE_URL="$(git remote get-url origin 2>/dev/null || true)"
if [ -z "$REMOTE_URL" ]; then
  echo "Error: No 'origin' remote found. Cannot determine repository URL."
  exit 1
fi

# 3. Ensure all commits are pushed
if git rev-parse @{u} >/dev/null 2>&1; then
  # upstream exists
  if ! git diff --quiet @{u}..HEAD; then
    echo "Error: You have unpushed commits. Please push them before submitting via link."
    exit 1
  fi
else
  echo "Warning: No upstream tracking branch set for the current branch. Skipping push check."
fi

# 4. Stage the AI disclosure file (if present)
if [ -f ai_disclosure.md ]; then
  git add ai_disclosure.md
  echo "Staged ai_disclosure.md for inclusion in the repo."
fi

# 5. Print submission info
COMMIT_SHA="$(git rev-parse HEAD)"
BRANCH_NAME="$(git rev-parse --abbrev-ref HEAD)"

echo "Repository URL: $REMOTE_URL"
echo "Branch: $BRANCH_NAME"
echo "Latest commit SHA: $COMMIT_SHA"

echo "\nYou should now copy the above URL, branch, and commit SHA into the Canvas submission form (or wherever the assignment asks for a Git link)."
