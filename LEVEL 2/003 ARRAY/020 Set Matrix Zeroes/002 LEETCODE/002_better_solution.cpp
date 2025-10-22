#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Create marker arrays for rows and columns
        vector<int> row(m, -1);
        vector<int> col(n, -1);

        // Step 2: Mark which rows and columns should be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        // Step 3: Zero out marked rows
        for (int i = 0; i < m; i++) {
            if (row[i] == 0) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4: Zero out marked columns
        for (int j = 0; j < n; j++) {
            if (col[j] == 0) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    sol.setZeroes(matrix);

    // Output result
    for (auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}

/*
Expected Output:
1 0 1
0 0 0
1 0 1

✅ Time Complexity: O(m * n)
✅ Space Complexity: O(m + n)
*/