#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};
typedef struct node* tree;

struct node1
{
    char data;
    struct node1* link;
};
typedef struct node1* stack;

struct node2
{
    float data;
    struct node2* next;
};
typedef struct node2* stack2;

int Added;

int Is_Empty (tree Tree)
{
    return Tree==NULL;
}

void Make_NULL_Tree (tree* Tree)
{
    *Tree = NULL;
}

int Is_Digit(char c)
{
    return c >= '0' && c <= '9';
}

tree Left_Child (tree Tree)
{
    if(Tree!=NULL) return Tree->left;
    else return NULL;
}

tree Right_Child (tree Tree)
{
    if(Tree!=NULL) return Tree->right;
    else return NULL;
}

int Is_Leaf (tree Tree)
{
    if (Tree!=NULL) return (Left_Child(Tree)==NULL) && (Right_Child(Tree)==NULL) ;
    else return -1;
}

tree Create_New_Node (char data)
{ 
    tree temp = (tree)malloc(sizeof(struct node));
    if (temp!=NULL)
    {
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
    }
    else 
    {
        printf("No more memory for you! No more!\n");
        exit(1);
    }
    return temp;
}


void postorder_Print_Tree(tree Tree)
{
    if( Is_Empty(Tree) ) return;
    postorder_Print_Tree( Left_Child(Tree) );
    postorder_Print_Tree( Right_Child(Tree) );
    printf("%c ", Tree->data);
}

tree Add_Node_to_Right (tree Tree, char data)
{
    Added=0;
    if( Is_Empty(Tree) ) 
    {
        Tree = Create_New_Node(data);
        Added=1;
        return Tree;
    }
    if( Right_Child(Tree)==NULL ) Tree->right = Add_Node_to_Right(Right_Child(Tree), data);
    else if( !Is_Digit( Right_Child(Tree)->data ) ) Tree->right = Add_Node_to_Right(Right_Child(Tree), data);
    if(Added==0)
    {
        if(Left_Child(Tree)==NULL) Tree->left = Add_Node_to_Right(Left_Child(Tree), data);
        else if( !Is_Digit( Left_Child(Tree)->data ) ) Tree->left = Add_Node_to_Right(Left_Child(Tree), data);
    }
    return Tree;
}


void Make_NULL_Stack(stack* Stack)
{
    *Stack = NULL;
}

stack push(stack Stack, char value)
{
    stack temp;
    temp=(stack)malloc(sizeof(struct node1));
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
    temp=(stack)malloc(sizeof(struct node1));
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

tree from_Stack_to_Tree (tree Tree, stack Stack)
{
    while (Stack!=NULL)
    {
        char temp;
        Stack = pop(Stack, &temp);

        Tree = Add_Node_to_Right(Tree, temp);
    }
    return Tree;
}

stack Remove_Stack_Top(stack Stack)
{
    stack temp;
    temp = Stack;
    Stack = Stack->link;
    free(temp);
    return Stack;
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
            if(Phep_Toan==NULL) Phep_Toan = push(Phep_Toan, string[i]);
            else
            {
                while(Phep_Toan->data=='*' || Phep_Toan->data=='/' || Phep_Toan->data=='^')
                {
                    Phep_Toan = pop(Phep_Toan, &temp);
                    Postf = push(Postf, temp);
                }
                Phep_Toan = push(Phep_Toan, string[i]);
            }
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

int Stack_Length(stack Stack)
{
    int count=0;
    stack cur;
    for(cur = Stack; cur!=NULL; cur=cur->link) count++;
    return count;
}

stack2 push2(stack2 Stack, float value)
{
    stack2 temp;
    temp=(stack2)malloc(sizeof(struct node2));
    if(temp==NULL)
    {
        printf("No Memory available Error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = Stack;
    Stack = temp;
    return(Stack);
}

stack2 pop2(stack2 Stack, float* value)
{
    stack2 temp;
    temp=(stack2)malloc(sizeof(struct node2));
    if(Stack==NULL)
    {
        printf(" The stack is empty cannot pop Error\n");
        exit(0);
    }
    *value = Stack->data;
    temp = Stack;
    Stack = Stack->next;
    free(temp);
    return(Stack);
}


float Calculator (float a, float b, char c)
{
    if(c=='+') return a+b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
    if(c=='/') return a/b;
    if(c=='^') return pow(a, b);
}

float Calculator_All (stack Stack, int Strlen)
{
    char Postf[20];
    float ans;
    Postf[Strlen]='\0';
    int i=1;
    stack2 Stack2 = NULL; 

    while(Stack!=NULL)
    {
        char temp;
        Stack = pop(Stack, &temp);
        Postf[Strlen-i]=temp;
        i++;
    }

    for(i=0; i<strlen(Postf); i++)
    {
        if( Is_Digit(Postf[i]) )
        {
            float temp; 
            char Temp[2]; Temp[1]='\0';
            Temp[0] = Postf[i];
            temp = atof(Temp);
            Stack2 = push2(Stack2, temp);
        }
        else 
        {
            float a, b, c;
            Stack2 = pop2(Stack2, &b);
            Stack2 = pop2(Stack2, &a);
            c = Calculator(a, b, Postf[i]);
            Stack2 = push2(Stack2, c);
        }
    }

    Stack2 = pop2(Stack2, &ans);
    return ans;
}

int main()
{
    char Inf[20];
    float Ans;
    stack Postf; Make_NULL_Stack(&Postf);
    stack Phep_Toan; Make_NULL_Stack(&Phep_Toan);
    tree Root; Make_NULL_Tree(&Root);

    printf("Bieu thuc: "); gets(Inf); fflush(stdin);

    Postf = Inf_to_Postf(Postf, Phep_Toan, Inf);

    Root = from_Stack_to_Tree(Root, Postf);

    Make_NULL_Stack(&Postf);

    Postf = Inf_to_Postf(Postf, Phep_Toan, Inf);

    postorder_Print_Tree(Root); 

    Ans = Calculator_All(Postf, Stack_Length(Postf));

    printf("= %g", Ans);
    return 0;
}