#include<stdio.h>
#include<stdlib.h>

#define g_e 2
#define mu_b 9.274e-24
//#define h_bar 1.0546e-34

int main()
{

        int L = 20;
        int crystal[L][L];

        // INITIALIZING SPINS
        for(int i=0;i<L;i++) {
                for(int j=0;j<L;j++) {
                        crystal[i][j] = -1;
                }
        }
        
        // CALCULATE MAGENTIC MOMENT
        int sum = 0;
        for(int i=0;i<L;i++) {
                for(int j=0;j<L;j++) {
                        sum += crystal[i][j];
                }
        }
        double mu_s = -(g_e * mu_b * sum );
        printf("Magnetic moment: %e J/T\n",mu_s);

        return 0;
}

