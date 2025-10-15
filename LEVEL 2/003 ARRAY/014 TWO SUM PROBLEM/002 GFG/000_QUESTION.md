# Two Sum - Pair with Given Sum

[GFG](https://www.geeksforgeeks.org/problems/key-pair5616/1)

## 📌 Problem Statement
Given an integer array `arr[]` and a target integer `target`, determine if there exist **two distinct indices** such that their sum equals the target.  

Return `true` if such a pair exists, otherwise `false`.  

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [0, -1, 2, -3, 1], target = -2`  

**Output:**  
`true`  

**Explanation:**  
`arr[3] + arr[4] = -3 + 1 = -2`.

---

### Example 2
**Input:**  
`arr = [1, -2, 1, 0, 5], target = 0`  

**Output:**  
`false`  

**Explanation:**  
No pair adds up to `0`.

---

### Example 3
**Input:**  
`arr = [11], target = 11`  

**Output:**  
`false`  

**Explanation:**  
Only one element exists → no pair possible.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `-10^5 ≤ arr[i] ≤ 10^5`  
- `-2*10^5 ≤ target ≤ 2*10^5`

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(n)`  

---

## 💡 Approach – Hashing
1. Create an empty hash set.  
2. For each element `x` in `arr`:  
   - Check if `target - x` exists in the set.  
   - If yes → return `true`.  
   - Otherwise, insert `x` into the set.  
3. If no pair found → return `false`.  

---

🏷️ Company Tags

Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, FactSet, Hike, Adobe, Google, Wipro, SAP Labs, CarWale

⸻

🏷️ Topic Tags
	•	Arrays
	•	Hashing
	•	Data Structures

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int target) {
    unordered_set<int> s;
    for (int x : arr) {
        int complement = target - x;
        if (s.find(complement) != s.end()) {
            return true;
        }
        s.insert(x);
    }
    return false;
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    cout << (hasPairWithSum(arr, target) ? "true" : "false") << endl;
    return 0;
}
```