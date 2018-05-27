#!/bin/bash

if [ "$1" == "clean" ]
then
    echo "Cleaning the build folder"
    rm -rf build
else
    mkdir build >/dev/null 2>&1
    pushd build
    cmake ..
    cmake --build .
    popd
fi
