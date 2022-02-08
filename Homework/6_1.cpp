#include<stdio.h>

int linearSearch(int a[], int count, int x){
	int i;
    for(i=0; i<count; i++)
        if(a[i] == x) return i;
    return -1;
}

int main(){
    int a[10],x;
    for(int i=0; i<10; i++) scanf("%d",&a[i]);
    printf("Nhap x: ");scanf("%d",&x);
    printf("%d",linearSearch(a,10,x));
    return 0;
    
}