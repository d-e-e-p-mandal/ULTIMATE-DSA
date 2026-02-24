# Replace O's with X's

## 📌 Problem Statement
You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

---

## ✨ Examples

### Example 1
**Input:**  
`grid[][] = [['X', 'X', 'X', 'X'],  
             ['X', 'O', 'X', 'X'],  
             ['X', 'O', 'O', 'X'],  
             ['X', 'O', 'X', 'X'],  
             ['X', 'X', 'O', 'O']]`

**Output:**  
`[['X', 'X', 'X', 'X'],  
  ['X', 'X', 'X', 'X'],  
  ['X', 'X', 'X', 'X'],  
  ['X', 'X', 'X', 'X'],  
  ['X', 'X', 'O', 'O']]`

**Explanation:**  
We only changed those 'O' that are surrounded by 'X'.

---

### Example 2
**Input:**  
`grid[][] = [['X', 'O', 'X', 'X'],  
             ['X', 'O', 'X', 'X'],  
             ['X', 'O', 'O', 'X'],  
             ['X', 'O', 'X', 'X'],  
             ['X', 'X', 'O', 'O']]`

**Output:**  
`[['X', 'O', 'X', 'X'],  
  ['X', 'O', 'X', 'X'],  
  ['X', 'O', 'O', 'X'],  
  ['X', 'O', 'X', 'X'],  
  ['X', 'X', 'O', 'O']]`

**Explanation:**  
There's no 'O' that's surrounded by 'X'.

---

### Example 3
**Input:**  
`grid[][] = [['X', 'X', 'X'],  
             ['X', 'O', 'X'],  
             ['X', 'X', 'X']]`

**Output:**  
`[['X', 'X', 'X'],  
  ['X', 'X', 'X'],  
  ['X', 'X', 'X']]`

**Explanation:**  
There's only one 'O' that's surrounded by 'X'.

---

## 🎯 Constraints
- 1 ≤ grid.size() ≤ 100  
- 1 ≤ grid[0].size() ≤ 100  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n × m)  
- Auxiliary Space: O(n × m)

---

## 💡 Approach – DFS / BFS from Boundary
1. All 'O' connected to boundary cannot be converted.  
2. Traverse boundary cells and mark all connected 'O' as safe (e.g., change to '#').  
3. After marking, traverse entire grid:  
	- Convert remaining 'O' to 'X'  
	- Convert '#' back to 'O'  
4. Return modified grid.

---

🏷️ Company Tags
	•	Google  
	•	NPCI  

⸻

🏷️ Topic Tags
	•	Recursion  
	•	Matrix  
	•	Graph  
	•	Data Structures  
	•	Algorithms  
	•	BFS  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != 'O')
            return;

        grid[r][c] = '#';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& grid) {

        // Mark boundary connected O's
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 'O') dfs(grid, i, 0);
            if(grid[i][m-1] == 'O') dfs(grid, i, m-1);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 'O') dfs(grid, 0, j);
            if(grid[n-1][j] == 'O') dfs(grid, n-1, j);
        }

        // Convert remaining O to X and # back to O
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O')
                    grid[i][j] = 'X';
                else if(grid[i][j] == '#')
                    grid[i][j] = 'O';
            }
        }

        return grid;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    vector<vector<char>> result = sol.fill(5, 4, grid);

    for(auto &row : result) {
        for(char ch : row)
            cout << ch << " ";
        cout << endl;
    }

    return 0;
}
```