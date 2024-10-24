#include <stdio.h>

void create(int arr[], int *size) {
    printf("Name: Viral Vaghela\n");
    printf("Roll No: 23BIT224\n");
    
    printf("Enter number of elements: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
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
    int arr[100];
    int size = 0;
    
    create(arr, &size);
    traverse(arr, size);
    
    return 0;
}