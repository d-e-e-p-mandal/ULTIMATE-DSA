#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Step 1: Transpose the matrix
        // Swap mat[i][j] with mat[j][i] for all i < j
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each column (to achieve 90° anti-clockwise rotation)
        for (int i = 0, j = m - 1; i < j; i++, j--) {
            for (int k = 0; k < n; k++) {
                swap(mat[i][k], mat[j][k]);
            }
        }
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    obj.rotateMatrix(mat);

    cout << "Matrix after 90° anti-clockwise rotation:\n";
    for (auto& row : mat) {
        for (auto& val : row) cout << val << " ";
        cout << "\n";
    }
    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Matrix after 90° anti-clockwise rotation:
3 6 9
2 5 8
1 4 7
-----------------------------------

✅ Time Complexity: O(n²)
   - Each element is swapped once during transpose and again while reversing columns.

✅ Space Complexity: O(1)
   - Rotation is done in-place, without using extra space.

✅ Explanation:
   1. Transpose converts rows into columns.
   2. Reversing columns completes the anti-clockwise rotation.
-----------------------------------
*/