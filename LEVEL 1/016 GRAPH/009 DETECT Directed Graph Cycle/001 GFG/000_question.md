# Directed Graph Cycle

## 📌 Problem Statement
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.  
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

---

## ✨ Examples

### Example 1
**Input:**  
`V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]`

**Output:**  
`true`

**Explanation:**  
The graph contains a cycle: 0 → 1 → 2 → 0

---

### Example 2
**Input:**  
`V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]`

**Output:**  
`false`

**Explanation:**  
There is no cycle in the graph.

---

## 🎯 Constraints
- 1 ≤ V ≤ 10^5  
- 0 ≤ E ≤ 10^5  
- 0 ≤ edges[i][0], edges[i][1] < V  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V + E)  
- Auxiliary Space: O(V)

---

## 💡 Approach – DFS with Recursion Stack
1. Convert edge list into adjacency list.  
2. Maintain two arrays:  
   - visited[] to mark visited nodes  
   - recStack[] to track nodes in the current recursion path  
3. Perform DFS for each unvisited node.  
4. If during DFS, we visit a node that is already in recursion stack, cycle exists.  
5. If no cycle detected in any component, return false.

---

🏷️ Company Tags
	•	Flipkart  
	•	Amazon  
	•	Microsoft  
	•	Samsung  
	•	MakeMyTrip  
	•	Oracle  
	•	Goldman Sachs  
	•	Adobe  
	•	BankBazaar  
	•	Rockstand  
	•	NPCI  

⸻

🏷️ Topic Tags
	•	Graph  
	•	Data Structures  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& recStack) {

        visited[node] = true;
        recStack[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor, adj, visited, recStack))
                    return true;
            }
            else if(recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{2,3}};

    cout << sol.isCyclic(V, edges) << endl; // Output: 1 (true)

    return 0;
}
```