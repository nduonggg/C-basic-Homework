#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE *f1, *f2;
    f1 = fopen(argv[1],"r");
    if(f1 == NULL){
        printf("Error1");
        exit(1);
    }
    f2 = fopen(argv[2],"r");
    if(f2 == NULL){
        printf("Error2");
        exit(1);
    }
    char str1[100], str2[100];
    while(!feof(f1) || !feof(f2)){
        fgets(str1,100,f1);
        fgets(str2,100,f2);
        if(strcmp(str1,str2) != 0)
            printf("%s\n%s\n\n",str1,str2);
    }
    

}