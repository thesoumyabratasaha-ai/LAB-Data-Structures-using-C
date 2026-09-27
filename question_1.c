// swap max and min elements in an array
#include <stdio.h>

int main()
{
    int n, i, max, min, maxPos, minPos, temp;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];
    maxPos = minPos = 0;

    printf("Original Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxPos = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minPos = i;
        }
    }

    temp = arr[maxPos];
    arr[maxPos] = arr[minPos];
    arr[minPos] = temp;

    printf("\nNew Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}