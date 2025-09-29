# 485. Max Consecutive Ones

[LeetCode](https://leetcode.com/problems/max-consecutive-ones/description/)

## 📌 Problem Statement
Given a binary array `nums`, return the maximum number of consecutive `1's` in the array.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1,1,0,1,1,1]`  

**Output:**  
`3`  

**Explanation:**  
The first two `1’s` or the last three `1’s` are consecutive. The maximum is **3**.  

---

### Example 2
**Input:**  
`nums = [1,0,1,1,0,1]`  

**Output:**  
`2`  

**Explanation:**  
The maximum consecutive 1’s are **2**.  

---

## 🎯 Constraints
- `1 <= nums.length <= 10^5`  
- `nums[i]` is either `0` or `1`.  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`  

---

## 💡 Approach
1. Initialize `count = 0` and `maxCount = 0`.  
2. Traverse the array:  
   - If `nums[i] == 1`, increment `count`.  
   - Else reset `count = 0`.  
3. Update `maxCount = max(maxCount, count)` during traversal.  
4. Return `maxCount`.  

---

🏷️ Topic Tags
	•	Array

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxCount = 0;

    for (int num : nums) {
        if (num == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums) << endl; // Output: 3
    return 0;
}