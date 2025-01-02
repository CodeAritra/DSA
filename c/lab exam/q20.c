// Write a C program to sort an unsorted array using recursive Quick Sort algo andafter sorting return the index position of third highest number using Interpolation Search.

#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int interpolationSearch(int arr[], int low, int high, int x)
{
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        int pos = low + (((x - arr[low]) / (arr[high] - arr[low])) * (high - low));

        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
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
    int arr[] = {4, 2, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);

    quickSort(arr, 0, n - 1);
    print(arr, n);

    int x = arr[n - 3];

    int pos = interpolationSearch(arr, 0, n - 1, x);
    printf("pos = %d", pos + 1);

    return 0;
}