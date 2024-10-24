#include <stdio.h>

void insert(int arr[], int *size) {
    printf("Name: Viral Vaghela\n");
    printf("Roll No: 23BIT224\n");

    if (*size >= 100) {
        printf("Array is full!\n");
        return;
    }
    
    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", *size);
    scanf("%d", &position);

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    (*size)++;
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
    int arr[100] = {1, 2, 3, 4, 5}; 
    int size = 5;

    insert(arr, &size);
    traverse(arr, size);
    
    return 0;
}