// switch case
#include <stdio.h>

int main()
{
    int choice, flag = 1;

    while (flag)
    {
        printf("\nṇ------MENU------\n\t1. Tea\n\t2. Coffee\n\t3. Cold drink\n\t4. Exit");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enjoy tea...");
            break;
        case 2:
            printf("Enjoy Coffee...");
            break;
        case 3:
            printf("Enjoy cold drink...");
            break;
        case 4:
            printf("Ending program...");
            flag = 0;
            break;
        default:
            printf("Enter proper choice...");
            break;
        }
    }
}