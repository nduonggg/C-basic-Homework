#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *fin;
    fin = fopen("lab1.txt","r");
    if(fin == NULL){
        printf("Error");
        exit(1);
    }
    char c;
    int i = 2;
    printf("1 ");
    while((c=fgetc(fin)) != EOF){
        if(c != '\n' && c != '\0') printf("%c",c);
        else{
            printf("\n%d ",i);
            i++;
        }
    }
    
    return 0;
}