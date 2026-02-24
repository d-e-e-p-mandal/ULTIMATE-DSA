#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // DFS to mark boundary-connected 'O's
    void dfs(vector<vector<char>>& grid,
             vector<vector<int>>& vis,
             int ind_r,
             int ind_c) {

        int m = grid.size();
        int n = grid[0].size();

        vis[ind_r][ind_c] = 1;

        int dir_row[] = {-1, 0, 1, 0};
        int dir_col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int nr = ind_r + dir_row[i];
            int nc = ind_c + dir_col[i];

            if (nr >= 0 && nc >= 0 &&
                nr < m && nc < n &&
                grid[nr][nc] == 'O' &&
                vis[nr][nc] == 0) {

                dfs(grid, vis, nr, nc);
            }
        }
    }

public:
    void fill(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Step 1: Mark all boundary connected 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 || i == m - 1 ||
                    j == 0 || j == n - 1) {

                    if (grid[i][j] == 'O' &&
                        vis[i][j] == 0) {

                        dfs(grid, vis, i, j);
                    }
                }
            }
        }

        // Step 2: Convert unvisited 'O' to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 'O' &&
                    vis[i][j] == 0) {

                    grid[i][j] = 'X';
                }
            }
        }
    }
};

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    obj.fill(grid);

    for (auto row : grid) {
        for (auto ch : row)
            cout << ch << " ";
        cout << endl;
    }

    return 0;
}

/*
-----------------------------------------
Sample Input:
4 4
X X X X
X O O X
X X O X
X O X X

Sample Output:
X X X X
X X X X
X X X X
X O X X

Explanation:
Only boundary-connected 'O' (at row 3, col 1)
remains unchanged.
All other enclosed 'O' are replaced with 'X'.

-----------------------------------------
Time Complexity:
O(M × N)
Reason:
Each cell is visited at most once.

-----------------------------------------
Space Complexity:
O(M × N)
Reason:
Visited matrix + recursion stack.

-----------------------------------------
*/