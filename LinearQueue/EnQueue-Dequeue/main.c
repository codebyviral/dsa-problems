#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int enqueue_operation(int *rear, int size, int arr[], int *front) {
    if (*rear >= size - 1) {
        printf("Queue overflow\n");
        return -1;
    }
    int data;
    printf("Enter the data to be enqueued: ");
    scanf("%d", &data);
    if (*front == -1) *front = 0;
    arr[++(*rear)] = data;
    return 0;
}

int dequeue_operation(int *front, int *rear, int arr[]) {
    if (*front == -1 || *front > *rear) {
        printf("Queue underflow\n");
        return -1;
    }
    printf("Dequeued data is: %d\n", arr[(*front)++]);
    if (*front > *rear) {
        *front = *rear = -1;
    }
    return 0;
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n\n");

    int size = 2;
    int arr[size];
    int front = -1, rear = -1;
    char choice;
    printf("q: quit, e: enqueue, d: dequeue\n");
    printf("What do you want to do ------> ");
    scanf(" %c", &choice);
    while (choice != 'q') {
        switch (choice) {
            case 'e':
                enqueue_operation(&rear, size, arr, &front);
                break;
            case 'd':
                dequeue_operation(&front, &rear, arr);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("What do you want to do? ");
        scanf(" %c", &choice);
    }
    return 0;
}