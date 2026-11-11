#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void display()
{
    struct node *temp;

    if (head == NULL)
        printf("Linked list is empty\n");
    else
    {
        temp = head;

        while (1)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;

            if (temp == head)
                break;
        }

        printf("(head)\n");
    }
}

void deleteBeg()
{
    struct node *temp, *last;

    if (head == NULL)
        printf("Linked list is empty\n");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;

        free(temp);
    }
}

void deleteEnd()
{
    struct node *temp, *prev;

    if (head == NULL)
        printf("Linked list is empty\n");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }
}

int main()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data for first node: ");
    scanf("%d", &newnode->data);

    head = newnode;
    newnode->next = head;

    int ch = 0;

    printf("\n---- MENU ----\n1. Insert at beginning\n2. Insert at end\n3. Display\n4. Delete from beginning\n5. Delete from end\n6. Exit\n");

    while (ch != 6)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            display();
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}