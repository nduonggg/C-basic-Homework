#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    float a1 = atof(argv[1]);
    float a2 = atof(argv[2]);
    float s = a1*a2;
    float p = (a1+a2)*2;
    printf("s=%f\np=%f",s,p);  
return 0;
}