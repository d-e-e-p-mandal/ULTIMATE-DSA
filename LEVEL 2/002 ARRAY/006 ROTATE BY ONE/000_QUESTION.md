# Rotate Array by One

[GFG](https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1)

## 📌 Problem Statement
Given an array `arr`, rotate the array by one position in **clockwise** direction.  

That means the **last element becomes the first**, and all other elements are shifted one step to the right.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [1, 2, 3, 4, 5]`  

**Output:**  
`[5, 1, 2, 3, 4]`  

**Explanation:**  
After rotating once, `5` comes in front and others shift one place.

---

### Example 2
**Input:**  
`arr = [9, 8, 7, 6, 4, 2, 1, 3]`  

**Output:**  
`[3, 9, 8, 7, 6, 4, 2, 1]`  

**Explanation:**  
After rotating once, `3` comes in front.

---

## 🎯 Constraints
- `1 <= arr.size() <= 10^5`  
- `0 <= arr[i] <= 10^5`

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`

---

## 💡 Approach
1. Store the **last element** in a temporary variable.  
2. Shift all other elements to the right by one position.  
3. Place the stored element at index `0`.  

---

🏷️ Topic Tags
	•	Arrays
	•	Implementation

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void rotateArrayByOne(vector<int>& arr) {
    int n = arr.size();
    int last = arr[n - 1]; // store last element

    // shift elements to the right
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = last; // put last element at first
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    rotateArrayByOne(arr);

    cout << "Rotated Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}