#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // BFS to mark boundary-connected land cells
    void bfs(vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             int ind_r,
             int ind_c) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({ind_r, ind_c});
        vis[ind_r][ind_c] = 1;

        int dir_row[] = {-1, 0, 1, 0};
        int dir_col[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nr = r + dir_row[i];
                int nc = c + dir_col[i];

                if (nr >= 0 && nc >= 0 &&
                    nr < m && nc < n &&
                    grid[nr][nc] == 1 &&
                    vis[nr][nc] == 0) {

                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }

public:
    int numberOfEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Step 1: Mark all boundary-connected land cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 || j == 0 ||
                    i == m - 1 || j == n - 1) {

                    if (grid[i][j] == 1 &&
                        vis[i][j] == 0) {

                        bfs(grid, vis, i, j);
                    }
                }
            }
        }

        // Step 2: Count remaining unvisited land cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 &&
                    vis[i][j] == 0) {

                    cnt++;
                }
            }
        }

        return cnt;
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
    cout << obj.numberOfEnclaves(grid) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
4 4
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0

Sample Output:
3

Explanation:
The 3 land cells in the middle are not
connected to boundary → enclaves.

-----------------------------------------
Time Complexity:
O(M × N)
Reason:
Each cell is visited at most once.

-----------------------------------------
Space Complexity:
O(M × N)
Reason:
Visited matrix + queue in worst case.

-----------------------------------------
*/