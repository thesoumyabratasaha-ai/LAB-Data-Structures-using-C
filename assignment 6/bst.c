#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = newnode->right = NULL;

    return newnode;
}

void insert(struct node **root, int value)
{
    if (*root == NULL)
    {
        *root = createNode(value);
        printf("Node inserted successfully\n");
    }
    else if (value < (*root)->data)
        insert(&((*root)->left), value);
    else if (value > (*root)->data)
        insert(&((*root)->right), value);
    else
        printf("Duplicate value not allowed\n");
}

void search(struct node *root, int key)
{
    if (root == NULL)
        printf("Element not found\n");
    else if (root->data == key)
        printf("Element found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    int ch = 0, value;

    printf("\n---- MENU ----\n1. Search element\n2. Insert element\n3. In-order traversal\n4. Exit\n");

    while (ch != 4)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(root, value);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&root, value);
            break;

        case 3:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}