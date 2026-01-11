#include<stdio.h>
#include<stdlib.h>

float sum_rand() {
    
    float ran[10000];
    float x;
    float n;
    float sum = 0;
    
    for(int i=0;i<10000;i++) {
        
        /*while(x=0.5) {
            x = frand();
        } */

        x =  (rand()%2) + 1;
        
        if(x == 1) {
            n = 1;
        } else {
            n = -1;
        }
        sum = sum + n;
    }
/*
    for(int i=0;i<10000;i++) {
        n = n + ran[i];
    }*/
    return sum;
}

int main() {

    srand(31);
    FILE*fPtr;
    FILE*fp;

    fPtr = fopen("sum_ran_walk.dat","w");
    
    for(int i=0;i<10000;i++) {
        fprintf(fPtr,"%f\n",sum_rand());
    }
    fclose(fPtr);

    fp = fopen("q1k.dat","w");

    for(int i=0;i<100000;i++) {
        fprintf(fp,"%f\n",sum_rand());
    }

    fclose(fp);

    return 0;
}
