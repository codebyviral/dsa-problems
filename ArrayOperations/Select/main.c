#include <stdio.h>

// Function to perform selection sort
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j; // Update min_index if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Name: Viral Vaghela\n");
    printf("Roll Number: 23BIT224\n");


    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    print_array(array, size);

    // Perform selection sort
    selection_sort(array, size);

    printf("Sorted array: \n");
    print_array(array, size);

    return 0;
}