# Remove Duplicates from Sorted Array

[GFG](https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1)

## 📌 Problem Statement
You are given a **sorted array** `arr[]` containing positive integers.  
Your task is to **remove all duplicate elements** such that each element appears **only once**.  
Return an array containing these **distinct elements** in the **same order** as they appeared.

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [2, 2, 2, 2, 2]`  

**Output:**  
`[2]`  

**Explanation:**  
After removing duplicates, only one instance of `2` remains.

---

### Example 2
**Input:**  
`arr[] = [1, 2, 4]`  

**Output:**  
`[1, 2, 4]`  

**Explanation:**  
The array does not contain duplicates, so it remains the same.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `1 ≤ arr[i] ≤ 10^6`

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)` (if modifying in-place)  

---

## 💡 Approach (Two-Pointer)
1. Use a **slow pointer** `i` to track the last unique element index.  
2. Traverse the array with a **fast pointer** `j`.  
3. Whenever `arr[j] != arr[i]`:  
   - Increment `i` and set `arr[i] = arr[j]`.  
4. Return the array from index `0` to `i` (inclusive).

---

🏢 Company Tags
	•	Zoho
	•	Morgan Stanley
	•	Microsoft
	•	Samsung
	•	Google
	•	Wipro
	•	Xome

⸻

🏷️ Topic Tags
	•	Two-pointer Algorithm
	•	Arrays
	•	Data Structures
	•	Algorithms

--- 

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return {};
    
    int i = 0; // slow pointer
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return vector<int>(arr.begin(), arr.begin() + i + 1);
}

int main() {
    vector<int> arr = {2, 2, 2, 2, 2};
    vector<int> result = removeDuplicates(arr);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}