#!/bin/bash

run_exe() {
    if [[ "$(uname)" == "Darwin" ]]; then
        app_path="./OpenLeetCodeUI/OpenLeetCodeUI.app/Contents/MacOS/OpenLeetCodeUI"
        echo "app_path: $app_path"
        if [ -x "$app_path" ]; then
            echo "Running OpenLeetCodeUI"
            "$app_path" --problem_builds_dir="$(pwd)"
            exit
        else
            echo "Error: OpenLeetCodeUI executable not found or not executable at $app_path"
        fi
    elif [[ "$(uname)" == "Linux" ]]; then
        for D in OpenLeetCodeUI; do
            if [ -f "${D}/OpenLeetCodeUI" ]; then
                echo "Running OpenLeetCodeUI in ${D}"
                "${D}/OpenLeetCodeUI.app" --problem_builds_dir=$(pwd)
                exit
            fi
        done
        echo "No OpenLeetCodeUI found in $(pwd)/OpenLeetCodeUI directory."
    else
        echo "Only Mac and Linux are supported."
    fi
}

pushd "$(dirname "$0")" > /dev/null
run_exe
popd > /dev/null
