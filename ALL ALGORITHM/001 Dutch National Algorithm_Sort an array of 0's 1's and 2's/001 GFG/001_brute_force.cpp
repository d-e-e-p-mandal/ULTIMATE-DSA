// Brute Force Solution : Use Merge Sort

#include <bits/stdc++.h>
using namespace std;

// Standard merge function
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted subarray back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void sort012(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sort012(arr);

    cout << "Sorted Array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------
🧩 Example Output:
Original Array: 2 0 2 1 1 0 
Sorted Array:   0 0 1 1 2 2 
-----------------------------------------

⏱️ Time Complexity:  O(N log N)
💾 Space Complexity: O(N)
   → Due to temporary arrays used in merging.
-----------------------------------------
*/ 