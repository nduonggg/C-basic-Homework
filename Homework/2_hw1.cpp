#include <stdio.h>
#include <string.h>
struct dienthoai{
    char Model[10];
    char Memory[10];
    char DisplaySize[15];
    char Price[10];
};

int main(){
    FILE* fin=fopen("NokiaDB.txt","r");
    FILE* fout=fopen("NokiaDB2.dat","wb");

    if(fin==NULL||fout==NULL){
        printf("Error opening file!\n");
        return 1;
    }

    struct dienthoai list[5];
    int soluong=0;
    char timkiem[10];

    while(!feof(fin)){
        fscanf(fin,"%s %s %s %s",list[soluong].Model,list[soluong].Memory,list[soluong].DisplaySize,list[soluong].Price);
        fprintf(fout,"%-10s %-10s %-15s %-10s\n",list[soluong].Model,list[soluong].Memory,list[soluong].DisplaySize,list[soluong].Price);
        printf("%-10s %-10s %-15s %-10s\n",list[soluong].Model,list[soluong].Memory,list[soluong].DisplaySize,list[soluong].Price);
        soluong++;
    }

    printf("Enter model name: ");
    gets(timkiem);
    fflush(stdin);
    for (int i = 0; i <soluong ; ++i) {
        if(strcmp(timkiem,list[i].Model)==0){
            printf("%-10s %-10s %-15s %-10s\n",list[i].Model,list[i].Memory,list[i].DisplaySize,list[i].Price);
            break;
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
