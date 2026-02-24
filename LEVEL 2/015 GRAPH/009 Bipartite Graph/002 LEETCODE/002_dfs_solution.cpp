#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to check bipartite using coloring
    bool dfs(vector<vector<int>>& adjLs,
             vector<int>& color,
             int node,
             int colour) {
        
        color[node] = colour;

        for (int adjNode : adjLs[node]) {

            // If not colored, assign opposite color
            if (color[adjNode] == -1) {
                if (!dfs(adjLs, color, adjNode, !color[node])) {
                    return false;
                }
            }
            // If same color → not bipartite
            else if (color[adjNode] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjLs(V);
        vector<int> color(V, -1);

        // Build adjacency list (Undirected Graph)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }

        // Check all components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(adjLs, color, i, 0)) {
                    return false;
                }
            }
        }

        return true;
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

    if (obj.isBipartite(V, edges))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is Not Bipartite\n";

    return 0;
}

/*
-----------------------------------------
Sample Input:
3 3
0 1
1 2
2 0

Sample Output:
Graph is Not Bipartite

Explanation:
Cycle length = 3 (odd cycle).
Odd-length cycle → cannot color using 2 colors.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge is visited once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + recursion stack + color array.

-----------------------------------------
*/