#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    
    return (front == -1 && rear == -1);
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n");
    printf("Is empty? %d\n", isEmpty());
    return 0;
}