// Code to integrate 4/(1+x**2) from 0 to 1 using trapezoidal method to determine pi
// "actual value" of pi taken for comparison: 4tan-1(1)
//
// Difference in actual value and the integrated value(with varying sizes of dx)
// is written to the file "pi_diff.dat"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Implementing trapezoidal integration scheme for this function
double trap_int_pi(double n)
{
        double x1 = 0;
        double x2;
        double y1;
        double y2;

        y1 = 4 / (1 + (pow(x1, 2)));

        double dx = 1 / n;
        double buf = 0;
        double sum = 0;

        for (int i = 0; i < n; i++) {
                x2 = (i + 1) * (1 / n);
                y2 = 4 / (1 + (pow(x2, 2)));

                buf = (dx * y1) + (0.5 * dx * (y2 - y1));
                sum = sum + buf;

                x1 = x2;
                y1 = y2;
        }

        return sum;
}

int main()
{
        FILE *fptr;
        fptr = fopen("pi_diff.dat", "w");

        double no_bins[9] =
            {1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9}; // Size of 1/dx
        double diff;

        // Calculating absolute error for a given dx and writing it to the file
        for (int i = 0; i < 9; i++) {
                double pi_calc = trap_int_pi(no_bins[i]);
                diff = fabs(pi_calc - (4 * atan(1)));
                fprintf(fptr, "%0.20f\n", diff);
                printf("10^%d: %0.20f\n", i + 1, pi_calc);
        }
        fclose(fptr);

        return 0;
}
