#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive DFS function
  private :
    void fun(vector<vector<int>>& adj, vector<int>& vis, int node, vector<int>& ans) {

        if (vis[node]) return;

        ans.push_back(node);   // visit node
        vis[node] = 1;         // mark visited

        // Traverse all adjacent nodes
        for (int neighbors : adj[node]) {
            if (!vis[neighbors]) {
                fun(adj, vis, neighbors, ans);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {

        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> ans;

        // Start DFS from node 0
        fun(adj, vis, 0, ans);

        return ans;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // Undirected graph input
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> result = obj.dfs(adj);

    for (int node : result)
        cout << node << " ";

    cout << endl;
    return 0;
}

/*
-----------------------------------------
Sample Input:
5 4
0 1
0 2
1 3
1 4

Sample Output:
0 1 3 4 2

Explanation:
Starting DFS from node 0:
0 → 1 → 3 → 4 → back → 2

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex is visited once.
Each edge is processed once.

-----------------------------------------
Space Complexity:
O(V)
Reason:
Visited array + recursion stack (worst case depth V).

-----------------------------------------
*/