# Rotten Oranges

## 📌 Problem Statement
Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell  
1 : Cell have fresh oranges  
2 : Cell have rotten oranges  

Your task is to determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: If it is impossible to rot every orange then simply return -1.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

---

## ✨ Examples

### Example 1
**Input:**  
`mat[][] = [[2, 1, 0, 2, 1], [1, 0, 1, 2, 1], [1, 0, 0, 2, 1]]`

**Output:**  
`2`

**Explanation:**  
Oranges at positions (0,0), (0,3), (1,3), and (2,3) will rot adjacent fresh oranges in successive time frames.  
All fresh oranges become rotten after 2 units of time.

---

### Example 2
**Input:**  
`mat[][] = [[2, 1, 0, 2, 1], [0, 0, 1, 2, 1], [1, 0, 0, 2, 1]]`

**Output:**  
`-1`

**Explanation:**  
Oranges at positions (0,0), (0,3), (1,3), and (2,3) rot some fresh oranges,  
but the fresh orange at (2,0) can never be reached, so not all oranges can rot.

---

## 🎯 Constraints
- 1 ≤ mat.size() ≤ 500  
- 1 ≤ mat[0].size() ≤ 500  
- mat[i][j] ∈ {0, 1, 2}  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n × m)  
- Auxiliary Space: O(n × m)

---

## 💡 Approach – Multi-Source BFS
1. Push all initially rotten oranges (value 2) into a queue.  
2. Count the number of fresh oranges.  
3. Perform BFS level by level.  
4. For each rotten orange, rot adjacent fresh oranges and decrease fresh count.  
5. Increase time after each level.  
6. If fresh oranges remain at the end, return -1. Otherwise return time.

---

🏷️ Company Tags
	•	Flipkart  
	•	Accolite  
	•	Amazon  
	•	Microsoft  
	•	OYO Rooms  
	•	Samsung  
	•	MakeMyTrip  
	•	NPCI  

⸻

🏷️ Topic Tags
	•	Matrix  
	•	Graph  
	•	Data Structures  
	•	Queue  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2)
                    q.push({i, j});
                else if(mat[i][j] == 1)
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

                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && mat[nr][nc] == 1) {
                        mat[nr][nc] = 2;
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

    vector<vector<int>> mat = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    cout << sol.orangesRotting(mat) << endl; // Output: 2

    return 0;
}
```