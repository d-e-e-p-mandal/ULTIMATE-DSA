# Alternate Positive Negative

[GeeksForGeeks Problem Link](https://practice.geeksforgeeks.org/problems/alternate-positive-and-negative-numbers4147/1)

---

## 📌 Problem Statement
Given an unsorted array `arr` containing both positive and negative numbers.  

Your task is to **rearrange the array** and convert it into an array of **alternate positive and negative numbers** without changing the relative order.

### Note:
- Resulting array should start with a positive integer (**0 is considered positive**).  
- If any of the positive or negative integers are exhausted, append the remaining elements while maintaining relative order.  
- The array may or may not have an equal number of positive and negative integers.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [9, 4, -2, -1, 5, 0, -5, -3, 2]`  

**Output:**  
`[9, -2, 4, -1, 5, -5, 0, -3, 2]`  

**Explanation:**  
Positive numbers: `[9, 4, 5, 0, 2]`  
Negative numbers: `[-2, -1, -5, -3]`  
We start with a positive number and alternate, preserving relative order.

---

### Example 2
**Input:**  
`arr = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]`  

**Output:**  
`[5, -5, 2, -2, 4, -8, 7, 1, 8, 0]`  

**Explanation:**  
Positive numbers: `[5, 2, 4, 7, 1, 8, 0]`  
Negative numbers: `[-5, -2, -8]`  
After exhausting negatives, remaining positives are appended as-is.

---

### Example 3
**Input:**  
`arr = [9, 5, -2, -1, 5, 0, -5, -3, 2]`  

**Output:**  
`[9, -2, 5, -1, 5, -5, 0, -3, 2]`  

**Explanation:**  
Positive numbers: `[9, 5, 5, 0, 2]`  
Negative numbers: `[-2, -1, -5, -3]`  
Alternating order preserved.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^6`  
- `-10^6 ≤ arr[i] ≤ 10^6`  

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Traverse array once to separate and merge |
| **Space Complexity** | `O(n)` — Extra space for positive and negative arrays |

---

## 🏢 Company Tags
Paytm, VMWare, Amazon, Microsoft, Intuit  

---

## 🏷️ Topic Tags
- Array  
- Data Structures  

---

## 💡 Approach – Separate and Merge
1. Traverse the array and store **positives** and **negatives** in separate arrays.  
2. Merge both arrays **alternately**, starting with a positive.  
3. If one list is exhausted, append remaining elements from the other list, maintaining relative order.  
4. Return the final rearranged array.

---

## 🧠 Algorithm
1. Initialize two arrays: `pos[]` and `neg[]`.  
2. Traverse `arr`:
   - Append non-negative numbers to `pos[]`  
   - Append negative numbers to `neg[]`  
3. Merge arrays alternately:
   - Take `pos[i]` then `neg[j]` until one array ends  
   - Append remaining elements from whichever array still has numbers  
4. Return the merged array.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr) {
    vector<int> pos, neg, ans;

    // Separate positives and negatives
    for (int num : arr) {
        if (num >= 0) pos.push_back(num);
        else neg.push_back(num);
    }

    int i = 0, j = 0;
    // Alternate merging
    while (i < pos.size() && j < neg.size()) {
        ans.push_back(pos[i++]);
        ans.push_back(neg[j++]);
    }

    // Append remaining elements
    while (i < pos.size()) ans.push_back(pos[i++]);
    while (j < neg.size()) ans.push_back(neg[j++]);

    return ans;
}

int main() {
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    vector<int> res = rearrangeArray(arr);

    for (int x : res) cout << x << " ";
    return 0;
}
```