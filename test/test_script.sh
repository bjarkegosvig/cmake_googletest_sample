#!/usr/bin/env bash
set -e
# Handle input argument -c
if [ $1 = "-c" ]; then
    echo "Clean build"
    rm -rf bld
    mkdir -p bld
    exit 0
fi

# generate make file using cmake
cmake -B bld .

# Build the test exe
cmake --build bld -j 6

# run the test
ctest -V --test-dir bld -j 6
