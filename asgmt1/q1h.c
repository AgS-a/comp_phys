#include<stdio.h>
#include<stdlib.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

double avg_ran() {
    double n;
    for (int i=0;i<10000;i++) {
        n = n + frand();
    }
    return n;
}

int main() {
    
    srand(31415);

    FILE*fPtr;

    fPtr = fopen("dist_sum_10k.dat","w");

    for(int i=0;i<10000;i++) {
        fprintf(fPtr,"%f\n",avg_ran());
    }

    fclose(fPtr);

    return 0;
}

