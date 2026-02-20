#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter Number of Vertex : ";
    cin >> n;

    cout << "Enter Number of Edges : ";
    cin >> m;

    // Create adjacency matrix and initialize with 0
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;   // Remove this line for directed graph
    }

    cout << "\nAdjacency Matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
Enter Number of Nodes: 3
Enter Number of Edges: 2
Enter edges (u v):
1 2
1 3

Adjacency Matrix:
0 1 1 
1 0 0 
1 0 0 
*/