#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int peek() {
    if (front == -1 && rear == -1) {
        printf("Error: Queue is empty\n");
        printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n");
        return -1;
    }
    return queue[front];
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n");
    printf("Peeked value: %d\n", peek());
    return 0;
}