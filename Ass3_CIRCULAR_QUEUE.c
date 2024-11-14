#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
  
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }


    if (front == -1) {
        front = 0;
    }


    rear = (rear + 1) % SIZE;
    queue[rear] = data;
    printf("Enqueued %d\n", data);
}

void dequeue() {

    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int data = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued %d\n", data);
}

void display() {

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
