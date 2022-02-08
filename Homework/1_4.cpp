#include<stdio.h>

void tach(float a){
    int b = (int)a;
    float c = a-b;
    printf("Phan nguyen: %d\n",b);
    printf("Phan thap phan: %f\n",c);
}

int main(){
    float x;
    printf("x= ");scanf("%f",&x);
    tach(x);
return 0;
}