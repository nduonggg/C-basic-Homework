#include<stdio.h>
#include<string.h>

void xoaXuongDong(char str[]){
    int len = strlen(str);
    if(str[len-1] == '\n') str[len-1] = '\0';
}

void thayTheKiTu(char str[], char a, char b){
    int len = strlen(str);
    for(int i=0; i<len; i++)
        if(str[i] == a) str[i] = b;
}

int main(){
    char str[100];
    char a,b;
    printf("Input: ");fgets(str,100,stdin);
    xoaXuongDong(str);
    printf("Nhap a,b: ");scanf("%c %c",&a,&b);
    thayTheKiTu(str,a,b);
    puts(str);
return 0;
}