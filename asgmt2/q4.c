// integrate 4/(1+x**2) from 0 to 1 using trapezoidal method to determine pi
// actual value: 4tan-1(1)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double trap_int_pi(int n) {
    
    double x1 = 0;
    double x2;
    double y1;
    double y2;

    y1 = 4 / (1+(pow(x1,2)));

    double dx = 1/(double)n ;
    double buf = 0;
    double sum = 0;

    for(int i=0;i<=n;i++) {
        x2 = (i+1) * (1/(double)n);
        y2 = 4 / (1+(pow(x2,2)));

        buf = (dx * y1) + (0.5 * dx * (y2 - y1));
        sum = sum + buf;

        x1 = x2;
        y1 = y2;
    }
    
    return sum;
}

int main() {
    
    int no_bins[9] = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    for(int i=0;i<9;i++) {
        printf("10^%d: %0.20f\n",i+1,trap_int_pi(no_bins[i]));
    }

    return 0;
}
