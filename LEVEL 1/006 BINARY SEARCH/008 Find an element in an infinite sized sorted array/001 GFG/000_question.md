# Find position of an element in a sorted array of infinite numbers

## 📌 Problem Statement
Given a sorted array arr[] of infinite numbers, the task is to find the index of a given key k.  
Since the array is considered infinite, its actual size is unknown.  
If the key is present, return its index; otherwise return -1.

---

## 🔗 Problem Link
https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170], k = 10`

**Output:**  
`4`

**Explanation:**  
10 is at index 4 in the array.

---

### Example 2
**Input:**  
`arr[] = [2, 5, 7, 9], k = 3`

**Output:**  
`-1`

**Explanation:**  
3 is not present in the array.

---

## 🎯 Constraints
- Array is sorted in ascending order  
- Infinite size assumed (actual size unknown)  

---

## ⏱️ Expected Complexities
- Time Complexity: O(log p), where p is the position of key  
- Auxiliary Space: O(log p)

---

## 💡 Approach – Exponential Search + Binary Search
1. Start with low = 0 and high = 1  
2. Increase high exponentially (high = high * 2) until arr[high] ≥ key  
3. Perform binary search between low and high  
4. Return the index if found, else return -1

---

🏷️ Company Tags
	•	(No specific company tags available)

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

int binarySearch(vector<int> &arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int findPos(vector<int> &arr, int key) {
    int l = 0, h = 1;

    while (h < arr.size() && arr[h] < key) {
        l = h;
        h = 2 * h;
    }

    if (h >= arr.size())
        h = arr.size() - 1;

    return binarySearch(arr, l, h, key);
}

int main() {
    vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int k = 10;

    cout << findPos(arr, k) << endl; // Output: 4

    return 0;
}
```