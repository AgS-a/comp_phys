#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main() {

    FILE*fPtr;

    fPtr = fopen("test_ran.dat","a");

    #define frand() ((double) rand() / (RAND_MAX+1.0))
    srand(time(NULL));

    double hred;
    double tthous;
    double mil;

    for (int i=0;i<100;i++) {
        hred = hred + frand();    
    }

    for (int i=0;i<10000;i++) {
        tthous = tthous + frand();
    }

    for (int i=0;i<1000000;i++) {
        mil = mil + frand();
    }
    
    double avg_hred;
    double avg_tthous;
    double avg_mil;

    avg_hred = hred/100;
    avg_tthous = tthous/10000;
    avg_mil = mil/1000000;
/*
    printf("%f\n",hred);
    printf("%f\n",tthous);
    printf("%f\n",mil);
*/
    fprintf(fPtr,"\nAverage of 100 numbers:\n%f\n",avg_hred);
    fprintf(fPtr,"\nAverage of 10000 numbers:\n%f\n",avg_tthous);
    fprintf(fPtr,"\nAverage of 1000000 numbers:\n%f\n",avg_mil);
    
    double diff_hred;
    double diff_tthous;
    double diff_mil;
    double pf = 0.5;

    diff_hred = fabs(avg_hred-pf);
    diff_tthous = fabs(avg_tthous-pf);
    diff_mil = fabs(avg_mil-pf);
    
    fprintf(fPtr, "\ndifference between avg and 0.5(100):\n%f\n",diff_hred);
    fprintf(fPtr, "\ndifference between avg and 0.5(10000):\n%f\n",diff_tthous);
    fprintf(fPtr, "\ndifference between avg and 0.5(1000000):\n%f\n",diff_mil);
    fclose(fPtr);
// as we increase number of random numbers, avg is getting closer to 0.5
    return 0;
}
