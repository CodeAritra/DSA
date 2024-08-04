#include <stdio.h>
#define capacity 100

void insert(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertAtBegin(int arr[], int *size, int val)
{
    if (*size >= capacity)
    {
        printf("Array full");
        return;
    }

    for (int i = *size; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = val;
    (*size)++;

    display(arr, *size);
}

void insertAtEnd(int arr[], int *size, int val)
{
    if (*size >= capacity)
    {
        printf("Array full");
        return;
    }
    arr[*size] = val;
    (*size)++;
    display(arr, *size);
}

void insertAtPos(int arr[], int *size, int pos, int val)
{
    if (*size >= capacity)
    {
        printf("Array full");
        return;
    }
    for (int i = *size; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    (*size)++;
    display(arr, *size);
}

void deleteFromBeginning(int arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty!\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    display(arr, *size);
}

void deleteFromEnd(int arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty!\n");
        return;
    }
    (*size)--;

    display(arr, *size);
}

void deleteFromPosition(int arr[], int *size, int position)
{
    if (*size <= 0)
    {
        printf("Array is empty!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    display(arr, *size);
}

void replaceElement(int arr[], int size, int position, int newElement)
{
    if (position < 0 || position >= size)
    {
        printf("Invalid position!\n");
        return;
    }
    arr[position] = newElement;

    display(arr, size);
}

int searchElement(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[capacity];
    int size, choice, val, pos;

    printf("Enter the size : ");
    scanf("%d", &size);

    printf("Enter array elements : ");
    insert(arr, size);

    while (1)
    {
        printf("\nEnter your choice : \n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a position\n");
        printf("7. Replace an element at a specific position\n");
        printf("8. Search for an element\n");
        printf("9. Display the array element\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &val);
            insertAtBegin(arr, &size, val);
            break;
        case 2:
            printf("Enter the value : ");
            scanf("%d", &val);
            insertAtEnd(arr, &size, val);
            break;
        case 3:
            printf("Enter the position : ");
            scanf("%d", &pos);
            printf("Enter the value : ");
            scanf("%d", &val);
            insertAtPos(arr, &size, pos, val);
            break;
        case 4:
            deleteFromBeginning(arr, &size);
            break;
        case 5:
            deleteFromEnd(arr, &size);
            break;
        case 6:
            printf("Enter position to delete the element : ");
            scanf("%d", &pos);
            deleteFromPosition(arr, &size, pos);
            break;
        case 7:
            printf("Enter position to replace the element : ");
            scanf("%d", &pos);
            printf("Enter new element: ");
            scanf("%d", &val);
            replaceElement(arr, size, pos, val);
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &val);
            int position = searchElement(arr, size, val);
            if (position != -1)
            {
                printf("Element found at position %d\n", position);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 9:
            display(arr, size);
            break;
        default:
            printf("Wrong choice");
        }
    } 

    return 0;
}