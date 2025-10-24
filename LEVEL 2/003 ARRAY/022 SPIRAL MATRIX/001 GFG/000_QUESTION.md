# Spirally Traversing a Matrix

[GeeksforGeeks Problem Link](https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1)

---

## 📌 Problem Statement
You are given a rectangular matrix `mat[][]` of size `n x m`.  
Return an array containing the elements of the matrix **in spiral order**.

---

## ✨ Examples

### Example 1
**Input:**  
`mat = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]`  

**Output:**  
`[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]`

---

### Example 2
**Input:**  
`mat = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]`  

**Output:**  
`[1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]`

---

### Example 3
**Input:**  
`mat = [[32, 44, 27, 23], [54, 28, 50, 62]]`  

**Output:**  
`[32, 44, 27, 23, 62, 50, 28, 54]`

---

## 🎯 Constraints
- `1 ≤ n, m ≤ 1000`  
- `0 ≤ mat[i][j] ≤ 100`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n * m)` — Each element visited once |
| **Space Complexity** | `O(n * m)` — Resultant array |

---

## 🏢 Company Tags
Paytm, Flipkart, Morgan Stanley, Microsoft, OYO Rooms, Snapdeal, D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, Adobe, nearbuy, Nagarro, BrowserStack, Salesforce, Zoho

---

## 🏷️ Topic Tags
- Arrays  
- Matrix  
- Data Structures  

---

## 💡 Approach – Layer by Layer Spiral Traversal
We traverse the matrix **layer by layer** using boundaries:

1. Initialize four pointers: `top = 0`, `bottom = n-1`, `left = 0`, `right = m-1`.
2. While `top <= bottom` and `left <= right`:
   - Traverse **left → right** across the top row.
   - Traverse **top → bottom** down the right column.
   - If `top <= bottom`, traverse **right → left** across the bottom row.
   - If `left <= right`, traverse **bottom → top** up the left column.
   - Shrink the boundaries: `top++`, `bottom--`, `left++`, `right--`.
3. Repeat until all elements are traversed.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat, int n, int m) {
    vector<int> result;
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int j = left; j <= right; j++)
            result.push_back(mat[top][j]);
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            result.push_back(mat[i][right]);
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result.push_back(mat[bottom][j]);
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(mat[i][left]);
            left++;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> ans = spirallyTraverse(mat, 4, 4);
    for (int x : ans) cout << x << " ";
    return 0;
}
```