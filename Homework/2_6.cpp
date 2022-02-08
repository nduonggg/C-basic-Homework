#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct list{
    char name[30];
    char phone[12];
    char email[30];
}list;

int main(){
    list l1[100];
    int sl;
    do{
        printf("Nhap sl: ");scanf("%d",&sl);
    }while(sl<=0 || sl>100);
    for(int i=0; i<sl; i++){
        printf("name: ");scanf("%s",&l1[i].name);
        printf("phone: ");scanf("%s",&l1[i].phone);
        printf("email: ");scanf("%s",&l1[i].email);
    }
    FILE *f1;
    f1 = fopen("phonebook.txt","w");
    for(int i=0; i<sl; i++){
        fprintf(f1,"%-30s",l1[i].name);
        fprintf(f1,"%-12s",l1[i].phone);
        fprintf(f1,"%-30s\n",l1[i].email);
    }
    fclose(f1);
    printf("Done");

    return 0;
}