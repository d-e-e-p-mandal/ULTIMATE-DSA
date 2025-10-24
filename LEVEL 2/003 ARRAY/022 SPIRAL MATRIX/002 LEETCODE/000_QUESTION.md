# Spiral Matrix

[LeetCode Problem Link](https://leetcode.com/problems/spiral-matrix/)

---

## 📌 Problem Statement
Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

---

## ✨ Examples

### Example 1
**Input:**  
`matrix = [[1,2,3],[4,5,6],[7,8,9]]`  
**Output:**  
`[1,2,3,6,9,8,7,4,5]`

---

### Example 2
**Input:**  
`matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]`  
**Output:**  
`[1,2,3,4,8,12,11,10,9,5,6,7]`

---

## 🎯 Constraints
- `m == matrix.length`  
- `n == matrix[i].length`  
- `1 <= m, n <= 10`  
- `-100 <= matrix[i][j] <= 100`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(m * n)` — Each element visited exactly once |
| **Space Complexity** | `O(1)` — Output list excluded |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Adobe, Facebook, Bloomberg

---

## 🏷️ Topic Tags
- Array  
- Matrix  
- Simulation  

---

## 💡 Approach – Boundary Traversal

The matrix is traversed in **layers**:
1. Move **left → right** across the top row.
2. Move **top → bottom** down the right column.
3. Move **right → left** across the bottom row (if still valid).
4. Move **bottom → top** up the left column (if still valid).

After finishing one outer layer, shrink the boundaries (`top`, `bottom`, `left`, `right`) and repeat until all elements are visited.

---

## 🧠 Algorithm
1. Initialize `top = 0`, `bottom = m-1`, `left = 0`, `right = n-1`.
2. While `top <= bottom` and `left <= right`:
   - Traverse from `left` to `right` → move right.
   - Increment `top`.
   - Traverse from `top` to `bottom` → move down.
   - Decrement `right`.
   - If `top <= bottom`, traverse from `right` to `left` → move left.
   - Decrement `bottom`.
   - If `left <= right`, traverse from `bottom` to `top` → move up.
   - Increment `left`.
3. Continue until all boundaries overlap.
4. Return the spiral order list.

---

## 🧩 Dry Run Example

For `matrix = [[1,2,3],[4,5,6],[7,8,9]]`

| Step | Direction | Elements Added | Remaining Bounds (top, bottom, left, right) |
|------|------------|----------------|---------------------------------------------|
| 1 | → | 1,2,3 | (1,2,0,2) |
| 2 | ↓ | 6,9 | (1,2,0,1) |
| 3 | ← | 8,7 | (1,1,0,1) |
| 4 | ↑ | 4 | (1,1,1,1) |
| 5 | → | 5 | Done ✅ |

**Final Output:** `[1,2,3,6,9,8,7,4,5]`

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;
            
            // Traverse from right to left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
            }
            
            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    vector<int> ans = obj.spiralOrder(matrix);
    for (int x : ans) cout << x << " ";
    return 0;
}