// Optimal Solution : Using Two Pointer : Time Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to remove duplicates from a sorted array
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return {};  // empty array

        vector<int> ans;        
        ans.push_back(arr[0]);  // first element is always unique

        // Traverse the array and add only unique elements
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,1,2,2,3,4,4,5};

    vector<int> result = sol.removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
Example Output:
Array after removing duplicates: 1 2 3 4 5

-----------------------
Time Complexity:
- O(n), single pass through array

Space Complexity:
- O(n), extra vector used to store unique elements
*/