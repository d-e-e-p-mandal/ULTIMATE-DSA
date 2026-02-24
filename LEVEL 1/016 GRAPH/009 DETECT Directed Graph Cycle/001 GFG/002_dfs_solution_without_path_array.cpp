#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // DFS using 3-state visitation
    // 0 = not visited
    // 2 = visiting (in recursion stack)
    // 1 = completely processed
    bool dfs(vector<vector<int>>& adjLs,
             vector<int>& vis,
             int node) {

        vis[node] = 2;   // mark as visiting

        for (int adjNode : adjLs[node]) {

            if (vis[adjNode] == 0) {
                if (dfs(adjLs, vis, adjNode))
                    return true;
            }
            else if (vis[adjNode] == 2) {
                return true;   // back edge → cycle
            }
        }

        vis[node] = 1;   // mark as fully processed
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjLs(V);
        vector<int> vis(V, 0);

        // Build adjacency list (Directed Graph)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
        }

        // Check each vertex
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adjLs, vis, i))
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
When DFS reaches node 1 again
while it is still in recursion stack,
a cycle is detected.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge is processed once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + recursion stack.

-----------------------------------------
*/