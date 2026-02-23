// Code to sample random numbers from exponential and normal distributions
// Writing to files "exp.dat" and "gau.dat"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

int main()
{

        srand(time(NULL));

        int n = 100000;

        double expx[n];
        
        // Generating random numbers following exponential distribution
        // from random numbers following uniform distribution using
        // Inverse method
        for (int i = 0; i < n; i++) {
                expx[i] = -log(frand()) / 2;
        }

        FILE *fptr;
        fptr = fopen("exp.dat", "w");

        for (int i = 0; i < n; i++) {
                fprintf(fptr, "%f\n", expx[i]);
        }
        fclose(fptr);

        double gauss[n];

        double mean = 0;
        double std_dev = 2;
        double var = std_dev * std_dev;

        // Generating random numbers following normal distribution
        // from random numbers following uniform distribution using
        // Box-Muller method
        for (int i = 0; i < n; i++) {
                double rn =
                    sqrt(-2 * log(frand())) * cos(2 * 3.1415 * frand()) *
                    std_dev;
                gauss[i] = rn;
        }

        FILE *fpt;
        fpt = fopen("gau.dat", "w");

        for (int i = 0; i < n; i++) {
                fprintf(fpt, "%f\n", gauss[i]);
        }
        fclose(fpt);

        return 0;
}
