# 3Sum

[LeetCode Problem Link](https://leetcode.com/problems/3sum/)

---

## 📌 Problem Statement
Given an integer array `nums`, return all the **unique triplets** `[nums[i], nums[j], nums[k]]` such that:
- `i != j`, `i != k`, and `j != k`, and  
- `nums[i] + nums[j] + nums[k] == 0`.

The solution set **must not contain duplicate triplets**.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [-1,0,1,2,-1,-4]`  
**Output:**  
`[[-1,-1,2], [-1,0,1]]`  

**Explanation:**  
Distinct triplets that sum to zero are:
- (-1) + 0 + 1 = 0  
- (-1) + (-1) + 2 = 0

---

### Example 2
**Input:**  
`nums = [0,1,1]`  
**Output:**  
`[]`  
**Explanation:**  
No triplet sums to zero.

---

### Example 3
**Input:**  
`nums = [0,0,0]`  
**Output:**  
`[[0,0,0]]`  
**Explanation:**  
The only triplet sums to zero.

---

## 🎯 Constraints
- `3 <= nums.length <= 3000`  
- `-10⁵ <= nums[i] <= 10⁵`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n²)` — two-pointer technique after sorting |
| **Space Complexity** | `O(1)` (excluding output storage) |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Facebook, Apple, Goldman Sachs, Adobe, Bloomberg, Flipkart

---

## 🏷️ Topic Tags
- Array  
- Two Pointers  
- Sorting  

---

## 💡 Approach – Sorting + Two Pointers

### 🔍 Idea:
We fix one element `nums[i]`, and then find two elements in the remaining array whose sum equals `-nums[i]`.

### 🔹 Steps:
1. Sort the array.
2. Iterate `i` from `0` to `n-3`:
   - Skip duplicate values for `nums[i]`.
   - Set `target = -nums[i]`.
   - Use two pointers:
     - `j = i + 1`
     - `k = n - 1`
   - Move pointers inward:
     - If `nums[j] + nums[k] == target`, store triplet and skip duplicates.
     - If sum < target → increment `j`.
     - If sum > target → decrement `k`.
3. Return the list of triplets.

---

## 🧠 Algorithm
1. Sort `nums`.
2. Loop through each element `nums[i]`.
3. Apply two-pointer search for `nums[j] + nums[k] = -nums[i]`.
4. Store only unique triplets.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                // Skip duplicates for j and k
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if (sum < 0) j++;
            else k--;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto triplet : ans) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }
    return 0;
}
```