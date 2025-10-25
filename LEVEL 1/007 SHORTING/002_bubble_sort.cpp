#include<stdio.h>

void bubbleSort(int *arr, int size) {
    for(int i=size-1; i>=0; i--) {
        for(int j = 0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[10] = {10,9,8,6,3,7,4,1,5,2};
    int size = sizeof(arr)/sizeof(int);
    
    //printf("%d\n",size);

    printf("Before Bubble sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }
    bubbleSort(arr, size);
    printf("\nAfter Bubble sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }

    return 0;
}