# Rotate Image

[LeetCode Problem Link](https://leetcode.com/problems/rotate-image/)

---

## 📌 Problem Statement
You are given an `n x n` 2D matrix representing an image.  
Rotate the image **90 degrees clockwise**.

You must **rotate it in-place**, meaning — modify the input matrix directly.  
**Do not** allocate another 2D matrix for the rotation.

---

## ✨ Examples

### Example 1
**Input:**  
matrix = [
[1,2,3],
[4,5,6],
[7,8,9]
]

**Output:**  
[
[7,4,1],
[8,5,2],
[9,6,3]
]

---

### Example 2
**Input:**  

matrix = [
[5,1,9,11],
[2,4,8,10],
[13,3,6,7],
[15,14,12,16]
]

**Output:**  

[
[15,13,2,5],
[14,3,4,1],
[12,6,8,9],
[16,7,10,11]
]

---

## 🎯 Constraints
- `n == matrix.length == matrix[i].length`  
- `1 <= n <= 20`  
- `-1000 <= matrix[i][j] <= 1000`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n²)` — Each element is processed once |
| **Space Complexity** | `O(1)` — In-place rotation |

---

## 🏢 Company Tags
Amazon, Microsoft, Apple, Google, Facebook

---

## 🏷️ Topic Tags
- Array  
- Matrix  
- Math  
- In-place Algorithms  

---

## 💡 Approach – Transpose + Reverse Each Row

To rotate the matrix 90° clockwise:

1. **Transpose the matrix** — swap elements `matrix[i][j]` with `matrix[j][i]`.  
   (This flips the matrix over its diagonal.)
2. **Reverse each row** — this gives the rotated result.

---

### 🔍 Steps:

For matrix  
1 2 3
4 5 6
7 8 9
**After Transpose:**  
1 4 7
2 5 8
3 6 9
**After Reversing Each Row:**  
7 4 1
8 5 2
9 6 3

✅ Rotated 90° clockwise!

---

## 🧠 Algorithm
1. Iterate over the upper triangle (`i < j`) of the matrix and swap `(i, j)` with `(j, i)`.  
2. Reverse each row individually.  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };

    Solution obj;
    obj.rotate(matrix);

    for (auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
```