#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand(time(NULL)); // Seeding the random number generator with current time 

// lower bound + (random number mod RANGE)

//    int r = rand()%10;
  //  double ra = r/10;

    #define frand() ((double) rand() / (RAND_MAX+1.0))

//    printf("random number:%f",frand());


    for (int i=0;i<10;i++) {
        printf("random number%d: %f\n",i,frand());
    }

    return 0;
}
