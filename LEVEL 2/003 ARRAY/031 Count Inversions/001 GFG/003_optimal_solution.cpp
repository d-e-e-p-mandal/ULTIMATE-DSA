#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Merge two sorted halves and count inversions caused during merge
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int i = low, j = mid + 1;
        int cnt = 0;

        // Merge two sorted subarrays and count inversions
        while (i <= mid && j <= high) {
            if (arr[i] > arr[j]) {
                temp.push_back(arr[j]);
                j++;
                // All elements from i to mid are greater than arr[j]
                cnt += (mid - i + 1);
            } else {
                temp.push_back(arr[i]);
                i++;
            }
        }

        // Copy remaining elements from left half (if any)
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        // Copy remaining elements from right half (if any)
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy sorted temp back to original array
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }

        return cnt;
    }

    // Recursive function to divide array and count inversions
    int solve(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        int leftCount = solve(arr, low, mid);
        int rightCount = solve(arr, mid + 1, high);
        int mergeCount = merge(arr, low, mid, high);

        return leftCount + rightCount + mergeCount;
    }

    // Function to return total inversion count
    int inversionCount(vector<int>& arr) {
        return solve(arr, 0, (int)arr.size() - 1);
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<int> arr = {2, 4, 1, 3, 5};

    int invCount = sol.inversionCount(arr);
    cout << "Inversion Count: " << invCount << "\n";

    return 0;
}

/*
-------------------------------------------
Example Output:
-------------------------------------------
Inversion Count: 3

-------------------------------------------
Time Complexity: O(n log n)
    - The array is recursively divided and merged.
    - Each merge step takes O(n) time.
    - Total merges ≈ log n levels, resulting in O(n log n).

Space Complexity: O(n)
    - Temporary vector used during merges takes O(n) space.
-------------------------------------------
*/