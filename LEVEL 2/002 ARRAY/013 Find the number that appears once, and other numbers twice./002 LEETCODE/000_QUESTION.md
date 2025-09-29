# 136. Single Number

[LEETCODE](https://leetcode.com/problems/single-number/description/)

## 📌 Problem Statement
Given a **non-empty array** of integers `nums`, every element appears **twice** except for **one element**.  
Find that single element.  

- **Constraint:** Use **linear runtime** and **constant extra space**.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [2,2,1]`  

**Output:**  
`1`  

---

### Example 2
**Input:**  
`nums = [4,1,2,1,2]`  

**Output:**  
`4`  

---

### Example 3
**Input:**  
`nums = [1]`  

**Output:**  
`1`  

---

## 🎯 Constraints
- `1 <= nums.length <= 3 * 10^4`  
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`  
- Each element appears **twice** except for **one element**.  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach (XOR Trick)
1. Initialize `res = 0`.  
2. XOR every element with `res`.  
3. Since `a ^ a = 0` and `0 ^ b = b`, all numbers appearing twice cancel out, leaving the **single number**.  

---

🏷️ Topic Tags
	•	Array
	•	Bit Manipulation
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int num : nums) res ^= num;
    return res;
}

int main() {
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums) << endl; // Output: 4
    return 0;
}