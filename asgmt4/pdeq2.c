// neumann boundary condition
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
        clock_t begin = clock();

        double grids[36][36]; // Add additional grid point to set constant gradient
        double gr_tmp[36][36];
/*
        for(int i=0;i<34;i++){
                grids[0][i] = 2000 + (-70*i);
                gr_tmp[0][i] = 2000 + (-70*i);
                grids[i][0] = 2000 + (-10*i);
                gr_tmp[i][0] = 2000 + (-10*i);
                grids[33][i] = (2000 - (10*33)) + (-40*i);
                gr_tmp[33][i] = (2000 - (10*33)) + (-40*i);
                grids[i][33] = (2000 - (70*33)) + (20*i);
                gr_tmp[i][33] = (2000 - (70*33)) + (20*i);
        }
*/
        for(int i=0;i<36;i++){
                for(int j=0;j<36;j++){
                        grids[i][j] = 0;
                        gr_tmp[i][j] = 0;
                }
        }

        int cond =0;
        while(cond == 0){

                for(int i=1;i<35;i++){
                        for(int j=1;j<35;j++){
                                gr_tmp[i][j] = 0.25*(grids[i+1][j]+grids[i-1][j]+grids[i][j+1]+grids[i][j-1]);
                        }
                }
                //BOUNDARY CONDITIONS
                for(int i=0;i<36;i++){
                        gr_tmp[i][0] = gr_tmp[i][1] + 70;
                        gr_tmp[i][35] = gr_tmp[i][34] - 40;
                        gr_tmp[0][i] = gr_tmp[1][i] - 10;
                        gr_tmp[35][i] = gr_tmp[34][i] -20;
                }
                gr_tmp[1][1] = 2000;

                cond = 1;
                double tol = 1e-5;
                for(int i=0;i<36;i++){
                        for(int j=0;j<36;j++){
                                if(fabs(gr_tmp[i][j]-grids[i][j]) > tol){
                                        cond = 0;
                                }
                        }
                }
                for(int i=0;i<36;i++){
                        for(int j=0;j<36;j++){
                                grids[i][j] = gr_tmp[i][j];
                        }
                }
        }
        FILE *fpt;
        fpt = fopen("pde2.dat","w");

        for(int i=1;i<35;i++){
                for(int j=1;j<35;j++){
                        fprintf(fpt,"%.4f    ",grids[i][j]);
                }
                fprintf(fpt,"\n");
        }
        fclose(fpt);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

