// Heat diffusion
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
        clock_t begin = clock();
        
        // Double the intervals not the grid points
        // Draw grid and make sure that the grids overlap
        double grids[67][67];
        double gr_tmp[67][67];
        
        for(int i=0;i<67;i++){
                // at x=1, T=3.7 for all y
                grids[0][i] = 3.7;
                gr_tmp[0][i] = 3.7;
                // at x=67, T=0.4 for all y
                grids[66][i] = 0.4;
                gr_tmp[66][i] = 0.4;
                // at y=1 and 67, x changes linearly from 3.7 to 0.4
                double slope = (0.4-3.7)/66;
                grids[i][0] = 3.7 + (slope*i);
                gr_tmp[i][0] = 3.7 + (slope*i);
                grids[i][66] = 3.7 + (slope*i);
                gr_tmp[i][66] = 3.7 + (slope*i);
        }

        int cond =0;
        while(cond == 0){
                for(int i=1;i<66;i++){
                        for(int j=1;j<66;j++){
                                gr_tmp[i][j] = 0.25*(grids[i+1][j]+grids[i-1][j]+grids[i][j+1]+grids[i][j-1]);
                        }
                }
                cond = 1;
                double tol = 1e-4;
                for(int i=0;i<67;i++){
                        for(int j=0;j<67;j++){
                                if(fabs(gr_tmp[i][j]-grids[i][j]) > tol){
                                        cond = 0;
                                }
                        }
                }
                for(int i=0;i<67;i++){
                        for(int j=0;j<67;j++){
                                grids[i][j] = gr_tmp[i][j];
                        }
                }
        }
        FILE *fpt;
        fpt = fopen("pde1.dat","w");

        for(int i=0;i<67;i++){
                for(int j=0;j<67;j++){
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

