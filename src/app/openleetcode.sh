#!/bin/bash

# Run inside the project's uv environment when uv is available, so the
# dependencies from pyproject.toml are found however this script is launched.
DIR="$(dirname "$0")"
if command -v uv > /dev/null 2>&1; then
    exec uv run --quiet --project "$DIR" python "$DIR/openleetcode.py" "$@"
fi
exec python3 "$DIR/openleetcode.py" "$@"
