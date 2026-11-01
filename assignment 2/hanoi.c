#include <stdio.h>

int move_disks(int n, char S, char D, char T)
{
    if (n > 0)
    {
        move_disks(n - 1, S, T, D);
        printf("\tMove disk %d from %c to %c.\n", n, S, D);
        move_disks(n - 1, T, D, S);
    }
    return 0;
}

int main()
{
    int n = 0;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    move_disks(n, 'S', 'D', 'T');
    return 0;
}
