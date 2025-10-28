#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔹 Function to generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {
        // Create 2D vector with 'numRows' rows
        vector<vector<int>> ans(numRows, vector<int>());

        // Iterate through each row
        for (int i = 0; i < numRows; i++) {
            int result = 1; // First element of each row is always 1

            // Generate each element in the current row
            for (int j = 0; j <= i; j++) {
                if (j == 0) // devide by zero(0) would be wrong 
                    ans[i].push_back(result);  // First & last element of every row = 1
                else {
                    // Use the formula: C(i, j) = C(i, j-1) × (i - j + 1) / j
                    result = (result * (i - j + 1)) / j;
                    ans[i].push_back(result);
                }
            }
        }

        return ans; // Return the complete Pascal’s triangle
    }
};

int main() {
    Solution sol;
    int numRows = 5; // Example: generate 5 rows

    // Call function
    vector<vector<int>> res = sol.generate(numRows);

    // Print Pascal’s Triangle
    cout << "Pascal’s Triangle (" << numRows << " rows):" << endl;
    for (auto &row : res) {
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
   - Each row 'i' has 'i+1' elements → total ≈ n(n+1)/2 computations.

✅ Space Complexity: O(n²)
   - The result vector stores all 'n' rows and their elements.

✅ Additional Notes:
   - Uses mathematical property of binomial coefficients.
   - Avoids recomputation of factorials for efficiency.
   - Works well for LeetCode’s "Pascal's Triangle" problem.
-----------------------------------
*/