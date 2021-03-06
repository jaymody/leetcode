#!/bin/bash

if [ $# -lt 6 ]; then
    echo "Invalid Input: must provide [number][name][url][language][difficulty] and at least one [tag]"
    exit 1
fi

if [ $4 = 'python' ]; then
    cd python
    printf -- "# $1
# $2
# $3
# $4
# $5
# 
# 
# ${*:6}
" > "$1 - $2.py"
elif [ $4 = 'c++' ]; then
    cd c++
    printf -- "// $1
// $2
// $3
// $4
// $5
// 
// 
// ${*:6}
" > "$1 - $2.cpp"
elif [ $4 = 'java' ]; then
    cd java
    printf -- "// $1
// $2
// $3
// $4
// $5
// 
// 
// ${*:6}
" > "$1 - $2.java"
else
    echo Invalid language input: $4
    exit 1
fi