#include <stdio.h>

void input(int arr[], int n)
{
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
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

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[r + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
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
    int x = 1;
    while (x)
    {
        int ch, n;
        int arr[100];
        printf("\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Merge Sort\n5.Quick Sort\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            bubbleSort(arr, n);
            print(arr, n);
            break;
        case 2:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            insertionSort(arr, n);
            print(arr, n);
            break;
        case 3:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            selectionSort(arr, n);
            print(arr, n);
            break;
        case 4:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            mergeSort(arr, 0, n - 1);
            print(arr, n);
            break;
        case 5:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            quickSort(arr, 0, n - 1);
            print(arr, n);
            break;

        default:
            printf("Wrong input");
        }
    }

    return 0;
}