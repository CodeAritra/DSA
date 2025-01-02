#include<stdio.h>

void bubbleSort(int arr[],int n){

    if(n<=1) return;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubbleSort(arr,n-1);
}

void insertionSort(int arr[],int n){
    if(n<=1) return;

    insertionSort(arr,n-1);

    int last = arr[n-1];
    int j = n-2;

    while(j>=0 && arr[j]>last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

void selectionSort(int arr[],int n,int index){
    if(index==n-1) return;

    int min = index;

    for(int i=index+1;i<n;i++){
        if(arr[i]<arr[min]){
            min = i;
        }
    }

    if(min!=index){
        int temp = arr[min];
        arr[min] = arr[index];
        arr[index] = temp;
    }

    selectionSort(arr,n,index+1);

}

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[m+1+i];
    }

    int i=0,j=0,k=l;

    while(i<n1&&j<n2){
        if(L[i]<=R[i]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i<n1){
            arr[k++] = L[i++];
    }
    while(j<n2){
            arr[k++] = L[j++];
    }

}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low + 1;      // Index of the smaller element
    int j = high;         // Index for elements larger than the pivot

    while (i <= j) {
        // Find an element greater than the pivot from the left
        while (i < high && arr[i] <= pivot)
            i++;

        // Find an element smaller than the pivot from the right
        while (j>low && arr[j] > pivot)
            j--;

        // Swap elements at i and j if needed
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot in its correct position
    arr[low] = arr[j];
    arr[j] = pivot;

    return j; // Return the partition index
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int p = partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

int main(){
    int n = 5;
    int arr[] = {5,4,3,2,1};

    // printf("Bubble Sort : ");
    // bubbleSort(arr,n);

      printf("Insertion Sort : ");
      insertionSort(arr,n);

    // printf("Selection Sort : ");
    // selectionSort(arr,n,0);

    //  printf("Merge Sort : ");
    //  mergeSort(arr,0,n-1);

    //  printf("Quick Sort : ");
    //  quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


}