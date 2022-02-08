#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address
{
    char last_mid_name[25];
    char first_name[15];
    char number[11];
    char address[50];
}Address;

struct node 
{
    Address data;
    struct node* next;
};
typedef struct node* list;

void Insertion_Sort_Array (Address* data, int amount)
{
    int i, j;
    Address temp;

    for(i=1; i<amount; i++)
    {
        temp = data[i];
        for(j=i-1; j>=0 && strcmp(temp.first_name, data[j].first_name)<0; j--) data[j+1] = data[j];
        data[j+1] = temp;
    }
}

void Selection_Array (Address* data, int amount)
{
    int i, j, min;
    Address temp;
    for(i=0; i<amount-1; i++)
    {
        min = i;
        for(j=i+1; j<amount-1; j++)
        {
            if( strcmp(data[j].first_name, data[min].first_name)<0 ) min = j;
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void Make_NULL_List (list* List)
{
    List = NULL;
}

list Create_New_Node (Address data)
{
    list temp = (list)malloc( sizeof( struct node ) );
    if(temp==NULL)
    {
        printf("Out of Memory.\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    return temp; 
}

list Add_to_Tail (list List, Address data)
{
    list temp = Create_New_Node(data);
    if(List==NULL) List = temp;
    else
    {
        list cur = List;
        while(cur->next!=NULL) cur = cur->next;
        cur->next = temp;
    }
    
    return List;
}

list Insertion_Sort_List (list List)
{
    list cur = List->next;
    list to_cmp = List;
    while(cur->next!=NULL)
    {
        if( strcmp(cur->data.first_name, to_cmp->data.first_name)<0 )
        {
            to_cmp->next = cur->next;
            cur->next = to_cmp;
        }
    }

    return List;
}


int main()
{
    FILE* f;
    Address person[10];
    int amount=0;
    list Linked_List; Make_NULL_List(&Linked_List);

    f = fopen("10_1.txt","r");
    if(f==NULL)
    {
        printf("Cannot find Text.txt.\n");
        exit(0);
    }

    while(!feof(f))
    {
        fscanf(f, "%s %s %s %s", person[amount].last_mid_name, person[amount].first_name, person[amount].number, person[amount].address);
        amount++;
    }

    fclose(f);

    /*Insertion_Sort_Array(person, amount);
    printf("%-25s %-15s %-15s %-30s\n", "Last Name && Mid Name", "First Name", "Number", "Address");
    for(int i=0; i<amount; i++)
    {
        printf("%-25s %-15s %-15s %-30s\n", person[i].last_mid_name, person[i].first_name, person[i].number, person[i].address);
    }*/

    //for(int i=0; i<amount; i++) Linked_List = Add_to_Tail(Linked_List, person[i]);

    Selection_Array(person, amount);
    printf("%-25s %-15s %-15s %-30s\n", "Last Name && Mid Name", "First Name", "Number", "Address");
    for(int i=0; i<amount; i++)
    {
        printf("%-25s %-15s %-15s %-30s\n", person[i].last_mid_name, person[i].first_name, person[i].number, person[i].address);
    }

    return 0;
}