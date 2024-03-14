@echo off
setlocal

pushd "%~dp0"

call :run_exe
popd
exit /b

:run_exe
for /D %%D in (OpenLeetCodeUI) do (
    if exist "%%D\OpenLeetCodeUI.exe" (
        echo Running OpenLeetCodeUI.exe in %%D
        start "" "%%D\OpenLeetCodeUI.exe" --problem_builds_dir=%~dp0
        exit /b
    )
)
echo No OpenLeetCodeUI.exe found in %~dp0OpenLeetCodeUI directory.
exit /b