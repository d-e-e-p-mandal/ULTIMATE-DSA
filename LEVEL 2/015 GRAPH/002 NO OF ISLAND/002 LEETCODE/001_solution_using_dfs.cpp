#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // DFS to mark all connected land cells
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {

        int r = grid.size();
        int c = grid[0].size();

        vis[row][col] = 1;

        // 4-directional movement
        int m_row[] = {-1, 0, 1, 0};
        int m_col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = row + m_row[i];
            int nc = col + m_col[i];

            if (nr >= 0 && nc >= 0 && nr < r && nc < c &&
                grid[nr][nc] == '1' && vis[nr][nc] == 0) {

                dfs(grid, vis, nr, nc);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));
        int cnt = 0;

        // Traverse entire grid
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                // If unvisited land found, start DFS
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return cnt;
    }
};

int main() {

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.numIslands(grid) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Sample Output:
3

Explanation:
There are 3 connected components (islands) of '1's.

-----------------------------------------
Time Complexity:
O(R × C)
Reason:
Each cell is visited once during DFS.

-----------------------------------------
Space Complexity:
O(R × C)
Reason:
Visited matrix + recursion stack in worst case.

-----------------------------------------
*/