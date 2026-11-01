#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertRear()
{
    int x;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("#deque overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = rear = 0;
        else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;

        deque[rear] = x;
    }
}

void insertFront()
{
    int x;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("#deque overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = MAX - 1;
        else
            front--;

        deque[front] = x;
    }
}

void deleteFront()
{
    if (front == -1)
        printf("#deque underflow\n");
    else
    {
        printf("Deleted element: %d\n", deque[front]);

        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

void deleteRear()
{
    if (front == -1)
        printf("#deque underflow\n");
    else
    {
        printf("Deleted element: %d\n", deque[rear]);

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("#deque underflow\n");
    else
    {
        i = front;

        while (1)
        {
            printf("%d ", deque[i]);

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

    while (ch != 6)
    {
        printf("\n---- MENU ----\n1. Rear Insert\n2. Front Insert\n3. Front Delete\n4. Rear Delete\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertRear();
            break;
        case 2:
            insertFront();
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
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