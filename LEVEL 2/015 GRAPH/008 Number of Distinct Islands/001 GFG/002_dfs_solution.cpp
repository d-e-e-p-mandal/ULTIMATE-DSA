#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // DFS to capture island shape using relative coordinates
    void dfs(vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             vector<pair<int,int>>& vec,
             int ind_r,
             int ind_c,
             int base_r,
             int base_c) {

        int m = grid.size();
        int n = grid[0].size();

        vis[ind_r][ind_c] = 1;

        // Store relative position
        vec.push_back({ind_r - base_r, ind_c - base_c});

        int dir_row[] = {-1, 0, 1, 0};
        int dir_col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int nr = ind_r + dir_row[i];
            int nc = ind_c + dir_col[i];

            if (nr >= 0 && nc >= 0 &&
                nr < m && nc < n &&
                grid[nr][nc] == 1 &&
                vis[nr][nc] == 0) {

                dfs(grid, vis, vec, nr, nc, base_r, base_c);
            }
        }
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

                    vector<pair<int,int>> vec;

                    dfs(grid, vis, vec, i, j, i, j);

                    s.insert(vec);
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
Relative coordinates are stored
for each island shape.
Set ensures only distinct shapes are counted.

-----------------------------------------
Time Complexity:
O(M × N × log K)
Reason:
Each cell visited once.
Insertion into set costs log K,
where K = number of distinct islands.

-----------------------------------------
Space Complexity:
O(M × N)
Reason:
Visited matrix + storing island shapes.

-----------------------------------------
*/