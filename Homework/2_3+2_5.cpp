#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 3){
        FILE *f1, *f2;
        f1 = fopen(argv[1],"r");
        if(f1 == NULL){
            printf("Error");
            exit(1);
        }
        f2 = fopen(argv[2],"w");
        char str[80];
        int n;
        n = fread(str,sizeof(char),80,f1);
        str[n*sizeof(char)] = '\0';
        fwrite(str,sizeof(char),n,f2);
        fclose(f1);
        fclose(f2);
        printf("Done");
    }else{
        printf(" %s <file1> <file2>",argv[0]);
        exit(1);
    }
    

    return 0;
}