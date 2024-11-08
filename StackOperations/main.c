#include <stdio.h>

#define SIZE 5  


int push_operation(int* top, int arr[]) {
    printf("Viral Vaghela 23BIT224\n");
    if (*top == SIZE - 1) {
        printf("Stack overflow: Cannot push data, the stack is full.\n");
        return -1;
    }
    int data;
    printf("Enter the data to be pushed: ");
    scanf("%d", &data);
    (*top)++; 
    arr[*top] = data; 
    printf("Data %d pushed successfully!\n", data);
    return 0;
}


int pop_operation(int* top, int arr[]) {
    printf("Viral Vaghela 23BIT224\n");
    if (*top == -1) {
        printf("Stack underflow: Cannot pop data, the stack is empty.\n");
        return -1;
    }
    printf("Popped data is: %d\n", arr[*top]); 
    (*top)--; 
    return 0;
}


int main() {
    int arr[SIZE]; 
    int top = -1; 
    char choice;

    printf("Welcome to the Stack Operations Program!\n");
    printf("Available operations:\n");
    printf("p: Push data onto the stack\n");
    printf("d: Pop data from the stack\n");
    printf("q: Quit the program\n");

    while (1) { 
        printf("\nWhat do you want to do? (p/d/q): ");
        scanf(" %c", &choice); 

        switch (choice) {
            case 'p':
                push_operation(&top, arr); 
                break;
            case 'd':
                pop_operation(&top, arr); 
                break;
            case 'q':
                printf("Exiting the program. Goodbye!\n");
                return 0; 
            default:
                printf("Invalid choice! Please enter 'p', 'd', or 'q'.\n");
        }
    }

    return 0; 
}