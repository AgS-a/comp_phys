#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand(time(NULL)); // Seeding the random number generator with current time 

// lower bound + (random number mod RANGE)

    int r = rand()%10;
    double ra = r/10;

    printf("random number:%f",ra);


    for (int i=0;i<10;i++) {
        int r = rand()%10;
        double ra = r/10;
        printf("random number:%f\n",ra);
    }

    return 0;
}
