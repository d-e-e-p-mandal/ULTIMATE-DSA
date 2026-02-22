# Distance of nearest cell having 1

## 📌 Problem Statement
Given a binary grid[][], where each cell contains either 0 or 1, find the distance of the nearest 1 for every cell in the grid.  
The distance between two cells (i1, j1) and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|.  
You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

Note: It is guaranteed that there is at least one cell with value 1 in the grid.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1/1

---

## ✨ Examples

### Example 1
**Input:**  
`grid[][] = [[0, 1, 1, 0],  
             [1, 1, 0, 0],  
             [0, 0, 1, 1]]`

**Output:**  
`[[1, 0, 0, 1],  
  [0, 0, 1, 1],  
  [1, 1, 0, 0]]`

**Explanation:**  
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from nearest 1's.

---

### Example 2
**Input:**  
`grid[][] = [[1, 0, 1],  
             [1, 1, 0],  
             [1, 0, 0]]`

**Output:**  
`[[0, 1, 0],  
  [0, 0, 1],  
  [0, 1, 2]]`

**Explanation:**  
0's at (0,1), (1,2), (2,1) and (2,2) are at distances 1, 1, 1 and 2 respectively from nearest 1's.

---

## 🎯 Constraints
- 1 ≤ grid.size() ≤ 200  
- 1 ≤ grid[0].size() ≤ 200  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n × m)  
- Auxiliary Space: O(n × m)

---

## 💡 Approach – Multi-Source BFS
1. Push all cells containing 1 into a queue initially.  
2. Initialize a distance matrix with large values.  
3. Set distance of all cells containing 1 as 0.  
4. Perform BFS simultaneously from all 1's.  
5. Update distance of neighboring cells if a shorter distance is found.  
6. Continue until queue becomes empty.

---

🏷️ Company Tags
	•	Bloomberg  
	•	Amazon  
	•	Microsoft  
	•	Accenture  
	•	Google  
	•	Flipkart  
	•	Uber  
	•	NPCI  

⸻

🏷️ Topic Tags
	•	Graph  
	•	Breadth-First Search  
	•	Matrix  
	•	Data Structures  
	•	Algorithms  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Push all 1's into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };

    vector<vector<int>> result = sol.nearest(grid);

    for(auto &row : result) {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
```