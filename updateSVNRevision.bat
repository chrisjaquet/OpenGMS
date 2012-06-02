@echo off
rem Makes use of Tortoise SVN's SubWCRev to get the working copy's version 
rem number.
rem If the app is not available, copy the Version.in file to Version.h and 
rem modify as necessary.
SubWCRev %CD% src/Version.in src/Version.h
