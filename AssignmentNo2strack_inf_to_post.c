#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Stack structures
float float_stack[MAX];
char char_stack[MAX];
int float_top = -1;
int char_top = -1;

// Function prototypes
void match_parentheses();
void infix_to_postfix();
void evaluate_postfix();
void push_float(float value);
float pop_float();
void push_char(char value);
char pop_char();
int precedence(char op);
int is_operator(char ch);

// Main function
int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Check Matching Parentheses\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Evaluate Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character after scanf

        switch (choice) {
            case 1:
                match_parentheses();
                break;
            case 2:
                infix_to_postfix();
                break;
            case 3:
                evaluate_postfix();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to check matching parentheses
void match_parentheses() {
    char expression[MAX]; // Array to store the input expression
    char stack[MAX]; // Stack array to store the parentheses
    int top = -1; // Initialize the stack top to -1
    int i, valid = 1; // valid flag to check if the expression is balanced

    // Input the expression
    printf("Enter an expression with parentheses: ");
    fgets(expression, MAX, stdin);

    // Loop through the expression
    for (i = 0; expression[i] != '\0' && expression[i] != '\n'; i++) {
        // If an opening parenthesis is found, push it onto the stack
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            if (top < MAX - 1) {
                stack[++top] = expression[i];
            } else {
                printf("Stack Overflow\n");
                valid = 0;
                break;
            }
        }
        // If a closing parenthesis is found
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (top == -1) { // Check for stack underflow
                valid = 0;
                break;
            }
            char last = stack[top--]; // Pop the top of the stack
            // Check if the popped parenthesis matches the current closing parenthesis
            if ((expression[i] == ')' && last != '(') ||
                (expression[i] == '}' && last != '{') ||
                (expression[i] == ']' && last != '[')) {
                valid = 0;
                break;
            }
        }
    }

    // If the stack is not empty or the valid flag is not set, the expression is not balanced
    if (top != -1 || !valid) {
        printf("The expression is not balanced.\n");
    } else {
        printf("The expression is balanced.\n");
    }
}

// Function to convert infix to postfix
void infix_to_postfix() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    // Input the infix expression
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Loop through the infix expression
    for (i = 0; infix[i] != '\0' && infix[i] != '\n'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push_char(infix[i]);
        } else if (infix[i] == ')') {
            while (char_top != -1 && char_stack[char_top] != '(') {
                postfix[j++] = pop_char();
            }
            pop_char(); // Pop '('
        } else if (is_operator(infix[i])) {
            postfix[j++] = ' ';
            while (char_top != -1 && precedence(char_stack[char_top]) >= precedence(infix[i])) {
                postfix[j++] = pop_char();
                postfix[j++] = ' ';
            }
            push_char(infix[i]);
        }
    }

    // Pop the remaining operators from the stack
    while (char_top != -1) {
        postfix[j++] = ' ';
        postfix[j++] = pop_char();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);
}

// Function to evaluate postfix expression
void evaluate_postfix() {
    char postfix[MAX];
    int i;
    float op1, op2, value;

    // Input the postfix expression
    printf("Enter a postfix expression (use space to separate operands and operators): ");
    fgets(postfix, MAX, stdin);

    // Initialize the stack top to -1
    float_top = -1;

    // Loop through the postfix expression
    for (i = 0; postfix[i] != '\0' && postfix[i] != '\n'; i++) {
        // If the character is a digit, read the full number
        if (isdigit(postfix[i])) {
            value = 0;
            // Read the full number (to handle multi-digit numbers)
            while (isdigit(postfix[i])) {
                value = value * 10 + (postfix[i] - '0'); // Convert character to integer
                i++;
            }
            push_float(value);
            i--; // Adjust index for the next iteration
        } else if (postfix[i] == ' ') {
            continue;
        } else {
            // Operator case
            if (float_top < 1) { // Check if there are at least two operands
                printf("Error: Not enough operands for operation '%c'\n", postfix[i]);
                return;
            }

            float op2 = pop_float(); // Last pushed is the second operand
            float op1 = pop_float(); // Second last pushed is the first operand

            // Perform the operation based on the operator
            switch (postfix[i]) {
                case '+':
                    push_float(op1 + op2);
                    break;
                case '-':
                    push_float(op1 - op2);
                    break;
                case '*':
                    push_float(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        push_float(op1 / op2);
                    } else {
                        printf("Division by zero error\n");
                        return;
                    }
                    break;
                case '^':
                    push_float(pow(op1, op2));
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    return;
            }
        }
    }

    if (float_top != 0) { // Check if exactly one result remains in the stack
        printf("Error: Too many operands left in the stack.\n");
        return;
    }

    // Output the result
    printf("Result: %.2f\n", pop_float());
}

// Stack functions for postfix evaluation
void push_float(float value) {
    if (float_top < MAX - 1) {
        float_stack[++float_top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

float pop_float() {
    if (float_top != -1) {
        return float_stack[float_top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

// Stack functions for infix to postfix conversion
void push_char(char value) {
    if (char_top < MAX - 1) {
        char_stack[++char_top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

char pop_char() {
    if (char_top != -1) {
        return char_stack[char_top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

// Function to check precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
