#include <stdio.h>
#define MAX 5

int circular_queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int x;

    if ((rear + 1) % MAX == front)
        printf("#queue overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        circular_queue[rear] = x;
    }
}

void delete()
{
    if (front == -1)
        printf("#queue underflow\n");
    else
    {
        printf("Deleted element: %d\n", circular_queue[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
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

        while (1)
        {
            printf("%d ", circular_queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % MAX;
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