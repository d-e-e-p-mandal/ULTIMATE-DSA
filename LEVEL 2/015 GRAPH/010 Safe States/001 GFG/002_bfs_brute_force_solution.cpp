#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Kahn's Algorithm on reversed graph
    vector<int> bfs(int V,
                    vector<vector<int>>& revAdj,
                    vector<int>& indegree) {
      
        queue<int> q;
        vector<int> ans;
      
        // Push terminal nodes (indegree 0)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
      
        while (!q.empty()) {
            int node = q.front();
            q.pop();
          
            ans.push_back(node);
          
            for (int adjNode : revAdj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
      
        sort(ans.begin(), ans.end());  // optional for sorted output
        return ans;
    }
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjLs(V);
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V, 0);
        
        // Build adjacency list (Directed Graph)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjLs[u].push_back(v);
        }
        
        // Build reverse graph + compute indegree
        for (int i = 0; i < V; i++) {
            for (int adjNode : adjLs[i]) {
                revAdj[adjNode].push_back(i);
                indegree[i]++;
            }
        }
        
        return bfs(V, revAdj, indegree);
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
    vector<int> result = obj.safeNodes(V, edges);

    for (int node : result)
        cout << node << " ";

    cout << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
7 7
0 1
1 2
2 3
3 4
4 5
5 6
6 4

Sample Output:
0 1 2 3

Explanation:
Nodes 4,5,6 form a cycle.
Terminal nodes are processed first.
Reverse graph helps remove unsafe nodes.

-----------------------------------------
Time Complexity:
O(V + E)
Reason:
Each vertex and edge processed once.

-----------------------------------------
Space Complexity:
O(V + E)
Reason:
Adjacency list + reverse graph + indegree + queue.

-----------------------------------------
*/