#!/bin/sh
#########################################################################
# This is a script to build a tutorial application
#########################################################################

### Confirm the file 'source' exists
if [ ! -d ./source ] ; then
  echo "Error: You cannot execute this script in the current directory!"
  exit 1
fi

### Clean up work directories
if [ -d build ] ; then
  rm -r build
fi

if [ -d bin ] ; then
  rm -r bin
fi

### Build using cmake
mkdir build
cd build
cmake ../source
make
make install

