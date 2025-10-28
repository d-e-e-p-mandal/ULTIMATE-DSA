#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔹 Generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {
        // Create 2D vector with 'numRows' empty rows
        vector<vector<int>> ans(numRows, vector<int>());

        // Build triangle row by row
        for (int i = 1; i <= numRows; i++) {
            for (int j = 1; j <= i; j++) {
                // 🔸 First and last element in each row is always 1
                if (j == 1 || j == i)
                    ans[i - 1].push_back(1);
                else
                    // 🔸 Each middle element = sum of two elements above it
                    ans[i - 1].push_back(ans[i - 2][j - 2] + ans[i - 2][j - 1]);
            }
        }
        return ans;
    }
};

// 🧩 Main function for demonstration
int main() {
    Solution sol;
    int numRows = 5; // Example: 5 rows

    // Generate Pascal's Triangle
    vector<vector<int>> triangle = sol.generate(numRows);

    // Display result
    cout << "Pascal’s Triangle (" << numRows << " rows):" << endl;
    for (auto &row : triangle) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Pascal’s Triangle (5 rows):
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
-----------------------------------

✅ Time Complexity: O(n²)
   → Each element depends on two elements above it.

✅ Space Complexity: O(n²)
   → Stores all rows of the triangle in memory.

✅ Additional Notes:
   - Builds the triangle iteratively using the DP relationship:
        C(i, j) = C(i-1, j-1) + C(i-1, j)
   - Simple and intuitive approach used in most LeetCode solutions.
-----------------------------------
*/