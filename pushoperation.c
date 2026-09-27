#include <stdio.h>
#include <stdlib.h>

int n[5];
int top = -1;

void push()
{
    if (top == 4)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;

        printf("Enter element : ");
        scanf("%d", &n[top]);

        printf("Element pushed successfully\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Element popped : %d\n", n[top]);

        top--;

        printf("Element popped successfully\n");
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are :\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", n[i]);
        }
    }
}

void exitStack()
{
    printf("Program exited successfully\n");
    exit(0);
}

int main()
{
    int choice;
    int flag = 1;
    char ch;

    while (flag)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter a choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exitStack();
                break;

            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\nDo u want to continue? yes or no : ");
        scanf(" %c", &ch);

        if (ch == 'n' || ch == 'N')
        {
            flag = 0;
        }
    }

    return 0;
}
