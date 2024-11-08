#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX_SIZE - 1);
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n");
    printf("Is full? %d\n", isFull());
    return 0;
}