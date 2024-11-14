#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* create_node(int data);
void insert(struct Node** root, int data);
void inorder_traversal(struct Node* root);
void preorder_traversal(struct Node* root);
void postorder_traversal(struct Node* root);
int count_nodes(struct Node* root);
void mirror_image(struct Node* root);
void display_menu();

// Main function
int main() {
    struct Node* root = NULL; // Initialize the root of the binary tree
    int choice, data;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder_traversal(root);
                printf("\n");
                break;
            case 5:
                printf("Total nodes in the tree: %d\n", count_nodes(root));
                break;
            case 6:
                mirror_image(root);
                printf("Mirror image created.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a node in the binary tree
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Function for inorder traversal
void inorder_traversal(struct Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Function for preorder traversal
void preorder_traversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function for postorder traversal
void postorder_traversal(struct Node* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to count the number of nodes in the tree
int count_nodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Function to create a mirror image of the tree
void mirror_image(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* temp;
    mirror_image(root->left);
    mirror_image(root->right);

    // Swap the left and right child
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to display the menu
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Count Nodes\n");
    printf("6. Create Mirror Image\n");
    printf("7. Exit\n");
}
