#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct address{
    char name[30];
    char phone[12];
    char email[30];
}address;

int main(){
    address l1[20],l2[20];
    FILE *f1,*f2;
    f1 = fopen("6_31.txt","r");
    f2 = fopen("6_32.txt","r");
    if(f1==NULL){
        printf("Error");
        exit(1);
    }
    if(f2==NULL){
        printf("Error");
        exit(1);
    }
    int sl1=0,sl2=0;
    while(!feof(f1)){
        fscanf(f1,"%s %s %s",&l1[sl1].name,&l1[sl1].phone,&l1[sl1].email);
        sl1++;
    }
    while(!feof(f2)){
        fscanf(f2,"%s %s %s",&l2[sl2].name,&l2[sl2].phone,&l2[sl2].email);
        sl2++;
    }
    int k1=0,k2=0;
    printf("(1)\n");
    for(int i=0; i<sl1; i++){
        k1=0;
        for(int j=0; j<sl2; j++)
            if(strcmp(l1[i].name,l2[j].name)==0
                && strcmp(l1[i].phone,l2[j].phone)==0
                && strcmp(l1[i].email,l2[j].email)==0)
            k1=1;
        if(k1!=1)
            printf("%-30s%-12s%-30s\n",l1[i].name,l1[i].phone,l1[i].email);
        
        
        
    }
    printf("(2)\n");
    for(int i=0; i<sl2; i++){
        k2=0;
        for(int j=0; j<sl1; j++)
            if(strcmp(l2[i].name,l1[j].name)==0
                && strcmp(l2[i].phone,l1[j].phone)==0
                && strcmp(l2[i].email,l1[j].email)==0)
            k2=1;
        if(k2!=1)
            printf("%-30s%-12s%-30s\n",l2[i].name,l2[i].phone,l2[i].email);
        
        
    }
    fclose(f1);fclose(f2);

    return 0;
}