#include<stdio.h>
#include<stdlib.h>

int main() {
    
    FILE*fPtr;
    char ch;

    fPtr = fopen("test_ran.dat","r");
/*    
    do {
        ch = fgetc(fPtr);
        printf("%c",ch);
    }while(ch!=EOF); // EOF -> End of file
*/
    
    double numbers[12];
    int i=0;

    while(i<10) {
        fscanf(fPtr,"%lf",&numbers[i]);
        i++;
    }
    
    fclose(fPtr);
   
   double sum;
    for(int j=0;j<10;j++) {
        sum = sum + numbers[j];
    }
    double avg;
    avg = sum/10;

    printf("average is: %f",avg);
    return 0;
}
