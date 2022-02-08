#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct address{
    char name[30];
    char phone[12];
    char email[30];
}address;

void xoa_n(char*str){
    int len = strlen(str);
    if(str[len-1]=='\n') str[len-1]='\0';
}

struct _node{
    address data;
    _node*next;
};
typedef struct _node*node;

node createNode(address x){
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

node addHead(node head,address x){
    node temp=createNode(x);
    if(head==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

node addTail(node head,address x){
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

node addAt(node head,address x,int position){
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

void sreach(node head, char* x){
    for(node p=head;p!=NULL;p=p->next)
        if(strcmp(p->data.name,x)==0){
            printf("%-30s%-12s%-30s",p->data.name,p->data.phone,p->data.email);
            return;
        }
    printf("Not found");
}

int main(){
    node head=NULL;
    address l1[100];
    FILE *f1;
    f1 = fopen("phonebook.txt","r");
    if(f1==NULL){
        printf("Error");
        exit(1);
    }
    int sl=0;
    while(!feof(f1)){
        fscanf(f1,"%s %s %s",&l1[sl].name,&l1[sl].phone,&l1[sl].email);
        sl++;
    }
    for(int i=0;i<sl;i++) head = addTail(head,l1[i]);
    char x[30];
    printf("Nhap ten can tim: ");
    fgets(x,30,stdin);xoa_n(x);
    sreach(head,x);  
    
    fclose(f1);
    return 0;