#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    
    printf("Computational Physics");
    
    int one = 1;
    one = one * one;
    printf("\n%d\n",one);

    srand(time(0));
    int min = 1;
    int max = 6;
    int random_number = (rand() % (max - min + 1)) + min;
    printf("Random number between %d and %d: %d\n", min, max, random_number);
    return 0;

}
