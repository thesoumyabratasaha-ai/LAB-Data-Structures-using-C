#include <stdio.h>

int stack[3]
void push()
{
    printf("\nHello world");
}

int main()
{
    int choice, flag = 1;

    while (flag)
    {
        printf("\n\n----- Menu -----\n 1. Push\n 2. Exit\n---------------\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            printf("\nExiting...");
            flag = 0;
            break;
        default:
            printf("\nEnter proper input...");
            break;
        }
    }
    return 0;
}