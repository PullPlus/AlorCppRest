#!/bin/bash
cd AlorCppRest
pwd
chmod +x build.sh
sh -c ./build.sh
cd ../
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
