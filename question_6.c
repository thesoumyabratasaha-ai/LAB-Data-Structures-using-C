// Menu driven program using switch case
#include <stdio.h>

int main()
{
    int num, choice, flag = 1;

    while (flag)
    {
        printf("\n----- Menu -----\n1 Check EVEN or ODD\n2 Check POSTIVIE or NEGATIVE\n3 Find SQUARE\n4 Find CUBE\n5 Exit the program\n");
        printf("\nYour choice and number: ");
        scanf("%d %d", &choice, &num);

        printf("\n");
        switch (choice)
        {
        case 1:
            if (num % 2 == 0)
                printf("Your number is EVEN\n");
            else
                printf("Your number is ODD\n");
            break;

        case 2:
            if (num > 0)
                printf("Your number is POSITIVE\n");
            else if (num == 0)
                printf("Dont trick the program by entring 0\n");
            else
                printf("Your number is NEGATIVE\n");
            break;

        case 3:
            printf("Square: %d\n", num * num);
            break;

        case 4:
            printf("Cube: %d\n", num * num * num);
            break;

        case 5:
            printf("Ending program\n");
            flag = 0;
            break;

        default:
            printf("Enter proper input\n");
            break;
        }
    }
    return 0;
}
