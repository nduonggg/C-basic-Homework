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
    struct node* left;
    struct node* right;
};
typedef struct node* tree;

void Make_NULL_Tree (tree* Tree)
{
    *Tree=NULL;
}

int Is_Empty (tree Tree)
{
    return Tree == NULL;
}

tree Create_New_Node (Address data)
{
    tree temp = (tree)malloc( sizeof( struct node ) );
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

tree Insert_by_Address (Address data, tree Tree)
{
    if( Is_Empty(Tree) ) 
    {
        tree temp; 
        temp = Create_New_Node(data);
        Tree = temp;  
        return Tree;
    }
    else if (strcmp(data.address, Tree->data.address) >0) Tree->right = Insert_by_Address(data, Tree->right);
    else Tree->left = Insert_by_Address(data, Tree->left);
    return Tree;
}

tree Insert_by_Name (Address data, tree Tree)
{
    if( Is_Empty(Tree) ) 
    {
        tree temp; 
        temp = Create_New_Node(data);
        Tree = temp;  
        return Tree;
    }
    else if (strcmp(data.first_name, Tree->data.first_name) >0) Tree->right = Insert_by_Name(data, Tree->right);
    else Tree->left = Insert_by_Name(data, Tree->left);
    return Tree;
}

void inorder_Print_Tree(tree Tree)
{
    if( Is_Empty(Tree) )
    {
        return;
    }
    inorder_Print_Tree( Tree->left );
    printf("%-25s %-15s %-15s %-40s\n", Tree->data.last_mid_name, Tree->data.first_name, Tree->data.number, Tree->data.address);
    inorder_Print_Tree( Tree->right );
}

struct node1
{
    tree Tree;
    struct node1* next;
};
typedef struct node1* queue;

int Is_Empty_Queue (queue Queue)
{
    return Queue == NULL;
}

queue EnQueue (queue Queue, tree Tree)
{
    if( Is_Empty(Tree) ) return NULL;
    queue temp = (queue)malloc( sizeof( struct node1 ) );
    if(temp==NULL)
    {
        printf("Out of Memory.\n");
        exit(0); 
    }
    temp->Tree = Tree;
    temp->next = NULL;

    if( Is_Empty_Queue(Queue) ) Queue = temp;
    else
    {
        queue cur = Queue;
        while(cur->next!=NULL) cur=cur->next;
        cur->next = temp;
    }
    return Queue;
}

queue DeQueue (queue Queue, tree* Tree)
{
    *Tree = Queue->Tree;
    queue temp = Queue;
    Queue = Queue->next;
    free(temp);
    return Queue;
}

void BFS (tree Tree)
{
    queue Queue = NULL;

    if( !Is_Empty(Tree) )
    {
        Queue = EnQueue(Queue, Tree);
        while( !Is_Empty_Queue(Queue) )
        {
            tree cur = (tree)malloc( sizeof( struct node1 ) );
            Queue = DeQueue(Queue, &cur);
            printf("%s \n", cur->data.first_name);
            if(cur->left!=NULL) Queue = EnQueue(Queue, cur->left);
            if(cur->right!=NULL) Queue = EnQueue(Queue, cur->right);
        }
    }
}


int main()
{
    FILE* f;
    f = fopen("9_address.txt","r");
    if(f==NULL)
    {
        printf("Cannot find Text.txt.\n");
        exit(0);
    }

    Address person[10];

    int amount=0;
    while(!feof(f))
    {
        fscanf(f, "%s %s %s %s", person[amount].last_mid_name, person[amount].first_name, person[amount].number, person[amount].address);
        amount++;
    }

    tree Root; Make_NULL_Tree(&Root);

    for(int i=0; i<amount; i++)
    {
        Root = Insert_by_Address(person[i], Root);
    }

    printf("%-25s %-15s %-15s %-40s\n", "Last Name & Mid Name", "First Name", "Number", "Address");
    inorder_Print_Tree(Root);
    printf("\n");

    tree Root_2; Make_NULL_Tree(&Root_2);

    for(int i=0; i<amount; i++)
    {
        Root_2 = Insert_by_Name(person[i], Root_2);
    }

    printf("%-25s %-15s %-15s %-40s\n", "Last Name & Mid Name", "First Name", "Number", "Address");
    inorder_Print_Tree(Root_2);
    printf("\n\n");

    BFS(Root);

    fclose(f);
    return 0;
}