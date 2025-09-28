# Rotate Array

[GFG](https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1)

## 📌 Problem Statement
Given an array `arr[]`, rotate the array to the **left (counter-clockwise direction)** by `d` steps, where `d` is a positive integer.  
The array is **circular** (elements shifted beyond the start come to the end).  
Do the changes **in place**.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [1, 2, 3, 4, 5], d = 2`  

**Output:**  
`[3, 4, 5, 1, 2]`  

**Explanation:**  
After rotating left by 2 positions → `[3, 4, 5, 1, 2]`.

---

### Example 2
**Input:**  
`arr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3`  

**Output:**  
`[8, 10, 12, 14, 16, 18, 20, 2, 4, 6]`  

**Explanation:**  
After rotating left by 3 positions → `[8, 10, 12, 14, 16, 18, 20, 2, 4, 6]`.

---

### Example 3
**Input:**  
`arr = [7, 3, 9, 1], d = 9`  

**Output:**  
`[3, 9, 1, 7]`  

**Explanation:**  
Since `d = 9` and `n = 4`, effective rotation is `d % n = 1`.  
So result = `[3, 9, 1, 7]`.

---

## 🎯 Constraints
- `1 <= arr.size(), d <= 10^5`  
- `0 <= arr[i] <= 10^5`

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`

---

## 💡 Approach (Reversal Algorithm)
To rotate an array left by `d` steps:  
1. Reduce `d = d % n` (because rotating more than `n` is redundant).  
2. **Reverse first `d` elements**.  
3. **Reverse remaining `n-d` elements**.  
4. **Reverse the whole array**.  

---

🏢 Company Tags
	•	Amazon
	•	Microsoft
	•	MAQ Software

⸻

🏷️ Topic Tags
	•	Arrays
	•	Data Structures

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to reverse subarray from index l to r
void reverseArray(vector<int>& arr, int l, int r) {
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // effective rotations

    // Step 1: Reverse first d elements
    reverseArray(arr, 0, d - 1);

    // Step 2: Reverse remaining n-d elements
    reverseArray(arr, d, n - 1);

    // Step 3: Reverse the whole array
    reverseArray(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    rotateArray(arr, d);

    cout << "Rotated Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}