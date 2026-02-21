# 200. Number of Islands

## 📌 Problem Statement
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

---

## 🔗 Problem Link
https://leetcode.com/problems/number-of-islands/

---

## ✨ Examples

### Example 1
**Input:**  
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

**Output:**  
1

---

### Example 2
**Input:**  
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

**Output:**  
3

---

## 🎯 Constraints
- m == grid.length  
- n == grid[i].length  
- 1 <= m, n <= 300  
- grid[i][j] is '0' or '1'  

---

## ⏱️ Expected Complexities
- Time Complexity: O(m × n)  
- Auxiliary Space: O(m × n)

---

## 💡 Approach – DFS / BFS
1. Traverse each cell of the grid.  
2. If a cell contains '1', increment island count.  
3. Perform DFS (or BFS) to mark all connected land cells as visited (convert to '0').  
4. Continue scanning the grid.  
5. Final count gives the number of islands.

---

🏷️ Topic Tags
	•	Array  
	•	Depth-First Search  
	•	Breadth-First Search  
	•	Union-Find  
	•	Matrix  

⸻

🏷️ Company Tags
	•	(LeetCode Premium Companies)

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << sol.numIslands(grid) << endl; // Output: 3

    return 0;
}
```