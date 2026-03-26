#! /bin/bash

gcc band.c -o band -fopenmp -lm -lopenblas
