#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // BFS to spread rot level by level
    int bfs(vector<vector<int>>& mat,
            queue<pair<pair<int,int>, int>>& q) {

        int row = mat.size();
        int col = mat[0].size();

        int t = 0;

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            t = it.second;

            // 4-direction movement
            int m_row[] = {-1, 0, 1, 0};
            int m_col[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {

                int nr = r + m_row[i];
                int nc = c + m_col[i];

                if (nr >= 0 && nc >= 0 &&
                    nr < row && nc < col &&
                    mat[nr][nc] == 1) {

                    mat[nr][nc] = 2;  // make fresh orange rotten
                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        return t;
    }

    int orangesRot(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        queue<pair<pair<int,int>, int>> q;

        // Push all initially rotten oranges
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int ans = bfs(mat, q);

        // Check if any fresh orange remains
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};

int main() {

    int r, c;
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.orangesRot(mat) << endl;

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
Each cell is processed at most once.

-----------------------------------------
Space Complexity:
O(R × C)
Reason:
Queue may contain all cells in worst case.

-----------------------------------------
*/