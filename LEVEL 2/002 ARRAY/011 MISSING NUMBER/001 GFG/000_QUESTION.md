# Missing in Array

[GFG](https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1)

## 📌 Problem Statement
You are given an array `arr[]` of size `n - 1` containing **distinct integers** in the range `1` to `n` (inclusive).  
This array represents a **permutation** of integers from `1` to `n` with **one element missing**.  

Your task: **Find and return the missing element.**

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [1, 2, 3, 5]`  

**Output:**  
`4`  

**Explanation:**  
All numbers from 1 to 5 should be present, but 4 is missing.  

---

### Example 2
**Input:**  
`arr = [8, 2, 4, 5, 3, 7, 1]`  

**Output:**  
`6`  

---

### Example 3
**Input:**  
`arr = [1]`  

**Output:**  
`2`  

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^6`  
- `1 ≤ arr[i] ≤ arr.size() + 1`  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approaches

### ✅ Method 1: Mathematical Sum Formula
- The sum of first `n` natural numbers = `n * (n + 1) / 2`  
- Compute this sum and subtract the sum of given array elements.  
- The result is the missing number.  

---

### ✅ Method 2: XOR Trick (Bit Magic)
- XOR of `1...n` with all elements in array → gives the missing element.  
- Works because duplicate numbers cancel out in XOR.  

---

🏢 Company Tags
	•	Flipkart
	•	Morgan Stanley
	•	Accolite
	•	Amazon
	•	Microsoft
	•	D-E-Shaw
	•	Ola Cabs
	•	Payu
	•	Visa
	•	Intuit
	•	Adobe
	•	Cisco
	•	Qualcomm
	•	TCS

⸻

🏷️ Topic Tags
	•	Arrays
	•	Searching
	•	Bit Magic
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation (Sum Formula)

```cpp
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& arr) {
    int n = arr.size() + 1; // since one number is missing
    long long total = (1LL * n * (n + 1)) / 2;
    long long sum = 0;

    for (int num : arr) sum += num;

    return (int)(total - sum);
}

int main() {
    vector<int> arr = {1, 2, 3, 5};
    cout << missingNumber(arr) << endl; // Output: 4
    return 0;
}