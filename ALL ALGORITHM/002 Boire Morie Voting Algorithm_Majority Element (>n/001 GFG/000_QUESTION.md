# Majority Element

[GFG Problem Link](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1)

---

## 📌 Problem Statement
Given an array `arr[]`, find the **majority element** in the array.  
If no majority element exists, return `-1`.

🧠 **Note:**  
A majority element in an array is an element that appears **strictly more than `arr.size()/2` times**.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [1, 1, 2, 1, 3, 5, 1]`  

**Output:**  
`1`

**Explanation:**  
Since `1` is present more than `7/2` times, it is the majority element.

---

### Example 2
**Input:**  
`arr = [7]`  

**Output:**  
`7`

**Explanation:**  
Since `7` is the single element, it appears more than `1/2` times.

---

### Example 3
**Input:**  
`arr = [2, 13]`  

**Output:**  
`-1`

**Explanation:**  
No element occurs more than `2/2` times, hence no majority element.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `1 ≤ arr[i] ≤ 10^5`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|------------------|-------------|
| **Time Complexity** | `O(n)` |
| **Space Complexity** | `O(1)` |

---

## 🏢 Company Tags
Flipkart, Accolite, Amazon, Microsoft, D-E-Shaw, Google, Nagarro, Atlassian

---

## 🏷️ Topic Tags
- Arrays  
- Searching  
- Greedy  
- Data Structures  
- Algorithms

---

## 💡 Approach – Boyer–Moore Majority Vote Algorithm (Optimal)

This is the most efficient algorithm to find a majority element in **linear time** and **constant space**.

### 🔍 Intuition
We maintain a **candidate** and a **count**:
- If `count` becomes 0 → choose current element as new candidate.
- If the current element equals the candidate → increment count.
- Else → decrement count.

At the end, the **candidate** is the potential majority element.  
We then verify whether it actually appears more than `n/2` times.

---

## 🧠 Algorithm
1. Initialize `count = 0`, `candidate = -1`.  
2. Traverse the array:  
   - If `count == 0`, set `candidate = arr[i]`.  
   - If `arr[i] == candidate`, increment count.  
   - Else decrement count.  
3. Verify the candidate — count its actual frequency.  
4. If frequency > `n/2`, return candidate; else return `-1`.

---

## ⏱️ Time & Space Complexity

| Complexity Type | Description |
|------------------|-------------|
| **Time Complexity** | `O(n)` — Two passes (finding + verification) |
| **Space Complexity** | `O(1)` — Constant space usage |

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr) {
    int count = 0;
    int candidate = -1;

    // Step 1: Find candidate
    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify candidate
    int freq = 0;
    for (int num : arr) {
        if (num == candidate) freq++;
    }

    if (freq > arr.size() / 2) return candidate;
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout << majorityElement(arr);
    return 0;
}
```