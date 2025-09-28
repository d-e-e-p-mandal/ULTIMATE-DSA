# Move All Zeroes to End

[GFG](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1)

## 📌 Problem Statement
You are given an array `arr[]` of **non-negative integers**.  
Move all the **zeros** in the array to the **right end** while maintaining the **relative order of the non-zero elements**.  

The operation must be performed **in place** (no extra array allowed).  

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [1, 2, 0, 4, 3, 0, 5, 0]`  

**Output:**  
`[1, 2, 4, 3, 5, 0, 0, 0]`  

**Explanation:**  
There are three `0`s, moved to the end while preserving the order of `[1,2,4,3,5]`.

---

### Example 2
**Input:**  
`arr = [10, 20, 30]`  

**Output:**  
`[10, 20, 30]`  

**Explanation:**  
No change since there are no zeros.

---

### Example 3
**Input:**  
`arr = [0, 0]`  

**Output:**  
`[0, 0]`  

**Explanation:**  
All are zeros, so array remains unchanged.

---

## 🎯 Constraints
- `1 <= arr.size() <= 10^5`  
- `0 <= arr[i] <= 10^5`  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach (Two-Pointer)
1. Maintain a pointer `j` for the position of the **next non-zero element**.  
2. Traverse the array:  
   - If `arr[i] != 0`, swap `arr[i]` with `arr[j]` and increment `j`.  
3. At the end, all zeros are automatically pushed to the right.  

---

🏢 Company Tags
	•	Paytm
	•	Amazon
	•	Microsoft
	•	Samsung
	•	SAP Labs
	•	LinkedIn
	•	Bloomberg

⸻

🏷️ Topic Tags
	•	Arrays
	•	Data Structures

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    int j = 0; // position for next non-zero element

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    moveZeroes(arr);

    cout << "Array after moving zeroes: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}