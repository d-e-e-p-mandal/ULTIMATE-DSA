# Missing And Repeating

[GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/)

---

## 📌 Problem Statement
Given an unsorted array `arr[]` of size `n`, containing elements from the range `1` to `n`,  
it is known that one number in this range is **missing**, and another number **occurs twice** in the array.  
Find both the **duplicate** number and the **missing** number.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [2, 2]`  
**Output:**  
`[2, 1]`  
**Explanation:**  
Repeating number is `2` and the missing number is `1`.

---

### Example 2
**Input:**  
`arr = [1, 3, 3]`  
**Output:**  
`[3, 2]`  
**Explanation:**  
Repeating number is `3` and the missing number is `2`.

---

### Example 3
**Input:**  
`arr = [4, 3, 6, 2, 1, 1]`  
**Output:**  
`[1, 5]`  
**Explanation:**  
Repeating number is `1` and the missing number is `5`.

---

## 🎯 Constraints
- `2 ≤ n ≤ 10⁶`  
- `1 ≤ arr[i] ≤ n`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` |
| **Space Complexity** | `O(1)` |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Flipkart, Adobe, TCS

---

## 🏷️ Topic Tags
- Array  
- Mathematics  
- Bit Manipulation  

---

## 💡 Approach – Mathematical Formula

### 🔹 Steps:
1. Compute `S = n*(n+1)/2` and `P = n*(n+1)*(2n+1)/6`.  
2. Find `S1 = Σarr[i]` and `P1 = Σ(arr[i]²)`.  
3. Calculate `diff = S - S1` and `sum = (P - P1)/diff`.  
4. Get `missing = (diff + sum)/2` and `repeating = missing - diff`.  
5. Return `[repeating, missing]`.

---

## 🧠 Algorithm
1. Compute total sum and total square sum for numbers `1..n`.  
2. Compute actual sum and square sum from the array.  
3. From their differences, derive missing and repeating numbers.  
4. Return the pair `[repeating, missing]`.

---

## 🖥️ C++ Implementation

```cpp
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr, int n) {
        long long S = (long long)n * (n + 1) / 2;
        long long P = (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long S1 = 0, P1 = 0;
        for (int x : arr) {
            S1 += (long long)x;
            P1 += (long long)x * x;
        }

        long long diff = S - S1;              // M - R
        long long diff2 = (P - P1) / diff;    // M + R

        long long M = (diff + diff2) / 2;
        long long R = M - diff;

        return {(int)R, (int)M};
    }
};
```

