#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

rm results/time/*
rm agm/*

./scripts/test_part1.sh &
./scripts/test_part2.sh &
./scripts/test_part3.sh &
./scripts/test_part4.sh &
./scripts/test_part5.sh &
./scripts/test_part6.sh &
./scripts/test_part7.sh &
./scripts/test_part8.sh &
./scripts/test_part9.sh &
./scripts/test_part10.sh &
./scripts/test_part11.sh &
./scripts/test_part12.sh &
