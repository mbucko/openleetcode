#!/usr/bin/env bash
set -euo pipefail

# fetch-lecture.sh — fetch and extract text from CS3704 lecture PDFs hosted in
# the external Course repository (https://github.com/CS3704-VT/Course).
# Used by the concept-explain skill to ground explanations in lecture content.
#
# Lecture files are PDFs under Course/main/resources/lectures/. The script
# downloads them to a temp dir (never into the repo) and extracts the text
# layer with pdftotext, so agents can read the content without a PDF viewer.
#
# Usage:
#   .opencode/scripts/fetch-lecture.sh list
#   .opencode/scripts/fetch-lecture.sh dump <filename> [<outfile>]
#   .opencode/scripts/fetch-lecture.sh match <concept>
#   .opencode/scripts/fetch-lecture.sh match --text <concept>
#
# Commands:
#   list                     List lecture filenames under resources/lectures/ on
#                            the Course repo default branch (`main`).
#   dump <filename>          Download the named PDF (URL-encoding any spaces) and
#                            print its extracted text to stdout, or copy it to
#                            <outfile> when given. The temp text-file path is
#                            printed to stderr so the agent can grep/read it.
#   match <concept>          Find lectures likely to cover <concept>. First scores
#                            filenames by token overlap (fast); with `--text` it
#                            instead downloads every lecture and counts in-text
#                            mentions of the concept (slow, more thorough).
#                            Prints ranked matches: <filename><TAB><reason>.
#
# Exit codes:
#   0  success
#   1  graceful failure — lectures dir missing/empty (HTTP 404/200-empty),
#      a named file not found (HTTP 404/403/410), network or tooling unavailable.
#      Nothing is guessed or fabricated; callers should relay the stderr message
#      and fall back (e.g., to the local concept blurb).
#
# Requires: curl, python3, pdftotext. Temp files live under /tmp.

REPO_API="https://api.github.com/repos/CS3704-VT/Course"
RAW_BASE="https://raw.githubusercontent.com/CS3704-VT/Course/main"
LECTURES_DIR="resources/lectures"

say() { printf '%s\n' "$*" >&2; }

require_reqs() {
  local c
  for c in curl python3 pdftotext; do
    command -v "$c" >/dev/null 2>&1 || {
      say "fetch-lecture: required tool '$c' was not found; cannot proceed."
      return 1
    }
  done
}

urlencode() {
  python3 -c 'import sys, urllib.parse; sys.stdout.write(urllib.parse.quote(sys.argv[1], safe=""))' "$1"
}

# Emit one lecture filename per line; exit 1 (with a message) when missing/unavailable.
list_lectures() {
  require_reqs || return 1
  local url out code
  url="$REPO_API/contents/$LECTURES_DIR"
  out="$(curl -s -L --max-time 20 -H "Accept: application/vnd.github+json" -w '\n%{http_code}' "$url" || true)"
  code="${out##*$'\n'}"
  out="${out%$'\n'*}"
  if [[ "$code" == "200" ]]; then
    printf '%s\n' "$out" | python3 -c '
import json, sys
data = json.load(sys.stdin)
for e in data:
    if e.get("type") == "file":
        print(e["name"])
'
    return 0
  fi
  if [[ "$code" == "404" ]]; then
    say "fetch-lecture: $LECTURES_DIR/ does not exist yet in the Course repo (HTTP 404)."
    say "  Lectures must be published at https://github.com/CS3704-VT/Course/tree/main/$LECTURES_DIR"
  else
    say "fetch-lecture: lecture listing failed (HTTP $code) from $url."
  fi
  return 1
}

# Internal: download <filename> into <tmpdir>, extract text, set TEXTFILE. Silent on stdout.
fetch_extract() {
  local filename="$1" tmpdir="$2" encoded url pdf text code
  encoded="$(urlencode "$filename")"
  url="$RAW_BASE/$LECTURES_DIR/$encoded"
  pdf="$tmpdir/lecture.pdf"
  code="$(curl -s -L --max-time 60 -o "$pdf" -w '%{http_code}' "$url" || true)"
  case "$code" in
    404|403|410)
      say "fetch-lecture: no lecture found at $url (HTTP $code)."
      say "  Check the filename (see 'fetch-lecture.sh list') or that the file exists on main."
      return 1
      ;;
    200) ;;
    *)
      say "fetch-lecture: download failed for $url (HTTP $code)."
      return 1
      ;;
  esac
  text="$tmpdir/extracted.txt"
  if ! pdftotext -layout "$pdf" "$text" 2>/dev/null || [[ ! -s "$text" ]]; then
    say "fetch-lecture: no text layer could be extracted from $(basename "$filename")"
    say "  (the PDF may be image-only / scanned; pdftotext cannot read it)."
    return 1
  fi
  TEXTFILE="$text"
  return 0
}

