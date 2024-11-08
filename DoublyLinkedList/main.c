#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Inserted %d\n", value);
}

void delete(int value) {
    if (head == NULL) {
        printf("Error: Linked list is empty\n");
        return;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Deleted %d\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Deleted %d\n", value);
            return;
        }
        temp = temp->next;
    }

    printf("Error: %d not found in the list\n", value);
}

void traverse() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(int value) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return -1;
    }

    struct Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at index %d\n", value, index);
            return index;
        }
        temp = temp->next;
        index++;
    }

    printf("%d not found in the list\n", value);
    return -1;
}

int count() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return 0;
    }

    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes: %d\n", count);
    return count;
}

int main() {
    printf("Name: Viral Vaghela\nRoll Number: 23BIT224\n\n");

    insert(10);
    insert(20);
    insert(30);
    traverse();
    search(20);
    delete(20);
    traverse();
    count();

    return 0;
}