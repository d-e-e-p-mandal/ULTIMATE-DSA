#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    // DFS for Topological Sort
    void dfs(vector<vector<int>>& adjLs,
             vector<int>& vis,
             vector<int>& ans,
             int node) {

        vis[node] = 1;

        for (int adjNode : adjLs[node]) {
            if (!vis[adjNode]) {
                dfs(adjLs, vis, ans, adjNode);
            }
        }

        // Store node after visiting neighbours
        ans.push_back(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjLs(V);
        vector<int> vis(V, 0);
        vector<int> ans;

        // Build adjacency list (Directed Graph)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
        }

        // Call DFS for all vertices
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adjLs, vis, ans, i);
            }
        }

        // Reverse to get correct topological order
        reverse(ans.begin(), ans.end());

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
    vector<int> result = obj.topoSort(V, edges);

    for (int node : result)
        cout << node << " ";

    cout << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
6 6
5 2
5 0
4 0
4 1
2 3
3 1

Sample Output:
5 4 2 3 1 0

Explanation:
Nodes are pushed after DFS completion.
Reversing the order gives valid
topological sorting.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge is visited once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + recursion stack + result vector.

-----------------------------------------
*/