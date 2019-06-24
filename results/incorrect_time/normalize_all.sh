#!/bin/bash

mkdir -p treated

./normalize_results.sh time1
./normalize_results.sh time2
./normalize_results.sh time3
./normalize_results.sh time4
./normalize_results.sh time5
./normalize_results.sh time6
./normalize_results.sh time7
./normalize_results.sh time8
./normalize_results.sh time9
./normalize_results.sh timeA

for filename in treated/*
do
  first=$(echo $filename | cut -c -9 | tail -c 2)
  last=$(echo $filename | tail -c 2)
  echo $filename $first $last
  if [ "$first" == "m" ] || [ "$first" == "r" ]
  then
    (sed 's/,/./' $filename) &>> treated/$first$last
  fi
done


rm treated/*time*
