#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main()
{
        int nei[6][2];
        neighbours(4,2,0,0,nei);

        return 0;
}
