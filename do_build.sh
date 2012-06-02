#!/bin/bash
INST_DIR="${PWD}/../exec/"

CUR_DIR=${PWD}
mkdir build
cd build
cmake ../  -DCMAKE_INSTALL_PREFIX=${INST_DIR} -DCMAKE_BUILD_TYPE=Release
make install
cmake ../  -DCMAKE_INSTALL_PREFIX=${INST_DIR} -DCMAKE_BUILD_TYPE=Debug
make install
cd ${CUR_DIR}
