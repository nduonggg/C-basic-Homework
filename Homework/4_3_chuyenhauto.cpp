#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
    char data;
    struct node *link;
};

typedef struct node* stack;

void Make_NULL_Stack(stack* Stack)
{
    *Stack = NULL;
}

stack push(stack Stack, char value)
{
    stack temp;
    temp=(stack)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No Memory available Error\n");
        exit(0);
    }
    temp->data = value;
    temp->link = Stack;
    Stack = temp;
    return(Stack);
}

stack pop(stack Stack, char* value)
{
    stack temp;
    temp=(stack)malloc(sizeof(struct node));
    if(Stack==NULL)
    {
        printf(" The stack is empty cannot pop Error\n");
        exit(0);
    }
    *value = Stack->data;
    temp = Stack;
    Stack = Stack->link;
    free(temp);
    return(Stack);
}

stack Remove_Stack_Top(stack Stack)
{
    stack temp;
    temp = Stack;
    Stack = Stack->link;
    free(temp);
    return Stack;
}

int Is_Digit(char c)
{
    return c >= '0' && c <= '9';
}

stack Inf_to_Postf(stack Postf, stack Phep_Toan, char string[])
{
    char temp;
    for(int i=0; i<strlen(string); i++)
    {
        if( Is_Digit(string[i]) ) Postf = push(Postf, string[i]);
        else if(string[i]=='(') Phep_Toan = push(Phep_Toan, string[i]);
        else if(string[i]==')') 
        {
            while(Phep_Toan->data!='(') 
            {
                Phep_Toan = pop(Phep_Toan, &temp);
                Postf = push(Postf, temp);
            }
            Phep_Toan = Remove_Stack_Top(Phep_Toan);
        }
        else if(string[i]=='*' || string[i]=='/')
        {
            while(Phep_Toan->data=='*' || Phep_Toan->data=='/' || Phep_Toan->data=='^')
            {
                Phep_Toan = pop(Phep_Toan, &temp);
                Postf = push(Postf, temp);
            }
            Phep_Toan = push(Phep_Toan, string[i]);
        }
        else if(string[i]=='^') Phep_Toan = push(Phep_Toan, string[i]);
        else 
        {
            if(Phep_Toan==NULL) Phep_Toan = push(Phep_Toan, string[i]);
            else
            {
                while(Phep_Toan->data=='*' || Phep_Toan->data=='/' || Phep_Toan->data=='^' || Phep_Toan->data=='-' || Phep_Toan->data=='+')
                {
                    Phep_Toan = pop(Phep_Toan, &temp);
                    Postf = push(Postf, temp);
                    if(Phep_Toan==NULL) break;
                }
                Phep_Toan = push(Phep_Toan, string[i]);
            }
        }
        
    }
    while(Phep_Toan!=NULL)
    {
        Phep_Toan = pop(Phep_Toan, &temp);
        Postf = push(Postf, temp);
    }

    return Postf;
}



int main()
{
    char Inf[50];
	int i=0;
	char rev[50];
    stack Postf; Make_NULL_Stack(&Postf);
    stack Phep_Toan; Make_NULL_Stack(&Phep_Toan);
    printf("Nhap bieu thuc: "); gets(Inf); fflush(stdin);
    Postf = Inf_to_Postf(Postf, Phep_Toan, Inf);
	while(Postf!=NULL)
    {
        Postf=pop(Postf,&rev[i]);
        i++;
    }
    int n=strlen(rev);
    for(i=n;i>=0;i--) printf("%c",rev[i]);
    
    return 0;
}