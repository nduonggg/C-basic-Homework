#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct queue{
    node* front; 
    node* rear;
}queue;

node *createNode(int x){
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

void enQueue(queue*q, int x){
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
    int n,a[20];
    queue *q = createQueue();
    printf("Nhap n: ");scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("%d: ",i+1);scanf("%d",&a[i]);
        enQueue(q,a[i]);
    }
    for(int i=n-1; i>9; i--){
        printf("%-5d",q->front->data);
        deQueue(q);
    }
    
    
    return 0;
}
