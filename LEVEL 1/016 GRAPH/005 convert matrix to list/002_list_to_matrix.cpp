#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // Adjacency List
    vector<int> adj[n + 1];

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);  // Remove for directed graph
    }

    // Create matrix initialized with 0
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    // Convert list to matrix
    for(int i = 1; i <= n; i++) {
        for(int neighbor : adj[i]) {
            matrix[i][neighbor] = 1;
        }
    }

    // Print matrix
    cout << "\nAdjacency Matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/* 
Time Complexity : O(n + m)
Space Complexity : O(n²)
*/