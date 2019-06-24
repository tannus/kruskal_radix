#!/bin/bash

FOLDER=$1

for filename in $FOLDER/*
do
  alg=$(echo $filename | cut -c -7 | cut -c 7-)
  if [ "$alg" == "m" ]
  then
    (cat $filename) &>> merge_final
  fi
  if [ "$alg" == "r" ]
  then
    (cat $filename) &>> radix_final
  fi
done
