#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x){

return sin(x);

}

int main() {

float initial_condition;

printf("Enter initial position:");
scanf("%f", &initial_condition);

float x_n = initial_condition;
float x_n_minus_1;
float x_trial;

float time_delta = 0.001;

int n = 0;

while (x_n_minus_1 != x_n) {
	x_n_minus_1 = x_n;
	x_trial = x_n + f(x_n) * time_delta;
	x_n = x_n + (0.5 * (f(x_n) + f(x_trial)) * time_delta);
	}

printf("%f",x_n);

}
