#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Find with Path Compression
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> parent(V);

        // Initially, each node is its own parent
        for (int i = 0; i < V; i++)
            parent[i] = i;

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            // If both nodes have same ultimate parent → cycle
            if (pu == pv)
                return true;

            // Union operation
            parent[pu] = pv;
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
Edge (4,1) connects two nodes already
in the same set → cycle exists.

-----------------------------------------
Time Complexity:
O(E * α(V))
Reason:
Each find operation takes almost constant time
due to path compression (inverse Ackermann).

-----------------------------------------
Space Complexity:
O(V)
Reason:
Parent array of size V.

-----------------------------------------
*/