#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int i;
    struct _node *link;
}node;


node* push(node* p, int value)
{
    node* temp;
    temp=(node*)malloc(sizeof(struct _node));
    if(temp==NULL)
    {
        printf("No Memory available Error\n");
        exit(0);
    }
    temp->i=value;
    temp->link = p;
    p = temp;
    return(p);
}

node* pop(node* p, int *value)
{
    node* temp;
    temp=(node*)malloc(sizeof(struct _node));
    if(p==NULL)
    {
        printf(" The stack is empty cannot pop Error\n");
        exit(0);
    }
    *value=p->i;
    temp = p;
    p = p->link;
    free(temp);
    return(p);
}

node* sum(node* a, node* b, node* c)
{
    int z=0;
    while(a!=NULL || b!=NULL)
    {
        int x=0,y=0;

        if(a!=NULL) a=pop(a,&x);
        if(b!=NULL) b=pop(b,&y);

        if(z>=10) y=y+1;

        z=x+y;

        if(z>=10)
        {
            int temp = z-10;
            c=push(c,temp);
        }
        else
        {
            c=push(c,z);
        }

        if(z>=10 && a==NULL && b==NULL)
        {
            int temp = (int)(z/10);
            c=push(c,temp);
        }
    }

    return(c);
}


int main()
{
    node* stack_1=NULL; node* stack_2=NULL; node* stack_3=NULL;
    char f_number[100]; 
    char s_number[100];
    int a[100];
    int b[100];

    printf("Nhap so dau:");
    gets(f_number);fflush(stdin);
    printf("Nhap so sau:");
    gets(s_number);fflush(stdin);

    for(int i=0; i<strlen(f_number); i++)
    {
        fflush(stdin);
        char temp[2]; temp[1]='\0';
        temp[0] = f_number[i];
        a[i]=atoi(temp);
    }
    for(int i=0; i<strlen(s_number); i++)
    {
        fflush(stdin);
        char temp[2]; temp[1]='\0';
        temp[0] = s_number[i];
        b[i]=atoi(temp);
    }
    
    for(int i=0; i<strlen(f_number); i++) stack_1=push(stack_1,a[i]);
    for(int i=0; i<strlen(s_number); i++) stack_2=push(stack_2,b[i]);

    stack_3=sum(stack_1,stack_2,stack_3);

    while(stack_3!=NULL)
    {
        int value;
        stack_3=pop(stack_3,&value);
        printf("%d",value);
    }

    return 0;
}
