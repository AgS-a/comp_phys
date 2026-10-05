#! /bin/bash

gcc q1h.c -o q1h
gcc q1h2.c -o q1h2
gcc q1i.c -o q1i
gcc q1kl.c -o q1kl

./q1h
./q1h2
./q1i
./q1kl

python plot_rand_walk.py
