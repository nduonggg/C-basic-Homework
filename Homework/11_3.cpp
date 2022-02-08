#include<stdio.h>
#include<stdlib.h>
#include<string.h>

swap(char *a, char *b){
	char temp = *a;
		*a = *b;
		*b = temp;
}

int partition (char *arr, int low, int high)
{
    char pivot = arr[high]; 
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    swap(&arr[left], &arr[high]);
    return left;
}
 
void quickSort(char *arr, int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(char *arr, int n)
{
	char key;
   	int i, j;
   	for (i = 1; i < n; i++){
       	key = arr[i];
       	j = i-1;
       	while (j >= 0 && arr[j] > key){
           	arr[j+1] = arr[j];
           	j = j-1;
       	}
       	arr[j+1] = key;
   	}
}

void sort_and_print(int x){
	FILE *fin;
	char a[200];
	fin = fopen("11_3_in.txt","r");
	if(fin == NULL){
		printf("Cannot open file");
		exit(1);
	}
	int i = 0;
	while(!feof(fin) && i < 100){
		a[i] = fgetc(fin);
		i++;
	}
	a[100] = '\0';
	if(100 > x){
		printf("Quicksort:\n");
		quickSort(a, 0, 99);
	}
	else{
		printf("Insertionsort:\n");
		insertionSort(a, 100);
	}
	printf("%s",a);
}

int main()
{
	sort_and_print(50);


return 0;
}

