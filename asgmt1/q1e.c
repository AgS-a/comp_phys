#include<stdio.h>
#include<stdlib.h>

int main() {
    
    FILE*fPtr;
    char ch;

    fPtr = fopen("test_ran.dat","r");
    
    do {
        ch = fgetc(fPtr);
        printf("%c",ch);
    }while(ch!=EOF);
    
    fclose(fPtr);

    return 0;
}
