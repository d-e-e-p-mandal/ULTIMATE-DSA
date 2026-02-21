# Flood fill Algorithm

## 📌 Problem Statement
You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate (sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/1

---

## ✨ Examples

### Example 1
**Input:**  
`image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2`

**Output:**  
`[[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]`

**Explanation:**  
Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2.

---

### Example 2
**Input:**  
`image[][] = [[0, 1, 0], [0, 1, 0]], sr = 0, sc = 1, newColor = 0`

**Output:**  
`[[0, 0, 0], [0, 0, 0]]`

**Explanation:**  
Starting from pixel (0, 1) with value 1, flood fill changes all 4-directionally connected pixels with value 1 to 0.

---

## 🎯 Constraints
- 1 ≤ n ≤ m ≤ 500  
- 0 ≤ image[i][j] ≤ 10  
- 0 ≤ newColor ≤ 10  
- 0 ≤ sr ≤ (n-1)  
- 0 ≤ sc ≤ (m-1)  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n × m)  
- Auxiliary Space: O(n × m)

---

## 💡 Approach – DFS
1. Store the original color of the starting pixel.  
2. If original color equals newColor, return the image directly.  
3. Perform DFS from (sr, sc).  
4. Change the color of the current pixel to newColor.  
5. Recursively visit all 4-directionally adjacent pixels having the original color.  

---

🏷️ Company Tags
	•	Microsoft  
	•	Google  
	•	NPCI  

⸻

🏷️ Topic Tags
	•	Recursion  
	•	DFS  
	•	Matrix  
	•	Graph  
	•	Data Structures  
	•	Algorithms  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        if(r < 0 || c < 0 || r >= n || c >= m || image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        dfs(image, r+1, c, oldColor, newColor);
        dfs(image, r-1, c, oldColor, newColor);
        dfs(image, r, c+1, oldColor, newColor);
        dfs(image, r, c-1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;

        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> image = {
        {1,1,1,0},
        {0,1,1,1},
        {1,0,1,1}
    };

    vector<vector<int>> result = sol.floodFill(image, 1, 2, 2);

    for(auto &row : result) {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
```