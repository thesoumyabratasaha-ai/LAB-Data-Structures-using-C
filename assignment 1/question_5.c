// find sum of array using recursion
#include <stdio.h>

int arraySum(int arr[], int n)
{
    return (n == 0) ? 0 : arr[n - 1] + arraySum(arr, n - 1);
}

int main()
{
    int n, i;

    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array: ");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Sum: %d", arraySum(arr, n));

    return 0;
}