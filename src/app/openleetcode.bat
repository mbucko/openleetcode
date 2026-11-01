@echo off

rem Run inside the project's uv environment when uv is available, so the
rem dependencies from pyproject.toml are found however this script is launched.
where uv >nul 2>nul
if %errorlevel% equ 0 (
    uv run --quiet --project "%~dp0." python "%~dp0openleetcode.py" %*
) else (
    python "%~dp0openleetcode.py" %*
)
