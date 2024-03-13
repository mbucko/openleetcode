#!/bin/bash

run_exe() {
    for D in OpenLeetCodeUI-*-*; do
        if [ -f "${D}/OpenLeetCodeUI.exe" ]; then
            echo "Running OpenLeetCodeUI.exe in ${D}"
            "${D}/OpenLeetCodeUI.exe" --problem_builds_dir=$(pwd)
            exit
        fi
    done
    echo "No OpenLeetCodeUI.exe found in $(pwd)/OpenLeetCodeUI-*-* directory."
}

pushd "$(dirname "$0")" > /dev/null
run_exe
popd > /dev/null