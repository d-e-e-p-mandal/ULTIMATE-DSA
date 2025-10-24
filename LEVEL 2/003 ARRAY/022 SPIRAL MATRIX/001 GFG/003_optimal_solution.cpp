#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0, right = n-1, up = 0, down = m-1;
        vector<int> ans;
        while(up <= down && left <= right) {
            int i = left;

            // Traverse top row
            while(i <= right) {
                ans.push_back(mat[up][i]);
                i++;
            }
            up++;
            i = up;

            // Traverse right column
            while(i <= down) {
                ans.push_back(mat[i][right]);
                i++;
            }
            right--;
            i = right;

            // Traverse bottom row
            if(up <= down) {
                while(i >= left) {
                    ans.push_back(mat[down][i]);
                    i--;
                }
                down--;
            }
            i = down;

            // Traverse left column
            if(left <= right) {
                while(i >= up) {
                    ans.push_back(mat[i][left]);
                    i--;
                }
                left++;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    vector<int> ans = sol.spirallyTraverse(mat);

    cout << "Spiral Traversal: ";
    for(int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Spiral Traversal: 1 2 3 6 9 8 7 4 5

-----------------------------------
✅ Time Complexity: O(m × n)
   - Each element is visited exactly once.

✅ Space Complexity: O(m × n)
   - The result vector stores all m × n elements.
-----------------------------------
*/