#include<stdio.h>
#include<string.h>

int main(){
    FILE *fin,*fout;
    fin = fopen("lab1.txt","r");
    if(fin == NULL) printf("Cannot open file");
    else{
        fout = fopen("lab1w.txt","w");
        char c;
        while((c = fgetc(fin)) != EOF)
            fputc(c,fout);
        fclose(fout);
        printf("Saved on file");
    }
    fclose(fin);
return 0;
}