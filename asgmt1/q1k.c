#include<stdio.h>
#include<stdlib.h>

float sum_rand() {
    
    float ran[100000];
    float x;
    float n;
    float sum = 0;
    
    for(int i=0;i<100000;i++) {
        
        x =  (rand()%2) + 1;
        
        if(x == 1) {
            n = 1;
        } else {
            n = -1;
        }
        sum = sum + n;
    }
    return sum;

}

int main() {

    srand(31);
    FILE*fPtr;
    fPtr = fopen("q1l.dat","w");
    
    for(int i=0;i<100000;i++) {
        fprintf(fPtr,"%f\n",sum_rand());
    }
    fclose(fPtr);
    return 0;
}

