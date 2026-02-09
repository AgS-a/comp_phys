#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

double ran()
{
        double n;
        for (int i = 0; i < 10000; i++) {
                n = n + ((2 * frand()) - 1);
        }
        return n;
}

int main()
{

        srand(time(NULL));

        FILE *fPtr;

        fPtr = fopen("omot.dat", "w");
        for (int i = 0; i < 10000; i++) {
                fprintf(fPtr, "%f\n", ran());
        }
        fclose(fPtr);

        FILE *fp;

        fp = fopen("omoh.dat", "w");
        for (int i = 0; i < 100000; i++) {
                fprintf(fp, "%f\n", ran());
        }
        fclose(fp);

        return 0;
}
