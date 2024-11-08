#include <stdio.h>

void update(int arr[], int size) {
    printf("Name: Viral Vaghela\n");
    printf("Roll No: 23BIT224\n");

    int position, newValue;
    printf("Enter position to update (0 to %d): ", size - 1);
    scanf("%d", &position);
    
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter new value: ");
    scanf("%d", &newValue);
    
    arr[position] = newValue;
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
    int arr[100] = {11, 22, 23, 74, 35};
    int size = 5;

    update(arr, size);
    traverse(arr,size);
    
    return 0;
}