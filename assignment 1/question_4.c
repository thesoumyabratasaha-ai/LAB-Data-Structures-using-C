// find second largest element in an array
#include <stdio.h>

int findSecondLargest(int arr[], int n)
{
    int i, max, secondMax;

    if (arr[0] > arr[1])
    {
        max = arr[0];
        secondMax = arr[1];
    }
    else
    {
        max = arr[1];
        secondMax = arr[0];
    }

    for (i = 2; i < n; i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] > secondMax)
        {
            secondMax = arr[i];
        }
    }

    return secondMax;
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

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nSecond Largest: %d", findSecondLargest(arr, n));

    return 0;
}