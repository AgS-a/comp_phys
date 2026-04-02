#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<openblas/lapacke.h>

void constr_matrix(double a,double k, double V0, int num_G_points, double store_matrix[])
{
        // Initializing the Hamiltonian matrix.
        double hamiltonian[num_G_points][num_G_points];
        for(int i=0; i<num_G_points; i++){
                for(int j=0;j<num_G_points;j++){
                        hamiltonian[i][j] = 0;
                }
        }

        // Generating G-points based on the number of G-points.
        double G_pts[num_G_points];
        int m_edge_pt = -(num_G_points-1)/2;
        for(int i=0; i<num_G_points; i++){
                G_pts[i] = (2*M_PI*m_edge_pt/a) + (i*2*M_PI/a);
        }
        
        // Changing the matrix to a 1D array(row by row) that is required by syev.
        double for_lapacke[num_G_points*num_G_points];
        int index = 0;
        // Constructing the hamiltonian(tri-diagonal matrix)
        for(int i=0; i<num_G_points; i++){
                for(int j=0; j<num_G_points; j++){
                        if(i==j){
                                hamiltonian[i][j] = -V0 + (0.5*(k+G_pts[i])*(k+G_pts[i]));
                        }
                        if(j==(i-1)){
                                hamiltonian[i][j] = -V0/2;
                        }
                        if(j==(i+1)){
                                hamiltonian[i][j] = -V0/2;
                        }
                        for_lapacke[index] = hamiltonian[i][j];
                        index++;
                }
        }
        
        memcpy(store_matrix,for_lapacke,sizeof(for_lapacke));
}

void diagonalizer(double a,double k, double V0, int num_G_points,double store_eval[],double store_evec[])
{
        double matrix[num_G_points*num_G_points]; // Tri-diagonal input matrix

        // Constructing the hamiltonian using the constr_matrix subroutine
        constr_matrix(a,k,V0,num_G_points,matrix);

        double diagonalized[num_G_points]; // Diagonal output matrix

        /*
         * Syntax of LAPACKE_dsyev:
         * 1) Type of input matrix(row or column major)
         * 2) If eigenvector is to be calculated[N-no][V-changes the input matrix into eigenvectors]
         * 3) If input matrix is upper or lower triangular['U' or 'L']
         * 4) Order of the matrix
         * 5) The input matrix(in form of a 1D array)
         * 6) Leading dimension of the array
         * 7) Array to store the eigenvalues
         */
        int info = LAPACKE_dsyev(LAPACK_ROW_MAJOR, 'V', 'U', num_G_points, matrix, num_G_points, diagonalized);

        memcpy(store_eval,diagonalized,sizeof(diagonalized));
        memcpy(store_evec,matrix,sizeof(matrix));

}

void run_bands(double a, int num_k_points, double V0, int num_G_points)
{
        FILE *fPtr;
        char name[64];
        sprintf(name,"a%.2f_Vo%.2f_nk%d_ng%d.dat", a, V0, num_k_points, num_G_points);
        fPtr = fopen(name,"w");

        FILE *fPt;
        char nameev[64];
        sprintf(nameev,"ev_a%.2f_Vo%.2f_nk%d_ng%d.dat", a, V0, num_k_points, num_G_points);
        fPt = fopen(nameev,"w");

        double k;
        double eigenvalues[num_G_points];
        double eigenvectors[num_G_points*num_G_points];

        for(int nk=0; nk<num_k_points; nk++){
                k = (-M_PI/a) + (nk*(2*M_PI/(a*(num_k_points-1))));
                diagonalizer(a, k, V0, num_G_points, eigenvalues, eigenvectors);
                fprintf(fPtr, "%f    ", k);
                for(int i=0; i< num_G_points; i++){
                        fprintf(fPtr, "%f    ", eigenvalues[i]);
                }
                fprintf(fPtr, "\n");
                
                fprintf(fPt, "%f\n", k);
                for(int i=0; i<num_G_points; i++){
                        fprintf(fPt, "%f    ",eigenvalues[i]);
                        for(int j=0;j<num_G_points;j++){
                                fprintf(fPt,"%f    ",eigenvectors[(i + (num_G_points*j))]);
                        }
                fprintf(fPt,"\n");
                }
                fprintf(fPt,"\n");
        }

        int z = 0;
        fclose(fPtr);
        fclose(fPt);
}

int main()
{
        clock_t begin = clock();
        
        double a = 1;
        int num_k_points = 401;
        double V0 = 0;
        int G_vary[4] = {3, 11, 21, 61};
        int num_G_points = 3;
        
        /*
         * Q3
         */
        for(int i=0; i<4; i++){
                run_bands(a, num_k_points,V0,G_vary[i]);
        }

        /*
         * Q4
         */
        a = 1.5;
        for(int i=0; i<4; i++){
                run_bands(a, num_k_points,V0,G_vary[i]);
        }

        a = 2.5;
        for(int i=0; i<4; i++){
                run_bands(a, num_k_points,V0,G_vary[i]);
        }
        
        /* 
         * Q5
         */ 
        V0 = 0.5;
        a = 1.5;
        for(int i=0; i<4; i++){
                run_bands(a, num_k_points,V0,G_vary[i]);
        }

        /*
         * Q6
         */
        double V_perturb[6] = {0, 2, 4, 6, 8, 10};
        num_G_points = 21;
        for(int i=0; i<6; i++){
                V0 = V_perturb[i];
                run_bands(a, num_k_points, V0, num_G_points);
        }

        /*
         * Q7
         */
        V0 = 0.5;
        a = 1;
        for(int i=0; i<4; i++){
                run_bands(a+(i*3), num_k_points, V0, num_G_points);
        }
        V0 = 8.5;
        for(int i=0; i<4; i++){
                run_bands(a+(i*3), num_k_points, V0, num_G_points);
        }

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

