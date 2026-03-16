#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int niter = 2000;
double dt = 0.02;

double f_v(double y_prev, double y, double y_next)
{
        double force = y_prev + y_next - (2*y);
        return force;
}

double f_y(double v)
{
        return v;
}

int main()
{
        clock_t begin = clock();

        double y_track[50];
        double v_track[50];

        // INITIALIZING y and v
        for(int i=0;i<50;i++){
                y_track[i] = 0;
                v_track[i] = 0;
        }
        y_track[0] = 0.8;
        y_track[25] = 0.8;

        double k1_y[50],k2_y[50],k3_y[50],k4_y[50];
        double k1_v[50],k2_v[50],k3_v[50],k4_v[50];
        for(int i=0;i<=niter;i++){
                printf("%f\n",y_track[0]);
                // CALCULATION OF k1
                for(int j=0;j<50;j++){
                        if(j == 0){
                              k1_y[0] = f_y(v_track[0]) * dt;
                              k1_v[0] = f_v(y_track[49],y_track[0],y_track[1]) * dt;
                        } else if(j == 49){
                                k1_y[49] = f_y(v_track[49]) * dt;
                                k1_v[49] = f_v(y_track[48],y_track[49],y_track[0]) * dt;
                        } else{
                               k1_y[j] = f_y(v_track[j]) * dt;
                               k1_v[j] = f_v(y_track[j-1],y_track[j],y_track[j+1]) * dt;
                        }
                }
                // CALCULATION OF k2 {k2 = f(x + 0.5k1)*dt}
                for(int j=0;j<50;j++){
                        if(j == 0){
                                k2_y[0] = f_y(v_track[0] + (0.5 * k1_v[0])) * dt;
                                k2_v[0] = f_v(y_track[49] + (0.5 * k1_y[49]), y_track[0] + (0.5 * k1_y[0]), y_track[1] + (0.5 * k1_y[1])) * dt;
                        } else if(j == 49){
                                k2_y[49] = f_y(v_track[49] + (0.5 * k1_v[49])) * dt;
                                k2_v[49] = f_v(y_track[48] + (0.5 * k1_y[48]), y_track[49] + (0.5 * k1_y[49]), y_track[0] + (0.5 * k1_y[0])) * dt;
                        } else{
                                k2_y[j] = f_y(v_track[j] + (0.5 * k1_v[j])) * dt;
                                k2_v[j] = f_v(y_track[j-1] + (0.5 * k1_y[j-1]), y_track[j] + (0.5 * k1_y[j]), y_track[j+1] + (0.5 * k1_y[j+1])) * dt;
                        }
                }
                // CALCULATION of k3 {k3 = f(x + 0.5k2)*dt}
                for(int j=0;j<50;j++){
                        if(j == 0){
                                k3_y[0] = f_y(v_track[0] + (0.5 * k2_v[0])) * dt;
                                k3_v[0] = f_v(y_track[49] + (0.5 * k2_y[49]), y_track[0] + (0.5 * k2_y[0]), y_track[1] + (0.5 * k2_y[1])) * dt;
                        } else if(j == 49){
                                k3_y[49] = f_y(v_track[49] + (0.5 * k2_v[49])) * dt;
                                k3_v[49] = f_v(y_track[48] + (0.5 * k2_y[48]), y_track[49] + (0.5 * k2_y[49]), y_track[0] + (0.5 * k2_y[0])) * dt;
                        } else{
                                k3_y[j] = f_y(v_track[j] + (0.5 * k2_v[j])) * dt;
                                k3_v[j] = f_v(y_track[j-1] + (0.5 * k2_y[j-1]), y_track[j] + (0.5 * k2_y[j]), y_track[j+1] + (0.5 * k2_y[j+1])) * dt;
                        }
                }
                // CALCULATION of k4 {k4 = f(x + k3)*dt}
                for(int j=0;j<50;j++){
                        if(j == 0){
                                k4_y[0] = f_y(v_track[0] + k3_v[0]) * dt;
                                k4_v[0] = f_v(y_track[49] + k3_y[49], y_track[0] + k3_y[0], y_track[1] + k3_y[1]) * dt;
                        } else if(j == 49){
                                k4_y[49] = f_y(v_track[49] + k3_v[49]) * dt;
                                k4_v[49] = f_v(y_track[48] + k3_y[48], y_track[49] + k3_y[49], y_track[0] + k3_y[0]) * dt;
                        } else{
                                k4_y[j] = f_y(v_track[j] + k3_v[j]) * dt;
                                k4_v[j] = f_v(y_track[j-1] + k3_y[j-1], y_track[j] + k3_y[j], y_track[j+1] + k3_y[j+1]) * dt;
                        }
                }
                // CALCULATION OF UPDATED VALUES
                for(int j=0;j<50;j++){
                        y_track[j] = y_track[j] + ((k1_y[j] + (2 * k2_y[j]) + (2 * k3_y[j]) + k4_y[j])/6);
                        v_track[j] = v_track[j] + ((k1_v[j] + (2 * k2_v[j]) + (2 * k3_v[j]) + k4_v[j])/6);
                }
                
        }

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

