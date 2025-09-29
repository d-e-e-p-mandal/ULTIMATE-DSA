#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return union of two sorted arrays
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        int n1 = a.size(), n2 = b.size();
        vector<int> ans;
        
        int i = 0, j = 0;
        int x = -1; // index for last inserted element in ans
        
        while (i < n1 && j < n2) {
            if (i < n1 && j < n2 && a[i] == b[j]) {
                if (x == -1 || a[i] != ans[x]) {
                    ans.push_back(a[i]);
                    x++;   
                }
                i++; j++;
            }
            
            while (i < n1 && j < n2 && a[i] < b[j]) {
                if (x == -1 || a[i] != ans[x]) {
                    ans.push_back(a[i]);
                    x++;
                }
                i++;
            }
            
            while (i < n1 && j < n2 && a[i] > b[j]) {
                if (x == -1 || b[j] != ans[x]) {
                    ans.push_back(b[j]);
                    x++;
                }
                j++;
            }
        }
        
        // Add remaining elements of a[]
        while (i < n1) {
            if (a[i] != ans[x]) {
                ans.push_back(a[i]);
                x++;   
            }
            i++;
        }
        
        // Add remaining elements of b[]
        while (j < n2) {
            if (b[j] != ans[x]) {
                ans.push_back(b[j]);
                x++;
            }
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