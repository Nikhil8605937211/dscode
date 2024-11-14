#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;  // Head of the list
    struct Node* temp = NULL;
    struct Node* new_node = NULL;
    int choice, value;

    while (1) {
        // Display menu for user
        printf("\nMenu:\n");
        printf("1. Insert node\n");
        printf("2. Find nodes having even numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert node
                new_node = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for new node
                if (new_node == NULL) {
                    printf("Memory allocation failed!\n");
                    return -1;
                }

                // Get data from the user for the new node
                printf("Enter data for the node: ");
                scanf("%d", &value);
                new_node->data = value;
                new_node->prev = NULL;
                new_node->next = NULL;

                if (head == NULL) {
                    // If list is empty, new node becomes the head
                    head = new_node;
                } else {
                    // Traverse to the end of the list and insert the new node
                    temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = new_node;
                    new_node->prev = temp;
                }
                printf("Node inserted successfully.\n");
                break;

            case 2:
                // Find nodes having even numbers
                if (head == NULL) {
                    printf("The list is empty.\n");
                } else {
                    printf("Nodes with even numbers: ");
                    temp = head;
                    int found = 0;
                    while (temp != NULL) {
                        if (temp->data % 2 == 0) {
                            printf("%d ", temp->data);
                            found = 1;
                        }
                        temp = temp->next;
                    }
                    if (!found) {
                        printf("No even numbers found.");
                    }
                    printf("\n");
                }
                break;

            case 3:
                // Exit the program
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
