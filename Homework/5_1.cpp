#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct address{
    char name[30];
    char phone[12];
    char email[30];
}address;

typedef struct node{
    address data;
    struct node *next;
}node;

typedef struct queue{
    node* front; 
    node* rear;
}queue;

node *createNode(address x){
    node*temp = (node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

queue *createQueue(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enQueue(queue*q, address x){
    node*temp = createNode(x);
    if(q->rear == NULL){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(queue*q){
    if(q->front == NULL){
        q->rear == NULL;
        return;
    }
    node*temp = q->front;
    q->front = q->front->next;
    free(temp);
}

int main(){
    FILE *f1,*f2;
    f1 = fopen("5_1_in.txt","r");
    if(f1 == NULL){
        printf("Error");
        exit(1);
    }
    f2 = fopen("5_1_out.txt","w");
    address l1[20];
    int sl=0;
    queue *q = createQueue();
    while(!feof(f1)){
        fscanf(f1,"%s %s %s",&l1[sl].name,&l1[sl].phone,&l1[sl].email);
        sl++;
    }
    for(int i=0; i<sl; i++) enQueue(q,l1[i]);
    while(q->front != NULL){
        fprintf(f2,"%-30s%-12s%-30s\n",q->front->data.name,q->front->data.phone,q->front->data.email);
        deQueue(q);
    }
    fclose(f1);fclose(f2);
    printf("Da ghi ra file");

    return 0;
}
