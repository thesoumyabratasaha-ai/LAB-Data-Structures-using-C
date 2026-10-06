#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *ptr;
};

typedef struct node node;
node *head; // global pointer for head

int ins_beg(node *head, int item)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->ptr = head;
    head = new_node;
    return (new_node); 
}

void display()
{
    node *current = head;
    if (current == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\n---- Linked List Items ----\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->ptr;
    }
    printf("NULL\n");
}

int main()
{
    head = NULL; // Initialised as an empty list (no predefined data)

    int choice, item;
    bool flag = true;
    do
    {
        printf("\n---- MENU ----\n");
        printf("1. Case 1: ins_beg\n");
        printf("2. Case 2: display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &item);
            head = (node *)ins_beg(head, item); 
            printf("Node inserted successfully!\n");
            break;

        case 2:
            display(); 
            break;

        case 3:
            printf("\nExiting program...\n");
            flag = false;
            break;

        default:
            printf("\nInvalid choice! Please select 1, 2, or 3.\n");
        }

    } while (flag);

    // Free all remaining memory allocated on the heap
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->ptr;
        free(temp);
    }

    return 0;
}
