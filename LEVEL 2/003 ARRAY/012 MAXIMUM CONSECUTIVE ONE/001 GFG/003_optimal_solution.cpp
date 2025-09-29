#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum consecutive equal elements
    int maxConsecBits(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0; // edge case: empty array

        int consecutive = 1;        // current streak
        int maxConsecutive = 1;     // maximum streak found

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                // Continue streak
                consecutive++;
                maxConsecutive = max(maxConsecutive, consecutive);
            } else {
                // Reset streak
                consecutive = 1;
            }
        }
        return maxConsecutive;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 1}; 

    int result = sol.maxConsecBits(arr);
    cout << "Maximum Consecutive Bits: " << result << endl;

    return 0;
}

/*
Example Output:
Maximum Consecutive Bits: 3

-----------------------
Time Complexity:
- O(n), single pass through array.

Space Complexity:
- O(1), constant extra space.
*/