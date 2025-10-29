# Maximum Subarray

[LeetCode Problem Link](https://leetcode.com/problems/maximum-subarray/)

---

## 📌 Problem Statement
Given an integer array `nums`, find the **subarray with the largest sum**, and return its sum.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [-2,1,-3,4,-1,2,1,-5,4]`  

**Output:**  
`6`  

**Explanation:**  
The subarray `[4,-1,2,1]` has the largest sum 6.

---

### Example 2
**Input:**  
`nums = [1]`  

**Output:**  
`1`  

**Explanation:**  
The subarray `[1]` has the largest sum 1.

---

### Example 3
**Input:**  
`nums = [5,4,-1,7,8]`  

**Output:**  
`23`  

**Explanation:**  
The subarray `[5,4,-1,7,8]` has the largest sum 23.

---

## 🎯 Constraints
- `1 <= nums.length <= 10^5`  
- `-10^4 <= nums[i] <= 10^4`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Single pass using Kadane’s Algorithm |
| **Space Complexity** | `O(1)` — Constant extra variables |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Facebook, Apple, Adobe, Oracle, D-E-Shaw, Flipkart, Zoho, Morgan Stanley, Accolite, Walmart

---

## 🏷️ Topic Tags
- Array  
- Divide and Conquer  
- Dynamic Programming  

---

## 💡 Approach – Kadane's Algorithm (Optimal, O(n))
Kadane’s Algorithm is ideal for finding the **maximum sum subarray** in linear time.

### 🔍 Key Idea
- Maintain a `current_sum` for the **maximum subarray sum ending at current index**.  
- Maintain `max_sum` to store the **global maximum**.  
- **Important:** For arrays with all negative numbers, initialize `max_sum` as the first element to handle correctly.

---

## 🧠 Algorithm
1. Initialize `max_sum = nums[0]` and `current_sum = nums[0]`.  
2. Traverse from the **second element** to the end of `nums`:  
   - `current_sum = max(num, current_sum + num)`  
   - `max_sum = max(max_sum, current_sum)`  
3. Return `max_sum`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums); // Output: 6
    return 0;
}
```