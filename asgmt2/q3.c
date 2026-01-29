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
        expx[i] = -log(frand())/2;
    }

    for(int i=0;i<n;i++) {
        fprintf(fptr,"%f\n",expx[i]);
    }
    fclose(fptr);

    double gauss[n];
    double x[n];

    double mean = 0;
    double std_dev = 2;
    double var = std_dev*std_dev;

    for(int i=0;i<n;i++) {
        //double rn = frand();
        //x[i] = rn;
        double rn = sqrt(-2*log(frand())) * cos(2*3.1415*frand()) * std_dev;
        gauss[i] = rn;
    }

    FILE*fpt;
    fpt = fopen("gau.dat","w");
    
    for(int i=0;i<n;i++) {
        fprintf(fpt,"%f\n",gauss[i]);
    }
    fclose(fpt);
/*
    FILE*fp;;
    fp = fopen("x.dat","w");

    for(int i=0;i<n;i++) {
        fprintf(fp,"%f\n",x[i]);
    }
    fclose(fp);
*/
    return 0;
}
