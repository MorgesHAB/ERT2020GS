#!/bin/bash
# bash script to compile the software
sudo rm -R build

mkdir build/ && cd build/

cmake ..

make

echo "Execute the program with : ./build/ERT2020GS"