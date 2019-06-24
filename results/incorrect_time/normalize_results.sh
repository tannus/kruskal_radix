#!/bin/bash

FOLDER=$1

mkdir -p treated

for filename in $FOLDER/*
do
  alg=$(echo $filename | cut -c -7 | cut -c 7-)
  if [ "$alg" == "m" ]
  then
    (sed '/^\($\|g\|u\|s\|-\)/ d' $filename | cut -c 6-) &>> treated/merge_final-$FOLDER
  fi
  if [ "$alg" == "r" ]
  then
    (sed '/^\($\|g\|u\|s\|-\)/ d' $filename | cut -c 6-) &>> treated/radix_final-$FOLDER
  fi

done
