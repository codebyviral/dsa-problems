#include <stdio.h>

int main() {
    printf("Name: Viral Vaghela\n");
    printf("Roll Number: 23BIT224\n");

    // Original array
    int array[10];
    int size = sizeof(array) / sizeof(array[0]);

    // Input elements into the array
    printf("Enter 10 integer numbers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Position to split the array
    int position;
    printf("Enter position to split the array into two: ");
    scanf("%d", &position);

    // Ensure the position is valid
    if (position < 0 || position > size) {
        printf("Invalid position!\n");
        return 1;
    }

    // Create two new arrays for the split
    int firstArray[position];
    int secondArray[size - position];

    // Fill the first array
    for (int i = 0; i < position; i++) {
        firstArray[i] = array[i];
    }

    // Fill the second array
    for (int i = position; i < size; i++) {
        secondArray[i - position] = array[i];
    }

    // Print the results
    printf("Elements of First Array:\n");
    for (int i = 0; i < position; i++) {
        printf("%d ", firstArray[i]);
    }
    
    printf("\nElements of Second Array:\n");
    for (int i = 0; i < size - position; i++) {
        printf("%d ", secondArray[i]);
    }
    
    printf("\n");

    return 0;
}