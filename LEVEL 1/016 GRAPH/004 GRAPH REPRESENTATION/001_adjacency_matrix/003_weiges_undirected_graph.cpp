#include<bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cout<<"Enter No of Vertex : ";
    cin>> v;
    cout<<"Enter No of Edges : ";
    cin >> e;

    // 
    vector<vector<int>> adj(v+1, vector<int>(v+1, 0));

    // Graph Input :
    cout << "Enter edges (u v) & w :\n";
    for(int i=1; i <= e; i++) {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u][v] = w;
        adj[v][u] = w; // remove for directed graph
    }

    // Graph Output :
    cout<<"\nGraph : "<<endl;

    for(int i=1; i<=v; i++) {
        for(int j=1; j<= v; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

}

/*
Enter No of Vertex : 3
Enter No of Edges : 2
Enter edges (u v) :
1 2 2
1 3 4

Graph : 
0 2 4 
2 0 0 
4 0 0 
*/

/*
Time Complexity: O(n² + m)
Space Complexity: O(n²)**
*/