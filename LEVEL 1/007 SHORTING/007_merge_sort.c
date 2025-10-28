#include<stdio.h>

void mergeSort(int *arr, int start, int end) {
    if(start > end) return;
    int mid = start + (end - start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

int main() {
    int arr[10] = {10,9,8,6,3,7,4,1,5,2};
    int size = sizeof(arr)/sizeof(int);
    
    //printf("%d\n",size);

    printf("Before Merge sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }
    mergeSort(arr, 0, size-1);
    printf("\nAfter Merge sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }

    return 0;
}