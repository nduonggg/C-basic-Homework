#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct address{
    char name[30];
    char phone[12];
    char email[30];
}address;

int linearSearch(address l1[], int sl, char* x){
    for(int i=0; i<sl; i++)
        if(strcmp(l1[i].name,x) == 0) return i;
    return -1;
}

void xoa_n(char*str){
    int len = strlen(str);
    if(str[len-1]=='\n') str[len-1]='\0';
}

int main(){
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
    char x[30];
    printf("Nhap ten can tim: ");
    fgets(x,30,stdin);xoa_n(x);
    int sreach = linearSearch(l1,sl,x);
    if(sreach!=-1)
        printf("%-30s%-12s%-30s",l1[sreach].name,l1[sreach].phone,l1[sreach].email);
    else printf("Not found");
    fclose(f1);
    return 0;
}