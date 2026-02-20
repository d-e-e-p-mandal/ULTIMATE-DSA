#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {

        int v = adj.size();

        vector<int> vis(v, 0);   // visited array
        queue<int> q;
        vector<int> ans;

        // Start BFS from node 0
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            // Traverse all adjacent nodes
            for (auto neighbors : adj[node]) {
                if (!vis[neighbors]) {
                    q.push(neighbors);
                    vis[neighbors] = 1;
                }
            }
        }

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
    vector<int> result = obj.bfs(adj);

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
0 1 2 3 4

Explanation:
Starting BFS from node 0:
Level order traversal → 0 → 1,2 → 3,4

-----------------------------------------
Time Complexity: 
O(N) + (2E) Degree // N is vertex
Approx : O(V) + O(E) = O(V + E)
Reason:
Each vertex is visited once → O(V)
Each edge is processed once (or twice in undirected graph) → O(E)

-----------------------------------------
Space Complexity:
O(V)
Reason:
Visited array + queue may store up to V nodes.

-----------------------------------------
*/