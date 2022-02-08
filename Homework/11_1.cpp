#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Phonebook{
	char name[30];
	char phone[12];
	char email[30];
};

typedef struct Phonebook phonebook;

void swap(phonebook *a, phonebook *b){
	phonebook temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition (phonebook list[], int low, int high)
{
	char pivot[30];
    strcpy(pivot, list[high].name);
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && strcmp(list[left].name, pivot) < 0) left++;
        while(right >= left && strcmp(list[right].name, pivot) > 0) right--;
        if (left >= right) break;
        swap(&list[left], &list[right]);
        left++;
        right--;
    }
    swap(&list[left], &list[high]);
    return left;
}
 
void quicksort(phonebook list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quicksort(list, low, pi - 1);
        quicksort(list, pi + 1, high);
    }
}
//void quicksort(phonebook list[], int left, int right){
//	int i, j;
//	char pivot[30];
//	if(left < right){
//		i = left;
//		j = right + 1;
//		strcpy(pivot, list[left].name);
//		do{
//			while(strcmp(list[i].name, pivot) < 0) i++;
//			while(strcmp(list[i].name, pivot) > 0) j--;
//			if(i < j) swap(&list[i], &list[j]);
//		}while(i < j);
//		swap(&list[left], &list[j]);
//		quicksort(list, left, j - 1);
//		quicksort(list, j + 1, right);
//	}
//}

void sort_and_fprint(){
	FILE *fin, *fout;
	phonebook list[100];
	int data_num = 0;
	fin = fopen("11_1_in.txt", "r");
	if(fin == NULL){
		printf("Cannot open file");
		exit(1);
	}
	while(!feof(fin)){
		fscanf(fin,"%s %s %s", list[data_num].name, list[data_num].phone, list[data_num].email);
		data_num++;
	}
	quicksort(list, 0, data_num - 1);
	fout = fopen("11_1_out.txt", "w");
	for(int i = 0; i < data_num; i++)
		fprintf(fout,"%-30s %-15s %-30s\n", list[i].name, list[i].phone, list[i].email);
	fclose(fin); fclose(fout);
	printf("Da ghi ra file");
}

int main()
{
	sort_and_fprint();


return 0;
}

