@echo off

set INST_DIR="%CD%\..\exec\"
set INST_DIR_UNIX=%INST_DIR:\=/%

set CUR_DIR=%CD%
IF NOT EXIST build mkdir build
cd build
set C1=cmake -G "MinGW Makefiles" ../ -DCMAKE_INSTALL_PREFIX=%INST_DIR_UNIX% -DCMAKE_BUILD_TYPE="Release"
set C2=mingw32-make install
set C3=cmake -G "MinGW Makefiles" ../ -DCMAKE_INSTALL_PREFIX=%INST_DIR_UNIX% -DCMAKE_BUILD_TYPE="Debug"
set C4=mingw32-make install
%C1% && %C2% && %C3% && %C4%
cd %CUR_DIR%
