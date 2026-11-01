// count even and odd elements in an array
#include <stdio.h>

int countEven(int arr[], int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            count++;
    }

    return count;
}

int main()
{
    int n, i, even, odd;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    even = countEven(arr, n);
    odd = n - even;

    printf("\nEven Elements: %d", even);
    printf("\nOdd Elements: %d", odd);

    return 0;
}