#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _phone{
    char Model[10];
    char Memory[10];
    char DisplaySize[15];
    char Price[10];
}phone;

struct _node{
    phone data;
    _node*next;
};
typedef struct _node*node;

node createNode(phone value){
    node temp;
    temp=(node)malloc(sizeof(struct _node));
    if(temp==NULL){
        printf("No Memory available Error\n");
        exit(0);
    }
    temp->data=value;
    temp->next=NULL;
    return temp;
}

node addHead(node head, phone value){
    node temp=createNode(value);
    if(head==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

node addTail(node head, phone value){
    node temp,p;
    temp=createNode(value);
    if(head==NULL) head=temp;
    else{
        p=head;
        while(p->next!=NULL) p=p->next;
        p->next=temp;
    }
    return head;
}

node addAt(node head,int position, phone value){
    if(position==0||head==NULL) head=addHead(head,value);
    else{
        int k=1;
        node p=head;
        while(p!=NULL&&k!=position){
            p=p->next;
            k++;
        }
        if(k!=position) head=addTail(head,value);
        else{
            node temp=createNode(value);
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
    return head;
}

void traver(node head){
    for(node p=head;p!=NULL;p=p->next)
        printf("%-10s%-10s%-15s%-10s\n",p->data.Model,p->data.Memory,p->data.DisplaySize,p->data.Price);
}

phone rePhone(char*s1,char*s2,char*s3,char*s4){
    phone phone;
    strcpy(phone.Model,s1);
    strcpy(phone.Memory,s2);
    strcpy(phone.DisplaySize,s3);
    strcpy(phone.Price,s4);
    return phone;
}

node readFile(node head, const char*fileName){
    FILE *f1;
    f1 = fopen(fileName,"r");
    if(f1 == NULL){
        printf("Error");
        exit(1);
    }
    char s1[10],s2[10],s3[15],s4[10];
    while(!feof(f1)){
        fscanf(f1,"%s %s %s %s",&s1,&s2,&s3,&s4);
        head = addTail(head, rePhone(s1,s2,s3,s4));
    }
    fclose(f1);
    return head;
}

void xoa_n(char*str){
    int len = strlen(str);
    if(str[len-1]=='\n') str[len-1]='\0';
}

phone createPhone(){
    phone newPhone;
    printf("Model: ");scanf("%s",&newPhone.Model);
    printf("Memory: ");scanf("%s",&newPhone.Memory);
    printf("DisplaySize: ");scanf("%s",&newPhone.DisplaySize);
    printf("Price: ");scanf("%s",&newPhone.Price);
    return newPhone; 
}

node addNode(node head){
    phone newPhone;
    int position;
    printf("Nhap vi tri muon them: ");scanf("%d",&position);
    newPhone = createPhone();
    head = addAt(head,position,newPhone);
    printf("Da them du lieu");
    return head;
}

int findIndex(node head, char*value){
    int index = 0;
    for(node p=head;p!=NULL;p=p->next){
        if(strcmp(value,p->data.Model) == 0)
            return index;
        index++;
    }
    return -1;
}

node delNode(node head){
    char a[10];
    printf("Nhap model muon xoa: ");
    scanf("%s",&a);
    int index = findIndex(head,a);
    if(index == -1) 
        printf("Khong tim thay du lieu can xoa");
    else{
        head = delAt(head,index);
        printf("Da xoa");
    }
    return head;
}

void editNode(node head){
    char a[10];
    printf("Nhap model muon sua: ");
    scanf("%s",&a);
    int found=0;
    for(node p = head; p!=NULL; p = p->next)
        if(strcmp(p->data.Model,a) == 0){
            found = 1;
            phone newPhone = createPhone();
            p->data = newPhone;
            break;
        }
    if(found != 1) printf("Khong tim thay");

}

void menu(){
    printf("\n================== MENU ====================\n");
    printf("1. Duyet danh sach\n");
    printf("2. Them du lieu (them Node)\n");
    printf("3. Sua du lieu (sua Node)\n");
    printf("4. Xoa du lieu (xoa Node)\n");
    printf("5. In ra file\n");
    printf("0. Thoat chuong trinh\n");
    printf("============================================\n");
}

void Fout(node head){
    FILE *fout;
    fout = fopen("NokiaDB_out.txt","w");
    for(node p = head; p!=NULL; p = p->next)
        fprintf(fout,"%-10s%-10s%-15s%-10s\n",p->data.Model,p->data.Memory,p->data.DisplaySize,p->data.Price);

}

int main(){
    node head = NULL;
    head = readFile(head,"nokiaDB.txt");
    traver(head);
    int c;
    do{
        menu();
        printf("Ban chon: ");scanf("%d",&c);
        switch(c){
            case 1:
                traver(head);
                break;
            case 2:
                head = addNode(head);
                break;
            case 3:
                editNode(head);
                break;
            case 4:
                head = delNode(head);
                break;
            case 5:
                Fout(head);
                break;
            default:
                printf("Try again");
                break;
        }
    }while(c!=0);

    return 0;
}