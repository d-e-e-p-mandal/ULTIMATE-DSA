# Bipartite Graph

## 📌 Problem Statement
Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.  
No edges exist between vertices within the same set.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/bipartite-graph/1

---

## ✨ Examples

### Example 1
**Input:**  
`V = 3, edges[][] = [[0, 1], [1, 2]]`

**Output:**  
`true`

**Explanation:**  
The graph can be colored using two colors such that no adjacent vertices share the same color.

---

### Example 2
**Input:**  
`V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]`

**Output:**  
`false`

**Explanation:**  
The graph cannot be colored using two colors such that adjacent vertices have different colors.

---

## 🎯 Constraints
- 1 ≤ V ≤ 2 × 10^5  
- 1 ≤ edges.size() ≤ 10^5  
- 0 ≤ edges[i][0], edges[i][1] < V  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V + E)  
- Auxiliary Space: O(V)

---

## 💡 Approach – BFS/DFS Coloring
1. Build adjacency list from edges.  
2. Maintain a color array initialized with -1.  
3. For each unvisited node, perform BFS/DFS.  
4. Assign alternate colors (0 and 1) to adjacent nodes.  
5. If a neighbor has the same color as current node, graph is not bipartite.  
6. If no conflict found in all components, graph is bipartite.

---

🏷️ Company Tags
	•	Flipkart  
	•	Microsoft  
	•	Samsung  

⸻

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
    bool isBipartite(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);

        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int neighbor : adj[node]) {
                        if(color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        }
                        else if(color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    int V = 3;
    vector<vector<int>> edges = {{0,1},{1,2}};

    cout << sol.isBipartite(V, edges) << endl; // Output: 1 (true)

    return 0;
}
```