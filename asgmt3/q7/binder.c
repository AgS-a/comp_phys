#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double Binders(int L, double T)
{
        FILE *fPtr2;
        char name[64];
        sprintf(name,"mag_L%d_T%.2f.dat",L,T);
        fPtr2 = fopen(name,"r");
        
        double entry;
        int i=0;
        double sum_sq = 0;
        double sum_4 = 0;
        double sum = 0;

        while(fscanf(fPtr2, "%lf", &entry) != EOF){
                i += 1;
                entry = entry * L * L; // Total magnetization
                sum += entry;
                sum_sq += entry*entry;
                sum_4 += entry*entry*entry*entry;
        }
        fclose(fPtr2);

        double binder = 1 - ((sum_4/i)/(3*(sum_sq/i)*(sum_sq/i)));
        return binder;
}

int main()
{
        clock_t begin = clock();

        FILE *file1;
        file1 = fopen("binder_L26.dat","w");

        for(int i=0; i < 71; i++){
                fprintf(file1, "%.12f\n", Binders(26, 3.3+(0.02*i)));
        }
        fclose(file1);

        FILE *file2;
        file2 = fopen("binder_L30.dat","w");

        for(int i=0; i < 71; i++){
                fprintf(file2, "%.12f\n", Binders(30, 3.3+(0.02*i)));
        }
        fclose(file2);

        FILE *file3;
        file3 = fopen("binder_L36.dat","w");

        for(int i=0; i < 71; i++){
                fprintf(file3, "%.12f\n", Binders(36, 3.3+(0.02*i)));
        }
        fclose(file3);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

