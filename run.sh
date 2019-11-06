# bash script to compile the software
rm -R build

mkdir build/ && cd build/

cmake ..

make

@echo "Execute the program with : ./build/ERT2020GS"