#include<stdio.h>

void sapxep(int a[]){
	int i,j;
	for(i=0;i<LENGTH-1;i++){
		for(j=LENGTH-1;j>i;j--){
			if(a[j]<a[j-1]){
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
}

int main()
{



return 0;
}

