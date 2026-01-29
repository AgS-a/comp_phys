#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

double wavefunction(double r1,double r2) {
    double wf;
    double alpha = 2;
    wf = pow(exp(1),(-2*alpha*(r1+r2)));

    return wf;
}

double interaction(double r1,double r2,double theta1,double theta2,double phi1,double phi2) {
    double in;
    double cb;

    cb = (cos(theta1) * cos(theta2)) + (sin(theta1) * sin(theta2) * cos(phi1 - phi2));
    double dist = (sqrt(pow(r1,2) + pow(r2,2) - (2*r1*r2*cb) ));
    if(dist<1e-10){dist = 1e-10;}
    in = 1/dist;
    return in;
}

double inf(double r1,double r2) {
    double iftsml;

    iftsml = pow(r1,2) * pow(r2,2);
    return iftsml;
}

double brute_integral() {
    double lower_limit = 0;
    double upper_limit = 5;

    double fn=0;
    double sum=0;
    
    int n = 1000000;
    double volume = (upper_limit * upper_limit) * (2*2) * (2*3.1415*2*3.1415);

    for(int i=0;i<n;i++) {
        double r1 = (frand() * ((upper_limit) - (lower_limit))) + lower_limit ;
        double r2 = (frand() * ((upper_limit) - (lower_limit))) + lower_limit ;

        double theta1 = acos(2 * frand() - 1);
        double theta2 = acos(2 * frand() - 1);

        double phi1 = frand() * 2 * 3.1415;
        double phi2 = frand() * 2 * 3.1415;
        
        fn = wavefunction(r1,r2) * interaction(r1,r2,theta1,theta2,phi1,phi2) * inf(r1,r2); 
        sum += fn;
    }
    return (sum/n) * volume;

}

double imp_integral() {
    int n = 1000000;
    double fn=0;
    double sum=0;
    double alpha = 2;

    double volume = (16 * 3.1415 * 3.1415) / (4* alpha* alpha);

    for(int i=0;i<n;i++) {
        double r1 = -log(frand()) / (2*alpha);
        double r2 = -log(frand()) / (2*alpha);

        double theta1 = acos(2 * frand() - 1);
        double theta2 = acos(2 * frand() - 1);

        double phi1 = frand() * 2 * 3.1415;
        double phi2 = frand() * 2 * 3.1415;

        fn = inf(r1,r2) * interaction(r1,r2,theta1,theta2,phi1,phi2);
        sum+= fn;
    }
    return (sum/n) * volume;
}
int main() {
    
    printf("%f\n",brute_integral());
    printf("%f",imp_integral());

    return 0;
}

