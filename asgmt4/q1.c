#include<stdio.h>
#include<stdlib.h>

double dx = 0.01;
double y_init = 0;

double f_y(double y)
{
        double fofy = (y * y) + 1;
        return fofy;
}

double euler()
{

}

double modified_euler()
{

}

double improved_euler()
{

}

double RK4()
{
        double k1,k2,k3,k4;
        double y_n_minus_1;

        double y_n = y_init;

        while (y_n != y_n_minus_1) {
                y_n_minus_1 = y_n;

                k1 = f_y(y_n) * dx;
                k2 = f_y(y_n + (0.5 * k1)) * dx;
                k3 = f_y(y_n + (0.5 * k2)) * dx;
                k4 = f_y(y_n + k3) * dx;

                y_n = y_n + (k1 + (2 * k2) + (2 * k3) + k4)/6;
        }
}

int main()
{
        
        


        return 0;
}

