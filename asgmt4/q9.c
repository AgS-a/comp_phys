// Gauss-Seidel y'' - 5y' + 10y = 10x
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double dx = 0.01;

int main()
{
        clock_t begin = clock();

        double y_old[101];
        double y_new[101];

        for(int i=1;i<100;i++){
                y_old[i] = i/50;
        }

        y_old[0] = y_new[0] = 0;
        y_old[100] = y_new[100] = 2;

        int check = 0;

        while(check == 0){
                // y(i) = {(20x[i](dx)^2) + (5dx - 2)y[i+1] - (2 + 5dx)y[i-1]}/{20(dx)^2 - 4}
                for(int i=1;i<100;i++){
                        y_new[i] = ((20*dx*dx*(i*dx)) - ((2+(5*dx))*y_new[i-1]) + (((5*dx)-2)*y_old[i+1]))/((20*(dx*dx))-4);
                }

                check = 1;
                double tol = 1e-4;
                for(int i=0;i<101;i++){
                        if(fabs(y_new[i]-y_old[i]) > tol){
                                check = 0;
                        }
                }
                for(int i=0;i<=100;i++){
                        y_old[i] = y_new[i];
                }
        }

        for(int i=0;i<101;i++){
                printf("%f\n",y_old[i]);
        }
        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

