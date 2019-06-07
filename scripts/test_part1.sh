#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  delim=$(echo $filename | cut -c 14- | cut -c -3 )
  if [ "$delim" -gt 001 ] && [ "$delim" -lt 021 ]
  then
    echo "-----" >> results/time/merge1
    echo $name >> results/time/merge1
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0 && echo "-----" && echo "" ) &>> results/time/merge1

    echo "-----" >> results/time/radix1
    echo $name >> results/time/radix1
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0) &>> results/time/radix1
  fi
done
