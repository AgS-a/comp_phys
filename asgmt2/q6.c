#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

// int -inf to inf, r1^2dr1 r2^2dr2 dcostheta1 dcostheta2 dpi1 dphi2
// 

double r1;
double r2;
double phi1;
double phi2;

double wavefunction(r1,r2) {
    double wf;
    double alpha = 2;
    wf = pow(exp(1),(-alpha*(r1+r2)));

    return wf;
}

double interaction(r1,r2,theta1,theta2) {
    double in;
    double cb;

    double phi1;
    double phi2;

    cb = (cos(theta1) * cos(theta2)) + (sin(theta1) * sin(theta2) * cos(phi1 - phi2));
    in = 1 / (sqrt(pow(r1,2) + pow(r2,2) - (2*r1*r2*cb) ));
    
    return in;
}

double inf(r1,r2) {
    double iftsml;

    iftsml = pow(r1,2) * pow(r2,2);
}

double integral() {
    double lower_limit = -5;
    double upper_limit = 5;

    double fn;
    double sum;
    
    double r1;
    double r2;

    r1 = (frand() * ((upper_limit) - (lower_limit))) - lower_limit ;
    r2 = (frand() * ((upper_limit) - (lower_limit))) - lower_limit ;
    
    fn = wavefuction(r1,r2) * interaction(r1,r2) * inf(r1,r2); 
}

int main() {
    
    

    return 0;
}

