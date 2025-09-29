// Brute Force Solution : Short -> Time Complexity O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Merge two sorted halves [l..m] and [m+1..r]
    void merge(vector<int> &arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        // Merge L[] and R[] back into arr[l..r]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        // Copy remaining elements (if any)
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    // Merge sort
    void mergeSort(vector<int> &arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    // Function to get largest element (via sorting)
    int largest(vector<int> &arr) {
        int n = arr.size();
        mergeSort(arr, 0, n - 1);
        return arr[n - 1];  // last element after sorting is the largest
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "Largest element: " << sol.largest(arr) << endl;

    return 0;
}

/*
Example Output:
Largest element: 35

-----------------------
Time Complexity:
- Merge sort: O(n log n)
- Returning last element: O(1)
=> Overall: O(n log n)

Space Complexity:
- O(n) for temporary arrays in merge.
*/