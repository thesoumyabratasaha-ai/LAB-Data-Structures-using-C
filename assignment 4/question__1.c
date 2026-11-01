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
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insertAny()
{
    struct node *newnode, *temp;
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertBeg();
        return;
    }

    temp = head;

    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
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

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

void count()
{
    struct node *temp;
    int c = 0;

    temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    printf("Number of nodes: %d\n", c);
}

void deleteFirst()
{
    struct node *temp;

    if (head == NULL)
        printf("Linked list is empty\n");
    else
    {
        temp = head;
        head = head->next;

        free(temp);
    }
}

void deleteLast()
{
    struct node *temp, *prev;

    if (head == NULL)
        printf("Linked list is empty\n");
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }
}

void deleteAny()
{
    struct node *temp, *prev;
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL)
        printf("Linked list is empty\n");
    else if (pos == 1)
        deleteFirst();
    else
    {
        temp = head;

        while (i < pos && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
            printf("Invalid position\n");
        else
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void reversePrint(struct node *temp)
{
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    printf("%d ", temp->data);
}

int main()
{
    int ch = 0;

    printf("\n---- MENU ----\n1. Insert at beginning\n2. Insert anywhere\n3. Insert at end\n4. Display linked list\n5. Count nodes\n6. Delete first node\n7. Delete last node\n8. Delete any node\n9. Reverse print\n10. Exit\n");

    while (ch != 10)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertAny();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            display();
            break;
        case 5:
            count();
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteLast();
            break;
        case 8:
            deleteAny();
            break;
        case 9:
            if (head == NULL)
                printf("Linked list is empty\n");
            else
            {
                reversePrint(head);
                printf("\n");
            }
            break;
        case 10:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}