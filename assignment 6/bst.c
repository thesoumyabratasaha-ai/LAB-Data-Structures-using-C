#include <stdio.h>
#include <stdlib.h>

// node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Helper function to allocate memory for a new node
node* createNode(int value) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Case 1: Search function using void return type
void search(node *root, int key) {
    if (root == NULL) {
        printf("element %d not found\n", key);
        return;
    }
    if (root->data == key) {
        printf("element %d found\n", key);
        return;
    }
    if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Case 2: Insert function using void return type (uses pointer-to-pointer to modify root)
void insert(node **root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        printf("%d inserted successfully.\n", value);
        return;
    }
    if (value < (*root)->data) {
        insert(&((*root)->left), value);
    } else if (value > (*root)->data) {
        insert(&((*root)->right), value);
    } else {
        printf("%d already exists in the tree (duplicates ignored).\n", value);
    }
}

// Case 3: In-order traversal print using void return type
void inOrderTraversal(node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    node *root = NULL; // The pointer to the root of the tree
    int choice, value;

    printf("--- Binary Search Tree (BST) System ---\n");
    
    while(1) {
        printf("\n1. Search Element\n2. Insert Element\n3. In-Order Print\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter integer value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 2:
                printf("Enter integer value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
                
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("BST elements (In-Order): ");
                    inOrderTraversal(root);
                    printf("\n");
                }
                break;
                
            default:
                printf("Invalid choice! Please choose 1, 2, or 3.\n");
        }
    }
    return 0;
}
