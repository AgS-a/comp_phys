#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<omp.h>

int main()
{
        double begin = omp_get_wtime();

        int num_k_points = 401;

        #pragma omp parallel for collapse(1)
        for(int nk=1; nk<=num_k_points; nk++){
                
        }

        double end = omp_get_wtime();
        printf("\nSuccessfully finished running in %.8f s.\n",(end-begin));

        return 0;
}

