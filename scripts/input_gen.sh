#!/bin/bash

mkdir -p input

for dimension in {005..100..5}
do
  for digits in {01..15}
  do
    echo "$dimension $digits 001000" > input/$dimension-$digits-001000
    echo "$dimension $digits 010000" > input/$dimension-$digits-010000
    echo "$dimension $digits 100000" > input/$dimension-$digits-100000
  done
done
