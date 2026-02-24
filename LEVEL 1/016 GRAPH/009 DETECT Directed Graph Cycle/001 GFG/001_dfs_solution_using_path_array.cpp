#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // DFS to detect cycle in directed graph
    bool dfs(vector<vector<int>>& adjLs,
             vector<int>& vis,
             vector<int>& path,
             int node) {

        vis[node] = 1;
        path[node] = 1;   // mark in current recursion stack

        for (int adjNode : adjLs[node]) {

            if (!vis[adjNode]) {
                if (dfs(adjLs, vis, path, adjNode))
                    return true;
            }
            else if (path[adjNode] == 1) // If node is already in current path → cycle
                return true;
        }

        path[node] = 0;   // remove from recursion stack
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjLs(V);
        vector<int> vis(V, 0), path(V, 0);

        // Build adjacency list (Directed Graph)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
        }

        // Check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adjLs, vis, path, i))
                    return true;
            }
        }

        return false;
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

    if (obj.isCyclic(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}

/*
-----------------------------------------
Sample Input:
4 4
0 1
1 2
2 3
3 1

Sample Output:
Cycle Detected

Explanation:
1 → 2 → 3 → 1 forms a directed cycle.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge is processed once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + visited array + recursion stack.

-----------------------------------------
*/