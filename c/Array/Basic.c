#include <stdio.h>

void insert(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// void insertAtEnd(int arr[], int key, int size, int capacity)
// {
//     arr[size + 1] = key;
//     print(arr, size+1);
// }

void insertAtPos(int arr[], int pos, int size, int key)
{
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = key;
    print(arr, size + 1);
}

int findele(int arr[],int size,int ele){
    for(int i=0;i<=size;i++){
        if(arr[i]==ele) return i;
    }
}

void delete(int arr[],int size,int ele){
    int pos = findele(arr,size,ele);
    for(int i=pos;i<size;i++){
        arr[i] = arr[i+1];
    }
    print(arr,size-1);
}

int main()
{
    int size, pos, key,ele;
    printf("Enter the size : ");
    scanf("%d", &size);

    int arr[50];
    printf("Entre the array elements : ");
    insert(arr, size);

    printf("Original array : ");
    print(arr, size);

    // insertAtEnd(arr, 6, size, 50);
    // printf("\n%d",arr[6]);

    /*printf("Enter the pos : ");
    scanf("%d", &pos);
    printf("Enter the key : ");
    scanf("%d", &key);
    insertAtPos(arr, pos, size, key);*/

    printf("Enter the element to delete : ");
    scanf("%d",&ele);
    delete(arr,size,ele);

    return 0;
}