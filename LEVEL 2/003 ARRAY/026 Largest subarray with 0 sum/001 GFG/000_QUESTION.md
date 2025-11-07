# Largest Subarray with 0 Sum

[GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

---

## 📌 Problem Statement
Given an array `arr[]` containing both positive and negative integers, your task is to find the **length of the longest subarray** whose **sum equals 0**.  

A **subarray** is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [15, -2, 2, -8, 1, 7, 10, 23]`  
**Output:**  
`5`  
**Explanation:**  
The longest subarray with sum 0 is `[-2, 2, -8, 1, 7]`.

---

### Example 2
**Input:**  
`arr = [2, 10, 4]`  
**Output:**  
`0`  
**Explanation:**  
There is no subarray with sum 0.

---

### Example 3
**Input:**  
`arr = [1, 0, -4, 3, 1, 0]`  
**Output:**  
`5`  
**Explanation:**  
The longest subarray with sum 0 is `[0, -4, 3, 1, 0]`.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10⁶`  
- `−10³ ≤ arr[i] ≤ 10³`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` |
| **Space Complexity** | `O(n)` |

---

## 🏢 Company Tags
Amazon, Microsoft, MakeMyTrip  

---

## 🏷️ Topic Tags
- Arrays  
- Hashing  
- Data Structures  

---

## 💡 Approach – Prefix Sum + Hash Map

### 🔍 Idea:
We keep track of the **cumulative (prefix) sum** while iterating through the array.  
If a prefix sum repeats, it means the subarray between the two occurrences of this sum has a **total sum of 0**.

---

### 🔹 Steps:
1. Initialize `sum = 0` and a hash map `mpp` to store `{sum: index}`.  
2. Traverse the array:
   - Add each element to `sum`.
   - If `sum == 0`, update max length as `i + 1`.
   - If `sum` already exists in `mpp`, calculate the subarray length `i - mpp[sum]` and update the maximum.
   - Otherwise, store the index of this `sum` in `mpp`.
3. Return the maximum length.

---

## 🧠 Algorithm
1. Initialize `sum = 0`, `maxLen = 0`, and an empty hash map.  
2. Traverse each element:
   - Update prefix sum.
   - If prefix sum = 0 → full subarray till i contributes.
   - If prefix sum seen before → subarray between old index and current index sums to 0.
3. Return `maxLen`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& arr) {
    unordered_map<int, int> mpp;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;
        else if (mpp.find(sum) != mpp.end())
            maxLen = max(maxLen, i - mpp[sum]);
        else
            mpp[sum] = i;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(arr) << endl;
    return 0;
}
```