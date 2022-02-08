#include<stdio.h>
#include <stdlib.h>

swap(int *a, int *b){
	int temp = *a;
		*a = *b;
		*b = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
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
 
void quickSort(int arr[], int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(int arr[], int n)
{
   int i, key, j;
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

int main()
{
	int a[1000], n;
	printf("Nhap n: ");scanf("%d",&n);
	for(int i = 0; i < n; i++)
		a[i] = rand();
									
	int ch=10;
	do{
		printf("\n\nLua chon:\n");
		printf("1. QuickSort\n");
		printf("2. InsertionSort\n");
		printf("0. Thoat\n");
		scanf("%d",&ch);
		fflush(stdin);
		switch(ch){
			case 1:
				quickSort(a, 0, n - 1);
				printf("QuickSort:\n");
				for(int i = 0; i < n; i++)
					printf("%d\t",a[i]);
				break;
			case 2:
				insertionSort(a, n);
				printf("InsertionSort:\n");
				for(int i = 0; i < n; i++)
					printf("%d\t",a[i]);
				break;
			default:
				printf("Hay nhap lai\n");
				break;
		}
	}while(ch != 0);
	
return 0;
}

