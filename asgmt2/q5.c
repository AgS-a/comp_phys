// Buffon's needle experiment

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

double l = 9; //length of the needle
int d = 10; //separation between lines
int D = 1000000;
double rand_nos[2];

double pos_det(double ned_pos[]) {    
    rand_nos[0] = frand();
    rand_nos[1] = frand();

    //double theta = atan2(rand_nos[0],rand_nos[1]); // theta //
    double theta = frand() * 3.1415; // theta //
    //double theta = frand() * 1000; // theta //
    double center = frand() * D; //center

    ned_pos[0] = -((l * sin(theta))/2) + center;
    ned_pos[1] = ((l * sin(theta))/2) + center;
}   

double pi_est(double probability) {
    double pi = (2 * l)/(d * probability);
    return pi;
}
int touch_check(double x1,double x2) {
    int x1_ceil = ceil(x1);
    int x2_floor = floor(x2);
    int size = ceil(x2_floor - x1_ceil) + 1;
    int list[size];
    int i=0;
    int check_var = x1_ceil;
    while(check_var<=x2_floor) {
        list[i] = check_var;
        check_var++;
        i++;
    }
    int ret = 0;
    for(int i=0;i<(x2_floor-x1_ceil+1);i++) {
        int reminder = list[i] % d;
        if(reminder == 0) {
            ret = 1;
        }
    }
    return ret;
}
int main() {
    
    srand(time(NULL));

    int n = 100000;
    double x[n+2]; 
    x[0] = 0;
    double d = (double)D/(double)n;

    for(int i=0; i<n+1; i++) {
        x[i+1] = x[i] + d;
    }
    
    double ned_pos[2];
    int check;
    int sum = 0;
    int no_tries[8] = {10,100,1000,10000,100000,1000000,10000000,100000000};

    FILE*fptr;
    fptr = fopen("buffon.dat","w");

    for(int j=0;j<8;j++) {
        for(int i=0;i<no_tries[j];i++) { 
            pos_det(ned_pos);
            check = touch_check(ned_pos[0],ned_pos[1]);
            sum = sum + check;
        }
        double prob = sum/(double)no_tries[j];
        sum = 0;
        double err = fabs(pi_est(prob) - 4*atan(1));
        printf("%f\n",pi_est(prob));
        fprintf(fptr,"%f\n",err);
    }
    fclose(fptr);
    return 0;
}
