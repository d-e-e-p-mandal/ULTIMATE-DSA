#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to move all zeroes to the end of the array
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        
        int firstZero = 0; // index of first zero

        // Find first zero in the array
        while (firstZero < n && arr[firstZero] != 0) firstZero++;

        // Traverse remaining elements
        for (int i = firstZero + 1; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[firstZero]);
                firstZero++; // move to next zero position
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 1, 0, 3, 12};

    sol.pushZerosToEnd(arr);

    cout << "Array after moving zeroes: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Array after moving zeroes: 1 3 12 0 0

-----------------------
Time Complexity:
- O(n), single pass through the array

Space Complexity:
- O(1), in-place swapping with no extra array
*/