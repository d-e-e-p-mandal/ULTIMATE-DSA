#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter Number of Nodes: ";
    cin >> n;

    cout << "Enter Number of Edges: ";
    cin >> m;

    // Array of vectors
    vector<int> adj[n + 1];

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        //adj[v].push_back(u);   // Remove this line for directed graph
    }

    cout << "\nAdjacency List:\n";
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
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

Adjacency List:
1 -> 2 3 
2 -> 1 
3 -> 1 
*/


/*
Time Complexity: O(n + m)
Space Complexity: O(m)
*/