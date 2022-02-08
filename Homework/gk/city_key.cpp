#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define TRUE 1
#define INVALID_CITY_CODE -1
 
// Khai báo ki?u c?u trúc City
struct City {
    int code;
    char name[100];
    float area;
    int population;
};
// Ð?nh nghia cho ki?u "struct City" 1 tên m?i ng?n g?n hon, thay vì khai báo ki?u "struct City" thì ta ch? c?n dùng "City"
typedef struct City City;
 
// Khai báo ki?u c?u trúc LinkedList
struct LinkedList{
    City city;
    struct LinkedList *next;
 };
 // Ð?nh nghia cho ki?u "struct LinkedList" 1 tên m?i ng?n g?n hon, thay vì khai báo ki?u "struct LinkedList" thì ta ch? c?n dùng "Node"
 typedef struct LinkedList *Node;
 
// Hàm t?o m?i 1 Node trong LinkedList
 Node createNode(City city){
    Node temp; // Khai báo 1 Node
    temp = (Node)malloc(sizeof(struct LinkedList)); // C?p phát vùng nh? cho Node
    temp->next = NULL;// Cho next tr? t?i NULL
    temp->city = city; // Gán giá tr? cho Node
    return temp;
}
 
// Thêm vào cu?i
Node addTail(Node head, City value){
    Node temp,p;// Khai báo 2 Node t?m temp và p
    temp = createNode(value);//G?i hàm createNode d? kh?i t?o Node temp có next tr? t?i NULL và giá tr? là value
    if(head == NULL){
        head = temp;     //N?u linked list dang tr?ng thì Node temp là head luôn
    }
    else{
        p  = head;// Kh?i t?o p tr? t?i head
        while(p->next != NULL){
            p = p->next;//Duy?t danh sách liên k?t d?n cu?i. Node cu?i là Node có next = NULL
        }
        p->next = temp;//Gán next c?a th?ng cu?i = temp. Khi dó temp s? là th?ng cu?i(temp->next = NULL mà)
    }
    return head;
}
 
 // Thêm vào d?u
Node addHead(Node head, City value){
    Node temp = createNode(value); // Kh?i t?o Node temp v?i data = value
    if(head == NULL){
        head = temp; // //N?u linked list dang tr?ng thì Node temp là head luôn
    }else{
        temp->next = head; // Tr? next c?a temp = head hi?n t?i
        head = temp; // Ð?i head hi?n t?i = temp(Vì temp bây gi? là head m?i mà)
    }
    return head;
}
 
 // Thêm vào ? "ch? s?" (b?t d?u t? 0) b?t k?, n?u mu?n thêm theo "v? trí" (b?t d?u t? 1) thì gi?m position di 1 don v?
Node addAt(Node head, City value, int position){
    position = position - 1; // Thêm theo v? trí
    if(position == 0 || head == NULL){
        head = addHead(head, value); // N?u v? trí chèn là 0, t?c là thêm vào d?u
    }else{
        // B?t d?u tìm v? trí c?n chèn. Ta s? dùng k d? d?m cho v? trí
        int k = 1;
        Node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh sách lk r?i mà v?n chua d?n v? trí c?n chèn, ta s? m?c d?nh chèn cu?i
            // N?u b?n không mu?n chèn, hãy thông báo v? trí chèn không h?p l?
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
 
 // Xóa Node ? "ch? s?" (b?t d?u t? 0) b?t k?
Node delAt(Node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = delHead(head); // N?u v? trí xóa là 0, t?c là thêm vào d?u
    }else{
        // B?t d?u tìm v? trí c?n xóa. Ta s? dùng k d? d?m cho v? trí
        int k = 1;
        Node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh sách lk r?i mà v?n chua d?n v? trí c?n chèn, ta s? m?c d?nh xóa cu?i
            // N?u b?n không mu?n xóa, hãy thông báo v? trí xóa không h?p l?
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
 
// Hàm kh?i t?o Node d?u tiên c?a LinkedList
Node initHead(){
    Node head;
    head = NULL;
    return head;
}
 
// Hàm tách các thành ph?n c?a 1 dòng trong file
City handleLineData(char *line){
    City city;
    city.code = INVALID_CITY_CODE; // Kh?i t?o giá tr? không h?p l?. V? sau ta có th? ki?m tra.
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
 
// Hàm d?c d? li?u t? t?p tin
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
    // Xóa \n ? cu?i chu?i v?a nh?p n?u có
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
 
// Hàm tìm ch? s? c?a Node có d? li?u thành ph? mà mã code c?a nó trùng v?i giá tr? c?n tìm
int findIndexByCode(Node head, int code){
    int index = -1;
    for(Node p = head; p != NULL; p = p->next){
        index++;
        if (p->city.code == code){
            return index;
        }
    }
    return -1; // Không tìm th?y
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
 
// Hàm tính t?ng di?n tích các thành ph? trong DSLK
float sumArea(Node head){
    float sum = 0;
    for(Node p = head; p != NULL; p = p->next){
        sum += p->city.area;
    }
    return sum;
}
 
 
// Hàm tìm ch? s? c?a Node có di?n tích l?n nh?t (gi? s? ch? có 1)
// N?u d? li?u có nhi?u hon 1, chúng ta tìm max r?i duy?t l?i 1 l?n n?a d? tìm ra các Node có giá tr? = max dó
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
 
// Hàm tìm Node có dân s? l?n nh?t
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
 
// Hàm s?p x?p 
// N?u sort theo code, thì byCode = 1, byArea = 0
// N?u sort theo area, thì byCode = 0, byArea = 1
// N?u s?p x?p tang d?n thì desc = 0, gi?m d?n thì desc = 1
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
                printf("Tinh co dien tich lon nhat o vi tri: %d\n", indexOfMaxArea(head) + 1); // v? trí = ch? s? + 1
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
