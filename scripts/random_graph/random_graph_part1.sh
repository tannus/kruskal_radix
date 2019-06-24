#!/bin/bash

mkdir -p input
mkdir -p bin
mkdir -p graphs


for filename in input/*
do
  name=$(echo $filename | cut -c 7-)
  delim=$(echo $filename | cut -c 7- | cut -c -3)
  if [ "$delim" -gt 001 ] && [ "$delim" -lt 021 ]
  then
    echo "creating graph for $name"
    ./bin/test_gen.exe $filename graphs/graph-$name
  fi
done
