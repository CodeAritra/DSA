#include <stdio.h>

void print(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(double arr[], int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            double temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSort(arr, n - 1);
}

void insertionSort(double arr[], int n)
{
    if (n <= 1)
        return;

    insertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

void selectionSort(double arr[], int n, int index)
{

    if (index == n - 1)
        return;

    int min = index;
    for (int i = index + 1; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }

    if (min != index)
    {
        int temp = arr[min];
        arr[min] = arr[index];
        arr[index] = temp;
    }

    selectionSort(arr, n, index + 1);
}

void merge(double arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    double L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(double arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    double arr[] = {50.987654321, -60.15, 2, 232.987456, -99999999.9999, 21, 7.65435679, -123.35, 88, -987};
    int n = sizeof(arr) / sizeof(arr[0]);

    double bubble[n], insertion[n], selection[n], merge[n];

    for (int i = 0; i < n; i++)
    {
        bubble[i] = insertion[i] = selection[i] = merge[i] = arr[i];
    }

    printf("Original array : ");
    print(arr, n);

    // printf("Bubble Array : ");
    // print(bubble, n);

    bubbleSort(bubble, n);
    printf("Bubble Sort : ");
    print(bubble, n);

    insertionSort(insertion, n);
    printf("Insertion Sort : ");
    print(insertion, n);

    selectionSort(selection, n, 0);
    printf("Selection Sort : ");
    print(selection, n);

    mergeSort(merge, 0, n - 1);
    printf("Merge Sort : ");
    print(merge, n);
}