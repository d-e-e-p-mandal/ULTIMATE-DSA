#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // BFS from a single cell to find nearest 1
    int bfs(vector<vector<int>>& grid,
            vector<vector<int>>& vis,
            int ind_r,
            int ind_c) {

        int m = grid.size();
        int n = grid[0].size();

        // {row, col}, time(distance)
        queue<pair<pair<int,int>, int>> q;
        q.push({{ind_r, ind_c}, 0});
        vis[ind_r][ind_c] = 1;

        int d_row[] = {-1, 0, 1, 0};
        int d_col[] = {0, 1, 0, -1};

        int t = 0;

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            t = it.second;

            for (int i = 0; i < 4; i++) {

                int nr = r + d_row[i];
                int nc = c + d_col[i];

                if (nr >= 0 && nc >= 0 &&
                    nr < m && nc < n &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = 1;

                    // If nearest 1 found
                    if (grid[nr][nc] == 1)
                        return t + 1;

                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        return t;
    }

    vector<vector<int>> nearest(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Run BFS from every 0 cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                vector<vector<int>> vis(m, vector<int>(n, 0));

                if (grid[i][j] == 0) {
                    ans[i][j] = bfs(grid, vis, i, j);
                }
            }
        }

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
For every 0 cell, we compute distance
to nearest 1 using BFS.

-----------------------------------------
Time Complexity:
O((M × N) × (M × N))
Reason:
For each 0 cell, BFS may traverse entire grid.

-----------------------------------------
Space Complexity:
O(M × N)
Reason:
Visited matrix used for each BFS.

-----------------------------------------
*/