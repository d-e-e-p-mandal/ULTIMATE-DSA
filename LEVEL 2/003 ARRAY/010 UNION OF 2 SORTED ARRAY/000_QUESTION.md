# Union of 2 Sorted Arrays

[gfg](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1)

## 📌 Problem Statement
Given two **sorted arrays** `a[]` and `b[]`, which may contain duplicate elements, return the **union** of the two arrays in **sorted order**.  

- **Union** is the set containing **distinct elements** present in either array.

---

## ✨ Examples

### Example 1
**Input:**  
`a = [1, 2, 3, 4, 5], b = [1, 2, 3, 6, 7]`  

**Output:**  
`[1, 2, 3, 4, 5, 6, 7]`  

**Explanation:**  
Distinct elements including both arrays: `[1, 2, 3, 4, 5, 6, 7]`.

---

### Example 2
**Input:**  
`a = [2, 2, 3, 4, 5], b = [1, 1, 2, 3, 4]`  

**Output:**  
`[1, 2, 3, 4, 5]`  

---

### Example 3
**Input:**  
`a = [1, 1, 1, 1, 1], b = [2, 2, 2, 2, 2]`  

**Output:**  
`[1, 2]`  

---

## 🎯 Constraints
- `1 ≤ a.size(), b.size() ≤ 10^5`  
- `-10^9 ≤ a[i], b[i] ≤ 10^9`

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n + m)`  
- **Auxiliary Space:** `O(n + m)`  

---

## 💡 Approach (Two-Pointer)
1. Initialize two pointers `i = 0, j = 0`.  
2. Compare `a[i]` and `b[j]`:  
   - If `a[i] < b[j]` → add `a[i]` to result and move `i`.  
   - If `b[j] < a[i]` → add `b[j]` to result and move `j`.  
   - If `a[i] == b[j]` → add any one of them and move both pointers.  
3. Skip duplicates while moving pointers.  
4. Append remaining elements from either array.  

---

🏢 Company Tags
	•	Amazon

⸻

🏷️ Topic Tags
	•	Arrays
	•	Data Structures
	•	Two-Pointer Algorithm

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> unionSortedArrays(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<int> result;
    int i = 0, j = 0;

    while (i < n && j < m) {
        // Skip duplicates in a
        while (i > 0 && i < n && a[i] == a[i-1]) i++;
        // Skip duplicates in b
        while (j > 0 && j < m && b[j] == b[j-1]) j++;

        if (i >= n || j >= m) break;

        if (a[i] < b[j]) result.push_back(a[i++]);
        else if (b[j] < a[i]) result.push_back(b[j++]);
        else {
            result.push_back(a[i]);
            i++; j++;
        }
    }

    while (i < n) {
        if (i == 0 || a[i] != a[i-1]) result.push_back(a[i]);
        i++;
    }

    while (j < m) {
        if (j == 0 || b[j] != b[j-1]) result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};

    vector<int> res = unionSortedArrays(a, b);
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}