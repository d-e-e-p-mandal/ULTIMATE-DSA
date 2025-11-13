# Count Inversions

[GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1)

---

## 📌 Problem Statement
Given an array of integers `arr[]`, you need to find the **Inversion Count** of the array.  

An **inversion** is a pair `(i, j)` such that:
- `i < j` and  
- `arr[i] > arr[j]`

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [2, 4, 1, 3, 5]`  
**Output:**  
`3`  
**Explanation:**  
The sequence `[2, 4, 1, 3, 5]` has three inversions:  
`(2, 1)`, `(4, 1)`, `(4, 3)`.

---

### Example 2
**Input:**  
`arr[] = [2, 3, 4, 5, 6]`  
**Output:**  
`0`  
**Explanation:**  
The sequence is already sorted, so there are **no inversions**.

---

### Example 3
**Input:**  
`arr[] = [10, 10, 10]`  
**Output:**  
`0`  
**Explanation:**  
All elements are equal, hence **no inversions**.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10⁵`  
- `1 ≤ arr[i] ≤ 10⁴`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n log n)` |
| **Space Complexity** | `O(n)` |

---

## 🏢 Company Tags
Flipkart, Amazon, Microsoft, MakeMyTrip, Adobe, BankBazaar, Myntra

---

## 🏷️ Topic Tags
- Array  
- Divide and Conquer  
- Sorting  
- Data Structures  
- Algorithms  

---

## 💡 Approach – Merge Sort Based Counting

### 🔹 Steps:
1. Divide the array into two halves recursively (like merge sort).  
2. While merging two sorted halves:
   - If `arr[i] > arr[j]`, then all elements from `i` to `mid` are greater than `arr[j]`.  
   - Add `(mid - i + 1)` to inversion count.  
3. Continue merging until the array is fully sorted.  
4. Return the total count.

---

## 🧠 Algorithm
1. Use a modified merge sort to count inversions during merging.  
2. If left element > right element, increment count by remaining elements in the left subarray.  
3. Return total inversion count after full merge.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long i = left, j = mid, k = left, invCount = 0;

        while (i <= mid - 1 && j <= right) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                invCount += (mid - i);
            }
        }

        while (i <= mid - 1) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (i = left; i <= right; i++) arr[i] = temp[i];

        return invCount;
    }

    long long mergeSort(long long arr[], long long temp[], long long left, long long right) {
        long long mid, invCount = 0;
        if (right > left) {
            mid = (left + right) / 2;

            invCount += mergeSort(arr, temp, left, mid);
            invCount += mergeSort(arr, temp, mid + 1, right);

            invCount += merge(arr, temp, left, mid + 1, right);
        }
        return invCount;
    }

    long long inversionCount(long long arr[], long long N) {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }
};

int main() {
    long long arr[] = {2, 4, 1, 3, 5};
    long long N = 5;
    Solution ob;
    cout << ob.inversionCount(arr, N);
    return 0;
}
```