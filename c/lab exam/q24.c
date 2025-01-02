// Write a program in C to delete duplicate elements from an array of 20 integers.

#include<stdio.h>

void removeDuplicates(int arr[],int *n){
    for(int i=0;i<*n;i++){
        for(int j=i+1;j<*n;){
            if(arr[i] == arr[j]){
                for(int k=j;k<*n-1;k++){
                    arr[k] = arr[k+1];
                }
                (*n)--;
            }
            else{
                j++;
            }
        }
    }
}

int main(){
    int n = 7;
    int arr[n];
    
    printf("Enter array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("Array elements before removing duplicates : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


    removeDuplicates(arr,&n);

    printf("\nArray elements after removing duplicates : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


}