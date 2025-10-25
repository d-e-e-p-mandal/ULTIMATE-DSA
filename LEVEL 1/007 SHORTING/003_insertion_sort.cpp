#include<stdio.h>

void insertionSort(int *arr, int size) {
    for(int i=size-1; i>=0; i--) {
        for(int j = 0; j<i; j++) {
          
        }
    }
}

int main() {
    int arr[10] = {10,9,8,6,3,7,4,1,5,2};
    int size = sizeof(arr)/sizeof(int);
    
    //printf("%d\n",size);

    printf("Before Insertion sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }
    insertionSort(arr, size);
    printf("\nAfter Insertion sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }

    return 0;
}