#include<stdio.h>
#include<stdlib.h>

double bad_rnd(double iran) {
    int m = 131072;
    int a = 1277;
    int ir;
    double bad_rn;

    ir = a * iran;
    ir = ir % m;

    iran = ir/(double)m;

    return iran;
}

int main() {
    
    printf("%f",bad_rnd(10.0));
    return 0;
}
