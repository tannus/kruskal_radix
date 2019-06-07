#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  delim=$(echo $filename | cut -c 14- | cut -c -3 )
  if [ "$delim" -gt 051 ] && [ "$delim" -lt 061 ]
  then
    echo "-----" >> results/time/merge4
    echo $name >> results/time/merge4
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0 && echo "-----" && echo "" ) &>> results/time/merge4

    echo "-----" >> results/time/radix4
    echo $name >> results/time/radix4
    (time ./bin/kruskal.exe $filename  agm/agm-$name 0) &>> results/time/radix4
  fi
done
