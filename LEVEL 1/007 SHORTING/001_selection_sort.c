#include<stdio.h>

void selectionSort(int *arr, int size) {
    for(int i=0; i<size-1; i++) {
        int min = i;
        for(int j = i+1; j<size; j++) {
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[10] = {10,9,8,6,3,7,4,1,5,2};
    int size = sizeof(arr)/sizeof(int);
    
    //printf("%d\n",size);

    printf("Before Selection sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }
    selectionSort(arr, size);
    printf("\nAfter Selection sort :\n");
    for(int i=0; i<size; i++) {
        printf("%d\t",arr[i]);
    }

    return 0;
}