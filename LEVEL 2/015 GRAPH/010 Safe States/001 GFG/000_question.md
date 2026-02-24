# Safe States

## 📌 Problem Statement
Given a directed graph with V vertices numbered from 0 to V-1 and E directed edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents a directed edge from vertex u to vertex v. Return all Safe Nodes of the graph.

A vertex with no outgoing edges is called a terminal node. A vertex is considered safe if every path starting from it eventually reaches a terminal node.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/safe-states/1

---

## ✨ Examples

### Example 1
**Input:**  
`V = 5, E = 6, edges[][] = [[1, 0], [1, 2], [1, 3], [1, 4], [2, 3], [3, 4]]`

**Output:**  
`[0, 1, 2, 3, 4]`

**Explanation:**  
4 and 0 are terminal nodes, and all paths from 1, 2, 3 lead to terminal node 4.

---

### Example 2
**Input:**  
`V = 4, E = 3, edges[][] = [[1, 2], [2, 3], [3, 2]]`

**Output:**  
`[0]`

**Explanation:**  
0 is the terminal node, and no other node leads to a terminal node.

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

## 💡 Approach – Reverse Graph + Topological Sort (BFS)
1. Build the reverse graph.  
2. Compute out-degree of each node.  
3. Push all terminal nodes (out-degree = 0) into queue.  
4. Perform BFS and reduce out-degree of connected nodes.  
5. If out-degree becomes 0, push into queue.  
6. All nodes processed this way are safe nodes.  
7. Sort the result before returning.

---

🏷️ Company Tags
	•	Bloomberg  

⸻

🏷️ Topic Tags
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
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V), rev(V);
        vector<int> outdegree(V, 0);

        // Build graph and reverse graph
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            rev[v].push_back(u);
            outdegree[u]++;
        }

        queue<int> q;

        // Push terminal nodes
        for(int i = 0; i < V; i++) {
            if(outdegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(V, false);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for(int prev : rev[node]) {
                outdegree[prev]--;
                if(outdegree[prev] == 0)
                    q.push(prev);
            }
        }

        vector<int> result;
        for(int i = 0; i < V; i++) {
            if(safe[i])
                result.push_back(i);
        }

        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    int V = 5;
    vector<vector<int>> edges = {
        {1,0},{1,2},{1,3},{1,4},{2,3},{3,4}
    };

    vector<int> result = sol.safeNodes(V, edges);

    for(int x : result)
        cout << x << " ";

    return 0;
}
```