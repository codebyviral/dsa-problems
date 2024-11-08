#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Dequeued %d\n", value);
    return value;
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

int peek() {
    if (front == -1 && rear == -1) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    return queue[front];
}

void show() {
    if (front == -1 && rear == -1) {
        printf("Error: Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    show();
    printf("Peeked value: %d\n", peek());
    dequeue();
    show();
    printf("Is empty? %d\n", isEmpty());
    printf("Is full? %d\n", isFull());

    return 0;
}