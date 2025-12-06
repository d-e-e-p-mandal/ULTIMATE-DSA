# Search in Rotated Sorted Array
Difficulty: MediumAccuracy: 37.64%Submissions: 288K+Points: 4
Given an array arr[] of distinct elements, which was initially sorted in ascending order but then rotated at some unknown pivot, the task is to find the index of a target key.  If the key is not present in the array, return -1.

---

## ✨ Examples

### Example 1
**Input:** arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
**Output:** 8
**Explanation:** 3 is found at index 8.

---

### Example 2
**Input:** arr[] = [3, 5, 1, 2], key = 6
**Output:** -1
**Explanation:** There is no element that has value 6.

---

### Example 3
**Input:** arr[] = [33, 42, 72, 99], key = 42
**Output:** 1
**Explanation:** 42 is found at index 1.

---

## 🎯 Constraints
- 1 ≤ arr.size() ≤ 10^6
- 0 ≤ arr[i] ≤ 10^6
- 0 ≤ key ≤ 10^6

---

## ⏱️ Expected Complexities
- Time Complexity: O(log n)
- Auxiliary Space: O(1)

---

## 💡 Approach – Modified Binary Search
1. Use binary search on the rotated array.  
2. At each step, check which half (left or right) is sorted.  
3. If key lies in the sorted half, continue binary search there; otherwise search the other half.  
4. Repeat until found or range exhausted.

---

🏷️ Company Tags
PaytmFlipkartAmazonMicrosoftSnapdealD-E-ShawFactSetHikeMakeMyTripIntuitAdobeGoogleBankBazaarTimes Internet

⸻

🏷️ Topic Tags
SearchingDivide and ConquerAlgorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInRotated(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) return mid;

            // left half is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= key && key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // right half is sorted
                if (arr[mid] < key && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout << sol.searchInRotated(a1, 3) << endl; // Output: 8

    vector<int> a2 = {3, 5, 1, 2};
    cout << sol.searchInRotated(a2, 6) << endl; // Output: -1

    vector<int> a3 = {33, 42, 72, 99};
    cout << sol.searchInRotated(a3, 42) << endl; // Output: 1

    return 0;
}
```