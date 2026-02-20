# BFS of graph

## 📌 Problem Statement
Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

---

[Problem Link](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

---

## ✨ Examples

### Example 1
**Input:**  
`adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]`

**Output:**  
`[0, 2, 3, 1, 4]`

**Explanation:**  
Starting from 0, the BFS traversal will follow these steps:  
Visit 0 → Output: 0  
Visit 2 (first neighbor of 0) → Output: 0, 2  
Visit 3 (next neighbor of 0) → Output: 0, 2, 3  
Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 1  
Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4  

---

### Example 2
**Input:**  
`adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`

**Output:**  
`[0, 1, 2, 3, 4]`

**Explanation:**  
Starting from 0, the BFS traversal proceeds as follows:  
Visit 0 → Output: 0  
Visit 1 (the first neighbor of 0) → Output: 0, 1  
Visit 2 (the next neighbor of 0) → Output: 0, 1, 2  
Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3  
Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4  

---

## 🎯 Constraints
- 1 ≤ V = adj.size() ≤ 10^4  
- 0 ≤ adj[i][j] ≤ 10^4  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V + E)  
- Auxiliary Space: O(V)

---

## 💡 Approach – Breadth First Search (BFS)
1. Use a queue to perform BFS traversal.  
2. Maintain a visited array to avoid revisiting nodes.  
3. Start from vertex 0, mark it visited, and push into queue.  
4. While queue is not empty:  
	- Pop front node  
	- Add it to result  
	- Push all unvisited neighbors (in given order) into queue  

---

🏷️ Company Tags
	•	Flipkart  
	•	Amazon  
	•	Microsoft  
	•	Samsung  
	•	Ola Cabs  
	•	Adobe  
	•	SAP Labs  

⸻

🏷️ Topic Tags
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
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfs;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> adj = {{2,3,1},{0},{0,4},{0},{2}};
    vector<int> result = sol.bfsOfGraph(5, adj);

    for(int x : result)
        cout << x << " ";

    return 0;
}
```