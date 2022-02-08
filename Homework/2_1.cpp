#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void xoa_n(char *s){
    int len = strlen(s);
    if(s[len-1] = '\n') s[len-1] = '\0';
}

char *my_strcat(char *s1, char *s2){
    char *s = (char*)malloc((strlen(s1)+strlen(s2))*sizeof(char));
    strcpy(s,s1);
    strcat(s,s2);
    return s;
}

int main(){
    char s1[100], s2[100];
    printf("Nhap s1,s2: ");
    fgets(s1,100,stdin); xoa_n(s1);
    fgets(s2,100,stdin); xoa_n(s2);
    char *s = (char*)malloc((strlen(s1)+strlen(s2))*sizeof(char));
    s = my_strcat(s1,s2);
    puts(s);
    free(s);
    return 0;
}