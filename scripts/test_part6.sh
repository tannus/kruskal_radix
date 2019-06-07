#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  delim=$(echo $filename | cut -c 14- | cut -c -3 )
  if [ "$delim" -eq 070 ]
  then
    echo "-----" >> results/time/merge6
    echo $name >> results/time/merge6
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0 && echo "-----" && echo "" ) &>> results/time/merge6

    echo "-----" >> results/time/radix6
    echo $name >> results/time/radix6
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0) &>> results/time/radix6
  fi
done
