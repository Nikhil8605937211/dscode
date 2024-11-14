#include<stdio.h>
#define MAX 100

int main() {
    int n;
    int choice;

    printf("Enter the limit for the array: ");
    scanf("%d", &n);

    int x[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int stack[MAX];
    int queue[MAX];
    int stack2[MAX];
    int top = -1;
    int top2 = -1;
    int front = 0;
    int rear = -1;

    do {
        printf("\nMenu:\n");
        printf("1. Push elements to Stack and print\n");
        printf("2. Transfer Stack to Queue and reverse to Stack2\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push elements to stack
                for (int i = 0; i < n; i++) {
                    if (top < MAX - 1) {
                        stack[++top] = x[i];
                    } else {
                        printf("Stack overflow\n");
                        return 1;
                    }
                }

                // Print stack elements
                printf("Stack elements:\n");
                for (int i = top; i >= 0; i--) {
                    printf("%3d ", stack[i]);
                }
                printf("\n");
                break;

            case 2:
                // Transfer stack to queue
                for (int i = top; i >= 0; i--) {
                    if (rear < MAX - 1) {
                        queue[++rear] = stack[i];
                    } else {
                        printf("Queue overflow\n");
                        return 1;
                    }
                }

                // Transfer queue to stack2
                for (int i = front; i <= rear; i++) {
                    if (top2 < MAX - 1) {
                        stack2[++top2] = queue[i];
                    } else {
                        printf("Stack2 overflow\n");
                        return 1;
                    }
                }

                // Print reversed stack elements
                printf("Reversed Stack elements:\n");
                for (int i = top2; i >= 0; i--) {
                    printf("%3d ", stack2[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
