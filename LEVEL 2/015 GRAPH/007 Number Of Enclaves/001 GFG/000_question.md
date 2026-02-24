# Number Of Enclaves

## 📌 Problem Statement
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

---

## ✨ Examples

### Example 1
**Input:**  
`grid[][] = {{0, 0, 0, 0},  
             {1, 0, 1, 0},  
             {0, 1, 1, 0},  
             {0, 0, 0, 0}}`

**Output:**  
`3`

**Explanation:**  
The highlighted land cells are those that cannot reach the boundary.

---

### Example 2
**Input:**  
`grid[][] = {{0, 0, 0, 1},  
             {0, 1, 1, 0},  
             {0, 1, 1, 0},  
             {0, 0, 0, 1},  
             {0, 1, 1, 0}}`

**Output:**  
`4`

**Explanation:**  
The highlighted land cells are those that cannot reach the boundary.

---

## 🎯 Constraints
- 1 <= n, m <= 500  
- grid[i][j] == 0 or 1  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n × m)  
- Auxiliary Space: O(n × m)

---

## 💡 Approach – DFS/BFS from Boundary
1. Traverse all boundary cells.  
2. For every boundary land cell (value 1), perform DFS/BFS and mark all reachable land cells as visited (or convert to 0).  
3. After removing all boundary-connected land cells, count remaining land cells.  
4. The remaining count is the number of enclaves.

---

🏷️ Company Tags
	•	Google  

⸻

🏷️ Topic Tags
	•	DFS  
	•	Matrix  
	•	Graph  
	•	BFS  
	•	Data Structures  
	•	Algorithms  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0)
            return;

        grid[r][c] = 0;

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Remove boundary-connected lands
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j);
            if(grid[n-1][j] == 1) dfs(grid, n-1, j);
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << sol.numberOfEnclaves(grid) << endl; // Output: 3

    return 0;
}
```