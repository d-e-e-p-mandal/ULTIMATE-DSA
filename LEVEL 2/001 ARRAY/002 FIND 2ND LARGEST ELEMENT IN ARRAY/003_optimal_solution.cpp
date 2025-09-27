// Optimal Solution : using 2 veriable update max and 2nd max both : Time Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1;  // Not enough elements for second largest

        int max1, max2;

        // Initialize with first two elements
        if (arr[0] > arr[1]) {
            max1 = arr[0];
            max2 = arr[1];
        } else {
            max1 = arr[1];
            max2 = arr[0];
        }

        // Traverse remaining array
        for (int i = 2; i < n; i++) {
            if (arr[i] > max1) {
                max2 = max1;
                max1 = arr[i];
            }
            else if (arr[i] > max2 && arr[i] != max1) {
                max2 = arr[i];
            }
        }

        // If all elements are equal → return -1
        return (max1 == max2) ? -1 : max2;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, 35, 1, 10, 34, 1};

    int result = sol.getSecondLargest(arr);
    cout << "Second largest element in array: " << result << endl;

    return 0;
}

/*
Example Output:
Second largest element in array: 34

-----------------------
Time Complexity:
- O(n), single traversal of array.

Space Complexity:
- O(1), only variables to track largest & second largest.
*/