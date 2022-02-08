#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Phonebook{
	char name[30];
	char phone[12];
	char email[30];
};

typedef struct Phonebook phonebook;

struct Node{
	phonebook list[100];
	Node *next;
};

typedef struct Node *node;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    	L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void sort_and_fprint(){
	FILE *fin, *fout;
	fin = fopen("11_3_merge_in.txt","r");
	if(fin == NULL){
		printf("Cannot open file");
		exit(1);
	}
	while(!feof(fin)){
		
	}
}

int main()
{



return 0;
}