dump_lecture() {
  local filename="$1" outfile="${2:-}" tmpdir
  require_reqs || return 1
  tmpdir="$(mktemp -d)"
  if ! fetch_extract "$filename" "$tmpdir"; then
    rm -rf "$tmpdir"
    return 1
  fi
  say "fetch-lecture: OK https://github.com/CS3704-VT/Course/tree/main/$LECTURES_DIR/$filename"
  say "fetch-lecture: extracted text: $TEXTFILE"
  if [[ -n "$outfile" ]]; then
    cp "$TEXTFILE" "$outfile"
    rm -rf "$tmpdir"
    say "fetch-lecture: wrote extract to $outfile"
  else
    cat "$TEXTFILE"
  fi
}

match_filename() {
  python3 - "$1" <<'PY'
import sys, re
concept = sys.argv[1]
names = [l.rstrip("\n") for l in sys.stdin if l.strip()]
base_tokens = set(re.findall(r"[a-z0-9]+", concept.lower())) or {concept.lower()}
scores = []
for n in names:
    # Drop trivial filename tokens (single letters / roman numerals like "I")
    # that otherwise cause spurious substring hits (e.g. "i" in "agile").
    nt = [tok for tok in re.findall(r"[a-z0-9]+", n.rsplit(".", 1)[0].lower()) if len(tok) >= 3]
    score = 0
    for t in base_tokens:
        for tok in nt:
            if t == tok:
                score += 4
            elif t in tok:
                score += 2
            elif tok in t:
                score += 1
    if score:
        scores.append((score, n))
scores.sort(key=lambda x: (-x[0], x[1].lower()))
for score, n in scores:
    print(f"{n}\tfilename-match:{score}")
if not scores:
    low = concept.lower()
    for n in names:
        if low in n.lower():
            print(f"{n}\tfilename-match:substring")
PY
}

match_text() {
  local concept="$1" namefile="$2" file count tmpdir
  while IFS= read -r file; do
    [[ -n "$file" ]] || continue
    tmpdir="$(mktemp -d)"
    if fetch_extract "$file" "$tmpdir"; then
      # guard grep's non-zero exit on zero matches so pipefail doesn't abort
      count="$( (grep -ioe "$concept" "$TEXTFILE" || true) | wc -l | tr -d ' ' )"
      if [[ -n "${count:-}" && "$count" -gt 0 ]]; then
        printf '%s\ttext-match:%s\n' "$file" "$count"
      fi
    fi
    rm -rf "$tmpdir"
  done < "$namefile"
}

match_concept() {
  local concept="$1" text_scan="${2:-}" names tmp outfile flag how
  require_reqs || return 1
  names="$(list_lectures || true)"
  if [[ -z "${names:-}" ]]; then
    say "fetch-lecture: cannot match \"$concept\" — no lectures are listed under $LECTURES_DIR/."
    return 1
  fi
  tmp="$(mktemp)"
  outfile="$(mktemp)"
  trap 'rm -f "$tmp" "$outfile"' RETURN
  printf '%s\n' "$names" > "$tmp"
  if [[ "$text_scan" == "--text" ]]; then
    flag="--text"
    match_text "$concept" "$tmp" > "$outfile"
  else
    flag=""
    match_filename "$concept" "$tmp" > "$outfile"
  fi
  if [[ -s "$outfile" ]]; then
    cat "$outfile"
    return 0
  fi
  how="filename"
  [[ "$flag" == "--text" ]] && how="filename or text"
  say "fetch-lecture: no lecture matched \"$concept\" (by $how); try local-blurb fallback."
  return 1
}

usage() {
  cat >&2 <<'EOF'
fetch-lecture.sh — fetch and extract text from CS3704 lecture PDFs.

Usage:
  fetch-lecture.sh list
  fetch-lecture.sh dump <filename> [<outfile>]
  fetch-lecture.sh match <concept>
  fetch-lecture.sh match --text <concept>
EOF
}

cmd="${1:-}"
case "$cmd" in
  list)
    list_lectures
    ;;
  dump)
    [[ $# -ge 2 ]] || { usage; exit 1; }
    dump_lecture "$2" "${3:-}"
    ;;
  match)
    [[ $# -ge 2 ]] || { usage; exit 1; }
    if [[ "$2" == "--text" ]]; then
      [[ $# -ge 3 ]] || { usage; exit 1; }
      match_concept "$3" "--text"
    else
      match_concept "$2"
    fi
    ;;
  -h|--help|"")
    usage
    [[ "$cmd" == "" ]] && exit 1 || exit 0
    ;;
  *)
    say "fetch-lecture: unknown command '$cmd'."
    usage
    exit 1
    ;;
esac
