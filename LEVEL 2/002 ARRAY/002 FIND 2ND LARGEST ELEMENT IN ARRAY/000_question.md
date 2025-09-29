# Second Largest Element in an Array
[GFG](https://www.geeksforgeeks.org/problems/second-largest3735/1)

## 📌 Problem Statement
Given an array of positive integers `arr[]`, return the **second largest element** from the array.  
If the second largest element doesn't exist, return `-1`.

⚠️ **Note:** The second largest element should **not** be equal to the largest element.

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [12, 35, 1, 10, 34, 1]`  

**Output:**  
`34`  

**Explanation:**  
The largest element is **35** and the second largest is **34**.

---

### Example 2
**Input:**  
`arr[] = [10, 5, 10]`  

**Output:**  
`5`  

**Explanation:**  
The largest element is **10** and the second largest is **5**.

---

### Example 3
**Input:**  
`arr[] = [10, 10, 10]`  

**Output:**  
`-1`  

**Explanation:**  
All elements are equal to **10**, so the second largest does not exist.

---

## 🎯 Constraints
- `2 ≤ arr.size() ≤ 10^5`  
- `1 ≤ arr[i] ≤ 10^5`

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`

---

🏷️ Topic Tags
	•	Arrays
	•	Searching
	•	Data Structures
	•	Algorithms
---

## 💡 Approach
1. Initialize two variables:  
   - `first = -1` (to store the largest)  
   - `second = -1` (to store the second largest)  
2. Traverse through the array:  
   - If the current element is **greater than `first`** → update `second = first`, `first = current`.  
   - Else if the current element is **less than `first` but greater than `second`** → update `second = current`.  
3. At the end, return `second`.  

---

🏢 Company Tags
	•	SAP Labs
	•	Rockstand

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int>& arr) {
    int first = -1, second = -1;
    
    for (int x : arr) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x < first && x > second) {
            second = x;
        }
    }
    return second;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << getSecondLargest(arr) << endl;
    return 0;
}