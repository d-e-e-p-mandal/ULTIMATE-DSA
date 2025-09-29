# Check if Array is Sorted

[GFG](https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1)

## 📌 Problem Statement
Given an array `arr[]`, check whether it is sorted in **non-decreasing order**.  
Return `true` if it is sorted, otherwise return `false`.

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [10, 20, 30, 40, 50]`  

**Output:**  
`true`  

**Explanation:**  
The given array is sorted in non-decreasing order.

---

### Example 2
**Input:**  
`arr[] = [90, 80, 100, 70, 40, 30]`  

**Output:**  
`false`  

**Explanation:**  
The array is not sorted in non-decreasing order.

---

## 🎯 Constraints
- `1 ≤ arr.size ≤ 10^6`  
- `-10^9 ≤ arr[i] ≤ 10^9`

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`

---

## 💡 Approach
1. Traverse the array from index `0` to `n-2`.  
2. For each index `i`, check if `arr[i] > arr[i+1]`.  
   - If true, return `false` immediately.  
3. If the loop completes without violations, return `true`.  

---

🏷️ Topic Tags
	•	Arrays
	•	Sorting
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << (isSorted(arr) ? "true" : "false") << endl;
    return 0;
}