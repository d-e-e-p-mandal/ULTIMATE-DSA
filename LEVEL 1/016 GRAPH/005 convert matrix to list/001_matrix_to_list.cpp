#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    // Input adjacency matrix
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));

    cout << "Enter adjacency matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Convert to adjacency list
    vector<int> adj[n + 1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(matrix[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    // Print adjacency list
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
T.C : O(n²)
S.C : O(n+m)
*/