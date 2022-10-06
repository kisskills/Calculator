#!/bin/bash

mkdir -p ./docs
cd ./docs
doxygen -g Doxyfile
doxygen Doxyfile