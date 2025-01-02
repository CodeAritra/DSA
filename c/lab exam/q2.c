// Write a C program to count the frequency of each element of an array.
#include <stdio.h>

void countFrequency(int arr[], int size)
{
    int visited[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    printf("Element | Frequency\n");
    printf("-------------------\n");

    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 1)
            continue;

        int count = 1;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }
        printf("   %d    |    %d\n", arr[i], count);
    }
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    countFrequency(arr, n);

    return 0;
}