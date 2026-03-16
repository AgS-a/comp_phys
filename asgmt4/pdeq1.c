// Heat diffusion?
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
        clock_t begin = clock();

        double grids[34][34];
        double gr_tmp[34][34];
        
        for(int i=0;i<34;i++){
                // at x=1, T=3.7 for all y
                grids[0][i] = 3.7;
                gr_tmp[0][i] = 3.7;
                // at x=34, T=0.4 for all y
                grids[33][i] = 0.4;
                gr_tmp[33][i] = 0.4;
                // at y=1 and 34, x changes linearly from 3.7 to 0.4
                double slope = (0.4-3.7)/33;
                grids[i][0] = 3.7 + (slope*i);
                gr_tmp[i][0] = 3.7 + (slope*i);
                grids[i][33] = 3.7 + (slope*i);
                gr_tmp[i][33] = 3.7 + (slope*i);
        }

        int cond =0;
        while(cond == 0){
                for(int i=1;i<33;i++){
                        for(int j=1;j<33;j++){
                                gr_tmp[i][j] = 0.25*(grids[i+1][j]+grids[i-1][j]+grids[i][j+1]+grids[i][j-1]);
                        }
                }
                cond = 1;
                double tol = 1e-4;
                for(int i=0;i<34;i++){
                        for(int j=0;j<34;j++){
                                if(abs(gr_tmp[i][j]-grids[i][j]) > tol){
                                        cond = 0;
                                }
                        }
                }
                for(int i=0;i<34;i++){
                        for(int j=0;j<34;j++){
                                grids[i][j] = gr_tmp[i][j];
                        }
                }
        }

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

