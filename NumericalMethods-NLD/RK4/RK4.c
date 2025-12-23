#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x) {

return sin(x);

}

int main() {

float initial_condition;
float x_n_minus_1;
float time_delta = 0.001;

float k1,k2,k3,k4;

printf("Enter initial condition:");
scanf("%f",&initial_condition);

float x_n = initial_condition;

while (x_n != x_n_minus_1) {
	x_n_minus_1 = x_n;

	k1 = f(x_n) * time_delta;
	k2 = f(x_n + (0.5 * k1)) * time_delta;
	k3 = f(x_n + (0.5 * k2)) * time_delta;
	k4 = f(x_n + k3) * time_delta;

	x_n = x_n + (k1 + (2 * k2) + (2 * k3) + k4)/6;
	}

printf("%f",x_n);
}
