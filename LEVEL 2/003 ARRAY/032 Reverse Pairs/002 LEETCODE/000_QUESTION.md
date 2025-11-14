# Reverse Pairs

[LeetCode Problem Link](https://leetcode.com/problems/reverse-pairs/)

---

## 📌 Problem Statement
Given an integer array `nums`, return the number of **reverse pairs** in the array.

A **reverse pair** is a pair `(i, j)` such that:  
- `0 <= i < j < nums.length`  
- `nums[i] > 2 * nums[j]`

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1, 3, 2, 3, 1]`  
**Output:**  
`2`  
**Explanation:**  
The reverse pairs are:  
- `(1, 4)` → `nums[1] = 3`, `nums[4] = 1`, and `3 > 2 * 1`  
- `(3, 4)` → `nums[3] = 3`, `nums[4] = 1`, and `3 > 2 * 1`

---

### Example 2
**Input:**  
`nums = [2, 4, 3, 5, 1]`  
**Output:**  
`3`  
**Explanation:**  
The reverse pairs are:  
- `(1, 4)` → `4 > 2 * 1`  
- `(2, 4)` → `3 > 2 * 1`  
- `(3, 4)` → `5 > 2 * 1`

---

## 🎯 Constraints
- `1 <= nums.length <= 5 * 10^4`  
- `-2^{31} <= nums[i] <= 2^{31} - 1`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n log n)` (using modified merge sort) |
| **Space Complexity** | `O(n)` |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Adobe, Facebook

---

## 🏷️ Topic Tags
- Array  
- Binary Search  
- Divide and Conquer  
- Binary Indexed Tree  
- Segment Tree  
- Merge Sort  
- Ordered Set  

---

## 💡 Approach – Modified Merge Sort

### 🔹 Steps:
1. Use a **merge sort** approach to sort the array and count reverse pairs efficiently.  
2. For every element in the left subarray, count how many elements in the right subarray satisfy `nums[i] > 2 * nums[j]`.  
3. Merge the two halves as in the classic merge sort while counting these pairs.  
4. Sum up counts from each merge step for the final answer.

---

## 🧠 Algorithm

1. Implement a merge sort that:
   - Recursively sorts the left and right halves.
   - Counts the reverse pairs before merging by:
     - For each element `nums[i]` in left half, increment count by the number of elements in right half `nums[j]` where `nums[i] > 2 * nums[j]`.
2. Merge the two sorted halves.
3. Return the total count.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0, j = mid + 1;

        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = 0;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    Solution sol;
    cout << sol.reversePairs(nums) << endl;  // Output: 2
    return 0;
}
```