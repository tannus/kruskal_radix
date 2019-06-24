#!/bin/bash

FOLDER=$1

mkdir -p treated

for filename in $FOLDER/*
do
  alg=$(echo $filename | cut -c -7 | cut -c 7-)
  extra=$(echo $filename | cut -c 13)
  if [ "$alg" == "m" ]
  then
    if [ "$extra" == "0" ]
    then
      mv $filename $FOLDER/mergeA
    fi
    if [ "$extra" == "1" ]
    then
      mv $filename $FOLDER/mergeB
    fi
    if [ "$extra" == "2" ]
    then
      mv $filename $FOLDER/mergeC
    fi
  fi
  if [ "$alg" == "r" ]
  then
    if [ "$extra" == "0" ]
    then
      mv $filename $FOLDER/radixA
    fi
    if [ "$extra" == "1" ]
    then
      mv $filename $FOLDER/radixB
    fi
    if [ "$extra" == "2" ]
    then
      mv $filename $FOLDER/radixC
    fi
  fi

done
