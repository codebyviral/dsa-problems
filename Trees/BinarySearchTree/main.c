#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for Queue used in BFS
struct Queue {
    struct Node* data;
    struct Queue* next;
};

// Function declarations
struct Node* newNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* deleteNode(struct Node* root, int data);
int minValue(struct Node* root);
void enqueue(struct Queue** front, struct Queue** rear, struct Node* node);
struct Node* dequeue(struct Queue** front, struct Queue** rear);
void traverseBFS(struct Node* root);
void traverseDFS_Inorder(struct Node* root);
int search(struct Node* root, int data);

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the binary search tree
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

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }

    return root;
}

// Function to find the minimum value in a binary search tree
int minValue(struct Node* root) {
    int minv = root->data;
    while (root->left != NULL) {
        root = root->left;
        minv = root->data;
    }
    return minv;
}

// Function to perform breadth-first traversal (level-order traversal)
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

// Function to perform depth-first traversal (in-order traversal)
void traverseDFS_Inorder(struct Node* root) {
    if (root != NULL) {
        traverseDFS_Inorder(root->left);
        printf("%d ", root->data);
        traverseDFS_Inorder(root->right);
    }
}

// Function to search for a value in the binary search tree
int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Helper functions for the queue operations
void enqueue(struct Queue** front, struct Queue** rear, struct Node* node) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = node;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
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

int main() {
    printf("Name: Viral Vaghela\n");
    printf("Roll Number: 23BIT224\n");
    
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Binary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Traverse using BFT (Breadth-First Traversal)\n");
    printf("4. Traverse using DFT (Depth-First Traversal)\n");
    printf("5. Search\n\n");

    printf("Inserting elements into the binary search tree...\n");

    printf("Traversing the binary search tree using BFT:\n");
    traverseBFS(root);
    printf("\n\n");

    printf("Traversing the binary search tree using DFT (in-order):\n");
    traverseDFS_Inorder(root);
    printf("\n\n");

    printf("Searching for value 40 in the binary search tree: %d\n\n", search(root, 40));

    printf("Deleting node with value 30 from the binary search tree...\n");
    root = deleteNode(root, 30);

    printf("Traversing the binary search tree using BFT:\n");
    traverseBFS(root);
    printf("\n\n");

    return 0;
}
