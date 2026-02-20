// Code to generate 10000 "good" random numbers between 0 and 1
// Writing to file "random.dat"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

int main()
{
        srand(time(NULL));

        FILE *fptr;

        fptr = fopen("random.dat", "w");

        for (int i = 0; i < 10000; i++) {
                fprintf(fptr, "%f\n", frand());
        }

        fclose(fptr);

        return 0;
}
