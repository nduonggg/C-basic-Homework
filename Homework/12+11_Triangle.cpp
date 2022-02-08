#include<stdio.h>

void recurTriangle(int n, char ch){
	if(n > 0){
		for(int i = 0; i < n; i++)
			printf("%c",ch);
		printf("\n");
		recurTriangle(n - 1, ch);
	}				
}

int main()
{
	char ch; int n;
	printf("Nhap ch: ");scanf("%c",&ch);
	printf("Nhap n: ");scanf("%d",&n);
	recurTriangle(n, ch);


return 0;
}

