#!/bin/bash

echo "CMake >>"

cd build
cmake ..

echo "make >>"
make

cd test

./runUnitTests --gtest_output="xml:testresults.xml"
