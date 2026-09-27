#include <stdio.h>

int n[5];
int top = -1;

int main()
{
    int choice;
    int flag = 1;
    char ch;

    while (flag)
    {
        printf("Enter a choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("This is a push\n");





















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

                printf("Do u want to continue ? yes or no ! ");
                scanf(" %c", &ch);

                if (ch == 'n' || ch == 'N')
                {
                    flag = 0;
                }

                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
