#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	char data;
	_node*next;
}node;

node *push(node *p, char value){
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

node *pop(node *p, char *value){
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


int main()
{
    node *stack = NULL;
    char a[100],b[100];
    printf("Nhap chuoi: ");fgets(a,100,stdin);
    xoa_n(a);
    for(int i=0; i<strlen(a); i++)
        stack = push(stack,a[i]);
    for(int i=0; i<strlen(a); i++)
        stack = pop(stack,&b[i]);
    b[strlen(a)] = '\0';
    puts(b);

return 0;
}
