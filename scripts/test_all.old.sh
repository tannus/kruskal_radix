#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

#rm results/time/*
rm agm/*

for filename in graphs/*
do
  name=$(echo $filename | cut -c 8-)
  
  echo "-----" >> results/time/merge
  echo $name >> results/time/merge
  (time ./bin/kruskal.exe $filename  agm/agm-$name 0 && echo "-----" && echo "" ) &>> results/time/merge

  echo "-----" >> results/time/radix
  echo $name >> results/time/radix
  (time ./bin/kruskal.exe $filename  agm/agm-$name 0) &>> results/time/radix
done
