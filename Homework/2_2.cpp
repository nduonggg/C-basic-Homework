#include<stdio.h>

typedef struct point{
    double x,y;
}point;

typedef struct cir{
    point o;
    double r;
}cir;

int is_in_circle(struct point a, struct cir b){
    if((a.x-b.o.x)*(a.x-b.o.x)+(a.y-b.o.y)*(a.y-b.o.y) > b.r*b.r) return 0;
    else return 1;
}

int main(){
    point a;
    cir b;
    printf("Nhap duong tron (O,r): ");
    scanf("%lf %lf %lf",&b.o.x,&b.o.y,&b.r);
    printf("Nhap toa do A(x,y): ");
    scanf("%lf %lf",&a.x,&a.y);
    printf("%d",is_in_circle(a,b));
    return 0;
}