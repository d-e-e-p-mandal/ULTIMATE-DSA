### Largest Element in Array

- [GFG](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1)


## Q

# Largest Element in an Array

## 📌 Problem Statement
Given an array `arr[]`, the task is to find the **largest element** and return it.

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [1, 8, 7, 56, 90]`  

**Output:**  
`90`  

**Explanation:**  
The largest element of the given array is **90**.

---

### Example 2
**Input:**  
`arr[] = [5, 5, 5, 5]`  

**Output:**  
`5`  

**Explanation:**  
All elements are equal, so the largest is **5**.

---

### Example 3
**Input:**  
`arr[] = [10]`  

**Output:**  
`10`  

**Explanation:**  
There is only one element which is the largest.

---

## 🎯 Constraints
- `1 <= arr.size() <= 10^6`  
- `0 <= arr[i] <= 10^6`

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`

---

🏷️ Topic Tags
	•	ArraysData
	•	Structures

---

## 💡 Approach
1. Initialize a variable `maxElement` with the first element of the array.  
2. Traverse through the array.  
3. Compare each element with `maxElement`.  
   - If the current element is greater, update `maxElement`.  
4. After the loop ends, return `maxElement`.

---

🏢 Company Tags
	•	Infosys
	•	Oracle
	•	Wipro
	•	Morgan Stanley
	•	TCS
	•	Accenture
	•	Cognizant
	•	Capgemini
	•	HCL Technologies
	•	Tech Mahindra

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& arr) {
    int maxElement = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    vector<int> arr = {1, 8, 7, 56, 90};
    cout << largestElement(arr) << endl;
    return 0;
}
```