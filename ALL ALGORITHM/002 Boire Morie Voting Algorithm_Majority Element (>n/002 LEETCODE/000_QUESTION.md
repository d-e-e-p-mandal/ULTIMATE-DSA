# Majority Element

[LeetCode Problem Link](https://leetcode.com/problems/majority-element/)

---

## 📌 Problem Statement
Given an integer array `nums` of size `n`, return the **majority element**.  

The **majority element** is the element that appears **more than ⌊n / 2⌋ times**.  
You may assume that the **majority element always exists** in the array.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [3, 2, 3]`

**Output:**  
`3`

---

### Example 2
**Input:**  
`nums = [2, 2, 1, 1, 1, 2, 2]`

**Output:**  
`2`

---

## 🎯 Constraints
- `n == nums.length`  
- `1 ≤ n ≤ 5 * 10⁴`  
- `-10⁹ ≤ nums[i] ≤ 10⁹`

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`

---

## 💡 Approach – Boyer–Moore Majority Vote Algorithm (Optimal)
This is the most efficient approach to find the majority element in linear time and constant space.

### Intuition
- We maintain a **candidate** and a **count**.  
- As we iterate:
  - If the current element equals the candidate, increment count.
  - If not, decrement count.
  - When count becomes zero, choose a new candidate.

Since the majority element appears more than `n/2` times, it will always remain as the final candidate.

---

## 🧠 Algorithm
1. Initialize `count = 0` and `candidate = 0`.  
2. Traverse each element `num` in `nums`:  
   - If `count == 0`, set `candidate = num`.  
   - If `num == candidate`, increment `count`, else decrement `count`.  
3. After traversal, return `candidate`.

---

## ⏱️ Time & Space Complexity

| Complexity Type | Description |
|------------------|-------------|
| **Time Complexity** | **O(n)** — Each element is processed once in a single traversal. |
| **Space Complexity** | **O(1)** — Constant space used for `candidate` and `count`. |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Adobe, Bloomberg, Facebook, Apple, Uber, Goldman Sachs, Walmart Labs

---

## 🏷️ Topic Tags
- Array  
- Hash Table  
- Divide and Conquer  
- Sorting  
- Counting  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
    return 0;
}