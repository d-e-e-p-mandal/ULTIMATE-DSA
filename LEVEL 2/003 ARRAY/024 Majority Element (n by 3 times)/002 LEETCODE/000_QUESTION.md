# Majority Element II

[LeetCode Problem Link](https://leetcode.com/problems/majority-element-ii/)

---

## 📌 Problem Statement
Given an integer array `nums` of size `n`, find **all elements** that appear **more than ⌊ n/3 ⌋ times**.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [3, 2, 3]`  
**Output:**  
`[3]`

---

### Example 2
**Input:**  
`nums = [1]`  
**Output:**  
`[1]`

---

### Example 3
**Input:**  
`nums = [1, 2]`  
**Output:**  
`[1, 2]`

---

## 🎯 Constraints
- `1 <= nums.length <= 5 * 10⁴`  
- `-10⁹ <= nums[i] <= 10⁹`

---

## 💡 Follow-up
Can you solve it in:
- **Linear time O(n)**
- **Constant space O(1)**?

---

## 🏷️ Topics
- Array  
- Hash Table  
- Sorting  
- Counting  

---

## ⚙️ Approach 1 – Using Hash Map (O(n) Time, O(n) Space)
1. Count frequency of each number using a hash map.  
2. Return all elements with count > ⌊n/3⌋.

### ✅ Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    vector<int> res;
    int n = nums.size();
    for (auto it : freq) {
        if (it.second > n / 3)
            res.push_back(it.first);
    }
    return res;
}

int main() {
    vector<int> nums = {3, 2, 3};
    vector<int> ans = majorityElement(nums);
    for (int x : ans) cout << x << " ";
    return 0;
}