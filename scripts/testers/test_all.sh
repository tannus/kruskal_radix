#!/bin/bash

mkdir -p graphs
mkdir -p agm
mkdir -p results/time
mkdir -p results/time

rm results/time/*
rm agm/*

./scripts/testers/test_part1.sh &
./scripts/testers/test_part2.sh &
./scripts/testers/test_part3.sh &
./scripts/testers/test_part4.sh &
./scripts/testers/test_part5.sh &
./scripts/testers/test_part6.sh &
./scripts/testers/test_part7.sh &
./scripts/testers/test_part8.sh &
./scripts/testers/test_part9.sh &
./scripts/testers/test_partA.sh &
./scripts/testers/test_partB.sh &
./scripts/testers/test_partC.sh &
