#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct address
{
    char name[30];
    char phone[10];
    char email[30];
}address;

void swap(char*a, char*b){
    char temp[30];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
void bubbleSort(address l1[], int sl){
	for(int i=0;i<sl-1;i++){
		for(int j=sl-1;j>i;j--){
			if(strcmp(l1[j].name, l1[j-1].name)<0){
                swap(l1[j].name, l1[j-1].name);
                swap(l1[j].phone, l1[j-1].phone);
                swap(l1[j].email, l1[j-1].email);
				// char temp[30];
                // strcpy(temp, l1[j].name);
				// strcpy(l1[j].name, l1[j-1].name);
				// strcpy(l1[j-1].name, temp);
			}
		}
	}
}

int BinarySearch(address l1[], char *key , int end ) {
	int Low, Mid, High;
	Low = 0; High = end - 1;
	while( Low <= High ) {
		Mid = ( Low + High ) / 2;
		if( strcmp(l1[ Mid ].name, key) < 0 )
			Low = Mid + 1;
		else if(strcmp(l1[ Mid ].name, key) > 0)
			High = Mid - 1;
		else
			return Mid;
	}
	return -1;
}

void xoa_n(char*str){
    int len = strlen(str);
    if(str[len-1]=='\n') str[len-1]='\0';
}

int main()
{
    FILE *f1;
    address l1[100];
    int sl=0;
    char x[20];
    f1 = fopen("7_2.txt","r");
    if(f1==NULL) 
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    while(!feof(f1))
    {
        fscanf(f1, "%s %s %s", l1[sl].name, l1[sl].phone, l1[sl].email);
        sl++;
    }
    bubbleSort(l1, sl);
    printf("Bin Search: "); fgets(x,20,stdin); xoa_n(x);
    int bin = BinarySearch(l1, x, sl);
    if(bin == -1) printf("Not Found.\n");
    else{
        printf("Found. Position %d.\n",bin);
        printf("%-30s %-10s %-30s\n", l1[bin].name, l1[bin].phone, l1[bin].email);
    }
    fclose(f1);
    return 0;
}