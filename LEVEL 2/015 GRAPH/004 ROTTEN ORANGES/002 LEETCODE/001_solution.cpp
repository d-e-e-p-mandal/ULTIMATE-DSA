#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // BFS to spread rot
    int bfs(vector<vector<int>>& grid,
            queue<pair<pair<int,int>, int>>& q) {

        int r = grid.size();
        int c = grid[0].size();

        int t = 0;

        int m_row[] = {-1, 0, 1, 0};
        int m_col[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            t = it.second;

            for (int i = 0; i < 4; i++) {

                int nr = row + m_row[i];
                int nc = col + m_col[i];

                if (nr >= 0 && nc >= 0 &&
                    nr < r && nc < c &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;          // make rotten
                    q.push({{nr, nc}, t + 1}); // push with time
                }
            }
        }

        return t;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>, int>> q;

        int r = grid.size();
        int c = grid[0].size();

        // Push all initially rotten oranges
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int ans = bfs(grid, q);

        // Check if any fresh orange remains
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {

    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.orangesRotting(grid) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
3 3
2 1 1
1 1 0
0 1 1

Sample Output:
4

Explanation:
Minute 0: Initial rotten oranges.
Minute 1-4: Rot spreads level by level.
All oranges become rotten in 4 minutes.

-----------------------------------------
Time Complexity:
O(R × C)
Reason:
Each cell is visited at most once.

-----------------------------------------
Space Complexity:
O(R × C)
Reason:
Queue may store all cells in worst case.

-----------------------------------------
*/