// Write a C program to right rotate an array.
#include <stdio.h>

void rotateArray(int arr[], int n)
{
    int last = arr[n - 1];

    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int k = 2, n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    print(arr, n);

    for (int i = 1; i <= k; i++)
    {
        rotateArray(arr, n);
    }

    print(arr, n);

    return 0;
}