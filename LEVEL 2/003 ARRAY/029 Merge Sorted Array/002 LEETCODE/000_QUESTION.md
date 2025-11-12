# Merge Sorted Array

[LeetCode Problem Link](https://leetcode.com/problems/merge-sorted-array/)

---

## 📌 Problem Statement
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`.  
To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged,  
and the last `n` elements are set to `0` and should be ignored.  
`nums2` has a length of `n`.

---

## ✨ Examples

### Example 1
**Input:**  
`nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3`  
**Output:**  
`[1,2,2,3,5,6]`  
**Explanation:**  
The arrays being merged are `[1,2,3]` and `[2,5,6]`.  
The result is `[1,2,2,3,5,6]`.

---

### Example 2
**Input:**  
`nums1 = [1], m = 1, nums2 = [], n = 0`  
**Output:**  
`[1]`

---

### Example 3
**Input:**  
`nums1 = [0], m = 0, nums2 = [1], n = 1`  
**Output:**  
`[1]`  
**Explanation:**  
Since `m = 0`, there are no elements in `nums1`. The only element comes from `nums2`.

---

## 🎯 Constraints
- `nums1.length == m + n`  
- `nums2.length == n`  
- `0 <= m, n <= 200`  
- `1 <= m + n <= 200`  
- `-10⁹ <= nums1[i], nums2[j] <= 10⁹`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(m + n)` |
| **Space Complexity** | `O(1)` (in-place merge) |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Facebook, Apple, Bloomberg

---

## 🏷️ Topic Tags
- Array  
- Two Pointers  
- Sorting  

---

## 💡 Approach – Two Pointers (from end)

### 🔍 Idea:
Start merging from the **end** of both arrays to avoid overwriting useful data in `nums1`.

---

### 🔹 Steps:
1. Initialize three pointers:
   - `i = m - 1` → last element in `nums1`
   - `j = n - 1` → last element in `nums2`
   - `k = m + n - 1` → last position in `nums1`
2. Compare `nums1[i]` and `nums2[j]`:
   - Place the larger one at `nums1[k]`.
   - Move pointers accordingly.
3. If any elements remain in `nums2`, copy them to `nums1`.
4. Done.

---

## 🧠 Algorithm
1. Traverse from right to left (`k = m + n - 1`).  
2. Compare and place larger elements from `nums1[i]` or `nums2[j]`.  
3. If `nums2` still has remaining elements, copy them.  
4. Return `nums1`.

---

## 🖥️ C++ Implementation

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // pointer for nums1
        int j = n - 1; // pointer for nums2
        int k = m + n - 1; // pointer for final position

        // Merge from end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If elements left in nums2
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};