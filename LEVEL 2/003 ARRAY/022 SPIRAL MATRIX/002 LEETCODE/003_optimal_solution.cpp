#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = n - 1, up = 0, down = m - 1;
        vector<int> ans;

        while (up <= down && left <= right) {
            int i = left;

            // Traverse top row
            while (i <= right) {
                ans.push_back(matrix[up][i]);
                i++;
            }
            up++;
            i = up;

            // Traverse right column
            while (i <= down) {
                ans.push_back(matrix[i][right]);
                i++;
            }
            right--;
            i = right;

            // Traverse bottom row (if still valid)
            if (up <= down) {
                while (i >= left) {
                    ans.push_back(matrix[down][i]);
                    i--;
                }
                down--;
            }
            i = down;

            // Traverse left column (if still valid)
            if (left <= right) {
                while (i >= up) {
                    ans.push_back(matrix[i][left]);
                    i--;
                }
                left++;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    cout << "Spiral order traversal: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Spiral order traversal: 1 2 3 6 9 8 7 4 5

-----------------------------------
✅ Time Complexity: O(m × n)
   → Every element is visited exactly once.

✅ Space Complexity: O(m × n)
   → Result vector stores all m×n elements.

-----------------------------------
🔍 Dry Run (3×3 matrix)

Step 1 → Top row:    1 2 3
Step 2 → Right col:       6 9
Step 3 → Bottom row:        8 7
Step 4 → Left col:     4
Step 5 → Remaining center: 5

✅ Final order → [1, 2, 3, 6, 9, 8, 7, 4, 5]
-----------------------------------
*/