#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	char data;
	_node*next;
}node;

node *push(node *p, int value){
	node *temp;
	temp = (node*)malloc(sizeof(struct _node));
	if(temp == NULL){
		printf("Error");
		exit(1);
	}
	temp->data = value;
	temp->next = p;
	p = temp;
	return p;
}

node *pop(node *p, int *value){
	node *temp;
	if(p == NULL){
		printf("Stack empty");
		exit(1);
	}
	*value = p->data;
	temp = p;
	p = p->next;
	free(temp);
	return p;
}

void xoa_n(char *str){
    int len = strlen(str);
    if(str[len-1] == '\n') str[len-1] = '\0';
}

void chuyen(char *str, int a[]){
    int n = atoi(str);
    int i=0;
    while(n!=0){
        a[i] = n%10;
        n = n/10;
        i++;
    }
}

int main(){
    node *stack1 = NULL,*stack2 = NULL,*stack3 = NULL;
    char s1[10],s2[10];
    printf("Nhap so 1: ");fgets(s1,10,stdin);
    xoa_n(s1);
    printf("Nhap so 2: ");fgets(s2,10,stdin);
    xoa_n(s2);
    int n1[10],n2[10];
    chuyen(s1,n1);
    chuyen(s2,n2);
    int len1 = strlen(s1),len2 = strlen(s2);
    int a1,a2,count = 0;
    for(int i=0; i<len1; i++)
        stack1 = push(stack1,n1[i]);
    for(int i=0; i<len2; i++)
        stack2 = push(stack2,n2[i]);

    while(stack1!=NULL || stack2!=NULL){
        if(stack1!=NULL) stack1 = pop(stack1,&a1);
            else a1 = 0;
        if(stack2!=NULL) stack2 = pop(stack2,&a2);
            else a2 = 0;
        if((a1+a2)<10){
            stack3 = push(stack3,a1+a2+count);
            count = 0;
        }else{
            int z = (a1+a2)%10;
            stack3 = push(stack3,z+count);
            count = 1;
        }
    }

    while(stack3!=NULL){
        int value;
        stack3 = pop(stack3,&value);
        printf("%d",value);
    }

    return 0;
}