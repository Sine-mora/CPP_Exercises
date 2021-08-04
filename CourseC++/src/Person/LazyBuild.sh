#!/bin/bash

ExeName=$1
Empty=""

if [ $ExeName == $Empty ]
then
    ExeName="exe"
fi

echo $ExeName

LIST="*.h *.cpp"
CompiledFiles=""
for I in $LIST
do
    CompiledFiles="$CompiledFiles $I"
    echo Compiled $I
done
g++ $CompiledFiles -o $ExeName
