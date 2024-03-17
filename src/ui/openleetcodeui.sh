#!/bin/bash

run_exe() {
    for D in OpenLeetCodeUI; do
        if [ -f "${D}/OpenLeetCodeUI" ]; then
            echo "Running OpenLeetCodeUI in ${D}"
            "${D}/OpenLeetCodeUI" --problem_builds_dir=$(pwd)
            exit
        fi
    done
    echo "No OpenLeetCodeUI found in $(pwd)/OpenLeetCodeUI directory."
}

pushd "$(dirname "$0")" > /dev/null
run_exe
popd > /dev/null
