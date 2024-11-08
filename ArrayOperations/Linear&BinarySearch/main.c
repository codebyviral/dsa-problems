#include <stdio.h>

void linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Linear Search: Element %d found at index %d.\n", target, i);
            return;
        }
    }
    printf("Linear Search: Element %d not found.\n", target);
}

void binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Binary Search: Element %d found at index %d.\n", target, mid);
            return;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Binary Search: Element %d not found.\n", target);
}

int main() {
    printf("Name: Viral Vaghela\n");
    printf("Roll Number: 23BIT224\n");


    int array[] = {3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(array) / sizeof(array[0]);


    int target_linear = 9;
    linear_search(array, size, target_linear);


    int target_binary = 11;
    binary_search(array, size, target_binary);

    return 0;
}