#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    FILE *fin, *fout;
    fin = fopen("lab1.txt","r");
    if(fin == NULL){
        printf("Error");
        exit(1);
    }
    fout = fopen("lab1w.txt","w");
    char a;
    while((a=fgetc(fin)) != EOF){
        if(islower(a)) putc(toupper(a),fout);
        else putc(tolower(a),fout);
    }
    fclose(fin);
    fclose(fout);
    printf("Done");

    return 0;

}
