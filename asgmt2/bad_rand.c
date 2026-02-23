// Code to generate a set of random numbers between 0 and 1 
// and write it to "bad_random_numbers.dat"
//
// Translated the function from "bad_rnd.f90"

#include<stdio.h>
#include<stdlib.h>

int iran; 

double bad_rnd()
{
        int m = 131072; // Constant for the random number generator
        int a = 1277; // Constant for the random number generator
        double bad_rn;

        iran = a * iran;
        iran = iran % m;

        bad_rn = iran / (double)m;

        return bad_rn;
}

int main()
{

        FILE *fptr;
        fptr = fopen("bad_random_numbers.dat", "w");
        iran = 13337; // Seeding

        for (int i = 0; i < 10000; i++) {
                fprintf(fptr, "%f\n", bad_rnd());
        }
        fclose(fptr);
        return 0;
}
