#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to detect cycle in undirected graph
    bool dfs(vector<vector<int>>& adjLs,
             vector<int>& vis,
             int ind,
             int parent) {

        vis[ind] = 1;  // mark visited

        for (int adjNode : adjLs[ind]) {

            if (!vis[adjNode]) {
                if (dfs(adjLs, vis, adjNode, ind))
                    return true;
            }
            // If visited and not parent → cycle exists
            else if (adjNode != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        int m = edges.size();
        vector<int> vis(V, 0);

        // Convert edge list to adjacency list
        vector<vector<int>> adjLs(V);

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);  // undirected graph
        }

        // Check all connected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adjLs, vis, i, -1))
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

    if (obj.isCycle(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}

/*
-----------------------------------------
Sample Input:
5 5
0 1
1 2
2 3
3 4
4 1

Sample Output:
Cycle Detected

Explanation:
Edge (4,1) connects two nodes
already reachable → cycle exists.

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