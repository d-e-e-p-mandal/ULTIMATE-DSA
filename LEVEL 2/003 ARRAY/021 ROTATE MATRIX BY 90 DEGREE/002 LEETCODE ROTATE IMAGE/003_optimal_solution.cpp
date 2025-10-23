#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each column (to achieve 90° rotation)
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            for (int k = 0; k < m; k++) {
                swap(matrix[k][i], matrix[k][j]);
            }
        }
    }
};

// ---------- main function ----------
int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    for (auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    sol.rotate(matrix);

    cout << "\nMatrix After 90° Rotation (Clockwise):\n";
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
1 2 3
4 5 6
7 8 9

Matrix After 90° Rotation (Clockwise):
7 4 1
8 5 2
9 6 3
-----------------------------------

✅ Time Complexity: O(n²)
   - Both transpose and reverse operations traverse the matrix once.

✅ Space Complexity: O(1)
   - Rotation is done in-place without using extra data structures.
-----------------------------------
*/