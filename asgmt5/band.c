#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<omp.h>
#include<openblas/lapacke.h>

#define PI 3.1415

double a = 1.2;

void constr_matrix(double k, double V0, int num_G_points)
{
        double hamiltonian[num_G_points][num_G_points];
        for(int i=0;i<num_G_points;i++){
                for(int j=0;j<num_G_points;j++){
                        hamiltonian[i][j] = 0;
                }
        }

        for(int i=0;i<num_G_points;i++){
                for(int j=0;j<num_G_points;j++){
                        if(i==j){
                                hamiltonian[i][j] = -V0 + (0.5*(k+)*(k+));
                        }
                        if(j==(i-1)){
                                hamiltonian[i][j] = -V0/2;
                        }
                        if(j==(i+1)){
                                hamiltonian[i][j] = -V0/2;
                        }
                }
        }

}

int main()
{
        double begin = omp_get_wtime();

        int num_k_points = 401;
        int num_G_points = 11;
        double V0 = 0.5;

        if((num_k_points % 2) == 0){
                printf("Enter odd number of k points");
                return 1;
        }
        if((num_G_points % 2) == 0){
                printf("Enter even number of G points");
                return 1;
        }

        #pragma omp parallel for collapse(1)
        for(int nk=1; nk<=num_k_points; nk++){
                
        }

        double end = omp_get_wtime();
        printf("\nSuccessfully finished running in %.8f s.\n",(end-begin));

        return 0;
}

