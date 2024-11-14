#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for iterative traversal
struct Stack {
    struct Node* nodes[100];
    int top;
};

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node* node) {
    stack->nodes[++stack->top] = node;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    return stack->nodes[stack->top--];
}

// Function to check if the stack is empty
int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary tree
struct Node* insert_node(struct Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    char direction;
    printf("Insert %d to the left (l) or right (r) of %d? ", data, root->data);
    scanf(" %c", &direction);

    if (direction == 'l' || direction == 'L') {
        root->left = insert_node(root->left, data);
    } else if (direction == 'r' || direction == 'R') {
        root->right = insert_node(root->right, data);
    } else {
        printf("Invalid direction! Node not inserted.\n");
    }

    return root;
}

// Function to perform non-recursive Inorder traversal
void inorder(struct Node* root) {
    struct Stack stack;
    stack.top = -1;
    struct Node* current = root;

    while (current != NULL || !is_empty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform non-recursive Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    struct Stack stack;
    stack.top = -1;
    push(&stack, root);

    while (!is_empty(&stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);

        // Push right child first so that left child is processed first
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

// Function to perform non-recursive Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    struct Stack stack1, stack2;
    stack1.top = -1;
    stack2.top = -1;

    push(&stack1, root);
    while (!is_empty(&stack1)) {
        struct Node* current = pop(&stack1);
        push(&stack2, current);

        // Push left and right children to the first stack
        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    // Print the contents of the second stack for postorder
    while (!is_empty(&stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
