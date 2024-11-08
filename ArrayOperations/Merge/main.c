#include <stdio.h>

// Function to merge two arrays into one
void merge_arrays(int array1[], int size1, int array2[], int size2, int merged_array[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements from both arrays
    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            merged_array[k++] = array1[i++];
        } else {
            merged_array[k++] = array2[j++];
        }
    }

    // Copy remaining elements of array1, if any
    while (i < size1) {
        merged_array[k++] = array1[i++];
    }

    // Copy remaining elements of array2, if any
    while (j < size2) {
        merged_array[k++] = array2[j++];
    }
}

// Function to print an array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    printf("Name: Viral Vaghela\n");
    printf("Roll Number: 23BIT224\n");

    // Two sample arrays for testing
    int array1[] = {1, 3, 5, 7};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {2, 4, 6, 8};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    // Merged array will have a size equal to the sum of both arrays
    int merged_array[size1 + size2];

    printf("Array 1: \n");
    print_array(array1, size1);

    printf("Array 2: \n");
    print_array(array2, size2);

    // Merge the two arrays
    merge_arrays(array1, size1, array2, size2, merged_array);

    printf("Merged Array: \n");
    print_array(merged_array, size1 + size2);

    return 0;
}