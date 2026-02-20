#include<bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cout<<"Enter No of Vertex : ";
    cin>> v;
    cout<<"Enter No of Edges : ";
    cin >> e;

    // graph : store the list with pair, like 1 -> (2,w) :
    vector<vector<pair<int, int>>> adj(v+1);

    cout << "Enter edges (u v) & w :\n";
    for(int i=1; i<=e; i++) {
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << "\nAdjacency List:\n";
    for(int i = 1; i <= v; i++) {
        cout << i << " -> ";
        for(auto neighbor : adj[i]) {
            cout <<"("<< neighbor.first << " " << neighbor.second <<")";
        }
        cout << endl;
    }

    return 0;
}

/*
Enter No of Vertex : 3
Enter No of Edges : 2
Enter edges (u v) & w :
1 2 3
1 3 4

Adjacency List:
1 -> (2 3)(3 4)
2 -> (1 3)
3 -> (1 4)
*/