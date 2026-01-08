#include<stdio.h>
#include<stdlib.h>

int main() {
    
    #define frand() ((double) rand() / (RAND_MAX+1.0))

    FILE*fPtr;

    fPtr = fopen("test_ran_10_seeds.dat","w");

    for (int i=0;i<10;i++) {
        srand(i);
        for (int j=0;j<10;j++) {
            fprintf(fPtr,"%0.10f    ",frand());
        }

        fprintf(fPtr,"\n");
    }
    
    fclose(fPtr);

    return 0;
}
