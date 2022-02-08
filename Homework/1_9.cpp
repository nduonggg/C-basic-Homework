#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *fin, *fout;
    fin = fopen("lab1.txt","r");
    if(fin == NULL){
        printf("Error");
        exit(1);
    }
    fout = fopen("lab1w.txt","w");
    while(!feof(fin)){
        char str[100];
        fgets(str,100,fin);
        fputs(str,fout);
    }
    fclose(fin);
    fclose(fout);
    printf("Done");

    return 0;

}
