
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj) {

        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> ans;
        stack<int> st;

        // Start DFS from node 0
        st.push(0);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (vis[node]) continue;

            vis[node] = 1;
            ans.push_back(node);

            // Push neighbors in reverse order
            // So that leftmost neighbor is processed first
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!vis[neighbor]) {
                    st.push(neighbor);
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
DFS traversal using stack:
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
Visited array + stack may store up to V nodes.

-----------------------------------------
*/