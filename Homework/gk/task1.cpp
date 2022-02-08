#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Address
{
    char name[20];
    char telephone_number[10];
    char email_address[30];
};

typedef struct Address address;

struct node{
	address data;
	struct node *next;
};

typedef struct node node;
node *createNode(address x){
    node *temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = x;
    return temp;
}

int BinarySearch(address list[], char*key , int end ) {
	int Low, Mid, High;
	Low = 0; High = end - 1;
	while( Low <= High ) {
		Mid = ( Low + High ) / 2;
		if( strcmp(list[ Mid ].name, key) < 0 )
			Low = Mid + 1;
		else if(strcmp(list[ Mid ].name, key) > 0)
			High = Mid - 1;
		else
			return Mid;
	}
	return -1;
}
void cau1(){
	FILE *fin,*fout;
	address list[100];
	int data_number=0;
	char*key;
    key=(char*)malloc(sizeof(char));
    printf("Nhap ten can tim: ");
	gets(key); fflush(stdin);
	fin = fopen("task1_in.txt","r");
	if(fin==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    while(!feof(fin)){
        fscanf(fin, "%s %s %s", list[data_number].name, list[data_number].telephone_number, list[data_number].email_address);
        data_number++;
    }
    fout=fopen("task1_out.txt","w");
    int binsearch = BinarySearch(list, key, data_number);
    if(binsearch == -1) printf("Not Found\n");
	else{
		printf("Da ghi ra task1_out.txt\n");
		fprintf(fout,"%-20s %-10s %-30s\n", list[binsearch].name, list[binsearch].telephone_number, list[binsearch].email_address);
	}
		
    fclose(fin);fclose(fout);
}


void printList(node *l){
	node *p = l;
	while (p != NULL){
		printf("%-20s%-20s%-20s\n",p->data.name,p->data.telephone_number,p->data.email_address);
		p = p->next;
	}
}
node *add(node*p, address x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}
node *search(node *l,address x){
	node *p = l;
	while(p != NULL){
		if(strcmp(p->data.name,x.name)==0) return p;
		p = p->next;
	}
	return NULL;
}
void cau2(){
	FILE *fin,*fout;
	fin = fopen("task1_in.txt","r");
	if(fin==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
	address value;
	fscanf(fin,"%s\t",value.name);
	fscanf(fin,"%s\t",value.telephone_number);
	fscanf(fin,"%s\n",value.email_address);
	node *l = createNode(value);
	node *p = l;
	int i;
	for(i=1;i<10;i++){
		fscanf(fin,"%s\t",value.name);
		fscanf(fin,"%s\t",value.telephone_number);
		fscanf(fin,"%s\n",value.email_address);
		p = add(p,value);
	}
	fout=fopen("task1_out.txt","w");
	printf("Nhap ten can tim: ");
	address x;
	fflush(stdin);
	gets(x.name);
	node *q = search(l,x);
	if(q == NULL) printf("Not found\n");
	else{
		printf("Da ghi ra task1_out.txt\n");
		fprintf(fout,"%-20s%-20s%-20s\n",q->data.name,q->data.telephone_number,q->data.email_address);
	}
	fclose(fin);fclose(fout);
}

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

void cau3(){
	FILE *fin,*fout;
	fin = fopen("task1_in.txt","r");
	if(fin==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
	queue *q = createQueue();
	address value;
	int i;
	for(i=0;i<10;i++){
		fscanf(fin,"%s\t",value.name);
		fscanf(fin,"%s\t",value.telephone_number);
		fscanf(fin,"%s\n",value.email_address);
		enQueue(q,value);
	}
	fout=fopen("task1_out.txt","w");
	printf("Nhap ten can tim: ");
	address x;
	fflush(stdin);
	gets(x.name);
	int count=0;
	while(q->front != NULL){
		if(strcmp(q->front->data.name,x.name) == 0){
			count++;
			printf("Da ghi ra task1_out.txt\n");
			fprintf(fout,"%-20s%-20s%-20s\n",q->front->data.name,q->front->data.telephone_number,q->front->data.email_address);
			break;
		}
		deQueue(q);
	}
	if(count == 0) printf("Not Found\n");
	fclose(fin);fclose(fout);
}

void cau4(){
	queue *q = createQueue();
	address value;
	int i;
	for(i=0;i<11;i++){
		printf("%d.\n",i+1);
		printf("Name: "); fflush(stdin); scanf("%s",value.name);
		printf("Telephone_number: "); fflush(stdin); scanf("%s",value.telephone_number);
		printf("Email: "); fflush(stdin); scanf("%s",value.email_address);
		enQueue(q,value);
	}
	printf("Da thay the du lieu vua nhap\n");
	printf("%-20s%-20s%-20s\n",q->front->data.name,q->front->data.telephone_number,q->front->data.email_address);
	deQueue(q);
}

int main(){
	int n=0;
	do{
		printf("\nMenu\n");
		printf("(1)\n");
		printf("(2)\n");
		printf("(3)\n");
		printf("(4)\n");
		printf("Nhap 0 de thoat\n\n");
		scanf("%d",&n);
		fflush(stdin);
		switch(n){
		case 1:
			cau1();
			break;
		case 2:
			cau2();
			break;
		case 3:
			cau3();
			break;
		case 4:
			cau4();
			break;
		default:
			printf("Nhap lai n:");
			break;
		}
	}while(n>0&&n<=4);
	return 0;
}
