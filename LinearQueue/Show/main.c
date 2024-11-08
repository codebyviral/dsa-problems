#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void show() {
    if (front == -1 && rear == -1) {
        printf("Error: Queue is empty\n");
        return;
    }
    
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n\n");
    
    queue[++rear] = 10;
    queue[++rear] = 20;
    queue[++rear] = 30;
    front = 0;
    
    show();
    
    return 0;
}