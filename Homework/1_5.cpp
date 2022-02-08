#include<stdio.h>
#include<string.h>

void xoaXuongDong(char *str){
    int len = strlen(str);
    if(str[len-1] == '\n') str[len-1] = '\0';
}
void replace_char(char *str, char c1, char c2){
    for(int i=0; i<strlen(str); i++)
        if(str[i] == c1) str[i] = c2;
}

int main(){
    char str[100],c1,c2;
    printf("Input: ");fgets(str,100,stdin);
    xoaXuongDong(str);
    printf("Nhap c1,c2: ");scanf("%c %c",&c1,&c2);
    replace_char(str,c1,c2);
    puts(str);

}