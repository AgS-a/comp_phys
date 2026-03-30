// Heat diffusion?
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
        clock_t begin = clock();

        double grids[68][68];
        double gr_tmp[68][68];
        
        for(int i=0;i<68;i++){
                // at x=1, T=3.7 for all y
                grids[0][i] = 3.7;
                grids[1][i] = 3.7;
                gr_tmp[1][i] = 3.7;
                gr_tmp[0][i] = 3.7;
                // at x=68, T=0.4 for all y
                grids[67][i] = 0.4;
                grids[66][i] = 0.4;
                gr_tmp[66][i] = 0.4;
                gr_tmp[67][i] = 0.4;
                // at y=1 and 68, x changes linearly from 3.7 to 0.4
        }
        for(int i=0;i<34;i++){
                double slope = (0.4-3.7)/33;
                grids[2*i][0] = 3.7 + (slope*i);
                grids[2*i][1] = 3.7 + (slope*i);
                gr_tmp[2*i][1] = 3.7 + (slope*i);
                gr_tmp[2*i][0] = 3.7 + (slope*i);
                grids[2*i][67] = 3.7 + (slope*i);
                grids[2*i][66] = 3.7 + (slope*i);
                gr_tmp[2*i][66] = 3.7 + (slope*i);
                gr_tmp[2*i][67] = 3.7 + (slope*i);

                grids[(2*i)+1][0] = 3.7 + (slope*i);
                grids[(2*i)+1][1] = 3.7 + (slope*i);
                gr_tmp[(2*i)+1][1] = 3.7 + (slope*i);
                gr_tmp[(2*i)+1][0] = 3.7 + (slope*i);
                grids[(2*i)+1][67] = 3.7 + (slope*i);
                grids[(2*i)+1][66] = 3.7 + (slope*i);
                gr_tmp[(2*i)+1][66] = 3.7 + (slope*i);
                gr_tmp[(2*i)+1][67] = 3.7 + (slope*i);
        }

        int cond =0;
        while(cond == 0){
                for(int i=2;i<66;i++){
                        for(int j=2;j<66;j++){
                                gr_tmp[i][j] = 0.25*(grids[i+1][j]+grids[i-1][j]+grids[i][j+1]+grids[i][j-1]);
                        }
                }
                cond = 1;
                double tol = 1e-4;
                for(int i=0;i<68;i++){
                        for(int j=0;j<68;j++){
                                if(fabs(gr_tmp[i][j]-grids[i][j]) > tol){
                                        cond = 0;
                                }
                        }
                }
                for(int i=0;i<68;i++){
                        for(int j=0;j<68;j++){
                                grids[i][j] = gr_tmp[i][j];
                        }
                }
        }
        FILE *fpt;
        fpt = fopen("pde1.dat","w");

        for(int i=0;i<68;i++){
                for(int j=0;j<68;j++){
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

