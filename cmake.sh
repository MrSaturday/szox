#!/bin/bash
mkdir -p build
cd build
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
cmake -G "Eclipse CDT4 - Ninja" -D_ECLIPSE_VERSION=4.4 -DCMAKE_CXX_COMPILER_ARG1=-std=c++11 -D CMAKE_BUILD_TYPE=Debug ../source/
