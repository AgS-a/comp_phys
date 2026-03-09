#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double dx = 0.01;
double y_init = 0;
double x_end = 1.55;

double f_y(double y)
{
        double fofy = (y * y) + 1;
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
        while (x_track <= x_end) {
                y_n = y_n + (f_y(y_n) * dx);
                fprintf(eul,"%f\n",y_n);
                x_track += dx;
        }
        printf("Error in euler:%f\n",fabs(y_n - tan(x_end)));
        fclose(eul);
}

double modified_euler() // Heun's method //just half the grid size?
{
        FILE *mod_eul;
        char name_mod_eul[64];
        sprintf(name_mod_eul,"mod_eul%d.dat",1);
        mod_eul = fopen(name_mod_eul,"w");

        double y_n = y_init;
        double x_track = 0;
        
        double y_np5 = 0;
        double m_mid = 0;
        while (x_track <= x_end) {
                y_np5 = y_n + (f_y(y_n) * dx * 0.5);
                m_mid = f_y(y_np5);
                y_n = y_n + (m_mid * dx);

                fprintf(mod_eul,"%f",y_n);
                x_track += dx;
        }
        printf("Error in modified euler:%f\n",fabs(y_n - tan(x_end)));
        fclose(mod_eul);
}

double improved_euler()
{
        FILE *imp_eul;
        char name_imp_eul[64];
        sprintf(name_imp_eul,"imp_eul%d.dat",1);
        imp_eul = fopen(name_imp_eul,"w");

        double y_n = y_init;
        double x_track = 0;

        double m_beg = 0;
        double m_end = 0;
        double y_n1 = 0;

        while (x_track <= x_end){
                m_beg = f_y(y_n);
                y_n1 = y_n + (m_beg * dx);
                m_end = f_y(y_n1);

                y_n = y_n + (((m_beg + m_end)/2)*dx);

                fprintf(imp_eul,"%f\n",y_n);
                x_track += dx;
        }
        printf("Error in improved euler:%f\n",fabs(y_n - tan(x_end)));
        fclose(imp_eul);
}

double RK4()
{
        FILE *RK;
        char name_RK[64];
        sprintf(name_RK,"RK4%d.dat",1);
        RK = fopen(name_RK,"w");

        double k1,k2,k3,k4;
        double y_n = y_init;
        double x_track = 0;

        while (x_track <= x_end) {

                k1 = f_y(y_n) * dx;
                k2 = f_y(y_n + (0.5 * k1)) * dx;
                k3 = f_y(y_n + (0.5 * k2)) * dx;
                k4 = f_y(y_n + k3) * dx;

                y_n = y_n + (k1 + (2 * k2) + (2 * k3) + k4)/6;
                fprintf(RK,"%f\n",y_n);
                x_track += dx;
        }
        printf("Error in RK4:%f\n", fabs(y_n - tan(x_end))); 
        fclose(RK);
}

int main()
{
        clock_t begin = clock();
        
        euler();
        modified_euler();
        improved_euler();
        RK4();

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

