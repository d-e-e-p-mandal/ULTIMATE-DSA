# Number of Provinces

## 📌 Problem Statement
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/number-of-provinces/1

---

## ✨ Examples

### Example 1
**Input:**  
`[[1, 0, 1],[0, 1, 0],[1, 0, 1]]`

**Output:**  
`2`

**Explanation:**  
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

---

### Example 2
**Input:**  
`[[1, 1],[1, 1]]`

**Output:**  
`1`

---

## 🎯 Constraints
- 1 ≤ V ≤ 500  

---

## ⏱️ Expected Complexities
- Time Complexity: O(V^2)  
- Auxiliary Space: O(V)

---

## 💡 Approach – DFS on Adjacency Matrix
1. Maintain a visited array of size V.  
2. Iterate through each vertex.  
3. If a vertex is not visited, increment province count.  
4. Perform DFS from that vertex and mark all connected vertices as visited.  
5. Repeat for all vertices.

---

🏷️ Company Tags
	•	Amazon  
	•	Microsoft  
	•	Google  

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
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int V) {
        visited[node] = true;

        for(int i = 0; i < V; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                dfs(i, adj, visited, V);
            }
        }
    }

    int numProvinces(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, adj, visited, V);
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> adj = {{1,0,1},{0,1,0},{1,0,1}};
    cout << sol.numProvinces(3, adj) << endl; // Output: 2

    return 0;
}
```