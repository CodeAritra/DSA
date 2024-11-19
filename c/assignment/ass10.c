#include <stdio.h>

void input(int arr[], int n)
{
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
} 

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        if (arr[pos] > x)
            hi = pos - 1;
    }
    return -1;
}

int main()
{
    int x = 1;
    while (x)
    {
        int ch, n, x, ans;
        int arr[100];
        printf("\n1.Bubble Sort\n2.Insertion Sort\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            printf("Enter the key : ");
            scanf("%d", &x);
            ans = binarySearch(arr, 0, n - 1, x);
            if (ans == -1)
                printf("Element not found");
            else
                printf("Element found at %d", ans + 1);
            break;
        case 2:
            printf("Enter the size : ");
            scanf("%d", &n);
            arr[n];
            input(arr, n);
            printf("Enter the key : ");
            scanf("%d", &x);
            ans = interpolationSearch(arr, 0, n - 1, x);
            if (ans == -1)
                printf("Element not found");
            else
                printf("Element found at %d", ans + 1);
            break;
        default:
            printf("Wrong input");
        }
    }

    return 0;
}