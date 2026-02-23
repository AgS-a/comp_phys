// Buffon's needle experiment:
// A needle of length l is thrown on a floor with parallel lines separated
// by lenght d. Find probability that the needle intersects the line.
// value of pi can be determined using the probability and the analytical 
// expression for the probability.
//
// "actual value" of pi taken for comparison: 4tan-1(1)
// 
// error in pi(by varying no of throws) is written to the file "buffon.dat"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

double l = 7;                   // length of the needle
int d = 11;                     // separation between lines
int D = 1000000;                // number of lines

// Function to randomly place the needle
// Placed by choosing random center and random angle from the vertical
double pos_det(double ned_pos[])
{
        double center = frand() * D;    // random x coordinate for center
        double theta = frand() * (4 * atan(1)); // random angle with vertical
        // PROBLEM: code to find pi is using pi to generate random angle

        ned_pos[0] = -((l * sin(theta)) / 2) + center; // x1 of the needle
        ned_pos[1] = ((l * sin(theta)) / 2) + center; // x2 of the needle
}

// Function to determine pi from the probability of intersection obtained
double pi_est(double probability)
{
        double pi = (2 * l) / (d * probability);
        return pi;
}

int touch_check(double x1, double x2)
{
        int x1_ceil = ceil(x1);
        int x2_floor = floor(x2);
        int size = ceil(x2_floor - x1_ceil) + 1;
        int list[size];
        int i = 0;
        int check_var = x1_ceil;
        while (check_var <= x2_floor) {
                list[i] = check_var;
                check_var++;
                i++;
        }
        int ret = 0;
        for (int i = 0; i < (x2_floor - x1_ceil + 1); i++) {
                int reminder = list[i] % d;
                if (reminder == 0) {
                        ret = 1;
                }
        }
        return ret;
}

int main()
{
        srand(time(NULL));

        double ned_pos[2];
        int check;
        int no_tries[8] =
            {1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8};

        FILE *fptr;
        fptr = fopen("buffon.dat", "w");

        for (int j = 0; j < 8; j++) {
                int sum = 0;
                for (int i = 0; i < no_tries[j]; i++) {
                        pos_det(ned_pos);
                        check = touch_check(ned_pos[0], ned_pos[1]);
                        sum += check;
                }
                double prob = sum / (double)no_tries[j];
                double err = fabs(pi_est(prob) - 4 * atan(1));

                printf("value of pi(on throwing %9d times): %f\n", no_tries[j], pi_est(prob));
                printf("error in value of pi: %f\n", err);
                fprintf(fptr, "%f\n", err);
        }

        fclose(fptr);
        return 0;
}
