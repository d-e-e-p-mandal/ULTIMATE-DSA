#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the unique number in the array
    int findUnique(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans ^= arr[i]; // XOR cancels duplicates
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 30, 2, 15, 20, 30, 15};

    int result = sol.findUnique(arr);
    cout << "Unique Number: " << result << endl;

    return 0;
}

/*
Time Complexity:
- O(n), single traversal of the array.

Space Complexity:
- O(1), constant extra space.

Example Output:
Unique Number: 20
*/