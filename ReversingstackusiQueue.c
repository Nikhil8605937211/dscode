#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack and queue

// Stack and Queue structure
int stack[MAX];
int queue[MAX];
int top = -1; // Stack top index
int front = 0; // Queue front index
int rear = 0;  // Queue rear index

// Function to push an element onto the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

// Function to enqueue an element to the queue
void enqueue(int value) {
    if (rear < MAX) {
        queue[rear++] = value;
    } else {
        printf("Queue Overflow\n");
        exit(1);
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front < rear) {
        return queue[front++];
    } else {
        printf("Queue Underflow\n");
        exit(1);
    }
}

int main() {
    int n, value;

    // Input number of elements in the stack
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    // Input elements into the stack
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Transfer elements from the stack to the queue
    for (int i = 0; i < n; i++) {
        enqueue(pop());
    }

    // Transfer elements from the queue back to the stack (reversing the order)
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }

    // Output the reversed stack
    printf("Reversed stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
