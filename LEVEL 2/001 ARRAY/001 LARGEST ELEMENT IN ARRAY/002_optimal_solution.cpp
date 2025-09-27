// Optimal Solution : Traverse store max : Time complexity O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest(vector<int> &arr) {
        int maxi = INT_MIN;   // start with smallest possible int
        int n = arr.size();

        // Iterate through array to find maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 45, 67, 2, 99, 23};

    int result = sol.largest(arr);
    cout << "Largest element in array: " << result << endl;

    return 0;
}

/*
Example Output:
Largest element in array: 99

-----------------------
Time Complexity:
- O(n), since we scan the array once.

Space Complexity:
- O(1), only a variable to store maximum.
*/