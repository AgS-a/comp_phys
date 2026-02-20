#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define J_ising 1

void neighbours(int m, int n, int i, int j, int result[6][2])
{
        // FIRST ATOM OF THE SECOND ROW IS SHIFTED TO THE RIGHT BY SOME AMOUNT (finite triangular lattice case)
        if (m%2 == 0) {
                m = m-1;
                n = n-1;
              if (i == 0 && j == 0) {         // TOP LEFT CORNER
                      int neigh[6][2] = { {0, 1}, {1, 0}, {0, n}, {1, n}, {m, 0}, {m, n} };
                      memcpy(result,neigh,sizeof(neigh));
              } else if (i == 0 && j == n) {  // TOP RIGHT CORNER
                      int neigh[6][2] = { {1, n}, {1, n-1}, {0, n-1}, {m, n}, {m, n-1}, {0, 0} };
                      memcpy(result,neigh,sizeof(neigh));
              } else if (i == m && j == n) {  // BOTTOM RIGHT CORNER
                      int neigh[6][2] = { {m, n-1}, {m-1, n}, {m, 0}, {0, n}, {0, 0}, {m-1, 0} };
                      memcpy(result,neigh,sizeof(neigh));
              } else if (i == m && j == 0) {  // BOTTOM LEFT CORNER
                      int neigh[6][2] = { {m-1, 0}, {m-1, 1}, {m, 1}, {0, 0}, {0, 1}, {m, n} };
                      memcpy(result,neigh,sizeof(neigh));
              } else if (j == 0) {            // LEFT COLUMN
                      if (i%2 == 0) {         // EVEN ROW
                              int neigh[6][2] = { {i-1, 0}, {i+1, 0}, {i, 1}, {i-1, 1}, {i+1, 1}, {i, n} };
                              memcpy(result,neigh,sizeof(neigh));
                      } else {                // ODD ROW
                              int neigh[6][2] = { {i-1, 0}, {i+1, 0}, {i, 1}, {i, n}, {i+1, n}, {i-1, n} };
                              memcpy(result,neigh,sizeof(neigh));
                      }
              } else if (j == n) {            // RIGHT COLUMN
                      if (i%2 == 0) {         // EVEN ROW
                              int neigh[6][2] = { {i-1, n}, {i+1, n}, {i, 0}, {i, n-1}, {i+1, 0}, {i-1, 0} };
                              memcpy(result,neigh,sizeof(neigh));
                      } else {                // ODD ROW
                              int neigh[6][2] = { {i-1, n}, {i-1, n-1}, {i+1, n}, {i+1, n-1}, {i, n-1}, {i, 0} };
                              memcpy(result,neigh,sizeof(neigh));
                      }
              } else if (i == 0) {            // TOP ROW
                      int neigh[6][2] = { {0, j-1}, {0, j+1}, {1, j-1}, {1, j}, {m, j-1}, {m, j} };
                      memcpy(result,neigh,sizeof(neigh));
              } else if (i == m) {            // BOTTOM ROW
                      int neigh[6][2] = { {m, j-1}, {m, j+1}, {0, j+1}, {0, j}, {m-1, j}, {m-1, j+1} };
                      memcpy(result,neigh,sizeof(neigh));
              } else {                        // BULK
                      int neigh[6][2] = { {i, j-1}, {i, j+1}, {i-1, j}, {i-1, j+1}, {i+1, j}, {i+1, j+1} };
                      memcpy(result,neigh,sizeof(neigh));
              }
        } else {
                printf("Enter odd number of rows!");
        }
}

int main()
{
        int L = 30;
        int crystal[L][L];

        // INITIALIZING SPINS
        for(int i=0;i<L;i++) {
                for(int j=0;j<L;j++) {
                        crystal[i][j] = 1;
                }
        }
        
        int cur_neigh[6][2];
        int total_energy;

        // CALCULATING ENERGY
        for(int i=0;i<L;i++) {
                for(int j=0;j<L;j++) {
                        neighbours(L,L,i,j,cur_neigh);
                        int energy_spin = 0;
                        for(int k=0;k<6;k++) {
                                int pos1 = cur_neigh[k][0];
                                int pos2 = cur_neigh[k][1];
                                int E_ij = J_ising * crystal[i][j] * crystal[pos1][pos2];
                                energy_spin += E_ij;
                        }
                        total_energy += energy_spin;
                }
        }
        printf("%d\n",total_energy/2);
        return 0;
}

