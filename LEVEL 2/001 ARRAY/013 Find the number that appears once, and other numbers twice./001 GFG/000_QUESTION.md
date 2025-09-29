# Unique Number I

[GFG](https://www.geeksforgeeks.org/problems/find-unique-number/1)

## 📌 Problem Statement
Given an **unsorted array** `arr[]` of positive integers, all numbers occur **exactly twice**, except for **one number** which occurs **only once**.  
Your task is to **find that unique number**.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [1, 2, 1, 5, 5]`  

**Output:**  
`2`  

**Explanation:**  
All numbers occur twice except `2`.  

---

### Example 2
**Input:**  
`arr = [2, 30, 2, 15, 20, 30, 15]`  

**Output:**  
`20`  

**Explanation:**  
All numbers occur twice except `20`.  

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^6`  
- `0 ≤ arr[i] ≤ 10^9`  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach (XOR Trick)
1. Initialize `res = 0`.  
2. Traverse the array and XOR every element with `res`.  
3. Since `a ^ a = 0` and `0 ^ b = b`, all numbers occurring twice cancel out, leaving the unique number.  

---

🏷️ Topic Tags
	•	Arrays
	•	Bit Manipulation
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int findUniqueNumber(vector<int>& arr) {
    int res = 0;
    for (int num : arr) res ^= num;
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 5, 5};
    cout << findUniqueNumber(arr) << endl; // Output: 2
    return 0;
}