#!/bin/bash

cd "build"

rm -rf *
cmake ..
cmake --build .

testPath="data/$1"

echo
echo "Running : $testPath"
echo

./LogAggregator "$testPath"


cd ..