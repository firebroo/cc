#!/bin/bash
if (( "$(uname)" == "Darwin" ))
then
    make -f Makefile.osx -j $1;
else
    make -f Makefile -j $1;
fi
