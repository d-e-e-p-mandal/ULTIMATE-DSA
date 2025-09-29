// Time Complexity : O(N) : TRAVERSE

// Optimal Solution: Check each pair of consecutive elements
// Time Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();

        // Check consecutive elements
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 2, 4, 5};

    cout << "Is arr1 sorted? " << (sol.isSorted(arr1) ? "Yes" : "No") << endl;  // Yes
    cout << "Is arr2 sorted? " << (sol.isSorted(arr2) ? "Yes" : "No") << endl;  // No

    return 0;
}

/*
Example Output:
Is arr1 sorted? Yes
Is arr2 sorted? No

-----------------------
Time Complexity:
- O(n), single pass through array

Space Complexity:
- O(1), only constant extra variables used
*/