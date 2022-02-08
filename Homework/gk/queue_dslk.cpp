#include<stdio.h>

struct queueNode{
	address data;
	struct queueNode *next;
};

typedef struct queueNode queueNode;
struct queue{
	queueNode *front;
	queueNode *rear;
};

typedef struct queue queue;
queueNode* createNodeQ(address x){
	queueNode* temp = (queueNode*)malloc(sizeof(queueNode));
	temp->data = x;
	temp->next = NULL;
	return temp; 
}

queue* createQueue(){
	queue* q = (queue*)malloc(sizeof(queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void enQueue(queue* q, address x){
	queueNode* temp = createNodeQ(x);
	if(q->rear == NULL){
		q->front = temp;
		q->rear = temp;
		return ;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void deQueue(queue* q){
	if(q->front == NULL){
		q->rear = NULL;
		return ; 
	}
	queueNode* temp = q->front;
	q->front = q->front->next;
	free(temp);
}


int main()
{



return 0;
}

