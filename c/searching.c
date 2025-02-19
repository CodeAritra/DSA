#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        binarySearch(arr, mid + 1, high, target);
    else
        binarySearch(arr, low, mid - 1, target);
}

int interpolationSeacrh(int arr[], int low, int high, int target)
{
    if (low > high || arr[low] > target || arr[high] < target)
    {
        return -1;
    }
    int pos = low + ((((target - arr[low]) / (arr[high] - arr[low]))) * (high - low));
    if (arr[pos] == target)
        return pos;
    if (arr[pos] > target)
        interpolationSeacrh(arr, low, pos - 1, target);
    else
        interpolationSeacrh(arr, pos + 1, high, target);
}
int interpolationSeacrh1(int arr[], int low, int high, int target)
{
    while (low < high && arr[low] <= target && arr[high] >= target)
    {
        int pos = low + ((((target - arr[low]) / (arr[high] - arr[low]))) * (high - low));
        if (arr[pos] == target)
            return pos;
        if (arr[pos] > target)
            high = pos - 1;
        else
            low = pos + 1;
    }
    return -1;
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

     int x = binarySearch(arr,0,n-1,30);
    // int x = interpolationSeacrh(arr, 0, n - 1, 30);
    printf("x = %d", x + 1);
}