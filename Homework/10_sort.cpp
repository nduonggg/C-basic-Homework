#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Insertion_Sort_Array (int array[], int amount)
{
    int i, j;
    int temp;

    for(i=1; i<amount; i++)
    {
        temp = array[i];
        for(j=i-1; j>=0 && temp < array[j]; j--) array[j+1] = array[j];
        array[j+1] = temp;
    }
}

void Selection_Sort_Array (int array[], int amount)
{
    int i, j, min;
    int temp;
    for(i=0; i<amount; i++)
    {
        min = i;
        for(j=i+1; j<amount; j++)
        {
            if( array[j] < array[min] ) min = j;
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void Swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Max_Heapify (int list[], int amount, int pos)
{
    int last = pos;
    int left = pos*2+1;
    int right = pos*2+2;

    //take the index of the biggest number
    if(left<amount && list[left]>list[last])
    {
        last = left;
    }
    if(right<amount && list[right]>list[last])
    {
        last = right;
    }

    //swap parent with the biggest child
    if(last!=pos)
    {
        Swap(&list[pos], &list[last]);
        Max_Heapify(list, amount, last);
    }
}

void Heap_Sort (int list[], int amount)
{
    //Build_Max_Heap
    for(int i=amount/2-1; i>=0; i--)
    {
        Max_Heapify(list, amount, i);
    }

    //Heap_Sort
    for(int i=amount-1; i>=0; i--)
    {
        Swap(&list[0], &list[i]);
        Max_Heapify(list, i, 0);
    }
}

void Merging (int list[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - (mid + 1) + 1;   
    int left[n1], right[n2];
    for (int i = 0; i < n1; ++i) left[i] = list[start + i];
    for (int i = 0; i < n2; ++i) right[i] = list[mid + 1 + i];
 
    int index_1 = 0, index_2 = 0;
 
    int index = start;
    while (index_1 < n1 && index_2 < n2) 
    {
        if (left[index_1] <= right[index_2]) 
        {
            list[index] = left[index_1];
            index_1++;
        }
        else 
        {
            list[index] = right[index_2];
            index_2++;
        }
        index++;
    }
 

    for(index_1; index_1 < n1; index++, index_1++) list[index] = left[index_1];
    for(index_2; index_2 < n2; index++, index_2++) list[index] = right[index_2]; 
}

void Merge_Sort (int list[], int start, int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        Merge_Sort(list, start, mid);
        Merge_Sort(list, mid+1, end);
        Merging(list, start, mid, end);
    }
}

int Partition (int list[], int start, int end)
{
    int pivot = list[end];
    int pos = start - 1;
    for(int i = start; i<=end-1; i++)
    {
        if(list[i] <= pivot)
        {
            pos++;
            Swap(&list[i], &list[pos]);
        }
    }
    Swap(&list[pos+1], &list[end]);
    return pos+1;
}

void Quick_Sort (int list[], int start, int end)
{
    if(start < end)
    {
        int pivot = Partition(list, start, end);
        Quick_Sort(list, start, pivot - 1);
        Quick_Sort(list, pivot + 1, end);
    }
}


int main()
{
    srand( (int)time(NULL) ); 
    int menu = -1;
    int n = 5;
    int array[n];
    clock_t t1, t2;
    int duration;

    while(menu != 0)
    {
        printf("-----MENU----- \n");
        printf("1. Create (Recreate) Data. \n");
        printf("2. Insertion Sort. \n");
        printf("3. Selection Sort. \n");
        printf("4. Heap Sort. \n");
        printf("5. Merge Sort.\n");
        printf("6. Quick Sort.\n");
        printf("0. Exit. \n");
        printf("Your order. Please: "); 

        do
        {
            scanf("%d", &menu);
            if(menu<=-1 || menu>=7)
            {
                printf("Please, choose again: ");
            }
        } while (menu<=-1 || menu>=7); 

        switch (menu)
        {
        case 1:
            fflush(stdin);
            for(int i = 0; i < n; i++)
            {
                int random = rand();
                array[i] = random;
            }
            for(int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
            break;
        case 2:
            fflush(stdin);
            t1 = clock();
            Insertion_Sort_Array(array, n);
            t2 = clock();
            for(int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
            duration = (int)(t2-t1);
            printf("Sorting Duration: %d", duration);
            printf("\n");
            break;
        case 3:
            fflush(stdin);
            t1 = clock();
            Selection_Sort_Array(array, n);
            t2 = clock();
            for(int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
            duration = (int)(t2-t1);
            printf("Sorting Duration: %d", duration);
            printf("\n");
            break;
        case 4:
            fflush(stdin);
            t1 = clock();
            Heap_Sort(array, n);
            t2 = clock();
            for(int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
            duration = (int)(t2-t1);
            printf("Sorting Duration: %d", duration);
            printf("\n");
            break;
        case 5:
            fflush(stdin);
            t1 = clock();
            Merge_Sort(array, 0, n-1);
            t2 = clock();
            for(int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
            duration = (int)(t2-t1);
            printf("Sorting Duration: %d", duration);
            printf("\n");
            break;
        case 6:
            fflush(stdin);
            t1 = clock();
            Quick_Sort(array, 0, n-1);
            t2 = clock();
            for(int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
            duration = (int)(t2-t1);
            printf("Sorting Duration: %d", duration);
            printf("\n");
            break;
        }
    }

    return 0;
}