#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double dx = 0.01;
double y_init = 1e-8;
double x_end = 1.55;
double y_end = 2; //to be removed

double f_y(double y)
{
        double fofy = (y * y) + 1;
        //fofy = 1/sin(y);
        return fofy;
}

double euler()
{
        FILE *eul;
        char name_eul[64];
        sprintf(name_eul,"eul%d.dat",1);
        eul = fopen(name_eul,"w");

        double y_n = y_init;
        double x_track = 0;
        while (x_track < x_end) {
                y_n = y_n + (f_y(y_n) * dx);
                fprintf(eul,"%f\n",y_n);
                x_track += dx;
        }
        fclose(eul);
}

double modified_euler() // Heun's method //just half the grid size?
{
        FILE *mod_eul;
        char name_mod_eul[64];
        mod_eul = fopen(name_mod_eul,"w");

        double y_n = y_init;
        while (y_n < y_end) {
                fprintf(mod_eul,"%f",y_n);
                // Heun's method
        }
        fclose(mod_eul);
}

double improved_euler()
{
        FILE *imp_eul;
        char name_imp_eul[64];
        imp_eul = fopen(name_imp_eul,"w");

        double y_n = y_init;
        while (y_n < y_end){
                // Improved euler method
                fprintf(imp_eul,"%f",y_n);
        }
        fclose(imp_eul);
}

double RK4()
{
        FILE *RK;
        char name_RK[64];
        RK = fopen(name_RK,"w");

        double k1,k2,k3,k4;
        //double y_n_minus_1;
        double y_n = y_init;

        while (y_n < y_end) {
                //y_n_minus_1 = y_n;

                k1 = f_y(y_n) * dx;
                k2 = f_y(y_n + (0.5 * k1)) * dx;
                k3 = f_y(y_n + (0.5 * k2)) * dx;
                k4 = f_y(y_n + k3) * dx;

                y_n = y_n + (k1 + (2 * k2) + (2 * k3) + k4)/6;
                fprintf(RK,"%f",y_n);
        }
        fclose(RK);
}

int main()
{
        clock_t begin = clock();
        
        euler();

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

