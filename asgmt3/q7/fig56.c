#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double Cv(int L, double T)
{
        FILE *fPtr1;
        char name[64];
        sprintf(name,"E_L%d_T%.2f.dat",L,T);
        fPtr1 = fopen(name,"r");
        
        double entry;
        int i=0;
        double sum = 0;

        while(fscanf(fPtr1, "%lf", &entry) != EOF){
                i += 1;
                sum += entry;
        }
        fclose(fPtr1);

        double cv = sum/i;
        return cv;
}

double Cai(int L, double T)
{
        FILE *fPtr2;
        char name[64];
        sprintf(name,"mag_L%d_T%.2f.dat",L,T);
        fPtr2 = fopen(name,"r");
        
        double entry;
        int i=0;
        double sum = 0;

        while(fscanf(fPtr2, "%lf", &entry) != EOF){
                i += 1;
                sum += fabs(entry);
        }
        fclose(fPtr2);

        double cai = sum/i;
        return cai;
}

int main()
{
        clock_t begin = clock();
        
        FILE *file1;
        FILE *file2;
        file1 = fopen("cv_L26_m.dat","w");
        file2 = fopen("cai_L26_m.dat","w");

        for(int i=0; i < 71; i++){
                fprintf(file1, "%.12f\n", Cv(26, 3.3+(0.02*i)));
                fprintf(file2, "%.12f\n", Cai(26, 3.3+(0.02*i)));
        }
        fclose(file1);
        fclose(file2);

        FILE *file3;
        FILE *file4;
        file3 = fopen("cv_L30_m.dat","w");
        file4 = fopen("cai_L30_m.dat","w");

        for(int i=0; i < 71; i++){
                fprintf(file3, "%.12f\n", Cv(30, 3.3+(0.02*i)));
                fprintf(file4, "%.12f\n", Cai(30, 3.3+(0.02*i)));
        }
        fclose(file3);
        fclose(file4);

        FILE *file5;
        FILE *file6;
        file5 = fopen("cv_L36_m.dat","w");
        file6 = fopen("cai_L36_m.dat","w");

        for(int i=0; i < 71; i++){
                fprintf(file5, "%.12f\n", Cv(36, 3.3+(0.02*i)));
                fprintf(file6, "%.12f\n", Cai(36, 3.3+(0.02*i)));
        }
        fclose(file5);
        fclose(file6);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

