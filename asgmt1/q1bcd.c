#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand(time(NULL)); // Seeding the random number generator with current time 
    
    #define frand() ((double) rand() / (RAND_MAX+1.0))

    FILE*fPtr;

    fPtr = fopen("test_ran.dat","w");

    for (int i=0;i<10;i++) {
        fprintf(fPtr,"%f\n",frand());
    }
    
    fprintf(fPtr,"\nChanging seed and generating 10 new random numbers\n\n");

    srand(time(NULL)+1); // Seeding the random number generator with current time 

    for (int i=0;i<10;i++) {
        fprintf(fPtr,"%f\n",frand());
    }

    fclose(fPtr);

    return 0;
}
