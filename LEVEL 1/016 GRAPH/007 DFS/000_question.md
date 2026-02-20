# DFS of Graph

## 📌 Problem Statement
Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

---

[Problem Link](https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

---

## ✨ Examples

### Example 1
**Input:**  
`adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]`

**Output:**  
`[0, 2, 4, 3, 1]`

**Explanation:**  
Starting from 0, the DFS traversal proceeds as follows:  
Visit 0 → Output: 0  
Visit 2 (the first neighbor of 0) → Output: 0, 2  
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4  
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3  
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1  

---

### Example 2
**Input:**  
`adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`

**Output:**  
`[0, 1, 2, 3, 4]`

**Explanation:**  
Starting from 0, the DFS traversal proceeds as follows:  
Visit 0 → Output: 0  
Visit 1 (the first neighbor of 0) → Output: 0, 1  
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2  
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3  
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4  

---

## 🎯 Constraints
- 1 ≤ V = adj.size() ≤ 10^4  
- 0 ≤ adj[i][j] ≤ 10^4  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V + E)  
- Auxiliary Space: O(V)

---

## 💡 Approach – Depth First Search (DFS)
1. Use recursion (or stack) to perform DFS traversal.  
2. Maintain a visited array to avoid revisiting nodes.  
3. Start from vertex 0 and recursively visit each unvisited neighbor in given order.  
4. Add each visited node to result.

---

🏷️ Company Tags
	•	Accolite  
	•	Amazon  
	•	Samsung  
	•	Intuit  

⸻

🏷️ Topic Tags
	•	DFS  
	•	Graph  
	•	Data Structures  
	•	Algorithms  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> result;
        vector<bool> visited(V, false);

        dfs(0, adj, visited, result);
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> adj = {{2,3,1},{0},{0,4},{0},{2}};
    vector<int> result = sol.dfsOfGraph(5, adj);

    for(int x : result)
        cout << x << " ";

    return 0;
}
```