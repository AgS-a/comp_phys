#include<stdio.h>
#include<stdlib.h>

int main() {
    srand(10);
    #define frand() ((double) rand() / (RAND_MAX+1.0))

    FILE*fptr;

    fptr = fopen("random.dat","w");

    for (int i=0;i<10000;i++){
        fprintf(fptr,"%f\n",frand());
    }
    
    fclose(fptr);

    return 0;
}
