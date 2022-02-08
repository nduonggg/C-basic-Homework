#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE *fin;
    fin = fopen(argv[2],"r");
    if(fin == NULL){
        printf("Error");
        exit(1);
    }
    if(argc == 3 && strcmp(argv[1],"cat") == 0){
        while(!feof(fin)){
            char str[100];
            fgets(str,100,fin);
            puts(str);
        }
    }
    if(argc == 4 && strcmp(argv[1],"cat") == 0
        && strcmp(argv[3],"1st_ln") == 0){
        char str[100];
        fgets(str,100,fin);
        puts(str);
    }
    
    fclose(fin);
    printf("Done");

    return 0;

}
