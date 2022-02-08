#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	int data;
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


int main()
{



return 0;
}

