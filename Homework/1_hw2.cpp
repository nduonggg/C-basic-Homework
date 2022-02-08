#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(strcmp(argv[1],"mycp") == 0 && argc == 4){
        FILE *fin, *fout;
        fin = fopen(argv[2],"r");
        if(fin == NULL){
            printf("Cannot open file"); 
            exit(1);
        }
        fout = fopen(argv[3],"w");
        char c;
        while((c = fgetc(fin)) != EOF)
            fputc(c,fout);
        fclose(fout);
        fclose(fin); 
        printf("done");
    }else printf("Error");

    return 0;
    
}