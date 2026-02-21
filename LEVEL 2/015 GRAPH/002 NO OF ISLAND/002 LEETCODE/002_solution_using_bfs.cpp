#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // BFS to mark all connected land cells
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {

        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;   // mark starting cell visited

        // 4-directional movement
        int m_row[] = {-1, 0, 1, 0};
        int m_col[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = x + m_row[i];
                int nc = y + m_col[i];

                if (nr >= 0 && nc >= 0 && nr < r && nc < c &&
                    grid[nr][nc] == '1' && vis[nr][nc] == 0) {

                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));
        int cnt = 0;

        // Traverse the grid
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    bfs(grid, vis, i, j);
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
There are 3 separate connected components (islands) of '1's.

-----------------------------------------
Time Complexity:
O(R × C)
Reason:
Each cell is visited at most once.

-----------------------------------------
Space Complexity:
O(R × C)
Reason:
Visited matrix + queue may store up to R*C cells.

-----------------------------------------
*/