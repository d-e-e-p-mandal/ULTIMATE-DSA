# 994. Rotting Oranges

## 📌 Problem Statement
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell  
1 representing a fresh orange  
2 representing a rotten orange  

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

---

## 🔗 Problem Link
https://leetcode.com/problems/rotting-oranges/

---

## ✨ Examples

### Example 1
**Input:**  
`grid = [[2,1,1],[1,1,0],[0,1,1]]`

**Output:**  
`4`

---

### Example 2
**Input:**  
`grid = [[2,1,1],[0,1,1],[1,0,1]]`

**Output:**  
`-1`

**Explanation:**  
The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

---

### Example 3
**Input:**  
`grid = [[0,2]]`

**Output:**  
`0`

**Explanation:**  
Since there are already no fresh oranges at minute 0, the answer is 0.

---

## 🎯 Constraints
- m == grid.length  
- n == grid[i].length  
- 1 <= m, n <= 10  
- grid[i][j] is 0, 1, or 2  

---

## ⏱️ Expected Complexities
- Time Complexity: O(m × n)  
- Auxiliary Space: O(m × n)

---

## 💡 Approach – Multi-Source BFS
1. Push all rotten oranges into a queue initially.  
2. Count the number of fresh oranges.  
3. Perform BFS level by level (each level represents 1 minute).  
4. For each rotten orange, rot all 4-directionally adjacent fresh oranges.  
5. Decrease fresh count accordingly.  
6. If fresh oranges remain after BFS, return -1; otherwise return time.

---

🏷️ Topic Tags
	•	Array  
	•	Breadth-First Search  
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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!q.empty() && fresh > 0) {
            int size = q.size();
            time++;

            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        if(fresh > 0) return -1;
        return time;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << sol.orangesRotting(grid) << endl; // Output: 4

    return 0;
}
```