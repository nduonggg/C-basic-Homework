#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sreach(char data[][15], char x[15], int sl, int slx){
    int k;
    for(int i=0; i<sl; i++){
        k=0;
        for(int j=0; j<slx; j++)
            if(data[i][j] != x[j]) k=1;
        if(k==0)
            printf("%s\n",data[i]);
    }
}

void xoa_n(char*str){
    int len = strlen(str);
    if(str[len-1]=='\n') str[len-1]='\0';
}

int main(){
    FILE *f1;
    f1 = fopen("data.txt","r");
    if(f1==NULL){
        printf("Error");
        exit(1);
    }
    char data[50][15],x[15];
    int sl=0;
    while(!feof(f1)){
        fscanf(f1,"%s",&data[sl]);
        sl++;
    }
    printf("Nhap tu khoa can tim: ");
    fgets(x,15,stdin);
    xoa_n(x);
    int slx = strlen(x);
    sreach(data,x,sl,slx);
    return 0;
}