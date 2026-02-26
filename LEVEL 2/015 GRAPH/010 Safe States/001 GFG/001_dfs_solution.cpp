#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    // DFS to detect cycle and mark safe nodes
    bool dfs(int node,
             vector<vector<int>>& adjLs,
             vector<int>& vis,
             vector<int>& pathVis,
             vector<int>& safe) {
        
        vis[node] = 1;
        pathVis[node] = 1;   // mark in recursion stack
        
        for (int adjNode : adjLs[node]) {
            
            if (!vis[adjNode]) {
                if (dfs(adjNode, adjLs, vis, pathVis, safe))
                    return true;   // cycle found
            }
            else if (pathVis[adjNode]) {
                return true;      // back-edge → cycle
            }
        }
        
        pathVis[node] = 0;   // remove from recursion stack
        safe[node] = 1;      // mark as safe (no cycle reachable)
        return false;
    }
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjLs(V);
        
        // Build adjacency list (Directed Graph)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safe(V, 0);
        
        // Run DFS on all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adjLs, vis, pathVis, safe);
            }
        }
        
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (safe[i] == 1)
                ans.push_back(i);
        }
        
        return ans;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<int> result = obj.safeNodes(V, edges);

    for (int node : result)
        cout << node << " ";

    cout << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
7 7
0 1
1 2
2 3
3 4
4 5
5 6
6 4

Sample Output:
0 1 2 3

Explanation:
Nodes 4,5,6 form a cycle.
Nodes that eventually lead to cycle are unsafe.
Nodes not part of any cycle are safe.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge is processed once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + recursion stack + arrays.

-----------------------------------------
*/