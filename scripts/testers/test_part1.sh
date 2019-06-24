#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  delim=$(echo $filename | cut -c 14- | cut -c -3 )
  if [ "$delim" -gt 001 ] && [ "$delim" -lt 021 ]
  then
   ./bin/kruskal.exe $filename agm/agm-m-$name 0
    (head agm/agm-m-$name -n 1) &>> results/time/merge1

   ./bin/kruskal.exe $filename agm/agm-r-$name 1
    (head agm/agm-r-$name -n 1) &>> results/time/radix1
  fi
done
