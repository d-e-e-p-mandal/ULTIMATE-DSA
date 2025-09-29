# Missing Number

## 📌 Problem Statement
Given an array `nums` containing `n` **distinct numbers** in the range `[0, n]`, return the **only number missing** from the array.  

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [3,0,1]`  

**Output:**  
`2`  

**Explanation:**  
n = 3, numbers in range [0,3]. Missing number = 2.  

---

### Example 2
**Input:**  
`nums = [0,1]`  

**Output:**  
`2`  

---

### Example 3
**Input:**  
`nums = [9,6,4,2,3,5,7,0,1]`  

**Output:**  
`8`  

---

## 🎯 Constraints
- `n == nums.length`  
- `1 <= n <= 10^4`  
- `0 <= nums[i] <= n`  
- All numbers in `nums` are **unique**  

---

## ⏱️ Follow-Up / Expected Complexity
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`  

---

## 💡 Approaches

### 1️⃣ Sum Formula
1. Compute sum of first `n` natural numbers: `total = n * (n + 1) / 2`  
2. Subtract sum of elements in array: `missing = total - sum(nums)`  

### 2️⃣ XOR Trick
1. XOR all indices and elements:  
    missing = 0
    for i in range(n):
    missing ^= i ^ nums[i]
    missing ^= n
2. The result is the missing number.  

### 3️⃣ Sorting / Binary Search
- Sort array and check for missing index using comparison (less efficient than O(n) solutions).

---

🏷️ Topic Tags
	•	Array
	•	Hash Table
	•	Math
	•	Binary Search
	•	Bit Manipulation
	•	Sorting

---

## 🖥️ C++ Implementation (XOR Method)

```cpp
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
 int n = nums.size();
 int res = n; // include n itself
 for (int i = 0; i < n; i++) {
     res ^= i ^ nums[i];
 }
 return res;
}

int main() {
 vector<int> nums = {3,0,1};
 cout << missingNumber(nums) << endl; // Output: 2
 return 0;
}