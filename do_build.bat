@echo off
set CUR_DIR=%CD%

REM Customise these
set INST_DIR="%CD%\exec"
set BUILD_DIR=%CUR_DIR%\build\
set SRC_DIR=%CUR_DIR%\

set GENERATOR="MinGW Makefiles"
REM set GENERATOR="CodeBlocks - MinGW Makefiles"
REM set GENERATOR="Visual Studio 10"
REM set GENERATOR="Eclipse CDT4 - MinGW Makefiles"

echo Generator is %GENERATOR%

set INST_DIR_UNIX=%INST_DIR:\=/%
set SRC_DIR_UNIX=%SRC_DIR:\=/%

IF NOT EXIST %BUILD_DIR% mkdir %BUILD_DIR%
set C1C0=cd %BUILD_DIR%
set C1C1=mkdir Debug
set C1C2=cd Debug
set C1C3=cmake -G %GENERATOR% %SRC_DIR_UNIX% -DBUILD_DONT_MODIFY_INSTALL_PREFIX=ON -DCMAKE_INSTALL_PREFIX=%INST_DIR_UNIX% -DCMAKE_BUILD_TYPE="Debug"
set C1C4=mingw32-make
set C1C5=mingw32-make install
set C1C6=cd %BUILD_DIR%
set C1C7=mkdir Release
set C1C8=cd Release
set C1C9=cmake -G %GENERATOR% %SRC_DIR_UNIX% -DBUILD_DONT_MODIFY_INSTALL_PREFIX=ON -DCMAKE_INSTALL_PREFIX=%INST_DIR_UNIX% -DCMAKE_BUILD_TYPE="Release"
set C1C10=mingw32-make install
REM Runs the actual commands successfully, stopping on failure.
%C1C0% && %C1C1% && %C1C2% && %C1C3% && %C1C4% && %C1C5% && %C1C6% && %C1C7% && %C1C8% && %C1C9% && %C1C10%
cd %CUR_DIR%

