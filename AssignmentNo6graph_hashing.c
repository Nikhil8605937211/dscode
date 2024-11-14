#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue for BFS
struct Queue {
    int items[MAX];
    int front, rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue *q) {
    return q->front == -1;
}

int isQueueFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Stack for DFS
struct Stack {
    int items[MAX];
    int top;
};

void initializeStack(struct Stack *s) {
    s->top = -1;
}

int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

int isStackFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top--];
}

// Graph structure
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};

void initializeGraph(struct Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // For undirected graph
}

void bfs(struct Graph *g, int startVertex) {
    struct Queue q;
    initializeQueue(&q);

    int visited[MAX] = {0};

    printf("BFS Traversal: ");
    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void dfs(struct Graph *g, int startVertex) {
    struct Stack s;
    initializeStack(&s);

    int visited[MAX] = {0};

    printf("DFS Traversal: ");
    visited[startVertex] = 1;
    push(&s, startVertex);

    while (!isStackEmpty(&s)) {
        int currentVertex = pop(&s);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                push(&s, i);
            }
        }
    }
    printf("\n");
}

// Hashing with Linear Probing
#define TABLE_SIZE 11

int hashTable[TABLE_SIZE];
int currentSize = 0;

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    if (currentSize == TABLE_SIZE) {
        printf("Hash Table is full\n");
        return;
    }

    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
    currentSize++;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("Slot %d: Empty\n", i);
        } else {
            printf("Slot %d: %d\n", i, hashTable[i]);
        }
    }
}

// Main function
int main() {
    int choice;
    struct Graph g;
    int vertices;
    int src, dest;
    int startVertex;
    int key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Implement BFS\n");
        printf("2. Implement DFS\n");
        printf("3. Insert in Hash Table (Linear Probing)\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                initializeGraph(&g, vertices);

                printf("Enter edges (src dest), -1 -1 to stop:\n");
                while (1) {
                    scanf("%d %d", &src, &dest);
                    if (src == -1 && dest == -1) break;
                    addEdge(&g, src, dest);
                }

                printf("Enter the start vertex for BFS: ");
                scanf("%d", &startVertex);
                bfs(&g, startVertex);
                break;

            case 2:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                initializeGraph(&g, vertices);

                printf("Enter edges (src dest), -1 -1 to stop:\n");
                while (1) {
                    scanf("%d %d", &src, &dest);
                    if (src == -1 && dest == -1) break;
                    addEdge(&g, src, dest);
                }

                printf("Enter the start vertex for DFS: ");
                scanf("%d", &startVertex);
                dfs(&g, startVertex);
                break;

            case 3:
                initializeHashTable();
                printf("Enter keys to insert, -1 to stop:\n");
                while (1) {
                    scanf("%d", &key);
                    if (key == -1) break;
                    insert(key);
                }
                break;

            case 4:
                displayHashTable();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
