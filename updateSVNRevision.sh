#!/bin/sh
# Makes use of the local app svnwcrev (the linux equivalent of Tortoise SVN's 
# SubWCRev) to get the working copy's version number.
#
# If the app does not exist, copy the Version.in file to Version.h and modify as
# necessary.
./svnwcrev ${PWD} src/Version.in src/Version.h
