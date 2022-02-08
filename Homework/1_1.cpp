#include<stdio.h>
#include<string.h>

void xoaXuongDong(char str[]){
    int len=strlen(str);
    if(str[len-1]=='\n') str[len-1]='\0';
}
int main(){
    int count[26]={0};
    char alphabet[26]={'a','b','c','d','e','f','g','h','i',
				'j','k','l','m','n','o','p','q','r',
				's','t','u','v','w','x','y','z'};
    char str[100];
    printf("Input: ");
    fgets(str,100,stdin);
    strlwr(str);
    xoaXuongDong(str);
    int len=strlen(str);
    for(int i=0;i<26;i++)
        for(int j=0;j<len;j++)
            if(alphabet[i]==str[j]) count[i]++;
    for(int i=0;i<26;i++)
        if(count[i]>0) printf("%c: %d\n",alphabet[i],count[i]);
    return 0;
}
