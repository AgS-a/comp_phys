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

        FILE *x_file;
        char name_x[64];
        sprintf(name_x,"sinx_x0%.4f.dat",initial_x);
        x_file = fopen(name_x,"w");

        FILE *v_file;
        char name_v[64];
        sprintf(name_v,"sinx_v0%.4f.dat",initial_v);
        v_file = fopen(name_v,"w");

        double k1_v,k2_v,k3_v,k4_v;
        double k1_x,k2_x,k3_x,k4_x;
        double x_n = initial_x;
        double v_n = initial_v;
        
        double v_np1 = 0;

        for (int i=0;i<n_iter;i++) {

                k1_v = f_x(x_n) * dt;
                k2_v = f_x(x_n + (0.5 * k1_v)) * dt;
                k3_v = f_x(x_n + (0.5 * k2_v)) * dt;
                k4_v = f_x(x_n + k3_v) * dt;

                v_np1 = v_n + (k1_v + (2 * k2_v) + (2 * k3_v) + k4_v)/6;

                k1_x = v_n * dt;
                k2_x = (v_n + (0.5 * k1_x)) * dt;
                k3_x = (v_n + (0.5 * k2_x)) * dt;
                k4_x = (v_n + k3_x) * dt;

                x_n = x_n + (k1_x + (2 * k2_x) + (2 * k3_x) + k4_x)/6;

                fprintf(x_file,"%f\n",x_n);
                fprintf(v_file,"%f\n",v_np1);
        }
        fclose(x_file);
        fclose(v_file);
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

