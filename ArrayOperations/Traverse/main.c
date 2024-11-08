#include <stdio.h>

void traverse(int arr[], int size) {
    printf("Name: Viral Vaghela\n");
    printf("Roll No: 23BIT224\n");

   if (size == 0) {
        printf("Array is empty!\n");
        return;
   }
   
   printf("Array elements:\n");
   for (int i = 0; i < size; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");
}

int main() {
    int arr[100] = {100, 200, 300, 400, 500}; 
   int size = 5;
   traverse(arr, size);
   return 0;
}