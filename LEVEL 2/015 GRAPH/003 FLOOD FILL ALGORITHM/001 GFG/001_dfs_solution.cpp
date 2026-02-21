#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    // DFS to recolor connected component
    void dfs(vector<vector<int>>& adjMat, int sr, int sc,
             int initialColor, int newColor) {

        adjMat[sr][sc] = newColor;

        int r = adjMat.size();
        int c = adjMat[0].size();

        // 4-directional movement
        int m_row[] = {-1, 0, 1, 0};
        int m_col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = sr + m_row[i];
            int nc = sc + m_col[i];

            if (nr >= 0 && nc >= 0 && nr < r && nc < c &&
                adjMat[nr][nc] == initialColor) {

                dfs(adjMat, nr, nc, initialColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc,
                                  int newColor) {

        vector<vector<int>> adjMat(image);  // copy original image

        int initialColor = image[sr][sc];

        // If color is same, no need to process
        if (initialColor == newColor)
            return image;

        dfs(adjMat, sr, sc, initialColor, newColor);

        return adjMat;
    }
};

int main() {

    int r, c;
    cin >> r >> c;

    vector<vector<int>> image(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;

    Solution obj;
    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

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
1 1 1
1 1 0
1 0 1
1 1 2

Sample Output:
2 2 2
2 2 0
2 0 1

Explanation:
Starting from (1,1), all connected cells with color 1
are changed to 2.

-----------------------------------------
Time Complexity:
O(R × C)
Reason:
Each cell is visited at most once.

-----------------------------------------
Space Complexity:
O(R × C)
Reason:
Recursion stack in worst case (entire grid filled).

-----------------------------------------
*/