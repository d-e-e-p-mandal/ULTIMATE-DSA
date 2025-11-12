# Find Missing and Repeated Values

[LeetCode Problem Link](https://leetcode.com/problems/find-missing-and-repeated-values/)

---

## 📌 Problem Statement
You are given a 0-indexed 2D integer matrix `grid` of size `n * n`  
with values in the range `[1, n²]`.  

Each integer appears exactly once **except**:  
- One number `a` appears **twice**, and  
- One number `b` is **missing**.  

Find both the repeating (`a`) and missing (`b`) numbers.  

Return a 0-indexed integer array `ans` of size `2` where:  
`ans[0] = a` and `ans[1] = b`.

---

## ✨ Examples

### Example 1
**Input:**  
`grid = [[1,3],[2,2]]`  
**Output:**  
`[2,4]`  
**Explanation:**  
Number `2` is repeated and number `4` is missing, so the answer is `[2,4]`.

---

### Example 2
**Input:**  
`grid = [[9,1,7],[8,9,2],[3,4,6]]`  
**Output:**  
`[9,5]`  
**Explanation:**  
Number `9` is repeated and number `5` is missing, so the answer is `[9,5]`.

---

## 🎯 Constraints
- `2 <= n == grid.length == grid[i].length <= 50`  
- `1 <= grid[i][j] <= n²`  
- Every number from `1` to `n²` appears **exactly once**, except:  
  - One number appears **twice**  
  - One number is **missing**

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n²)` |
| **Space Complexity** | `O(1)` |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Meta, Adobe

---

## 🏷️ Topic Tags
- Array  
- Hash Table  
- Math  
- Matrix  

---

## 💡 Approach – Mathematical Formula

### 🔹 Steps:
1. Flatten the 2D matrix into a 1D array.  
2. Compute expected sum and sum of squares for numbers `1..n²`.  
3. Compute actual sum and sum of squares from the matrix.  
4. Use equations to derive the missing and repeated values:  
   - Let `diff = expectedSum - actualSum = b - a`  
   - Let `sqDiff = expectedSqSum - actualSqSum = b² - a² = (b - a)(b + a)`  
   - Then, `b + a = sqDiff / diff`  
   - Solve for `b = (diff + (sqDiff/diff)) / 2` and `a = b - diff`.  
5. Return `[a, b]`.

---

## 🧠 Algorithm
1. Compute total expected sum and sum of squares.  
2. Calculate actual sums from the grid.  
3. Derive missing and repeated numbers using difference equations.  
4. Return `[repeated, missing]`.

---

## 🖥️ C++ Implementation

```cpp
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;
        
        long long sum = 0, sqSum = 0;
        for (auto &row : grid) {
            for (auto val : row) {
                sum += val;
                sqSum += (long long)val * val;
            }
        }

        long long totalSum = N * (N + 1) / 2;
        long long totalSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long diff = totalSum - sum;              // b - a
        long long sqDiff = totalSqSum - sqSum;        // b^2 - a^2
        long long sumAB = sqDiff / diff;              // b + a

        long long b = (diff + sumAB) / 2;
        long long a = b - diff;

        return {(int)a, (int)b};
    }
};
```