#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  delim=$(echo $filename | cut -c 14- | cut -c -3 )
  if [ "$delim" -eq 080 ]
  then
    echo "-----" >> results/time/merge8
    echo $name >> results/time/merge8
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0 && echo "-----" && echo "" ) &>> results/time/merge8

    echo "-----" >> results/time/radix8
    echo $name >> results/time/radix8
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0) &>> results/time/radix8
  fi
done
