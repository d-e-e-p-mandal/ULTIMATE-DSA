# Count Subarrays with given XOR

[GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/count-subarrays-with-given-xor/1)

---

## 📌 Problem Statement
Given an array of integers `arr[]` and a number `k`, count the number of **subarrays** whose **XOR of elements equals `k`**.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [4, 2, 2, 6, 4], k = 6`  
**Output:**  
`4`  
**Explanation:**  
Subarrays having XOR equal to `6` are:  
- `[4, 2]`  
- `[4, 2, 2, 6, 4]`  
- `[2, 2, 6]`  
- `[6]`

---

### Example 2
**Input:**  
`arr = [5, 6, 7, 8, 9], k = 5`  
**Output:**  
`2`  
**Explanation:**  
Subarrays with XOR equal to `5` are `[5]` and `[5, 6, 7, 8, 9]`.

---

### Example 3
**Input:**  
`arr = [1, 1, 1, 1], k = 0`  
**Output:**  
`4`  
**Explanation:**  
The subarrays having XOR = 0 are `[1, 1]`, `[1, 1]`, `[1, 1]`, and `[1, 1, 1, 1]`.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10⁵`  
- `0 ≤ arr[i] ≤ 10⁵`  
- `0 ≤ k ≤ 10⁵`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` |
| **Space Complexity** | `O(n)` |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Adobe, Paytm  

---

## 🏷️ Topic Tags
- Arrays  
- HashMap  
- Bit Manipulation  

---

## 💡 Approach – Prefix XOR + HashMap

### 🔍 Idea:
We use the **prefix XOR** concept to find subarrays whose XOR equals `k`.  
If `prefix_xor ^ k` has been seen before, it means a subarray ending at the current index has XOR = `k`.

---

### 🔹 Steps:
1. Initialize `xor = 0`, `count = 0`, and an unordered map `freq` to store frequency of prefix XORs.  
2. Traverse each element in the array:
   - Update `xor ^= arr[i]`
   - If `xor == k`, increment `count` (subarray from start)
   - If `freq[xor ^ k]` exists, add its frequency to `count`
   - Increment frequency of `xor` in the map
3. Return `count` at the end.

---

## 🧠 Algorithm
1. Maintain cumulative XOR as you traverse.  
2. Store XOR frequencies in a map.  
3. Each time check if `(current_xor ^ k)` appeared before — that means a subarray with XOR = k exists.  
4. Accumulate the total count.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXor(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int xr = 0, count = 0;

    for (int i = 0; i < arr.size(); i++) {
        xr ^= arr[i];

        if (xr == k)
            count++;

        if (freq.find(xr ^ k) != freq.end())
            count += freq[xr ^ k];

        freq[xr]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << countSubarraysWithXor(arr, k) << endl;
    return 0;
}
```