@echo off
echo Creates the build directories on windows, removing all existing build directories.
echo Current dir: %CD%

rd /s /q build\WindowsRelease
rd /s /q build\WindowsDebug

IF NOT EXIST build mkdir build
cd build
mkdir WindowsRelease
mkdir WindowsDebug
