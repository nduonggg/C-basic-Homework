#include<stdio.h>
#include<stdlib.h>

void Enqueue(char queue[], char data, int &rear, int size){
	if(rear==size) printf("OverFlow\n");
	else{
		queue[rear]=data;
		rear++;
	}
}

void Dequeue(char queue[], int &front, int rear){
	if(front==rear) printf("UnderFlow");
	else{
		queue[front]=0;
		front++;
	}
}

char Front(char queue[], int front){
	return queue[front];
}

int Size(int front,int rear){
	return (rear-front);
}

bool isEmpty(int front,int rear){
	return(front==rear);
}

int main() {
    char queue[20] = {'a', 'b', 'c', 'd'};        
    int front = 0, rear = 4;                
    int arraySize = 20;                // Size of the array
    int N = 3;                    // Number of steps
    char ch;
    for(int i = 0;i < N;++i) {
        ch = Front(queue, front);
        Enqueue(queue, ch, rear, arraySize);
        Dequeue(queue, front, rear);
    }
    for(int i = front;i < rear;++i)
        printf("%c", queue[i]);
    printf("\n");
    return 0;
}

