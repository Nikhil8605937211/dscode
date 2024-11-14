#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack structures for characters and strings
char stack[MAX];
int top = -1;

// Push function for stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop function for stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1; // Return -1 if stack is empty
}

// Function to reverse a string
void reverse(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to check if a character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert postfix to prefix
void postfix_to_prefix(char *postfix, char *prefix) {
    int i, j = 0;
    int len = strlen(postfix);
    
    // Traverse the postfix expression from right to left
    for (i = len - 1; i >= 0; i--) {
        char c = postfix[i];
        
        // If the character is an operand (alphanumeric), push it to the stack
        if (isalnum(c)) {
            push(c);
        }
        // If the character is an operator
        else if (is_operator(c)) {
            char op1 = pop();
            char op2 = pop();
            
            // Form a prefix expression and push it back to the stack
            prefix[j++] = c;  // Operator comes first
            prefix[j++] = op1; // Operand 1
            prefix[j++] = op2; // Operand 2
        }
    }
    prefix[j] = '\0'; // Null-terminate the prefix expression
    
    // Reverse the resulting prefix expression
    reverse(prefix);
}

int main() {
    char postfix[MAX], prefix[MAX];
    
    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Call the function to convert postfix to prefix
    postfix_to_prefix(postfix, prefix);
    
    // Output the prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
