# Number of Distinct Islands

## 📌 Problem Statement
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

---

## ✨ Examples

### Example 1
**Input:**  
grid[][] = [[1, 1, 0, 0, 0],  
            [1, 1, 0, 0, 0],  
            [0, 0, 0, 1, 1],  
            [0, 0, 0, 1, 1]]

**Output:**  
1

**Explanation:**  
We have 2 equal islands, so we have only 1 distinct island.

---

### Example 2
**Input:**  
grid[][] = [[1, 1, 0, 1, 1],  
            [1, 0, 0, 0, 0],  
            [0, 0, 0, 0, 1],  
            [1, 1, 0, 1, 1]]

**Output:**  
3

**Explanation:**  
We have 4 islands, but 2 of them are equal, so we have 3 distinct islands.

---

## 🎯 Constraints
- 1 ≤ n, m ≤ 500  
- grid[i][j] == 0 or 1  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n * m * log(n * m))  
- Auxiliary Space: O(n * m)

---

## 💡 Approach – DFS with Relative Position Encoding
1. Traverse the grid.  
2. For every unvisited land cell (1), perform DFS.  
3. Store the relative coordinates (row - baseRow, col - baseCol) of each cell in the island.  
4. Insert the shape vector into a set to maintain uniqueness.  
5. The size of the set gives the number of distinct islands.

---

🏷️ Topic Tags
	•	DFS  
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
    void dfs(int r, int c, int baseR, int baseC,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             vector<pair<int,int>>& shape) {

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        shape.push_back({r - baseR, c - baseC});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m &&
               grid[nr][nc] == 1 && !vis[nr][nc]) {
                dfs(nr, nc, baseR, baseC, grid, vis, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, i, j, grid, vis, shape);
                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

    cout << sol.countDistinctIslands(grid) << endl; // Output: 1

    return 0;
}
```