#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insert_front(struct Node** head, int data);
void insert_end(struct Node** head, int data);
void insert_at_position(struct Node** head, int data, int position);
void delete_front(struct Node** head);
void delete_end(struct Node** head);
void delete_at_position(struct Node** head, int position);
void display_list(struct Node* head);

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the linked list
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Given Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Given Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insert_front(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(&head, data, position);
                break;
            case 4:
                delete_front(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;
            case 7:
                display_list(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to insert a node at the front
void insert_front(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    printf("Node inserted at front: %d\n", data);
}

// Function to insert a node at the end
void insert_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        printf("Node inserted at end: %d\n", data);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    printf("Node inserted at end: %d\n", data);
}

// Function to insert a node at a given position
void insert_at_position(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insert_front(head, data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The previous node is NULL. Inserting at the end.\n");
        insert_end(head, data);
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Node inserted at position %d: %d\n", position, data);
    }
}

// Function to delete a node from the front
void delete_front(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from front.\n");
}

// Function to delete a node from the end
void delete_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from end.\n");
}

// Function to delete a node at a given position
void delete_at_position(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from position %d.\n", position);
        return;
    }

    if (position == 1) {
        delete_front(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* to_delete;

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d does not exist.\n", position);
        return;
    }

    to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
    printf("Node deleted from position %d.\n", position);
}

// Function to display the linked list
void display_list(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
