#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define TRUE 1
#define INVALID_CITY_CODE -1
 
// Khai b�o ki?u c?u tr�c City
struct City {
    int code;
    char name[100];
    float area;
    int population;
};
// �?nh nghia cho ki?u "struct City" 1 t�n m?i ng?n g?n hon, thay v� khai b�o ki?u "struct City" th� ta ch? c?n d�ng "City"
typedef struct City City;
 
// Khai b�o ki?u c?u tr�c LinkedList
struct LinkedList{
    City city;
    struct LinkedList *next;
 };
 // �?nh nghia cho ki?u "struct LinkedList" 1 t�n m?i ng?n g?n hon, thay v� khai b�o ki?u "struct LinkedList" th� ta ch? c?n d�ng "Node"
 typedef struct LinkedList *Node;
 
// H�m t?o m?i 1 Node trong LinkedList
 Node createNode(City city){
    Node temp; // Khai b�o 1 Node
    temp = (Node)malloc(sizeof(struct LinkedList)); // C?p ph�t v�ng nh? cho Node
    temp->next = NULL;// Cho next tr? t?i NULL
    temp->city = city; // G�n gi� tr? cho Node
    return temp;
}
 
// Th�m v�o cu?i
Node addTail(Node head, City value){
    Node temp,p;// Khai b�o 2 Node t?m temp v� p
    temp = createNode(value);//G?i h�m createNode d? kh?i t?o Node temp c� next tr? t?i NULL v� gi� tr? l� value
    if(head == NULL){
        head = temp;     //N?u linked list dang tr?ng th� Node temp l� head lu�n
    }
    else{
        p  = head;// Kh?i t?o p tr? t?i head
        while(p->next != NULL){
            p = p->next;//Duy?t danh s�ch li�n k?t d?n cu?i. Node cu?i l� Node c� next = NULL
        }
        p->next = temp;//G�n next c?a th?ng cu?i = temp. Khi d� temp s? l� th?ng cu?i(temp->next = NULL m�)
    }
    return head;
}
 
 // Th�m v�o d?u
Node addHead(Node head, City value){
    Node temp = createNode(value); // Kh?i t?o Node temp v?i data = value
    if(head == NULL){
        head = temp; // //N?u linked list dang tr?ng th� Node temp l� head lu�n
    }else{
        temp->next = head; // Tr? next c?a temp = head hi?n t?i
        head = temp; // �?i head hi?n t?i = temp(V� temp b�y gi? l� head m?i m�)
    }
    return head;
}
 
 // Th�m v�o ? "ch? s?" (b?t d?u t? 0) b?t k?, n?u mu?n th�m theo "v? tr�" (b?t d?u t? 1) th� gi?m position di 1 don v?
