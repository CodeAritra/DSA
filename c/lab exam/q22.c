// Write a C Program to find the index position of third highest negative number using binary search.

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target)
{
    if (high < low)
        return -1;

    int mid = (high + low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}

int main()
{
    int n = 7;
    int arr[] = {-3, -2, -1, 0, 1, 2, 3};

    int neg = 0;
    int negatives[n];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negatives[neg++] = arr[i];
        }
    }

    if (n < 3)
        printf("No third highest negative");

    int target = negatives[neg - 3];

    int index = binarySearch(arr, 0, n - 1, target);

    if (index != -1)
    {
        printf("%d is at index %d", target, index + 1);
    }
    else
    {
        printf("Not found");
    }
}