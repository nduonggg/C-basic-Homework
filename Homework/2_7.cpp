#include<stdlib.h>
#include<string.h>
#include<stdio.h>


typedef struct list{
    char name[30];
    char phone[12];
    char email[30];
}list;

int main(){
    list l1[100];
    FILE *f1,*f2;
    f1 = fopen("phonebook.txt","r");
    if(f1 == NULL){
        printf("error");
        exit(1);
    }
    f2 = fopen("phonebook_re.txt","w");
    int i=0;
    while(!feof(f1)){
        fscanf(f1,"%s %s %s",&l1[i].name,&l1[i].phone,&l1[i].email);
        i++;
    }
    int n=0;
    do{
        printf("Chon muc can sua: ");scanf("%d",&n);
    }while(n<=0 || n>=i);
    printf("name: ");scanf("%s",&l1[n].name);
    printf("phone: ");scanf("%s",&l1[n].phone);
    printf("email: ");scanf("%s",&l1[n].email);
    for(int j=0; j<i; j++)
        fprintf(f2,"%-30s%-12s%-30s\n",l1[j].name,l1[j].phone,l1[j].email);
    
    fclose(f1);
    fclose(f2);
    printf("Done");

    return 0;
}