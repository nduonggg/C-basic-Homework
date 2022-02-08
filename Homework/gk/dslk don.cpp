#include<stdio.h>
#include<stdlib.h>

struct _node{
    int data;
    _node*next;
};
typedef struct _node*node;

node createNode(int x){
    node temp;
    temp=(node)malloc(sizeof(struct _node));
    if(temp==NULL)
    {
        printf("No Memory available Error\n");
        exit(0);
    }
    temp->data=x;
    temp->next=NULL;
    return temp;
}

node addHead(node head,int x){
    node temp=createNode(x);
    if(head==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

node addTail(node head,int x){
    node temp,p;
    temp=createNode(x);
    if(head==NULL) head=temp;
    else{
        p=head;
        while(p->next!=NULL) p=p->next;
        p->next=temp;
    }
    return head;
}

node addAt(node head,int x,int position){
    if(position==0||head==NULL) head=addHead(head,x);
    else{
        int k=1;
        node p=head;
        while(p!=NULL&&k!=position){
            p=p->next;
            k++;
        }
        if(k!=position) head=addTail(head,x);
        else{
            node temp=createNode(x);
            temp->next=p->next;
            p->next=temp;
        }
    }
    return head;
}

node delHead(node head){
    if(head==NULL) printf("list empty");
    else head=head->next;
    return head;
}

node delTail(node head){
    if(head==NULL||head->next==NULL) return delHead(head);
    node p=head;
    while(p->next!=NULL) p=p->next;
    p=NULL;
    return head;
}

node delAt(node head, int position){
    if(position==0||head==NULL||head->next==NULL)
        head=delHead(head);
        else{
            int k=1;
            node p=head;
            while(p->next==NULL&&k!=position){
                p=p->next;
                k++;
            }
            if(k!=position) delTail(head);
            else p->next=p->next->next;
        }
}

int sreach(node head, int x){
    int k=0;
    for(node p=head;p!=NULL;p=p->next){
        if(p->data==x) return k;
        k++;
    }
    return -1;
}

void print(node head){
    for(node p=head;p!=NULL;p=p->next)
        printf("%5d",p->data);
}

node input(){
    node head=NULL;
    int n,x;
    do{
        printf("Nhap n= ");scanf("%d",&n);
    }while(n<=0);
    for(int i=0;i<n;i++){
        printf("data= ");scanf("%d",&x);
        head=addTail(head,x);
    }
    return head;
}

node delAll(node head){
	node p = head;
	while(p != NULL){
		head = head->next;
		p = NULL;
		p = head; 
	}
	return head;
}

int get(node head,int index){
    int k=0;
    node p=head;
    while(p->next!=NULL&&k!=index){
        p=p->next;
        k++;
    }
    return p->data;
}

int len(node head){
    int k=0;
    for(node p=head;p!=NULL;p=p->next)
        k++;
    return k;
}

int main(){
    printf("tao dslk:\n");
    node head=input();
    print(head);
    int choose=100,x,position;
    do{
        printf("\n======Menu======\n");
        printf("1. AddHead\n");
        printf("2. AddTail\n");
        printf("3. AddAt\n");
        printf("4. DelHead\n");
        printf("5. DelTail\n");
        printf("6. DelAt\n");
        printf("7. Sreach x\n");
        printf("8. Print\n");
        printf("9. DelAll\n");
        printf("0. Exit\n");
        printf("You choose?\n");scanf("%d",&choose);
        switch(choose){
            case 1:
                printf("data= ");scanf("%d",&x);
                head=addHead(head,x);
                break;
            case 2:
                printf("data= ");scanf("%d",&x);
                head=addTail(head,x);
                break;
            case 3:
                printf("data= ");scanf("%d",&x);
                printf("position= ");scanf("%d",&position);
                head=addAt(head,x,position);
                break;
            case 4:
                head=delHead(head);
                break;
            case 5:
                head=delTail(head);
                break;
            case 6:
                printf("position= ");scanf("%d",&position);
                head=delAt(head,position);
                break;
            case 7:
                printf("data= ");scanf("%d",&x);
                printf("index=%d\n",sreach(head,x));
                break;
            case 8:
                print(head);
                break;
            case 9:
                head=delAll(head);
                break;
            default:
                printf("Try again");
                break;
        }
    }while(choose!=0);
}
