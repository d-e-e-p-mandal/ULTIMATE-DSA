# Undirected Graph Cycle

## 📌 Problem Statement
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

---

## ✨ Examples

### Example 1
**Input:**  
`V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]`

**Output:**  
`true`

**Explanation:**  
1 -> 2 -> 0 -> 1 is a cycle.

---

### Example 2
**Input:**  
`V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]`

**Output:**  
`false`

**Explanation:**  
No cycle in the graph.

---

## 🎯 Constraints
- 1 ≤ V, E ≤ 10^5  
- 0 ≤ edges[i][0], edges[i][1] < V  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V + E)  
- Auxiliary Space: O(V)

---

## 💡 Approach – DFS with Parent Tracking
1. Convert edge list into adjacency list.  
2. Maintain a visited array.  
3. For each unvisited vertex, perform DFS.  
4. While exploring neighbors, if a visited neighbor is found and it is not the parent, then a cycle exists.  
5. If no cycle is found in any component, return false.

---

🏷️ Company Tags
	•	Flipkart  
	•	Amazon  
	•	Microsoft  
	•	Samsung  
	•	MakeMyTrip  
	•	Oracle  
	•	Adobe  

⸻

🏷️ Topic Tags
	•	DFS  
	•	Graph  
	•	union-find  
	•	Data Structures  
	•	Algorithms  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor, node, adj, visited))
                    return true;
            }
            else if(neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{2,3}};

    cout << sol.isCycle(V, edges) << endl; // Output: 1 (true)

    return 0;
}
```