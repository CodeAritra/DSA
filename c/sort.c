#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}

void insertionSort(int arr[], int n)
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

void selectionSort(int arr[], int n, int index)
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
        swap(&arr[min], &arr[index]);
    }

    selectionSort(arr, n, index + 1);
}

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

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
    while (i < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

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
            swap(&arr[i], &arr[j]);
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
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};

    // printf("Bubble Sort : ");
    // bubbleSort(arr, n);

    // printf("Insertion Sort : ");
    // insertionSort(arr, n);

    //   printf("Selection Sort : ");
    //   selectionSort(arr,n,0);

    // printf("Merge Sort : ");
    // mergeSort(arr, 0, n - 1);

      printf("Quick Sort : ");
      quickSort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}