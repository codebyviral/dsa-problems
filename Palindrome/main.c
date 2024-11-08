#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void push(char stack[], char element, int *top) {
    stack[(*top)++] = element;
}

char pop(char stack[], int *top) {
    return stack[--(*top)];
}

int isPalindrome(char str[]) {
    int top = 0;
    char stack[MAX_SIZE];
    
    for (int i = 0; i < strlen(str); i++) {
        push(stack, str[i], &top);
    }
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != pop(stack, &top)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char num[MAX_SIZE];
    
    printf("Viral Vaghela 23BIT224\n");
    printf("Enter a number: ");
    scanf("%s", num);
    
    if (isPalindrome(num)) {
        printf("%s is a palindrome number.\n", num);
    } else {
        printf("%s is not a palindrome number.\n", num);
    }
    
    return 0;
}