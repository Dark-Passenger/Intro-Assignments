#!/bin/bash

cd $1
find . -name CVS -exec rm -rf {} \;
