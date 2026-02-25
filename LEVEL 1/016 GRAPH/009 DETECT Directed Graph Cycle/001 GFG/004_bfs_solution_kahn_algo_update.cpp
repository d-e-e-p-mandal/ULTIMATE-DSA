#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Kahn's Algorithm (BFS using count)
    int bfs(int V,
            vector<vector<int>>& adjLs,
            vector<int>& indegree) {

        queue<int> q;
        int cnt = 0;

        // Push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            cnt++;  // count processed nodes

            for (int adjNode : adjLs[node]) {

                indegree[adjNode]--;

                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return cnt;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjLs(V);
        vector<int> indegree(V, 0);

        // Build adjacency list (Directed Graph)
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

        // If processed count != V → cycle exists
        return (bfs(V, adjLs, indegree) != V);
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
Nodes inside cycle never reach indegree 0.
Processed node count < V → cycle exists.

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