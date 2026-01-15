#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    #define frand() ((double) rand() / (RAND_MAX+1.0))

    double x[10000];
    for(int i=0;i<10000;i++) {
        x[i] = frand();
    }
    double expx[10000];
    for(int i=0;i<10000;i++) {
        expx[i] = exp((-2)*x[i]);
    }
    for(int i=0;i<10000;i++) {
        printf("%f\n",expx[i]);
    }

    return 0;
}
