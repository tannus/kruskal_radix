#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  delim=$(echo $filename | cut -c 14- | cut -c -3 )
  if [ "$delim" -eq 075 ]
  then
    echo "-----" >> results/time/merge7
    echo $name >> results/time/merge7
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0 && echo "-----" && echo "" ) &>> results/time/merge7

    echo "-----" >> results/time/radix7
    echo $name >> results/time/radix7
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0) &>> results/time/radix7
  fi
done
