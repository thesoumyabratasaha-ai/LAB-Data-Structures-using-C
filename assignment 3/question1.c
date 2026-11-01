#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int x;

    if (rear == MAX - 1)
        printf("#queue overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
    }
}

void delete()
{
    if (front == -1)
        printf("#queue underflow\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;

        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("#queue underflow\n");
    else
    {
        i = front;

        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }

        printf("\n");
    }
}

int main()
{
    int ch = 0;

    while (ch != 4)
    {
        printf("\n---- MENU ----\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
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