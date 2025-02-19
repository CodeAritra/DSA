 #include<stdio.h>

 int partition(int arr[],int low,int high){
    int pivot = arr[low];

    int i = low+1;
    int j = high;

    while(i<j){
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;

 }

 void quickSort(int arr[],int low,int high){
    if(low<high){
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
 }
 
 int interpolationSearch(int arr[],int low,int high,int x){
    while(low<high && arr[x]>=arr[low] && arr[x]<=arr[high]){
        int pos = low +(((x-arr[low])/(arr[high]-arr[low]))*(high-low));
        if(arr[pos] == x) return pos+1;
        else if(arr[pos]<x) low = pos+1;
        else high = pos-1;
    }
 }
 
 int main(){

    int arr[] = {5,2,3,1,4,6,9,7,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    int x = arr[n-3];
    printf("\nX = %d",interpolationSearch(arr,0,n-1,x));

    return 0;
 }