# Topological Sort

## 📌 Problem Statement
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/topological-sort/1

---

## ✨ Examples

### Example 1
**Input:**  
`V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]`

**Output:**  
`true`

**Explanation:**  
Few valid Topological orders are:  
[3, 2, 1, 0]  
[1, 2, 3, 0]  
[2, 3, 1, 0]  

---

### Example 2
**Input:**  
`V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]`

**Output:**  
`true`

**Explanation:**  
Few valid Topological orders are:  
[4, 5, 0, 1, 2, 3]  
[5, 2, 4, 0, 1, 3]  

---

## 🎯 Constraints
- 2 ≤ V ≤ 5 × 10^3  
- 1 ≤ E ≤ min[10^5, (V × (V - 1)) / 2]  
- 0 ≤ edges[i][0], edges[i][1] < V  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V + E)  
- Auxiliary Space: O(V)

---

## 💡 Approach – Kahn’s Algorithm (BFS)
1. Build adjacency list from edges.  
2. Compute in-degree of each vertex.  
3. Push all vertices with in-degree 0 into queue.  
4. While queue is not empty:  
	- Pop node  
	- Add to topo result  
	- Decrease in-degree of neighbors  
	- If in-degree becomes 0, push into queue  
5. The resulting list is a valid Topological ordering.

---

🏷️ Company Tags
	•	Moonfrog Labs  
	•	Flipkart  
	•	Morgan Stanley  
	•	Accolite  
	•	Amazon  
	•	Microsoft  
	•	OYO Rooms  
	•	Samsung  
	•	D-E-Shaw  
	•	Visa  

⸻

🏷️ Topic Tags
	•	Graph  
	•	Data Structures  
	•	topological-sort  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build graph
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push nodes with indegree 0
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return topo;
    }
};

int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {{3,0},{1,0},{2,0}};

    vector<int> result = sol.topoSort(V, edges);

    for(int x : result)
        cout << x << " ";

    return 0;
}
```