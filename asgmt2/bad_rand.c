#include<stdio.h>
#include<stdlib.h>

int iran;

double bad_rnd()
{
        int m = 131072;
        int a = 1277;
        int ir;
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
        iran = 13337;

        for (int i = 0; i < 10000; i++) {
                fprintf(fptr, "%f\n", bad_rnd());
        }
        fclose(fptr);
        return 0;
}