Node addAt(Node head, City value, int position){
    position = position - 1; // Th�m theo v? tr�
    if(position == 0 || head == NULL){
        head = addHead(head, value); // N?u v? tr� ch�n l� 0, t?c l� th�m v�o d?u
    }else{
        // B?t d?u t�m v? tr� c?n ch�n. Ta s? d�ng k d? d?m cho v? tr�
        int k = 1;
        Node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh s�ch lk r?i m� v?n chua d?n v? tr� c?n ch�n, ta s? m?c d?nh ch�n cu?i
            // N?u b?n kh�ng mu?n ch�n, h�y th�ng b�o v? tr� ch�n kh�ng h?p l?
            head = addTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            Node temp = createNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 
Node delHead(Node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
Node delTail(Node head){
    if (head == NULL || head->next == NULL){
         return delHead(head);
    }
    Node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next b?ng NULL
    return head;
}
 
 // X�a Node ? "ch? s?" (b?t d?u t? 0) b?t k?
Node delAt(Node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = delHead(head); // N?u v? tr� x�a l� 0, t?c l� th�m v�o d?u
    }else{
        // B?t d?u t�m v? tr� c?n x�a. Ta s? d�ng k d? d?m cho v? tr�
        int k = 1;
        Node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh s�ch lk r?i m� v?n chua d?n v? tr� c?n ch�n, ta s? m?c d?nh x�a cu?i
            // N?u b?n kh�ng mu?n x�a, h�y th�ng b�o v? tr� x�a kh�ng h?p l?
            head = delTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
void traverser(Node head){
    printf("Danh sach hien tai:\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("%10s%50s%20s%20s\n", "Ma Tinh/TP", "Tinh thanh", "Dien tich", "Dan so");
    for(Node p = head; p != NULL; p = p->next){
        printf("%10d%50s%20f%20d\n", p->city.code, p->city.name, p->city.area, p->city.population);
    }
    printf("------------------------------------------------------------------------------------------------------------\n");
}
 
// H�m kh?i t?o Node d?u ti�n c?a LinkedList
Node initHead(){
    Node head;
    head = NULL;
    return head;
}
 
// H�m t�ch c�c th�nh ph?n c?a 1 d�ng trong file
City handleLineData(char *line){
    City city;
    city.code = INVALID_CITY_CODE; // Kh?i t?o gi� tr? kh�ng h?p l?. V? sau ta c� th? ki?m tra.
    const char delimiter[] = "\t";
    char *tmp;
    tmp = strtok(line, delimiter);
    if (tmp == NULL) {
        printf("Du lieu khong dung dinh dang: %s", line);
        exit(EXIT_FAILURE);
    }
   city.code = atoi(tmp);
    int index = 0;
    for (;;index++) {
        tmp = strtok(NULL, delimiter);
        if (tmp == NULL)
            break;
        if (index == 0){
            strcpy(city.name, tmp);
        }else if (index == 1){
           city.area = (float)atof(tmp);
        }else if (index == 2){
            city.population = atoi(tmp);
        }else {
            printf("Du lieu khong dung dinh dang: %s", line);
            exit(EXIT_FAILURE);
        }
    }
    return city;
}
 
// H�m d?c d? li?u t? t?p tin
Node readData(Node head, const char* fileName){
    FILE* file = fopen(fileName, "r");
    if(!file){
        printf("Co loi khi mo file : %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    char line[500];
    while (fgets(line, sizeof(line), file)) {
        City city = handleLineData(line);
        if (city.code != INVALID_CITY_CODE) {
            head = addTail(head, city);
        }
    }
    fclose(file);
    return head;
}
 
City createCity(){
    City newCity;
    char *p;
    printf("Nhap code: ");
    scanf("%d", &newCity.code);
    printf("Nhap ten: ");
    getchar();
    fgets(newCity.name, 100, stdin);
    // X�a \n ? cu?i chu?i v?a nh?p n?u c�
    if ((p=strchr(newCity.name, '\n')) != NULL){
        *p = '\0';
    }
    printf("Nhap dien tich: ");
    scanf("%f", &newCity.area);
    printf("Nhap dan so: ");
    scanf("%d", &newCity.population);
    return newCity;
}
 
Node addNode(Node head){
    City newCity;
    char option;
    int position;
    while (TRUE) {
        printf("========== Nhap du lieu can them ===============\n");
        printf("Nhap vi tri muon them: ");
        scanf("%d", &position);
        newCity = createCity();
        head = addAt(head, newCity, position);
        printf("Them thanh cong? Them tiep (Y/n)? ");
        getchar(); // B? qua '\n' trong b? d?m
        scanf("%c", &option);
        if (option == 'N' || option == 'n'){
            break;
        }
    }
    return head;
}
 
// H�m t�m ch? s? c?a Node c� d? li?u th�nh ph? m� m� code c?a n� tr�ng v?i gi� tr? c?n t�m
int findIndexByCode(Node head, int code){
    int index = -1;
    for(Node p = head; p != NULL; p = p->next){
        index++;
        if (p->city.code == code){
            return index;
        }
    }
    return -1; // Kh�ng t�m th?y
}
 
void editNode(Node head){
    int code;
    char option;
    City newCity;
    while (TRUE) {
        printf("========== Chon Node muon sua ===============\n");
        printf("Nhap ma tinh/thanh pho can sua: ");
        scanf("%d", &code);
        int found = 0;
        for(Node p = head; p != NULL; p = p->next){
            if (p->city.code == code){
                found = 1;
                newCity = createCity();
                p->city = newCity;
                break;
            }
        }
        if (found) {
            printf("Sua thanh cong! Sua tiep (Y/n)? ");
        }else {
            printf("Khong tim thay du lieu! Sua tiep (Y/n)? ");
        }
        getchar(); // B? qua '\n' trong b? d?m
        scanf("%c", &option);
        if (option == 'N' || option == 'n'){
            break;
        }
    }
}
 
Node removeNode(Node head){
    int code;
    char option;
    while (TRUE) {
        printf("========== Chon Node muon xoa ===============\n");
        printf("Nhap ma tinh/thanh pho can xoa: ");
        scanf("%d", &code);
        int position = findIndexByCode(head, code);
        if (position < 0){
            printf("Khong tim thay du lieu can xoa! Xoa tiep (Y/n)? ");
        }else {
            head = delAt(head, position);
            printf("Xoa thanh cong? Xoa tiep (Y/n)? ");
        }
        getchar(); // B? qua '\n' trong b? d?m
        scanf("%c", &option);
        if (option == 'N' || option == 'n'){
            break;
        }
    }
    return head;
}
 
// H�m t�nh t?ng di?n t�ch c�c th�nh ph? trong DSLK
float sumArea(Node head){
    float sum = 0;
    for(Node p = head; p != NULL; p = p->next){
        sum += p->city.area;
    }
    return sum;
}
 
 
// H�m t�m ch? s? c?a Node c� di?n t�ch l?n nh?t (gi? s? ch? c� 1)
// N?u d? li?u c� nhi?u hon 1, ch�ng ta t�m max r?i duy?t l?i 1 l?n n?a d? t�m ra c�c Node c� gi� tr? = max d�
int indexOfMaxArea(Node head){
    int maxIndex = 0, index = 0;
    int maxArea = head->city.area;
    for(Node p = head; p != NULL; p = p->next){
        if (p->city.area > maxArea){
            maxArea = p->city.area;
            maxIndex = index;
        }
        index++;
    }
    return maxIndex;
}
 
// H�m t�m Node c� d�n s? l?n nh?t
City maxByPopulation(Node head){
    City city = head->city;
    for(Node p = head; p != NULL; p = p->next){
        if (p->city.population > city.population){
            city = p->city;
        }
    }
    return city;
}
 
void swapCityData(City *a, City *b){
    City tmp = *a;
    *a = *b;
    *b = tmp;
}
 
// H�m s?p x?p 
// N?u sort theo code, th� byCode = 1, byArea = 0
// N?u sort theo area, th� byCode = 0, byArea = 1
// N?u s?p x?p tang d?n th� desc = 0, gi?m d?n th� desc = 1
void sortCities(Node head, int byCode, int byArea, int desc){
    for(Node p = head; p != NULL; p = p->next){
        for(Node q = p->next; q != NULL; q = q->next){
            if (desc){
                if (byCode && p->city.code < q->city.code){
                    swapCityData(&p->city, &q->city);
                }else if (byArea && p->city.area < q->city.area){
                    swapCityData(&p->city, &q->city);
                }
            }else {
                if (byCode && p->city.code > q->city.code){
                swapCityData(&p->city, &q->city);
                }else if (byArea && p->city.area > q->city.area){
                    swapCityData(&p->city, &q->city);
                }
            }
        }
    }
}
 
void printMenu(){
    printf("================== MENU ====================\n");
    printf("1. Duyet danh sach\n");
    printf("2. Them du lieu (them Node)\n");
    printf("3. Sua du lieu (sua Node)\n");
    printf("4. Xoa du lieu (xoa Node)\n");
    printf("5. Tinh tong dien tich\n");
    printf("6. Tim dia chi cua Node co dien tich lon nhat\n");
    printf("7. Tim tinh co dan so lon nhat\n");
    printf("8. Sap xep danh sach theo ma tinh\n");
    printf("9. Sap xep danh sach theo dien tich\n");
    printf("10. Thoat chuong trinh\n");
    printf("============================================\n");
}
 
int main(){
    Node head = initHead();
    head = readData(head, "city.txt");
    traverser(head);
    int option;
    City result;
    while (TRUE) {
        printMenu();
        printf("Nhap lua chon cua ban (1-10): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                traverser(head);
                break;
            case 2:
                head = addNode(head);
                break;
            case 3:
                editNode(head);
                break;
            case 4:
                head = removeNode(head);
                break;
            case 5:
                printf("Tong dien tich: %f\n", sumArea(head));
                break;
            case 6:
                printf("Tinh co dien tich lon nhat o vi tri: %d\n", indexOfMaxArea(head) + 1); // v? tr� = ch? s? + 1
                break;
            case 7:
                result = maxByPopulation(head);
                printf("%s la noi co dien tich lon nhat voi %d nguoi!\n", result.name, result.population);
                break;
            case 8:
                sortCities(head, 1, 0, 0);
                traverser(head);
                break;
            case 9:
                sortCities(head, 0, 1, 0);
                traverser(head);
                break;
            case 10:
                printf("Ket thuc chuong trinh!...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Lua chon khong dung, vui long nhap lai!\n");
                break;
        }
    }
}
