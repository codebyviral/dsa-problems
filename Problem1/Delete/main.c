#include <stdio.h>

void delete(int arr[], int *size) {
    printf("Name: Viral Vaghela\n");
    printf("Roll No: 23BIT224\n");

    int position;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
}

void traverse(int arr[], int size) {
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

    delete(arr, &size);
    traverse(arr, size);
    
    return 0;
}