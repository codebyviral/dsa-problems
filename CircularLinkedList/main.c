#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    printf("Inserted %d\n", value);
}

void delete(int value) {
    if (head == NULL) {
        printf("Error: Linked list is empty\n");
        return;
    }

    struct Node* temp = head;
    if (temp->data == value) {
        if (temp->next == head) {
            head = NULL;
            free(temp);
            printf("Deleted %d\n", value);
            return;
        }
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        struct Node* del = head;
        head = head->next;
        free(del);
        printf("Deleted %d\n", value);
        return;
    }

    struct Node* prev = head;
    while (prev->next != head) {
        if (prev->next->data == value) {
            struct Node* del = prev->next;
            prev->next = del->next;
            free(del);
            printf("Deleted %d\n", value);
            return;
        }
        prev = prev->next;
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
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int search(int value) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return -1;
    }

    struct Node* temp = head;
    int index = 0;
    do {
        if (temp->data == value) {
            printf("%d found at index %d\n", value, index);
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != head);

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
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

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