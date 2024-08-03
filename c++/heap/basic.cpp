#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightInxddex = 2 * i + 1;

    if (leftIndex <= size && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }

    if (rightInxddex <= size && arr[rightInxddex] > arr[largest])
    {
        largest = rightInxddex;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{

    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    // h.deleteFromHeap();
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;

    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }

    cout << "Printing the array : " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    heapSort(arr,size);
    cout << "Printing the sorted array : " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}