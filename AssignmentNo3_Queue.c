#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

// Circular Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Stack structure for reversing using Queue
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function prototypes
void initializeQueue(CircularQueue* q);
int isFull(CircularQueue* q);
int isEmpty(CircularQueue* q);
void enqueue(CircularQueue* q, int value);
int dequeue(CircularQueue* q);
void displayQueue(CircularQueue* q);
void initializeStack(Stack* s);
int isStackFull(Stack* s);
int isStackEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
void reverseStackUsingQueue(Stack* s);

int main() {
    int choice;
    CircularQueue q;
    Stack s;
    
    initializeQueue(&q);
    initializeStack(&s);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Circular Queue\n");
        printf("2. Reverse Stack using Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int option, value;
                while (1) {
                    printf("\nCircular Queue Operations:\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display Queue\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &option);

                    switch (option) {
                        case 1:
                            printf("Enter a value to enqueue: ");
                            scanf("%d", &value);
                            enqueue(&q, value);
                            break;
                        case 2:
                            value = dequeue(&q);
                            if (value != -1) {
                                printf("Dequeued: %d\n", value);
                            }
                            break;
                        case 3:
                            displayQueue(&q);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice! Please enter a valid option.\n");
                    }
                    if (option == 4) break;
                }
                break;
            }
            case 2:
                printf("Enter the number of elements in the stack: ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    int value;
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &value);
                    push(&s, value);
                }
                reverseStackUsingQueue(&s);
                printf("Stack reversed successfully.\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Circular Queue functions
void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) { // Only one element was in the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Stack functions
void initializeStack(Stack* s) {
    s->top = -1;
}

int isStackFull(Stack* s) {
    return s->top == MAX - 1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isStackFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Indicates error
    }
    return s->items[s->top--];
}

// Function to reverse stack using queue
void reverseStackUsingQueue(Stack* s) {
    CircularQueue q;
    initializeQueue(&q);
    
    // Transfer stack elements to queue
    while (!isStackEmpty(s)) {
        enqueue(&q, pop(s));
    }
    
    // Transfer queue elements back to stack
    while (!isEmpty(&q)) {
        push(s, dequeue(&q));
    }
}
