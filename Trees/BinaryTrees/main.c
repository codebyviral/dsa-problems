#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node* data;
    struct Queue* next;
};


int minValue(struct Node* root);
struct Node* newNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* deleteNode(struct Node* root, int data);
void enqueue(struct Queue** front, struct Queue** rear, struct Node* node);
struct Node* dequeue(struct Queue** front, struct Queue** rear);
void traverseBFS(struct Node* root);
void traverseDFS_Inorder(struct Node* root);
int search(struct Node* root, int data);

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        root->data = minValue(root->right);  
        root->right = deleteNode(root->right, root->data);
    }

    return root;
}

int minValue(struct Node* root) {
    int minv = root->data;
    while (root->left != NULL) {
        root = root->left;
        minv = root->data;
    }
    return minv;
}

void enqueue(struct Queue** front, struct Queue** rear, struct Node* node) {
    struct Queue* newQueueNode = (struct Queue*)malloc(sizeof(struct Queue));
    newQueueNode->data = node;
    newQueueNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newQueueNode;
    } else {
        (*rear)->next = newQueueNode;
        *rear = newQueueNode;
    }
}

struct Node* dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) {
        return NULL;
    }

    struct Node* temp = (*front)->data;
    struct Queue* tempNode = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(tempNode);
    return temp;
}

void traverseBFS(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* front = NULL;
    struct Queue* rear = NULL;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        struct Node* current = dequeue(&front, &rear);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&front, &rear, current->left);
        }

        if (current->right != NULL) {
            enqueue(&front, &rear, current->right);
        }
    }
}

void traverseDFS_Inorder(struct Node* root) {
    if (root != NULL) {
        traverseDFS_Inorder(root->left);
        printf("%d ", root->data);
        traverseDFS_Inorder(root->right);
    }
}

int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    }

    int left = search(root->left, data);
    if (left) {
        return 1;
    }

    return search(root->right, data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Name: Viral Vaghela\n");
    printf("Roll Number: 23BIT224\n\n");

    printf("Binary Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Traverse using BFT (Breadth-First Traversal)\n");
    printf("4. Traverse using DFT (Depth-First Traversal)\n");
    printf("5. Search\n\n");

    printf("Inserting elements into the binary tree...\n");

    printf("Traversing the binary tree using BFT:\n");
    traverseBFS(root);
    printf("\n\n");

    printf("Traversing the binary tree using DFT (in-order):\n");
    traverseDFS_Inorder(root);
    printf("\n\n");

    printf("Searching for value 40 in the binary tree: %d\n\n", search(root, 40));

    printf("Deleting node with value 30 from the binary tree...\n");
    root = deleteNode(root, 30);

    printf("Traversing the binary tree using BFT:\n");
    traverseBFS(root);
    printf("\n\n");

    return 0;
}
