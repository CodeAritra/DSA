#include <stdio.h>

void freq(int arr[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {

        if (visited[i] == 1)
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++)
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
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    freq(arr,size);
}