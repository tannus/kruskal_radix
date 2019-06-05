#!/bin/bash

mkdir -p input
mkdir -p bin
mkdir -p graphs

rm graphs/*

for filename in input/*
do
  name=$(echo $filename | cut -c 7-)
  echo "creating graph for $name"
  ./bin/test_gen.exe $filename graphs/graph-$name
done
