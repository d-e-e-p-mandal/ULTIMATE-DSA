#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col = -1; // flag to track if first column should be zeroed

        // Step 1: Mark first row & column for zero rows/cols
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;           // mark row
                    if (j == 0) col = 0;        // mark first column separately
                    else matrix[0][j] = 0;      // mark column
                }
            }
        }

        // Step 2: Set zeroes for all rows except first
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Set zeroes for all columns except first
        for (int i = 1; i < n; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        // Step 4: Handle first row separately if needed
        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }

        // Step 5: Handle first column separately if needed
        if (col == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

// ---------- main function ----------
int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    for (auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    sol.setMatrixZeroes(matrix);

    cout << "\nMatrix After setZeroes():\n";
    for (auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Original Matrix:
1 1 1
1 0 1
1 1 1

Matrix After setZeroes():
1 0 1
0 0 0
1 0 1
-----------------------------------

✅ Time Complexity: O(m * n)
   → We traverse the entire matrix a few times (constant number of passes).

✅ Space Complexity: O(1)
   → No extra space used except constant variables (in-place modification).
-----------------------------------
*/