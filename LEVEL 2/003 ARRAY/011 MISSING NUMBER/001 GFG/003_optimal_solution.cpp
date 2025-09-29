#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the missing number using XOR
    int missingNum(vector<int>& arr) {
        int n = arr.size();

        int missingNumber = 0;
        for (int i = 0; i < n; i++) {
            // XOR with both array element and index+1
            missingNumber ^= arr[i] ^ (i + 1);
        }

        // Finally XOR with (n+1) to cover the last number
        return missingNumber ^ (n + 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 4, 5}; // Missing 3

    int result = sol.missingNum(arr);
    cout << "Missing Number: " << result << endl;

    return 0;
}

/*
Example Output:
Missing Number: 3

-----------------------
Time Complexity:
- O(n), single pass.

Space Complexity:
- O(1), constant extra space.
*/