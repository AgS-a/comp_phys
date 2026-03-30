// To implement periodic boundary conditions, for a box of size N,
// we do i mod N where i's are the coordinates x,y and z.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double PBC(double position,double box_size)
{
        // Take modulo of position with box size
        double modulo_position = fmod(position, box_size);
        
        double final_coordinate = modulo_position;
        // If position is negative after modulo, add the size of the box
        if(modulo_position < 0){
                final_coordinate = modulo_position + box_size;
        }

        return final_coordinate;
}

int main()
{
        clock_t begin = clock();

        double N = 30;

        double x_i = 27.05;
        double y_i = 30.05;
        double z_i = -30.03;

        printf("%f\n", PBC(x_i, N));
        printf("%f\n", PBC(y_i, N));
        printf("%f\n", PBC(z_i, N));

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("\nSuccessfully finished running in %.8f s.\n",time_spent);

        return 0;
}

