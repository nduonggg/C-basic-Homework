#include <stdio.h>
#include <string.h>
 
int main (void) {
   char string[] = "VietTuts.VN";
   char temp;
 
   int i, j;
    
    
   int size = strlen(string);
 
   printf("Chuoi truoc khi sap xep: %s \n", string);
 
   for (i = 0; i < size-1; i++) {
      for (j = i+1; j < size; j++) {
         if (string[i] > string[j]) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
   }
    
   printf("\nChuoi sau khi sap xep %s \n", string);
   return 0;
}
