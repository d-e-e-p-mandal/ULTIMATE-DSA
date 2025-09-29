// Optimal Solution : Using Two pointer : O(n+n) : All different

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return union of two sorted arrays
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1 = a.size(), n2 = b.size();
        vector<int> ans;

        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (a[i] == b[j]) {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++; j++;
            } 
            else if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
            } 
            else {
                if (ans.empty() || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            }
        }

        // Add remaining elements from a[]
        while (i < n1) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }

        // Add remaining elements from b[]
        while (j < n2) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5, 5, 6};

    vector<int> result = sol.findUnion(a, b);

    cout << "Union of arrays: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Union of arrays: 1 2 3 4 5 6

-----------------------
Time Complexity:
- O(n1 + n2), single traversal of both arrays.

Space Complexity:
- O(n1 + n2) in worst case (if no duplicates).
*/