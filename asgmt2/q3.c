#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    #define frand() ((double) rand() / (RAND_MAX+1.0))
    
    FILE*fptr;
    fptr = fopen("exp.dat","w");
    
    int n = 10000;

    double expx[n];
    for(int i=0;i<n;i++) {
        expx[i] = exp( ( (-2) * frand() ) );
    }

    double gauss[n];

    double mean = 0;
    double std_dev = 2;

    for(int i=0;i<n;i++) {
        double rn = frand();
        rn = pow((rn-mean),2);
        rn = rn/((-2) * std_dev);
        rn = pow(exp(1),rn);

        printf("%f\n",rn);
    }

    for(int i=0;i<n;i++) {
        fprintf(fptr,"%f\n",expx[i]);
    }
    
    fclose(fptr);

    return 0;
}
