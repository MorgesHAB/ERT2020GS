#!/bin/bash
# bash script pull and build program

cd build/

git reset --hard

git pull

make

echo "Execute the program with : ./build/ERT2020GS"