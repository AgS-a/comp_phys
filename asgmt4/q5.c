// d2x/dt2 = -sinx
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double dt = 0.01;

double f_x(double x)
{
        return -sin(x);
}

double RK4_solver(double initial_x, double initial_v)
{
        int n_iter = 5000

        FILE *RK;
        char name_RK[64];
        sprintf(name_RK,"RK4_sinx_x0%.4fv0%.4f.dat",initial_x,initial_v);
        RK = fopen(name_RK,"w");

        double k1,k2,k3,k4;
        double x_n = initial_x;

        for (int i=0;i<n_iter;i++) {

                k1 = f_y(y_n) * dt;
                k2 = f_y(y_n + (0.5 * k1)) * dt;
                k3 = f_y(y_n + (0.5 * k2)) * dt;
                k4 = f_y(y_n + k3) * dt;

                y_n = y_n + (k1 + (2 * k2) + (2 * k3) + k4)/6;
                fprintf(RK,"%f\n",y_n);
        }
        fclose(RK);
}

int main()
{
        clock_t begin = clock();
        
        double x_init = 0.1;
        double v_init = 1.9;
        RK_solver(x_init,y_init);

        x_init = 0;
        v_init = 1.99;
        RK_solver(x_init,v_init);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

