# Rotate by 90 Degree (Anti-Clockwise)

[GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1)

---

## 📌 Problem Statement
Given a **square matrix** `mat[][]` of size `n x n`,  
rotate it by **90 degrees in an anti-clockwise direction** — **without using any extra space**.

---

## ✨ Examples

### Example 1
**Input:**  
mat = [
[0, 1, 2],
[3, 4, 5],
[6, 7, 8]
]

**Output:**  
[
[2, 5, 8],
[1, 4, 7],
[0, 3, 6]
]

---

### Example 2
**Input:**  
mat = [
[1, 2],
[3, 4]
]

**Output:**  
[
[2, 4],
[1, 3]
]

---

## 🎯 Constraints
- `1 ≤ n ≤ 10²`  
- `0 ≤ mat[i][j] ≤ 10³`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n²)` — Each element is visited once |
| **Space Complexity** | `O(1)` — In-place rotation without extra matrix |

---

## 🏢 Company Tags
Paytm, Microsoft, Samsung, Adobe

---

## 🏷️ Topic Tags
Matrix, Data Structures, Algorithms

---

## 💡 Approach – Transpose + Reverse Columns

To rotate a square matrix **90° anti-clockwise**:
1. **Transpose the matrix** — swap `mat[i][j]` with `mat[j][i]`.  
   (Flips over the diagonal.)
2. **Reverse each column** — this gives a 90° anti-clockwise rotation.

---

### 🔍 Step-by-Step Example

For the matrix:
0 1 2
3 4 5
6 7 8

**After Transpose:**
0 3 6
1 4 7
2 5 8
**After Reversing Columns:**  
2 5 8
1 4 7
0 3 6

✅ Rotated 90° anti-clockwise!

---

## 🧠 Algorithm
1. Loop over all elements above the diagonal and **transpose** the matrix.  
2. Then, **reverse each column** by swapping top ↔ bottom elements.  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateby90(vector<vector<int>>& mat, int n) {
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each column
        for (int j = 0; j < n; j++) {
            int top = 0, bottom = n - 1;
            while (top < bottom) {
                swap(mat[top][j], mat[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    Solution obj;
    obj.rotateby90(mat, mat.size());

    for (auto &row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
```