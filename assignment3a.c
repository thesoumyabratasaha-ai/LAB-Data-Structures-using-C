#include <stdio.h>

#define MAX 10 

int queue[MAX]; 
int front = -1, rear = -1;

void insertion();
void deletion();
void print_queue();

int main()
{
    int choice, flag = 1;

    while (flag)
    {
        printf("\n------MENU------\n  1. Insertion\n  2. Deletion\n  3. Print Queue  4. Exit\n----------------");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertion(); 
            break;
        case 2:
            deletion(); 
            break;
        case 3:
            print_queue(); 
            break;
        case 4:
            printf("Ending program...\n");
            flag = 0;
            break;
        default:
            printf("Enter proper choice...\n");
            break;
        }
    }
    return 0;
}

void insertion()
{
    if(rear == MAX - 1)
        printf("Overflow!!\n");
    else
    {
        int value;
        if (front == -1)
            front = 0;       
        printf("Enter value to insert: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
    }
}

void deletion()
{
    if(front == -1 || front > rear)
        printf("Underflow!!\n");
    else
    {
        printf("Value deleted: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }    
}

void print_queue()
{
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
