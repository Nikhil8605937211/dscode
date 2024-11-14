#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    char stack[MAX_SIZE];
    int top = -1;
    char expression[MAX_SIZE];
    int i;

    printf("Enter an expression: ");
    fgets(expression, MAX_SIZE, stdin);

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            // Push the opening bracket onto the stack
            if (top == MAX_SIZE - 1) {
                printf("Stack overflow. Too many characters.\n");
                return -1;
            }
            stack[++top] = expression[i];
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            // Pop the stack and check if it matches the closing bracket
            if (top == -1) {
                printf("Unmatched closing bracket '%c' found.\n", expression[i]);
                return 0;
            }
            char lastBracket = stack[top--];
            if ((expression[i] == ')' && lastBracket != '(') ||
                (expression[i] == '}' && lastBracket != '{') ||
                (expression[i] == ']' && lastBracket != '[')) {
                printf("Mismatched brackets: '%c' and '%c'.\n", lastBracket, expression[i]);
                return 0;
            }
        }
    }

    if (top != -1) {
        printf("Unmatched opening bracket(s) found.\n");
    } else {
        printf("All brackets are matched.\n");
    }

    return 0;
}
