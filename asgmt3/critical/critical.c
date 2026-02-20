#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

int L  = 64;
double KbT = 3.64;
int J_ising = 1;

#define frand() ((double) rand() / (RAND_MAX+1.0))

void neighbours(int m, int n, int i, int j, int res_neigh[6][2])
{
        // FIRST ATOM OF THE SECOND ROW IS SHIFTED TO THE RIGHT BY SOME AMOUNT (finite triangular lattice case)
        if (m%2 == 0) {
                m = m - 1;
                n = n - 1;
              if (i == 0 && j == 0) {         // TOP LEFT CORNER
                      int neigh[6][2] = { {0, 1}, {1, 0}, {0, n}, {1, n}, {m, 0}, {m, n} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              } else if (i == 0 && j == n) {  // TOP RIGHT CORNER
                      int neigh[6][2] = { {1, n}, {1, n-1}, {0, n-1}, {m, n}, {m, n-1}, {0, 0} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              } else if (i == m && j == n) {  // BOTTOM RIGHT CORNER
                      int neigh[6][2] = { {m, n-1}, {m-1, n}, {m, 0}, {0, n}, {0, 0}, {m-1, 0} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              } else if (i == m && j == 0) {  // BOTTOM LEFT CORNER
                      int neigh[6][2] = { {m-1, 0}, {m-1, 1}, {m, 1}, {0, 0}, {0, 1}, {m, n} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              } else if (j == 0) {            // LEFT COLUMN
                      if (i%2 == 0) {         // EVEN ROW
                              int neigh[6][2] = { {i-1, 0}, {i+1, 0}, {i, 1}, {i-1, 1}, {i+1, 1}, {i, n} };
                              memcpy(res_neigh,neigh,sizeof(neigh));
                      } else {                // ODD ROW
                              int neigh[6][2] = { {i-1, 0}, {i+1, 0}, {i, 1}, {i, n}, {i+1, n}, {i-1, n} };
                              memcpy(res_neigh,neigh,sizeof(neigh));
                      }
              } else if (j == n) {            // RIGHT COLUMN
                      if (i%2 == 0) {         // EVEN ROW
                              int neigh[6][2] = { {i-1, n}, {i+1, n}, {i, 0}, {i, n-1}, {i+1, 0}, {i-1, 0} };
                              memcpy(res_neigh,neigh,sizeof(neigh));
                      } else {                // ODD ROW
                              int neigh[6][2] = { {i-1, n}, {i-1, n-1}, {i+1, n}, {i+1, n-1}, {i, n-1}, {i, 0} };
                              memcpy(res_neigh,neigh,sizeof(neigh));
                      }
              } else if (i == 0) {            // TOP ROW
                      int neigh[6][2] = { {0, j-1}, {0, j+1}, {1, j-1}, {1, j}, {m, j-1}, {m, j} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              } else if (i == m) {            // BOTTOM ROW
                      int neigh[6][2] = { {m, j-1}, {m, j+1}, {0, j+1}, {0, j}, {m-1, j}, {m-1, j+1} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              } else {                        // BULK
                      int neigh[6][2] = { {i, j-1}, {i, j+1}, {i-1, j}, {i-1, j+1}, {i+1, j}, {i+1, j+1} };
                      memcpy(res_neigh,neigh,sizeof(neigh));
              }
        } else {
                printf("Enter even number of rows!\n");
        }
}
int random_spin()
{
        int n;
        float x = (rand() % 2) + 1;

        if (x == 1) {
                n = 1;
        } else {
                n = -1;
        }
        return n;
}
int main()
{
        clock_t begin = clock();

        srand(time(NULL));
        
        int niter = 240000;

        int crystal[L][L];
        int cur_neigh[6][2];

        // INITIALIZING SPINS
        for(int i=0;i<L;i++) {
                for(int j=0;j<L;j++) {
                        crystal[i][j] = random_spin();
                }
        }

        FILE *fPtr;
        fPtr = fopen("critical_mag.dat","w");
        FILE *fPt;
        fPt = fopen("critical_E.dat","w");

        for(int k=0;k<niter;k++) {
                for(int i=0;i<L;i++) {
                        for(int j=0;j<L;j++) {
                                int a = rand() % (L);
                                int b = rand() % (L);
                                neighbours(L,L,a,b,cur_neigh);
                                int Ei = 0;
                                for(int z=0;z<6;z++) {
                                        int pos1 = cur_neigh[z][0];
                                        int pos2 = cur_neigh[z][1];
                                        int E_ij = -J_ising * crystal[a][b] * crystal[pos1][pos2];
                                        Ei += E_ij;
                                }
                                int Ef = -Ei;
                                if (Ef <= Ei){
                                        crystal[a][b] = -crystal[a][b];
                                } else{
                                        double P = exp(-(Ef-Ei)/(KbT));
                                        if (frand() < P){
                                                crystal[a][b] = -crystal[a][b];
                                        }
                                }
                        }
                }
                int magnetic_moment = 0;
                for(int p=0;p<L;p++){
                        for(int q=0;q<L;q++){
                                magnetic_moment += crystal[p][q];
                        }
                }
                double magnetization = (double)magnetic_moment/(L*L);
                fprintf(fPtr,"%0.8f\n",magnetization);

                double total_energy = 0;
                // CALCULATING ENERGY
                for(int p=0;p<L;p++) {
                        for(int q=0;q<L;q++) {
                                neighbours(L,L,p,q,cur_neigh);
                                int energy_spin = 0;
                                for(int z=0;z<6;z++) {
                                        int pos1 = cur_neigh[z][0];
                                        int pos2 = cur_neigh[z][1];
                                        int E_ij = -J_ising * crystal[p][q] * crystal[pos1][pos2];
                                        energy_spin += E_ij;
                                }
                                total_energy += energy_spin;
                        }
                }
                double e_perspin = total_energy/(2*L*L);
                fprintf(fPt,"%0.8f\n",e_perspin);
        }

        fclose(fPtr);
        fclose(fPt);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

