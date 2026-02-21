#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS traversal to mark connected components
    void dfs(vector<vector<int>>& adjLs, vector<int>& vis, int start) {

        vis[start] = 1;

        for (auto node : adjLs[start]) {
            if (!vis[node]) {
                dfs(adjLs, vis, node);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {

        vector<vector<int>> adjLs(V);  // adjacency list
        vector<int> vis(V, 0);
        int cnt = 0;

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[0].size(); j++) {

                // Ignore self-loops
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        // Count connected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(adjLs, vis, i);
            }
        }

        return cnt;
    }
};

int main() {

    int V;
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adj[i][j];
        }
    }

    Solution obj;
    cout << obj.numProvinces(adj, V) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
3
1 1 0
1 1 0
0 0 1

Sample Output:
2

Explanation:
Province 1: Cities 0 and 1 are connected.
Province 2: City 2 is isolated.

-----------------------------------------
Time Complexity:
O(V^2)
Reason:
Matrix to list conversion takes O(V^2).
DFS traversal takes O(V + E).

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + visited array + recursion stack.

-----------------------------------------
*/