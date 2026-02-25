#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Kahn's Algorithm (BFS)
    vector<int> bfs(int V,
                    vector<vector<int>>& adjLs,
                    vector<int>& indegree) {

        queue<int> q;
        vector<int> ans;

        // Push all nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int adjNode : adjLs[node]) {

                indegree[adjNode]--;

                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return ans;
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjLs(V);
        vector<int> indegree(V, 0);

        // Build adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
        }

        // Compute indegree
        for (int i = 0; i < V; i++) {
            for (int adjNode : adjLs[i]) {
                indegree[adjNode]++;
            }
        }

        return bfs(V, adjLs, indegree);
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
4 5 2 3 1 0

(Valid Topological Order — may vary)

Explanation:
Nodes with indegree 0 are processed first.
Removing them reduces indegree of neighbors.
Process continues until all nodes are covered.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge processed once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + indegree array + queue.

-----------------------------------------
*/