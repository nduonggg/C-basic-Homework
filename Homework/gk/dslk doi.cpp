#include<stdio.h>
#include<stdlib.h>

struct _node{
	int data;
	_node*next;
	_node*pre;
};

typedef struct _node*node;

node head,tail;

node createNode(int data){
	node newNode=(node)malloc(sizeof(struct _node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->pre=NULL;
	return newNode;
}

void addHead(int data){
	node newNode=createNode(data);
	if(head==NULL){
		head=newNode;
		tail=newNode;
		return;
	}
	head->pre=newNode;
	newNode->next=head;
	head=newNode;
}

void addTail(int data){
	node newNode=createNode(data);
	if(head==NULL){
		head=newNode;
		tail=newNode;
		return;
	}
	tail->next=newNode;
	newNode->pre=tail;
	tail=newNode;
}

void delHead(){
	if(head==NULL) return;
	head=head->next;
	head->pre=NULL;
}

void delTail(){
	if(head==NULL) return;
	tail=tail->pre;
	tail->next=NULL;
}

void print(){
	node temp=head;
	while(temp!=NULL){
		printf("%5d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void revPrint(){
	node temp=tail;
	printf("Rev: ");
	while(temp!=NULL){
		printf("%5d",temp->data);
		temp=temp->pre;
	}
	printf("\n");
}


int main()
{
	head = NULL;
    addTail(2);
    addTail(4);
    addHead(6);
    addTail(8);
    print();
    delHead();
    delTail();
    print(); revPrint();


return 0;
}

