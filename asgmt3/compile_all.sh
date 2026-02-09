#! /bin/bash

for f in *.c; 
do 
    gcc -lm "$f" -o "${f%.c}" # %.c removes .c from the file name
done
