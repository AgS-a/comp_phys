// Buffon's needle experiment

#include<stdio.h>
#include<stdlib.h>

int main() {
    
    int n = 100000;
    double x[n+2]; 
    x[0] = 0;
    int D = 1000000;
    double d = (double)D/(double)n;

    for(int i=0; i<n+1; i++) {
        x[i+1] = x[i] + d;
        printf("%f\n",x[i]);
    }

    return 0;
}
