#include <stdio.h>

float calculateAverage(float arr[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += arr[i];

    return sum / n;
}

int main()
{
    int n, i;

    printf("Enter array size: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter array: ");
    for (i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    printf("\nAverage: %.2f", calculateAverage(arr, n));

    return 0;
}