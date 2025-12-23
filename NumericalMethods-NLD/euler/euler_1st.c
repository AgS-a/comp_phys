#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x) {

return sin(x);

}

int main() {

float initial_condition={};

printf("Enter initial position:");
scanf("%f", &initial_condition);

float x_n = initial_condition;
float x_nm1={};

float time_delta = 0.001;

int n = 0;

while (x_nm1 != x_n) {
	x_nm1 = x_n;
	x_n = x_n + f(x_n) * time_delta;
	}

printf("%f",x_n);

}
