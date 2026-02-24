#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // BFS to capture island shape
    void bfs(vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             set<vector<pair<int,int>>>& s,
             int ind_r,
             int ind_c) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({ind_r, ind_c});
        vis[ind_r][ind_c] = 1;

        // Store relative coordinates (shape)
        vector<pair<int,int>> temp({{0,0}}); // first 1 occured it must be (0,0)-> (r-r, c-c)

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

                    // Store relative position
                    temp.push_back({nr - ind_r, nc - ind_c});
                }
            }
        }

        // Insert shape into set
        s.insert(temp);
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<vector<pair<int,int>>> s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    bfs(grid, vis, s, i, j);
                }
            }
        }

        return s.size();
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
    cout << obj.countDistinctIslands(grid) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 1 1 1

Sample Output:
2

Explanation:
There are two distinct island shapes.
Relative coordinates are stored and
inserted into a set to ensure uniqueness.

-----------------------------------------
Time Complexity:
O(M × N × log K)
Reason:
Each cell visited once.
Insertion of island shape into set costs log K,
where K = number of distinct islands.

-----------------------------------------
Space Complexity:
O(M × N)
Reason:
Visited matrix + storing island shapes.

-----------------------------------------
*/