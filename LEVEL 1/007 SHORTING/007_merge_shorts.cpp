// Merge shorts

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low; 
    int right = mid + 1;

    // Merge two sorted subarrays
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    //Copy remaining elements
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    // Copy back to original array
    for (int i = low; i <= high; ++i) {
        arr[i] = temp[i - low];
    }
}

void mergeShort(int arr[], int low, int high){
    if(low >= high) return;

    int mid = (low+high)/2;
    
    mergeShort(arr, low, mid);
    mergeShort(arr,mid+1,high);
    merge(arr, low, mid, high);
}

int main(){
    int arr[] = { 1,4,2,10,5,6,8,3,4};
    int n = sizeof(arr)/sizeof(int);

    mergeShort(arr,0,n-1);
    //display
    for(int i = 0; i<n ; i++){
        cout<<arr[i]<<"    ";
    }
    return 0;
}


/* OUTOUT :
1    2    3    4    4    5    6    8    10  */