#include<stdio.h>
#include<stdlib.h>

int top=-1;

bool isFull(int capacity){
	if(top>=capacity-1) return true;
	else return false;
}

bool isEmpty(){
	if(top==-1) return true;
	else return false;
}

void Push(int stack[], int data, int capacity){
	if(isFull(capacity)) printf("stack is full");
	else{
		top++;
		stack[top]=data;
	}
}

void Pop(){
	if(isEmpty()) printf("stack is empty");
	else top--;
}

int Top(int stack[]){
	return stack[top];
}

int Size(){
	return top+1;
}


int main(){
    int capacity = 3; 
    int top = -1; 
    int stack[capacity];
    Push(stack, 5, capacity);   
    Push(stack, 10, capacity);
    Push(stack, 24, capacity);
    
    printf("\nCurrent size of stack is %d\n", Size());
    Push(stack, 12, capacity); 
    printf("\nThe current top element in stack is %d\n", Top(stack));
    for(int i = 0 ; i < 3;i++)
        Pop();
    printf("\nCurrent size of stack is %d\n", Size());
    Pop();  
}
