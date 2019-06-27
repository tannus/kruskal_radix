#!/bin/bash

mkdir -p ../bin
mkdir -p ../graphs

rm ../graphs/*

./../bin/same_graph.exe 1000 &
./../bin/same_graph.exe 10000 &
