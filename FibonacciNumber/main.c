#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void fibonacciSeries(int n) {
    push(0);
    push(1);
    printf("Fibonacci Series: %d ", stack[0]); 

    if (n > 0) {
        printf("%d ", stack[1]);
    }

    for (int i = 2; i <= n; i++) {
        int a = pop();
        int b = pop();
        push(a);        
        push(a + b);    
        printf("%d ", stack[top]);
    }
    printf("\n");
}

int main() {
    int n;
     printf("Viral Vaghela 23BIT224\n");
    printf("Enter how many Fibonacci numbers to generate: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Number of terms cannot be negative.\n"); 
        return 1;
    }

    fibonacciSeries(n);
    return 0;
}
