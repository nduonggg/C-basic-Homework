#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE *f1;
    if(argc == 3 && strcmp(argv[1],"cat") == 0){
        f1 = fopen(argv[2],"r");
        if(f1 == NULL){
            printf("Error");
            exit(1);
        }
        char str[80];
        int n;
        n = fread(str,sizeof(char),80,f1);
        str[n*sizeof(char)] = '\0';
        puts(str);
        fclose(f1);
        printf("Done");
    }else printf("Wrong cmd");
    

    return 0;
}