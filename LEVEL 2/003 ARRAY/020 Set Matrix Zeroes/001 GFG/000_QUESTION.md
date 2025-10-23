# Set Matrix Zeroes

[GFG Problem Link](https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1)

---

## 📌 Problem Statement
Given an `m x n` integer matrix `matrix`, if an element is `0`, **set its entire row and column to 0's**.  

You must do it **in-place**.

---

## ✨ Examples

### Example 1
**Input:**  
matrix =   
[
[1,1,1],  
[1,0,1],  
[1,1,1]
]  
**Output:**  
[
[1,0,1],  
[0,0,0],  
[1,0,1]
]

---

### Example 2
**Input:**  
matrix = [
[0,1,2,0],  
[3,4,5,2],  
[1,3,1,5]
]  
**Output:**  
[
[0,0,0,0],  
[0,4,5,0],  
[0,3,1,0]  
]

---

## 🎯 Constraints
- `m == matrix.length`  
- `n == matrix[0].length`  
- `1 <= m, n <= 500`  
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(m*n)` — Each element may need to be visited once |
| **Space Complexity** | `O(1)` — Constant extra space allowed using matrix as markers |

---

## 🏢 Company Tags
Expedia, Amazon, Yahoo, TCS, Service Now, Google, Oracle

---

## 🏷️ Topic Tags
- Greedy
- Matrix

---

## 💡 Approach – Using First Row and Column as Markers
We use the **first row and first column** of the matrix to mark which rows and columns should be zeroed.

### 🔍 Steps:
1. Use two boolean flags `firstRowZero` and `firstColZero` to track if the first row or column contain zeros.  
2. Iterate through the matrix (excluding first row and column):
   - If `matrix[i][j] == 0`, mark `matrix[i][0] = 0` and `matrix[0][j] = 0`.  
3. Zero out rows and columns based on markers in first row and column.  
4. Finally, zero out the first row/column if needed.

---

## 🧠 Algorithm
1. Check first row and first column for any zero → set `firstRowZero` and `firstColZero`.  
2. For `i = 1` to `m-1`, `j = 1` to `n-1`:  
   - If `matrix[i][j] == 0`, `matrix[i][0] = 0` and `matrix[0][j] = 0`.  
3. For `i = 1` to `m-1`:  
   - If `matrix[i][0] == 0`, zero the entire row `i`.  
4. For `j = 1` to `n-1`:  
   - If `matrix[0][j] == 0`, zero the entire column `j`.  
5. Zero first row/column if `firstRowZero` / `firstColZero` is true.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Check first row and first column
    for (int i = 0; i < m; i++) if (matrix[i][0] == 0) firstColZero = true;
    for (int j = 0; j < n; j++) if (matrix[0][j] == 0) firstRowZero = true;

    // Use first row/col as markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero rows based on markers
    for (int i = 1; i < m; i++)
        if (matrix[i][0] == 0)
            for (int j = 1; j < n; j++) matrix[i][j] = 0;

    // Zero columns based on markers
    for (int j = 1; j < n; j++)
        if (matrix[0][j] == 0)
            for (int i = 1; i < m; i++) matrix[i][j] = 0;

    // Zero first row/col if needed
    if (firstRowZero) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    if (firstColZero) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for (auto &row : matrix) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
```