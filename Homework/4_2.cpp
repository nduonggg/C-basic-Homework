#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _address{
    char name[30];
    char phone[12];
    char email[30];
};

typedef struct _address address; 

typedef struct _node{
	address data;
	_node*next;
}node;

node *push(node *p, address value){
	node *temp;
	temp = (node*)malloc(sizeof(struct _node));
	if(temp == NULL){
		printf("Error");
		exit(1);
	}
	temp->data = value;
	temp->next = p;
	p = temp;
	return p;
}

node *pop(node *p, address *value){
	node *temp;
	if(p == NULL){
		printf("Stack empty");
		exit(1);
	}
	*value = p->data;
	temp = p;
	p = p->next;
	free(temp);
	return p;
}


int main()
{
    node *stack = NULL;
    address list[20];
    FILE *f1,*f2;
    f1 = fopen("phonebook.txt","r");
    if(f1 == NULL){
        printf("Error");
        exit(1);
    }
    f2 = fopen("phonebook_out.txt","w");
    int sl = 0;
    while(!feof(f1)){
        fscanf(f1,"%s %s %s",&list[sl].name,&list[sl].phone,&list[sl].email);
        sl++;
    }
    for(int i=sl-1; i>=0; i--) stack = push(stack,list[i]);
    while(stack!=NULL){
        address temp;
        stack = pop(stack,&temp);
        fprintf(f2,"%-30s %-12s %-30s\n",temp.name,temp.phone,temp.email);
    }
    printf("done");
    fclose(f1);fclose(f2);

return 0;
}
