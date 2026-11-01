#include <stdio.h>

int n[5];
int top = -1;

void push()
{
    if (top == 4)
        printf(" # overflow\n");
    else
    {
        top++;
        printf("Enter element : ");
        scanf("%d", &n[top]);
    }
}

void pop()
{
    if (top == -1)
        printf(" # underflow\n");
    else
    {
        printf("Element popped : %d\n", n[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
        printf(" # underflow\n");
    else
    {
        printf("Stack elements :\n");
        for (i = top; i >= 0; i--)
            printf("%d\t", n[i]);
    }
}

int main()
{
    int choice;
    int flag = 1;
    char ch;

    while (flag)
    {
        printf("\n------- MENU -------\n");
        printf("1. Push \t2.Pop\n3. Display\t4. Exit\n");
        printf("--------------------\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
        printf("--------------------\n");

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
            printf("Program exited successfully\n");
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
