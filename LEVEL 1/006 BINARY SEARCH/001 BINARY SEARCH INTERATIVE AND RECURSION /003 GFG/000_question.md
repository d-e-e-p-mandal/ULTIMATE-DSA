# Sorted Array Search

## 📌 Problem Statement
Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/search-in-a-sorted-array-1587115621/1

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [1, 2, 3, 4, 6], k = 6`

**Output:**  
`true`

**Exlpanation:**  
Since, 6 is present in the array at index 4 (0-based indexing), output is true.

---

### Example 2
**Input:**  
`arr[] = [1, 2, 4, 5, 6], k = 3`

**Output:**  
`false`

**Exlpanation:**  
Since, 3 is not present in the array, output is false.

---

### Example 3
**Input:**  
`arr[] = [2, 3, 5, 6], k = 1`

**Output:**  
`false`

---

## 🎯 Constraints
- 1 ≤ arr.size() ≤ 10^6  
- 1 ≤ k ≤ 10^6  
- 1 ≤ arr[i] ≤ 10^6  

---

## ⏱️ Expected Complexities
- Time Complexity: O(log n)  
- Auxiliary Space: O(1)

---

## 💡 Approach – Binary Search
1. Use binary search to find k in the sorted array.  
2. If found, return true.  
3. If search exhausts, return false.

---

🏷️ Company Tags
	•	Paytm

⸻

🏷️ Topic Tags
	•	Searching
	•	Binary Search
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool search(vector<int>& arr, int k){
        int low = 0, high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == k)
                return true;
            else if(arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

int main(){
    Solution sol;

    vector<int> a1 = {1, 2, 3, 4, 6};
    cout << sol.search(a1, 6) << endl; // Output: true

    vector<int> a2 = {1, 2, 4, 5, 6};
    cout << sol.search(a2, 3) << endl; // Output: false

    vector<int> a3 = {2, 3, 5, 6};
    cout << sol.search(a3, 1) << endl; // Output: false

    return 0;
}
```