#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Multi-source BFS
    void bfs(vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             vector<vector<int>>& ans,
             queue<pair<pair<int,int>, int>>& q) {

        int m = grid.size();
        int n = grid[0].size();

        int d_row[] = {-1, 0, 1, 0};
        int d_col[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;

            for (int i = 0; i < 4; i++) {

                int nr = r + d_row[i];
                int nc = c + d_col[i];

                if (nr >= 0 && nc >= 0 &&
                    nr < m && nc < n &&
                    !vis[nr][nc] &&
                    grid[nr][nc] == 0) {

                    vis[nr][nc] = 1;
                    ans[nr][nc] = t + 1;

                    q.push({{nr, nc}, t + 1});
                }
            }
        }
    }

    vector<vector<int>> nearest(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int,int>, int>> q;

        // Push all 1's into queue (multi-source)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        bfs(grid, vis, ans, q);

        return ans;
    }
};

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> result = obj.nearest(grid);

    for (auto row : result) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

/*
-----------------------------------------
Sample Input:
3 3
0 1 1
1 1 0
0 0 1

Sample Output:
1 0 0
0 0 1
1 1 0

Explanation:
All cells with value 1 are inserted initially.
BFS spreads level by level calculating
minimum distance to nearest 1.

-----------------------------------------
Time Complexity:
O(M × N)
Reason:
Each cell is visited at most once.

-----------------------------------------
Space Complexity:
O(M × N)
Reason:
Visited matrix + queue storage.

-----------------------------------------
*/