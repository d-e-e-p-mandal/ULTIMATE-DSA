#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // BFS to detect cycle in one connected component
    bool bfs(vector<vector<int>>& adjLs, vector<int>& vis, int ind) {

        queue<pair<int,int>> q;

        q.push({ind, -1});   // node, parent
        vis[ind] = 1;

        while (!q.empty()) {

            auto [node, parent] = q.front();
            q.pop();

            for (auto adjNode : adjLs[node]) {

                if (!vis[adjNode]) {
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                }
                else if (adjNode != parent) {
                    return true;   // cycle detected
                }
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
            adjLs[v].push_back(u);   // undirected graph
        }

        // Check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(adjLs, vis, i))
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
There is a cycle: 1 → 2 → 3 → 4 → 1

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge is processed once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + visited array + queue.

-----------------------------------------
*/